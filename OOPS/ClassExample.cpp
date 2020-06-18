/*  

Example of a class Rectangle with length and breadth as data members and area & perimeter as member functions. 

An object can occupy space in both stack and heap. 

*/


#include<bits/stdc++.h>
using namespace std;

class Rectangle{                             // size of this class = 0, size of an object of this class = 4,  Functions don't take up any space

	public:             /* Access Modifier, by default everything comes under private */
	int length;
	int breadth;
	
	int area(){
		return length*breadth;
	}
	
	int perimeter(){
		return 2*(length+breadth);
	}
};


int main(){
	Rectangle r1, r2;         // An object of class Rectangle, object created in stack
	r1.length = 10;
	r1.breadth = 5;
	cout<<r1.area()<<"\n";
	
	Rectangle *p = new Rectangle();  // Object created in heap
	
	p->length = 10;
}
