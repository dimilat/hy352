#include <string>

using std::string;

class Wizard {
   private:
    /* data */
    string name;
    string house;
    int hp;

   public:
    Wizard(/* args */);
    ~Wizard();
};

Wizard::Wizard(/* args */) {
}

Wizard::~Wizard() {
}
