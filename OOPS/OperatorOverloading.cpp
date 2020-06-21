/* Operator overloading in C++

An operator can be overloaded (Designed to work in a desired way) --> Only possible when one of the arguments is a class object

It is done by simply declaring a method in the class whose name contains the keyword operator and the actual operator.

Example:  void operator+(int x)


Some Facts about operator overloading:

Some operators can't be overloaded --> For example the dot(.), sizeOf operators

*/

#include<bits/stdc++.h>
using namespace std;

class Complex{
	int real;
	int imaginary;

public:
	Complex(int r=0, int l=0){
		real = r;
		imaginary = l;
	}

	Complex operator+(Complex c){
		Complex temp;
		temp.real = real+c.real;
		temp.imaginary = imaginary + c.imaginary;
		return temp;
	}

	void ShowParams(){
		cout<<"Real part = "<<real<<" ";
		cout<<"imaginary part = "<<imaginary<<" \n";
	}
}



int main(){
		Complex c1 = new Complex(4,5);
		Complex c2 = new Complex(5,7);
		Complex c3;
		c3 = c1 + c2;   // This looks for a function with name operator+  --> c1 will call its function.

		c3.ShowParams();
}