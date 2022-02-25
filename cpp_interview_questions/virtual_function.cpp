
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

#include <iostream>

using namespace std;

class Base {
    public:
    virtual void fun1() {
		cout << "Base::fun1" << endl;
    }
    virtual void fun2() {
		cout << "Base::fun2" << endl;
    }
};

class Derived1 : public Base {
    public:
    void fun2() {
		cout << "Derived1::fun2" << endl;
    }
};

class Derived2 : public Base {
    public:
        void fun1() {
			cout << "Derived2::fun1" << endl;
        }
        void fun2() {
			cout << "Derived2::fun2" << endl;
        }
        void fun3() {
			cout << "Derived2::fun3" << endl;
        }
};

int main(void) {
    Base *base = new Derived1;
    base->fun1();
    
    base = new Derived2;
    base->fun2();
    
    return 0;
}


/*---output---

Base::fun1
Derived2::fun2

*/


================================================================

//Q=3

#include <iostream>

using namespace std;

class Base {
    public:
    virtual void fun1() {
		cout << "Base::fun1" << endl;
    }
    virtual void fun2() {
		cout << "Base::fun2" << endl;
    }
};

class Derived1 : public Base {
    public:
    void fun2() {
		cout << "Derived1::fun2" << endl;
    }
};

class Derived2 : public Base {
    public:
        void fun1() {
			cout << "Derived2::fun1" << endl;
        }
        void fun2() {
          cout << "Derived2::fun2" << endl;
        }
        void fun3() {
			cout << "Derived2::fun3" << endl;
        }
};

int main(void) {
    Base *base = new Derived2;
    base->fun3();
    
    return 0;
}


/*---output---

error: 'class Base' has no member named 'fun3'; did you mean 'fun1'?
      |     base->fun3();
      |           ^~~~
      |           fun1

*/


================================================================

//Q=4

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


==========================================

//Q=5


#include <iostream>

using namespace std;

enum vehEnum {
    car=1,
    bike,
    bus
};
class Vehicle
{
    protected:
    int length;
    public:
    Vehicle(){
        length=0;
        cout << "Vehicle constructor" << endl;
    }
    virtual ~Vehicle(){
        cout << "Vehicle destructor" << endl;
    }
    virtual void displayLength(){
        cout << "length=" << length << endl;
    }
};
class CarVehicle: public Vehicle
{
    
    public:
    CarVehicle(){
        length=50;
        cout << "Car constructor" << endl;
    }
    ~CarVehicle(){
        cout << "Car destructor" << endl;
    }
    virtual void displayLength(){
        cout << "length=" << length << endl;
    }
};
class BikeVehicle: public Vehicle
{
    
    public:
    BikeVehicle(){
        length=25;
        cout << "Bike constructor" << endl;
    }
    ~BikeVehicle(){
        cout << "Bike destructor" << endl;
    }
    void displayLength(){
        cout << "length=" << length << endl;
    }
};
class BusVehicle: public Vehicle
{
    
    public:
    BusVehicle(){
        length=100;
        cout << "Bus constructor" << endl;
    }
    ~BusVehicle(){
        cout << "Bus destructor" << endl;
    }
    void displayLength(){
        cout << "length=" << length << endl;
    }
};
Vehicle*  getVehicleObject(vehEnum vt)
{
    switch(vt)
    {
        case car:
        {
            return new CarVehicle();
        }
        break;
        case bike:
        {
            return new BikeVehicle();
        }
        break;
        case bus:
        {
            return new BusVehicle();
        }
        break;
        default:
        {
            return new Vehicle();
        }
    }
}
int main() {
    int vt;
    cout << "1:car"<<endl;
    cout << "2:bike"<<endl;
    cout << "3:bus"<<endl;
    cout << "enter vehicle number which you want to get length:";
    cin >> vt;
    Vehicle *v = getVehicleObject((vehEnum)vt);
    v->displayLength();
    delete v;
    return 0;
}


/*---output---

1:car
2:bike
3:bus
enter vehicle number which you want to get length:3
Vehicle constructor
Bus constructor
length=100
Bus destructor
Vehicle destructor

*/