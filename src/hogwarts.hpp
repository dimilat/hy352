#include "data.hpp"
#pragma once

using namespace std;
#define CREATE
#define WIZARD
#define SPELL

/* function that prints elements in a list*/
void showlist(list<int> g) {
    list<int>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}

int main() {
    list<Spell> Spells;

    Wizard* harry = new Wizard("Harry Potter", House::Gryffindor, 100);

    vector<string> msg{harry->getWizardName(), std::to_string(harry->getWizardHouse()), std::to_string(harry->getWizardHp()), "from", "VS Code!"};
    // this is a comment
    for (const string& word : msg) {
        cout << word << " ";
    }
    cout << endl;
}