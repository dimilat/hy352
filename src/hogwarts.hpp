
#include "data.hpp"
#pragma once

#define CREATE
#define WIZARD
#define SPELL

int main() {
    // all the spells that exist
    std::vector<Spell> Spells;

    Wizard harry("Harry Potter", House::Gryffindor, 100);  // new goes on the heap and makes pointer
    Wizard draco("Draco Malfoy", House::Slytherin, 90);    // this way goes to the stack

    Spell boom("Avada Kedavra", ([](Wizard attacker, Wizard defender) { std::cout << "from: " << attacker << std::endl
                                                                                  << "to: " << defender << std::endl; }));

    Spell afoplisious("Expeliarmus", ([](Wizard attacker, Wizard defender) { defender.removeWand();
                                                                             std::cout << "from: " << attacker << std::endl
                                                                                       << "to: " << defender << std::endl; }));
    /*
    std::vector<string> msg{harry.toString(), "from", "VS Code!"};

    for (const string& word : msg) {
        std::cout << word << " ";
    }*/
    std::cout << "======== Wizards =========\n"
              << harry << std::endl
              << draco << std::endl
              << "==========================\n";

    std::cout << boom << "\n";
    boom.make_action(draco, harry);
    std::cout << afoplisious << "\n";
    afoplisious.make_action(harry, draco);
}