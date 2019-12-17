#include <iostream>
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
    ~Wizard();

    string getWizardName() {
        return this->name;
    }
    House getWizardHouse() {
        return this->house;
    }
    int getWizardHp() {
        return this->hp;
    }
};
