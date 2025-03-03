#include <iostream>
using namespace std;
class Complex
{

    // Abstraction - Keeping in private - Cannot access outside of base class
private:
    int real, img;

public:
    Complex(int a, int b) : real(a), img(b) {};

    void print() { cout << real << " + i" << img << endl; }

    friend Complex operator+(Complex &C1, Complex &C2);
};

// Operator overloading
Complex operator+(Complex &C1, Complex &C2)
{
    return Complex(C1.real + C2.real, C1.img + C2.img);
}

int main()
{
    Complex C1(2, 3);
    Complex C2(5, 4);

    Complex C3 = C1 + C2;
    C3.print();
}