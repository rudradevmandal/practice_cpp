#include <iostream>
using namespace std;

class Complex
{
    int real;
    int img;

public:
    Complex() : real(0), img(0) {};
    explicit Complex(int x, int y) : real(x), img(y) {};
    Complex(Complex &C) : real(C.real), img(C.img) {};

    void print() { cout << real << " + i" << img << endl; }
    void set(int x, int y)
    {
        real = x;
        img = y;
    }
    friend void show();
};
void show()
{
    cout << " + i" << endl;
}

int main()
{
    Complex C1;
    C1.print();
    C1.set(2, 3);
    C1.print();

    Complex C2(C1);
    C2.print();
    show();
}
