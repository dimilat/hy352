
#include "data.hpp"
#pragma once

#define CREATE
#define WIZARD
#define SPELL

/* function that prints elements in a list*/
int main() {
    std::vector<Spell> Spells;

    Wizard harry("Harry Potter", House::Gryffindor, 100);  // new goes on the heap and makes pointer
    Spell boom("Avada Kedavra");                           // this way goes to the stack

    std::vector<string> msg{harry.toString(), "from", "VS Code!"};
    
    for (const string& word : msg) {
        std::cout << word << " ";
    }
    std::cout << "\n"
              << boom << "\n";
}