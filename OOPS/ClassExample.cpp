/*  

Example of a class Rectangle with length and breadth as data members and area & perimeter as member functions. 

An object can occupy space in both stack and heap. 

Accessors and mutators -> Property functions. Data members are the properties of an object, together these functions can access and mutate the values

*/


#include<bits/stdc++.h>
using namespace std;

class Rectangle{          // size of this class = 0, size of an object of this class = 4,  Functions don't take up any space

	private:             /* Access Modifier, by default everything comes under private */
	int length;
	int breadth;
	
	public:
		// Mutators -> The functions which can change the value of the data members
    void setLength(int l){
    	if(l>=0)
    		length = l;
    	else{
    		cout<<"Length can't be nagative\n";
    		length = 0;
		}
	}
	
    void setBreadth(int b){
    	if(b>=0)
    		breadth = b;
    	else{
    		cout<<"Breadth can't be nagative\n";
    		breadth = 0;
		}
	}
	
	// Accessors -> Functions which are used to access the data members
	int getLength(){
		return length;
	}	
	
	int getBreadth(){
		return breadth;
	}
	
	int area(){
		return length*breadth;
	}
	
	int perimeter(){
		return 2*(length+breadth);
	}
};


int main(){
	Rectangle r1, r2;         // An object of class Rectangle, object created in stack
	// r1.length = 10;
	// r1.breadth = 5;
	
	r1.setLength(10);
	r1.setBreadth(5);
	cout<<r1.area()<<"\n";
	
	Rectangle *p = new Rectangle();  // Object created in heap
}
