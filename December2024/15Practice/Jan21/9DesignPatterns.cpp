#include <iostream>
using namespace std;

// Factory
class Sauce
{
public:
    virtual void GetSauce() = 0;
};

class MustardSauce : public Sauce
{
public:
    void GetSauce() { cout << "Mustard Sauce Applied." << endl; }
};

class BbqSauce : public Sauce
{
public:
    void GetSauce() { cout << "Bbq Sauce Applied." << endl; }
};

class Patty
{
public:
    virtual void GetPatty() = 0;
    virtual void GetPatty(Sauce &S) = 0;
};

class ChickenPatty : public Patty
{
public:
    void GetPatty() { cout << "Chicken Patty arrived." << endl; }
    void GetPatty(Sauce &S)
    {
        cout << "Chicken Patty arrived with ";
        S.GetSauce();
    }
};

class PaneerPatty : public Patty
{
public:
    void GetPatty() { cout << "Paneer Patty arrived." << endl; }
    void GetPatty(Sauce &S)
    {
        cout << "Paneer Patty arrived with ";
        S.GetSauce();
    }
};

class BurgerFactory
{
public:
    virtual Sauce *CreateSauce() = 0;
    virtual Sauce *CreateDipSauce() = 0;
    virtual Patty *CreatePatty() = 0;
};

class BbqDippedChickenBurgerWithMustardSauce : public BurgerFactory
{
    Sauce *CreateSauce() { return new MustardSauce(); }
    Sauce *CreateDipSauce() { return new BbqSauce(); }
    Patty *CreatePatty() { return new ChickenPatty(); }
};

class MustardDippedPanerBurgerWithBbqSauce : public BurgerFactory
{
    Sauce *CreateSauce() { return new BbqSauce(); }
    Sauce *CreateDipSauce() { return new MustardSauce(); }
    Patty *CreatePatty() { return new PaneerPatty(); }
};

void clientCode(BurgerFactory *factory)
{
    Sauce *createSauce = factory->CreateSauce();
    Sauce *CreateDipSauce = factory->CreateDipSauce();
    Patty *CreatePatty = factory->CreatePatty();

    createSauce->GetSauce();
    CreatePatty->GetPatty(*CreateDipSauce);
}

// Builder
class Plane
{
    string type;
    string body;
    string engine;

public:
    Plane(string type) : type(type), body(""), engine("") {}
    void GetType() { cout << "Plane is of " << type << endl; }
    void GetEngine() { cout << "Plane has " << engine << endl; }
    void GetBody() { cout << "Plane has " << body << endl; }

    void SetBody(string b) { this->body = b; }
    void SetEngine(string e) { this->engine = e; }

    void Print()
    {
        GetType();
        GetEngine();
        GetBody();
    }
};

class PlaneBuilder
{
protected:
    Plane *plane;

public:
    virtual void CreateParts() = 0;
    virtual void CreateEngine() = 0;
    virtual void CreateBody() = 0;
    Plane *GetPlane() { return plane; }
};

class PropellerPlane : public PlaneBuilder
{
public:
    void CreateParts()
    {
        plane = new Plane("Propeller Plane");
    }
    void CreateEngine()
    {
        plane->SetEngine("Propeller Engine");
    };
    void CreateBody()
    {
        plane->SetBody("Propeller body");
    };
};

class JetPlane : public PlaneBuilder
{
public:
    void CreateParts()
    {
        plane = new Plane("Jet Plane");
    }
    void CreateEngine()
    {
        plane->SetEngine("Jet Engine");
    };
    void CreateBody()
    {
        plane->SetBody("Jet body");
    };
};

class Director
{
public:
    Plane *Build(PlaneBuilder &builder)
    {
        builder.CreateParts();
        builder.CreateEngine();
        builder.CreateBody();
        return builder.GetPlane();
    }
};

// Singleton
class Singleton
{
    static Singleton *singletonInstance;
    static mutex mtx;
    Singleton() = default;

    int x;

public:
    Singleton(const Singleton &S) = delete;
    static Singleton *GetInstance()
    {
        if (!singletonInstance)
        {
            lock_guard<mutex> lock(mtx);
            if (!singletonInstance)
                singletonInstance = new Singleton();
        }
        return singletonInstance;
    }
    void Set(int x) { this->x = x; }
    void Print() { cout << "x=" << x << endl; }
    ~Singleton() { delete singletonInstance; }
};
Singleton *Singleton::singletonInstance = nullptr;
mutex Singleton::mtx;

int main()
{

    // Factory Design pattern
    BbqDippedChickenBurgerWithMustardSauce *A = new BbqDippedChickenBurgerWithMustardSauce();
    MustardDippedPanerBurgerWithBbqSauce *B = new MustardDippedPanerBurgerWithBbqSauce();
    clientCode(A);
    clientCode(B);

    delete A;
    delete B;

    // Builder Design Pattern
    Director D;
    PropellerPlane P;
    JetPlane J;

    Plane *propellerPlane = D.Build(P);
    Plane *jetPlane = D.Build(J);
    propellerPlane->Print();
    jetPlane->Print();

    // Singleton
    Singleton *S1 = Singleton::GetInstance();
    S1->Set(4);
    S1->Print();
    Singleton *S2 = Singleton::GetInstance();
    S2->Print(); // Print 4

    S2->Set(7);
    S1->Print(); // Print 7
    S2->Print(); // Print 7
}