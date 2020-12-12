
#include <iostream>

using namespace std;

class Base {
    public:
    virtual void fun1() {
      cout << "Base::fun1" << endl;
      fun2();
    }
    virtual void fun2() {
      cout << "Base::fun2" << endl;
    }
};

class Derived : public Base {
    public:
    void fun2() {
      cout << "Derived::fun2" << endl;
    }
};

int main(void) {
  Base *base = new Derived;
  base->fun1();
  return 0;
}



/*---output---

Base::fun1
Derived::fun2

*/