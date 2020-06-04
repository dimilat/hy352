/*
*   hy352, 2019-2020
*   George Kostomanolakis,  csd3787
*   Dimitris Milathianakis, csd3657
*/

#include <stdarg.h>

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using std::string;
class Wizard;
class Spell;
class Round;
class forActionsClass;
typedef void (*Action)();
std::vector<Action *> actions;
namespace Vectors {
std::vector<Wizard *> AllWizards;
std::vector<Spell *> Spells;
std::vector<Wizard *> Players;
}  // namespace Vectors

struct Types {
    Spell *spell_tmp;
    Wizard *wizard_tmp;
};
class Round {
   private:
    int attacker = 0;
    int defender = 1;
    int current_round = 1;

   public:
    Round(){};
    ~Round(){};
    int getAttackerIndex() {
        return this->attacker;
    }
    int getDefenderIndex() {
        return this->defender;
    }
    int getCurrentRound() {
        return this->current_round;
    }
    void swapAttackerDefender() {
        if (this->attacker == 0) {
            this->attacker = 1;
            this->defender = 0;
        } else {
            this->attacker = 0;
            this->defender = 1;
        }
    }
    void incRound() {
        this->current_round++;
    }
};

Round *new_game = new Round();
class Wizard {
   private:
    string name;
    string house;
    int hp;
    int max_hp;
    bool has_wand = true;
    /* Vector apo vectors stous wizard. Otan alazei o guros 8a 8eloume 
    na ginetai se ka8e upo-vector pop kai call i ka8e sunartisi (update)*/

    std::vector<Spell *> SpellsKnown;  // vector of spells that the wizard knows
   public:
    std::vector<forActionsClass *> myactions;
    // target constructor to make a wizard
    Wizard(string name, string house, int hp) : name(name),
                                                house(house),
                                                hp(hp) {
        this->max_hp = hp;
        Vectors::AllWizards.push_back(this);
    };
    // delegating constructor for wizard withought a name
    Wizard(string house, int hp) : Wizard("", house, hp){};
    Wizard(const Wizard &wizard_tocopy) {
        this->name = wizard_tocopy.name;
        this->house = wizard_tocopy.house;
        this->hp = wizard_tocopy.hp;
        this->max_hp = wizard_tocopy.hp;
    };
    Wizard(){};
    ~Wizard(){};

    void LearnSpell(Spell *spell_object) {
        SpellsKnown.push_back(spell_object);
    }
    bool isAlive() {
        if (this->hp > 0) {
            return true;
        }
        return false;
    }
    virtual string getWizardHouse();
    virtual int getWizardHp();
    virtual int getWizardMaxHp();
    virtual void setWizardHp(int life);
    virtual string getWizardName();
    virtual bool getWizardWand();
    virtual string toString();
    virtual void setWand(bool has_wand);
    virtual void updateRoundEffects();
    virtual std::vector<Spell *> getSpells();
    Wizard *operator,(Wizard *pre_wiz);
};
class Damage {
    Wizard *wizard;
    int damage_val;

   public:
    Damage() {}

    Damage(Wizard *wizard) {
        this->wizard = wizard;
        std::cout << wizard->getWizardName() << std::endl;
    }

    ~Damage() {}

    int operator,(int dmg) {
        Damage_func(wizard, dmg);
        return 1;
    }
    void Damage_func(Wizard *wizard, float damage) {
        Wizard *attacker = Vectors::Players.at(new_game->getAttackerIndex());
        if (attacker->getWizardHouse() == "Slytherin") {
            if (wizard->getWizardHouse() == "Gryffindor") {
                damage = damage + 0.2 * damage;
            } else {
                damage = damage + 0.15 * damage;
            }
        } else if (attacker->getWizardHouse() == "Hufflepuff") {
            damage = damage + 0.07 * damage;
        } else if (attacker->getWizardHouse() == "Ravenclaw") {
            if (new_game->getCurrentRound() % 2 != 0) {
                damage = damage + 0.07 * damage;
            }
        }
        if (wizard->getWizardHouse() == "Gryffindor") {
            if (attacker->getWizardHouse() == "Slytherin") {
                damage = damage - 0.3 * damage;
            } else {
                damage = damage - 0.2 * damage;
            }
        } else if (wizard->getWizardHouse() == "Hufflepuff") {
            damage = damage - 0.07 * damage;
        }

        if (wizard->getWizardHp() - damage <= 0) {
            wizard->setWizardHp(0);
        } else {
            wizard->setWizardHp(wizard->getWizardHp() - damage);
        }
    }
};

class Heal {
    Wizard *wizard;
    int heal_val;

   public:
    Heal() {}

    Heal(Wizard *wizard) {
        this->wizard = wizard;
        std::cout << wizard->getWizardName() << std::endl;
    }

    ~Heal() {}

    int operator,(int heal_life) {
        Heal_func(wizard, heal_life);
        return 1;
    }

    void Heal_func(Wizard *wizard, int heal_life) {
        /*if (wizard->getWizardHouse() == "Ravenclaw") {
            if (new_game->getCurrentRound() % 2 == 0) {
                heal_life = heal_life + 5 / 100 * heal_life;
            }
        }*/
        if (wizard->getWizardHp() + heal_life >= wizard->getWizardMaxHp()) {
            wizard->setWizardHp(wizard->getWizardMaxHp());
        } else {
            wizard->setWizardHp(wizard->getWizardHp() + heal_life);
        }
    }
};

class Wand {
    int wand_value;

   public:
    Wand() {
    }
    Wand(int val) : wand_value(val) {
    }
    ~Wand() {
    }

    Wand *operator--() {
        return this;
    }

    Wand operator-() const {
        Wand o(1);
        return o;
    }

    int getWandValue() {
        return wand_value;
    }
};
class Equip {
    Wizard *wizard;

   public:
    Equip() {}
    Equip(Wizard *wizard) {
        this->wizard = wizard;
    }
    ~Equip() {}

    Wand *operator,(Wand *ravdi) {  // ---o
        if (ravdi->getWandValue() == 1) {
            wizard->setWand(true);
        } else {
            wizard->setWand(false);
        }
        return ravdi;
    }

    Wand operator,(Wand ravdi) {  //  _
        if (ravdi.getWandValue() == 1) {
            wizard->setWand(true);
        } else {
            wizard->setWand(false);
        }
        return ravdi;
    }
};
class Wizards {
   private:
    Wizard *arr[1];

   public:
    Wizards() { arr[0] = new Wizard; }
    ~Wizards() {}
    Wizard *operator[](Wizard *index) {
        return arr[0];
    }
};

class Spell {
   private:
    string name;
    Action action;

   public:
    Spell(string name, Action action) : name(name), action(action) {
        Vectors::Spells.push_back(this);
    };
    Spell(string name) {
        this->name = "--SPELL_WITH_NO_NAME--";
        Vectors::Spells.push_back(this);
    };
    Spell(){};
    ~Spell(){};

    void make_action() {
        return action();
    }
    virtual string getSpellName();
    virtual string toString();
    Spell *operator,(Spell *pre_spell);
};

class forActionsClass {
   public:
    std::vector<Action *> actions;
    Action action;
    Action empty_action = []() {};
    forActionsClass() {}
    ~forActionsClass() {}
};

class Spells {
   private:
    Spell *arr[1];

   public:
    Spells() { arr[0] = new Spell; }
    ~Spells() {}
    Spell *operator[](Spell *index) {
        return arr[0];
    }
};

string Wizard::getWizardName() {
    return this->name;
}
string Wizard::getWizardHouse() {
    return this->house;
}
int Wizard::getWizardHp() {
    return this->hp;
}
int Wizard::getWizardMaxHp() {
    return this->max_hp;
}

void Wizard::setWizardHp(int life) {
    this->hp = life;
}

bool Wizard::getWizardWand() {
    return this->has_wand;
}
void Wizard::setWand(bool has_wand) {
    this->has_wand = has_wand;
}

string Wizard::toString() {
    return "Name: " + this->getWizardName() + ",House: " + this->getWizardHouse() + ",Hp: " + std::to_string(this->getWizardHp());
}

string Spell::getSpellName() {
    return this->name;
}

string Spell::toString() {
    return "Spell name: " + this->getSpellName() + "\n";
}

std::vector<Spell *> Wizard::getSpells() {
    return this->SpellsKnown;
}

std::ostream &operator<<(std::ostream &os, Spell *spell) {
    os << spell->getSpellName();
    return os;
}

std::ostream &operator<<(std::ostream &os, Wizard *wizard) {
    os << wizard->getWizardName();
    return os;
}

Wizard *Wizard::operator,(Wizard *pre_wiz) {
    return pre_wiz;
}

Wizard *returnWizard(Wizard *wiz, int dummy) {  //returns Wizard without comma from ATTACKER/DEFENDER define
    return wiz;
}

void Wizard::updateRoundEffects() {
    if (this->getWizardHouse() == "Ravenclaw") {
        if (new_game->getCurrentRound() % 2 == 0) {
            if (this->getWizardHp() + 0.05 * this->getWizardMaxHp() >= this->getWizardMaxHp()) {
                this->setWizardHp(this->getWizardMaxHp());
            } else {
                this->setWizardHp(this->getWizardHp() + 0.05 * this->getWizardMaxHp());
            }
        }
    }
    for (unsigned i = 0; i < this->myactions.size(); i++) {
        if (!(myactions[i]->actions.empty())) {
            (*(myactions[i]->actions.front()))();
            myactions[i]->actions.erase(myactions[i]->actions.begin() + 0);
        }
    }
}
Spell *Spell::operator,(Spell *spell) {
    return spell;
}
int and_function(int numargs, ...) {
    va_list ap;
    int check = 1;

    va_start(ap, numargs);
    while (numargs--)
        check = check && va_arg(ap, int);
    va_end(ap);

    return check;
}

int or_function(int numargs, ...) {
    va_list ap;
    int check = 1;
    va_start(ap, numargs);
    while (numargs--)
        check = check || va_arg(ap, int);
    va_end(ap);

    return check;
}

int not_function(int x) {
    return !x;
}

Wizard *find_wizard(string name) {
    for (unsigned int i = 0; i < Vectors::AllWizards.size(); i++) {
        if (Vectors::AllWizards[i]->getWizardName() == name) {
            Wizard *temp_wiz = Vectors::AllWizards[i];
            return temp_wiz;
        }
    }
    if (name[0] != '\0') {
        std::cout << "Wizard with name: " << name << " does not exist.\n\n"
                  << std::endl;
    }

    return nullptr;
}

Spell *find_wizard_spell(Wizard *wizard, string name) {
    for (unsigned int i = 0; i < wizard->getSpells().size(); i++) {
        if (wizard->getSpells().at(i)->getSpellName() == name) {
            return wizard->getSpells().at(i);
        }
    }
    if (name[0] != '\0') {
        std::cout << "Spell with name: " << name << " does not exist.\n\n"
                  << std::endl;
    }

    return nullptr;
}

int learn_spell(string name, Wizard *wiz) {
    if (wiz == nullptr) {
        return 0;
    }
    for (unsigned int i = 0; i < Vectors::Spells.size(); i++) {
        if (Vectors::Spells[i]->getSpellName() == name) {
            wiz->LearnSpell(Vectors::Spells[i]);
            std::cout << Vectors::Spells[i]->getSpellName() << std::endl;
            return 0;
        }
    }
    //print error den vrika spell me to onoma poy dineis
    return 0;
}

void printAvailableWizards() {
    for (unsigned int i = 0; i < Vectors::AllWizards.size(); i++) {
        std::cout << Vectors::AllWizards[i]->getWizardName() << std::endl;
    }
}

void initialize_Players_Wizards() {
    char wizard_name[40];

    //perimenei input onoma kapoiou wizard apo player 1

    std::cout << "\nPlayer1 select wizard:" << std::endl;
    std::cout << "-----------------------" << std::endl;
    printAvailableWizards();
    std::cout << "-----------------------" << std::endl;
    std::cin.getline(wizard_name, sizeof(wizard_name));

    while (find_wizard(wizard_name) == nullptr) {
        std::cout << "\nPlayer1 select wizard:" << std::endl;
        std::cout << "-----------------------" << std::endl;
        printAvailableWizards();
        std::cout << "-----------------------" << std::endl;
        std::cin.getline(wizard_name, sizeof(wizard_name));
    }

    Vectors::Players.push_back(find_wizard(wizard_name));

    std::cout << "\nPlayer2 select wizard:" << std::endl;
    std::cout << "-----------------------" << std::endl;
    printAvailableWizards();
    std::cout << "-----------------------" << std::endl;
    std::cin.getline(wizard_name, sizeof(wizard_name));

    while (find_wizard(wizard_name) == nullptr) {
        std::cout << "\nPlayer2 select wizard:" << std::endl;
        std::cout << "-----------------------" << std::endl;
        printAvailableWizards();
        std::cout << "-----------------------" << std::endl;
        std::cin.getline(wizard_name, sizeof(wizard_name));
        //  std::fgets(wizard_name, 40, stdin);
    }

    Vectors::Players.push_back(find_wizard(wizard_name));
    wizard_name[0] = '\0';
}

void StartNewRound() {
    std::cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "Round: " << new_game->getCurrentRound() << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
              << std::endl;
}

Spell *player_select_Spell(Wizard *player) {
    char spell_name[40];
    std::cout << "-----------------------" << std::endl;
    for (unsigned int i = 0; i < player->getSpells().size(); i++) {
        std::cout << player->getSpells().at(i)->getSpellName() << std::endl;
    }
    std::cout << "-----------------------" << std::endl;

    std::cin.getline(spell_name, sizeof(spell_name));

    while (find_wizard_spell(player, spell_name) == nullptr) {
        std::cin.getline(spell_name, sizeof(spell_name));
    }

    return find_wizard_spell(player, spell_name);
}

void printWizardStats(Wizard *Player) {
    // --- Printing player 1
    std::cout << "#######################" << std::endl;
    std::cout << "Name: " << Player->getWizardName() << std::endl;
    std::cout << "HP: " << Player->getWizardHp() << std::endl;
    if (Player->getWizardWand()) {
        std::cout << "Wand equipped " << std::endl;
    } else {
        std::cout << "Wand not equipped " << std::endl;
    }
    std::cout << "#######################" << std::endl
              << std::endl;
}

void duel() {
    std::cout << "------------------------------ HAPPY POTTER THE GAME ------------------------------" << std::endl;

    initialize_Players_Wizards();

    Wizard *Player1 = Vectors::Players.at(0);
    Wizard *Player2 = Vectors::Players.at(1);
    Spell *spell;

    while (Player1->isAlive() && Player2->isAlive()) {
        StartNewRound();
        if (Player1->getWizardWand()) {
            std::cout << Player1->getWizardName() << "(Player1) select spell:" << std::endl;
            spell = player_select_Spell(Player1);
            spell->make_action();
            printWizardStats(Player1);
            printWizardStats(Player2);
        } else {
            std::cout << Player1->getWizardName() << "(Player1) has not a wand so he can't cast a spell." << std::endl;
        }

        Player1->updateRoundEffects();
        new_game->swapAttackerDefender();

        if (!Player2->isAlive()) {
            break;
        }

        if (Player2->getWizardWand()) {
            std::cout << Player2->getWizardName() << "(Player2) select spell:" << std::endl;
            spell = player_select_Spell(Player2);
            spell->make_action();
            printWizardStats(Player1);
            printWizardStats(Player2);

        } else {
            std::cout << Player2->getWizardName() << "(Player2) has not a wand so he can't cast a spell." << std::endl;
        }

        Player2->updateRoundEffects();
        new_game->swapAttackerDefender();
        new_game->incRound();
    }
    std::cout << "\n\n-------------------------------- THE DUEL IS OVER --------------------------------" << std::endl;
    if (Player1->isAlive()) {
        std::cout << "\n=== RIP -> (Player2)" << Player2->getWizardName() << "\n"
                  << Player1->getWizardName() << "(Player1) Wins!!!" << std::endl;
    } else if (Player2->isAlive()) {
        std::cout << "\n=== RIP -> (Player1)" << Player1->getWizardName() << "\n"
                  << Player2->getWizardName() << "(Player2) Wins!!!" << std::endl;
    }
}