#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <vector>

using std::string;

enum House {
    Gryffindor,
    Hufflepuff,
    Ravenclaw,
    Slytherin
};

class Wizard {
   private:
    /* data */
    string name;
    House house;
    int hp;

   public:
    // target constructor to make a wizard
    Wizard(string name, House house, int hp) : name(name), house(house), hp(hp){};
    // delegating contsructor for wizard withought a name
    Wizard(House house, int hp) : Wizard("", house, hp){};
    Wizard(){};
    ~Wizard(){};

    virtual House getWizardHouse();
    virtual int getWizardHp();
    virtual string getWizardName();
};

string Wizard::getWizardName() {
    return this->name;
}
House Wizard::getWizardHouse() {
    return this->house;
}
int Wizard::getWizardHp() {
    return this->hp;
}

class Spell {
   private:
    /* data */
    string name;

   public:
    Spell(string name) : name(name){};
    Spell(){};
    ~Spell(){};
    /*  Function that will be implemented dynamically during the CREATE SPELL???*/
    void action();
};
