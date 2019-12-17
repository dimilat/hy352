#include "data.h"
#pragma once

using namespace std;

int main() {

    Wizard* harry = new Wizard("Harry Potter", House::Gryffindor, 100);
    
    vector<string> msg{harry->getWizardName(), std::to_string(harry->getWizardHouse()), std::to_string(harry->getWizardHp()), "from", "VS Code!"};
    // this is a comment
    for (const string& word : msg) {
        cout << word << " ";
    }
    cout << endl;
}