#include <iostream>
using namespace std;

class Animal
{
private:
    int x;

protected:
    int y;

public:
    void Print() { cout << "This is an animal." << endl; };
    virtual void PrintV() { cout << "This is an animal." << endl; };
    virtual void show() = 0;
};

class Dog : public Animal
{
public:
    void Print() { cout << "This is a Dog." << endl; };
    void show() { cout << "This is a Dog." << endl; };
};

class DogV : public Animal
{
public:
    void PrintV() { cout << "This is a Dog." << endl; };
    void show() { cout << "This is a DogV." << endl; };
};

int main()
{
    Animal *A;
    Dog dog;
    A = &dog;

    // This prints "This is an animal.". But since we had assigned dog to animal, we wanted "This is a Dog."
    A->Print();

    // Using virtual will fix this as binding happens at runtime
    Animal *A2;
    DogV dog2;
    A2 = &dog2;

    // This prints "This is a Dog."
    A2->PrintV();

    // Another way to fix this is to have pure virtual funvtions where the definitions are only defined in the derived class
    A->show();
    A2->show();
}