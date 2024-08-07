//Q=1

#include <iostream>

using namespace std;
class A{
    public:
    A(){
        cout << "A constructor" << endl;
    } 
    ~A(){
      cout << "A destructor" << endl;
    }
    void print(){
        cout << "A print" << endl;
    }
};

class B{
    
    public:
        A *a;
        B(){
            a = new A();
            cout << "B constructor" << endl;
        } 
        ~B(){
             delete a;
             cout << "B destructor" << endl;
        }
        void display()
        {
			a->print();
			cout << "B display" << endl;
		}
};

int main() {
    B *b = new B();
    b->display();    
    delete b;
    return 0;
}


/*---output---

A constructor
B constructor
A print
B display
A destructor
B destructor

*/