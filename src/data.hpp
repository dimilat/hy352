#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using std::string;
class Wizard;
class Spell;

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
    std::vector<Spell> SpellsKnown;  // vector of spells that the wizard knows

   public:
    // target constructor to make a wizard
    Wizard(string name, House house, int hp) : name(name), house(house), hp(hp){};
    // delegating contsructor for wizard withought a name
    Wizard(House house, int hp) : Wizard("", house, hp){};
    Wizard(){};
    ~Wizard(){};
    //-function to learn a spell, will fill
    void LearnSpell(Spell spell_object);
    // getters for wizard data
    virtual House getWizardHouse();
    virtual int getWizardHp();
    virtual string getWizardName();
    virtual std::vector<Spell> getWizardSpells();
    virtual string toString();
};

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
    string getSpellName();
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
std::vector<Spell> Wizard::getWizardSpells() {
    return this->SpellsKnown;
}
string Spell::getSpellName() {
    return this->name;
}
string Wizard::toString() {
    return "Name: " + this->getWizardName() + ",House: " + std::to_string(this->getWizardHouse()) + ",Hp: " + std::to_string(this->getWizardHp());
}

// Returns a string representation of a House
string toStringOfHouse(House house) {
    string ret_val = "";
    if (house == 0) {
        ret_val = "Gryffindor";
    } else if (house == 1) {
        ret_val = "Hufflepuff";
    } else if (house == 2) {
        ret_val = "Ravenclaw";
    } else if (house == 3) {
        ret_val = "Slytherin";
    }
    if (ret_val == "") {
        ret_val = "not found";
        return ret_val;
    } else {
        return ret_val;
    }
}

std::ostream& operator<<(std::ostream& os, Spell* spell) {
    os << spell->getSpellName();
    return os;
}
