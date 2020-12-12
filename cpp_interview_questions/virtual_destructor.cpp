
#include <iostream>

using namespace std;

class Base {
    virtual void method() {
      cout << "Base" << endl;
    }
  public:
    virtual ~Base() {
      method();
    }
};

class Derived : public Base {
    void method() {
      cout << "Derived"<< endl;
    }
  public:
    ~ Derived() {
      method();
    }
};

int main(void) {
  Base *base = new Derived;
  delete base;
  return 0;
}


/*---output---

Derived
Base

*/
