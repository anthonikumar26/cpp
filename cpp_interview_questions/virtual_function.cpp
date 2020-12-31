
//Q=1

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

================================================================

//Q=2

#include<iostream> 

using namespace std; 

class Base
{
    public:
        virtual void func()
        {
            cout << "Base::func" << endl;
        }
};
class Derived1: public Base
{
    public:
        void func()
        {
            cout << "Derived1::func" << endl;
        }
};
class Derived2: public Base
{
    public:
        void func()
        {
            cout << "Derived2::func" << endl;
        }
};
int main() 
{ 
    Derived1 d1;
    Derived2 d2;
	
	Base b=d1;
	b.func();
	
	Base &b1=d1;
	b1.func();
	
	Base &b2=d2;
	b2.func();
	
	return 0; 
} 



/*---output---

Base::func
Derived1::func
Derived2::func

*/