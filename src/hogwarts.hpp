
#include "data.hpp"
#pragma once

#define CREATE
#define WIZARD
#define SPELL

/* function that prints elements in a list*/
int main() {
    std::vector<Spell> Spells;

    Wizard harry("Harry Potter", House::Gryffindor, 100);  // new goes on the heap and makes pointer
    Wizard draco("Draco Malfoy", House::Slytherin, 90);    // this way goes to the stack

    Spell boom("Avada Kedavra", ([](Wizard attacker, Wizard defender) { std::cout << "from: " << attacker.toString()
                                                                                  << "\nto:" << defender.toString() << std::endl; }));
    /*
    std::vector<string> msg{harry.toString(), "from", "VS Code!"};

    for (const string& word : msg) {
        std::cout << word << " ";
    }*/
    std::cout << "\n"
              << boom << "\n";
    boom.make_action(draco, harry);
}