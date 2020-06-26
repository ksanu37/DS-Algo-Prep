/* FRIEND CLASS AND FUNCTION 

A friend class can access the private and protected members of the class which it is a friend of. Same goes for the friend functions.
For example:

Imagine a class Node 

class Node{
	int data;
	Node *next;
public:
	Node(int d=0){
		data = d;
		next = NULL;
	}
}

and Another class LinkedList

class LinkedList{
	int numNodes;

	public:
		LinkedList(int num=0){
			numNodes = num;
		}

		int search(Node* head, int data){
			// Now here we need to search a data in a linked list, for this we require the node information, 
			As the data memeber is private, this class can;t access that --> for this, it has to be a friend class or search has to be a friend function.
		}
}


************************** INFO *************************

1. Friendship is not mutual : if A is a friend of B, then B is not a friend of A automatically.
2. Friendships can't be inherited
3. Friend functions can be either global functions or member functions of other classes.

*/

class Node{
	int data;
	Node *next;

	friend class LinkedList;    // Friend Class
	friend int LinkedList::search(int num);  // Friend Function
	friend sayHello();   // Global function as a friend
};

class LinkedList{
	int numNodes;

public:
	int search(int num){

		/* Function Body here */
	}
};


void sayHello{
	cout<<data<<" "; 
}

