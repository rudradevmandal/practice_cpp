
#include <iostream>
using namespace std;

class Singleton
{
    static Singleton *singletonInstance;
    static mutex mtx;
    int x, y;
    Singleton() {};

public:
    // Delete copy constructor
    Singleton(const Singleton &S) = delete;
    static Singleton *GetInstance()
    {
        if (!singletonInstance)
        {
            lock_guard<mutex> lock(mtx);
            if (!singletonInstance)
            {
                singletonInstance = new Singleton();
            }
        }
        return singletonInstance;
    }
    void Set(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    void Print()
    {
        cout << "x=" << x << ", y=" << y << endl;
    }
};

// Initialize static members
Singleton *Singleton::singletonInstance = nullptr;
mutex Singleton::mtx;
int main()
{
    Singleton *s1 = Singleton::GetInstance();
    s1->Set(1, 2);
    s1->Print();
    Singleton *s2 = Singleton::GetInstance();
    s2->Set(2, 3);
    s1->Print();
    s2->Print();
}