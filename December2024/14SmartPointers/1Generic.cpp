#include <iostream>
using namespace std;

template <class T>
class SmartPtr
{
    T *Ptr;

public:
    explicit SmartPtr(T *p) { Ptr = p; }
    ~SmartPtr() { delete Ptr; }

    T &operator*() { return *Ptr; }
};

int main()
{
    SmartPtr<int> ptr(new int());
    *ptr = 20;
    cout << *ptr << endl;
}