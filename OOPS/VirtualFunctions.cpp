/* Virtual functions in C++ 

Base class pointer -> Derived class object.

When a base class pointer points to a derived class object, and the derived class has over-ridden a base class method,
then in order to call this over-ridden function, we use the virtual keyword in the base class.

This helps in achieving run time polymorphism. --> Late Binding (runtime binding)

NOTE: It is not mandatory for the derived class to override the base class function, in case it is not overridden, the base class
function is invoked

A pure virtual function virtual void pure() = 0;  --> A class having this function becomes abstract class, this class can't be instantiated

For a class deriving this method, it must implement this function in order to be non-abstract, if it is not implemented, the derived class
becomes abstract itself.

*/

#include<bits/stdc++.h>
using namespace std;

class Base{
	int x;
	public:
		virtual void display(){        // If this is overriden in the derived class, this will be called if a base pointer points to derived class object
			cout<<"Display base\n";
		}
		
		void hello(){
			cout<<"Hello base\n";
		}
		
		virtual void purelyVirtual() = 0;    // This is a pure virtual function, this method must be implemented by the derived class
};

class Derived : public Base{
	public:
		void display(){
			cout<<"Derived Display\n";
		}
		
		void Hello(){
			cout<<"Hello Derived\n";
		}
		
		void purelyVirtual(){
			cout<<"Impelemented inside derived class\n";
		}
};


int main(){
	Derived d;
	Base *p;
	p = &d;
	
	p->hello();   // This will display Hello base
	p->display(); // This will display Derived display
	
}
