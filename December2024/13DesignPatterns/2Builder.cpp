#include <iostream>
using namespace std;

// What I want to build? - A Plane
class Plane
{
    string planeType;
    string bodyType;
    string engineType;

public:
    Plane(string p) : planeType(p) {};
    void setEngine(string e) { engineType = e; }
    void setBody(string b) { bodyType = b; }

    void show()
    {
        cout << "Plane Type: " << planeType << endl
             << "Body Type: " << bodyType << endl
             << "Engine Type: " << engineType << endl
             << endl;
    }
};

// What all directors need to build a plane?
class PlaneBuilder
{
protected:
    Plane *plane;

public:
    virtual void getPartsDone() = 0;
    virtual void buildBody() = 0;
    virtual void buildEngine() = 0;
    Plane *getPlane() { return plane; }
};

// Want to build propeller plane - Use me
class PropellerPlaneBuilder : public PlaneBuilder
{
public:
    void getPartsDone() override { plane = new Plane("Propeller Plane"); }
    void buildBody() override { plane->setBody("Propeller Body"); }
    void buildEngine() override { plane->setEngine("Propeller Engine"); }
};

// Want to build Jet plane - Use me
class JetPlaneBuilder : public PlaneBuilder
{
public:
    void getPartsDone() override { plane = new Plane("Jet Plane"); }
    void buildBody() override { plane->setBody("Jet Body"); }
    void buildEngine() override { plane->setEngine("Jet Engine"); }
};

// Director to call steps in a particular order
class Director
{
public:
    Plane *createPlane(PlaneBuilder &builder)
    {
        builder.getPartsDone();
        builder.buildBody();
        builder.buildEngine();
        return builder.getPlane();
    }
};

int main()
{
    Director D;
    PropellerPlaneBuilder P;
    JetPlaneBuilder J;

    Plane *jet = D.createPlane(J);
    Plane *propeller = D.createPlane(P);
    jet->show();
    propeller->show();
}