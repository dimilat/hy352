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
    string name;
    House house;
    int hp;
    std::vector<Spell> SpellsKnown;  // vector of spells that the wizard knows
    bool has_wand = true;

   public:
    // target constructor to make a wizard
    Wizard(string name, House house, int hp) : name(name), house(house), hp(hp){};
    // delegating constructor for wizard withought a name
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
    string name;
    typedef void (*Action)(Wizard, Wizard);
    /*  Function that will be implemented dynamically during the CREATE SPELL???*/
    Action action;

   public:
    Spell(string name, Action action) : name(name), action(action){};
    Spell(){};
    ~Spell(){};

    void make_action(Wizard attacker, Wizard defender) {
        return action(attacker, defender);
    }

    virtual string getSpellName();
    virtual string toString();
};

class Round {
   private:
    int player = 1;

   public:
    Round(){};
    ~Round(){};

    void changeRound() {
        if (this->player == 1) {
            this->player = 2;
        } else {
            this->player = 1;
        }
    }
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
string Wizard::toString() {
    return "Name: " + this->getWizardName() + ",House: " + std::to_string(this->getWizardHouse()) + ",Hp: " + std::to_string(this->getWizardHp());
}
std::vector<Spell> Wizard::getWizardSpells() {
    return this->SpellsKnown;
}
string Spell::getSpellName() {
    return this->name;
}
string Spell::toString() {
    return "Spell name: " + this->getSpellName() + "\n";
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

std::ostream& operator<<(std::ostream& os, Spell spell) {
    os << spell.getSpellName();
    return os;
}

std::ostream& operator<<(std::ostream& os, Wizard wizard) {
    os << wizard.getWizardName();
    return os;
}
