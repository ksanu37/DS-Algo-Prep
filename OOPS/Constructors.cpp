/*
=========================================== CONSTRUCTOR =====================================================

A constructor is a special member function which is called everytime an object of that class is instantiated. 

The constructor has no return type and the name of the constructor is exactly same as the className. 

--> Everytime an object is 'constructed' the constructor is called. If the user doesn't define a constructor, the compiler
itself provides a constructor for the class. This is called 'DEFAULT CONSTRUCTOR'. This has no parameters and an empty body.

There can be 3 types of constructor:

1. Default constructor: Takes no arguments. 

2. Parameterized constructor: Takes parameters to initialise the data members of an object.

3. Copy constructor: Used to create an object same as another object. Extra care needs to be taken in such cases when an object is doing some dynamic 
memory allocation.

*/

#include<bits/stdc++.h>
using namespace std;

class Rectangle{          

	private:             
	int length;
	int breadth;
	int *p;
	
	public:
		
		Rectangle(){    // Default constructor
			length = 0;
			breadth = 0;
			//p = new int[l];
		}
		
		Rectangle(int l, int b){ // Parametrized constructor
			setLength(l);
			setBreadth(b);
			p = new int[l];
		}
		
		Rectangle(Rectangle &r){  // Copy constructor
			setLength(r.length);
			setBreadth(r.breadth);
			
			// p = r.p --> since p is a pointer, it will start pointing to r's p array which is not the wanted behaviour. Hence this should be taken care of (Deep copy)
			p = new int[length];
			
			/* If need arises, the content of r's p should be copied as well 
			
			for(int i=0; i<l; i++){
				p[i] = r.p[i];
			}
			
			*/
		}
		
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
	Rectangle r1;         
	
	r1.setLength(10);
	r1.setBreadth(5);
	
	Rectangle r2(r1);
	
	cout<<r2.getLength()<<"\n";
	cout<<r1.area()<<"\n";
	
	Rectangle *p = new Rectangle(); 
}
