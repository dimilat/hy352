
#include "data.hpp"
#pragma once

#define CREATE
#define WIZARD
#define SPELL

/* function that prints elements in a list*/
int main() {
    std::vector<Spell> Spells;

    Wizard* harry = new Wizard("Harry Potter", House::Gryffindor, 100);
    Spell* boom = new Spell("Avada Kedavra");

    std::vector<string> msg{harry->toString(), "from", "VS Code!"};
    // this is a comment
    for (const string& word : msg) {
        std::cout << word << " ";
    }
    std::cout << "\n"
              << boom << "\n";
}