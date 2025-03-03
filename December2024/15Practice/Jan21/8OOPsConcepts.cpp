#include <iostream>
#include <thread>
using namespace std;

class Complex
{
    int real;
    int img;

public:
    Complex() : real(0), img(0) {};                      // Default Constructor
    explicit Complex(int r, int i) : real(r), img(i) {}; // Explicit constructor
    Complex(Complex &C)                                  // Copy Constructor
    {
        this->real = C.real;
        this->img = C.img;
    }

    void Print()
    {
        cout << real << "+i(" << img << ")" << endl;
    }

    void SetReal(int r) { this->real = r; };
    void SetImg(int i) { this->img = i; };

    void Set(int r) { this->real = r; };
    void Set(int r, int i)
    {
        this->real = r;
        this->img = i;
    };

    friend Complex operator+(Complex C1, Complex C2);
};

Complex operator+(Complex C1, Complex C2)
{
    Complex result;
    result.real = C1.real + C2.real;
    result.img = C1.img + C2.img;
    return result;
}

class Animal
{
public:
    virtual void PrintType() { cout << "This is an Animal." << endl; }
};

class MaleDog : virtual public Animal
{
public:
    void PrintType() { cout << "This is a Male Dog." << endl; }
};

class FemaleDog : virtual public Animal
{
public:
    void PrintType() { cout << "This is a Female Dog." << endl; }
};

class Puppy : public MaleDog, public FemaleDog
{
public:
    void PrintType() { cout << "This is a Puppy." << endl; }
};

int x = 0;
mutex mtx;
condition_variable cv;
bool T1_ready = false;
bool T2_ready = false;
bool T3_ready = true;
void ThreadFunction()
{
    thread T1{[]()
              {
                  unique_lock<mutex> lock(mtx);
                  for (int i = 0; i < 20; i++)
                  {
                      cv.wait(lock, []
                              { return T2_ready; });
                      x++;
                      cout << "Incremented in T1. x=" << x << endl;
                      T2_ready = false;
                      T1_ready = true;
                      cv.notify_all();
                  }
                  T2_ready = false;
                  T1_ready = true;
                  cv.notify_all();
              }};
    thread T2{[]()
              {
                  unique_lock<mutex> lock(mtx);

                  for (int i = 0; i < 20; i++)
                  {
                      cv.wait(lock, []
                              { return T3_ready; });
                      x++;
                      cout << "Incremented in T2. x=" << x << endl;
                      T2_ready = true;
                      T3_ready = false;
                      cv.notify_all();
                  }
                  T2_ready = true;
                  T3_ready = false;
                  cv.notify_all();
              }};
    thread T3{[]()
              {
                  unique_lock<mutex> lock(mtx);
                  for (int i = 0; i < 20; i++)
                  {
                      cv.wait(lock, []
                              { return T1_ready; });
                      x++;
                      cout << "Incremented in T3. x=" << x << endl;
                      T3_ready = true;
                      T1_ready = false;
                      cv.notify_all();
                  }
                  T3_ready = true;
                  T1_ready = false;
                  cv.notify_all();
              }};
    T2.join();
    T1.join();
    T3.join();
}

namespace N1
{
    void Print() { cout << "I am in N1." << endl; }
} // namespace N1

namespace N2
{
    void Print() { cout << "I am in N2." << endl; }
}

void UniquePointers()
{
    unique_ptr<int> U1(new int);
    *U1 = 10;
    cout << "Value in U1=" << *U1 << endl;

    // Cannot be done
    // unique_ptr<int> U2 = U1;
    // U2 = U1;
    // cout << "Value in U1=" << *U1 << endl;

    // Can be done
    // unique_ptr<int> U2 = std::move(U1); // U1=nullptr after this
}

void SharedPointers()
{
    shared_ptr<int> S1(new int);
    *S1 = 10;
    cout << "Value in S1=" << *S1 << ", refCount=" << S1.use_count() << endl;

    // Can be done
    shared_ptr<int> S2(S1);
    cout << "Value in S2=" << *S2 << ", refCount=" << S2.use_count() << endl;
}

void WeakPointers()
{
    shared_ptr<int> S1(new int);
    *S1 = 10;
    cout << "Value in S1=" << *S1 << ", refCount=" << S1.use_count() << endl;
    shared_ptr<int> S2(S1);
    cout << "Value in S2=" << *S2 << ", refCount=" << S2.use_count() << endl;

    weak_ptr<int> W1 = S1;
    cout << "Value in W1=" << *(W1.lock()).get() << ", refCount=" << W1.use_count() << endl;

    // Can be done
    weak_ptr<int> W2(W1);
    cout << "Value in W2=" << *(W2.lock()).get() << ", refCount=" << S2.use_count() << endl;

    // Can be done
    weak_ptr<int> W3 = S1;
    cout << "Value in W3=" << *(W3.lock()).get() << ", refCount=" << S1.use_count() << endl;
}
using namespace N2;
int main()
{
    Complex C;
    C.Print();
    C.SetReal(3);
    C.SetImg(-5);
    C.Print();

    Complex C1 = C;
    C1.Print();

    Complex C2(C);
    C2.Print();
    C = C1 + C2;
    C.Print();

    C.Set(4);
    C.Print();
    C.Set(5, 7);
    C.Print();

    Puppy P;
    P.PrintType();

    Animal *A = &P;
    A->PrintType();

    ThreadFunction();
    N1::Print();
    N2::Print();
    Print();

    UniquePointers();
    SharedPointers();
    WeakPointers();
}