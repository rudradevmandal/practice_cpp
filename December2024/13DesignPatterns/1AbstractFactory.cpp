#include <iostream>

using namespace std;

// Let's create factory design for burgers

// Product 1: Sauces
class AbstractSauce
{
public:
    virtual ~AbstractSauce() {};
    virtual std::string GetSauce() const = 0;
};

class BBQsauce : public AbstractSauce
{
public:
    std::string GetSauce() const override
    {
        return "Added BBQ Sauce.";
    }
};

class MustardSauce : public AbstractSauce
{
public:
    std::string GetSauce() const override
    {
        return "Added Mustard Sauce.";
    }
};

// Product 2: Patty
class AbstractPatty
{
public:
    virtual ~AbstractPatty() {};
    virtual std::string GetPatty() const = 0;
    virtual std::string GetPatty(const AbstractSauce &AbstractSauce) const = 0;
};

class ChickenPatty : public AbstractPatty
{
public:
    std::string GetPatty() const override
    {
        return "Here's your Chicken Patty.";
    }
    std::string GetPatty(const AbstractSauce &AbstractSauce) const override
    {
        return "Here's your Chicken patty dipped." + AbstractSauce.GetSauce();
    }
};

class PaneerPatty : public AbstractPatty
{
public:
    std::string GetPatty() const override
    {
        return "Here's your Paneer Patty.";
    }
    std::string GetPatty(const AbstractSauce &AbstractSauce) const override
    {
        return "Here's your Paneer patty dipped." + AbstractSauce.GetSauce();
    }
};

// Let's create a Burger Factory
class AbstractBurgerFactory
{
public:
    virtual AbstractSauce *CreateSauce() const = 0;
    virtual AbstractSauce *CreateDipSauce() const = 0;
    virtual AbstractPatty *CreatePatty() const = 0;
};

class CreateMustardDippedChickenBBQBurger : public AbstractBurgerFactory
{
    AbstractSauce *CreateSauce() const override
    {
        return new BBQsauce();
    }
    AbstractSauce *CreateDipSauce() const override
    {
        return new MustardSauce();
    }
    AbstractPatty *CreatePatty() const override
    {
        return new ChickenPatty();
    }
};

class CreateBBQDippedPaneerMustardBurger : public AbstractBurgerFactory
{
    AbstractSauce *CreateSauce() const override
    {
        return new MustardSauce();
    }
    AbstractSauce *CreateDipSauce() const override
    {
        return new BBQsauce();
    }
    AbstractPatty *CreatePatty() const override
    {
        return new PaneerPatty();
    }
};

void clientCode(const AbstractBurgerFactory &factory)
{
    const AbstractSauce *createSauce = factory.CreateSauce();
    const AbstractSauce *createDipSauce = factory.CreateDipSauce();
    const AbstractPatty *createPatty = factory.CreatePatty();

    cout << createSauce->GetSauce() << endl;
    cout << createPatty->GetPatty(*createDipSauce) << endl;

    delete createSauce;
    delete createDipSauce;
    delete createPatty;
}

int main()
{
    CreateMustardDippedChickenBBQBurger *mustardChickenBbqBurger = new CreateMustardDippedChickenBBQBurger();
    CreateBBQDippedPaneerMustardBurger *bbqPaneerMustartBurger = new CreateBBQDippedPaneerMustardBurger();

    clientCode(*mustardChickenBbqBurger);
    clientCode(*bbqPaneerMustartBurger);

    delete mustardChickenBbqBurger;
    delete bbqPaneerMustartBurger;
}