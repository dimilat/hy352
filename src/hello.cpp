#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> msg{"Hello", "C++", "World", "from", "VS Code!"};
    // this is a comment
    for (const string& word : msg) {
        cout << word << " ";
    }
    cout << endl;
}
