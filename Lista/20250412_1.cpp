#include <iostream>
#include <string>
using namespace std;

struct Node {
	int value;
	Node* next;

	Node(int _value){
		value = _value;
		next = NULL;
	}
};

struct List {
	Node* start;
	Node* end;
	int cont;
	
	List(){
		start = NULL;
		end = NULL;
		cont = 0;
	}

	bool isEmpty(){
		return start == NULL && end == NULL;
	}

	void pushBack(int value){
		Node* n = new Node(value);
		cont++;
		if(isEmpty()){
			start = n;
			end = n;
			return;
		}
		end->next = n;
		end = n;
	}

	void pushFront(int value){
		Node* n = new Node(value);
		cont++;
		if(isEmpty()){
			start = n;
			end = n;
			return;
		}
		n->next = start;
		start = n;
	}

	void print(){
		Node* aux = start;
		while(aux != NULL){
			cout << aux->value;
			if(aux != end) cout << " -> ";
			aux = aux->next;
		}
		cout << endl;
	}
};

int main() {
	List l1;
	l1.pushBack(4);
	l1.pushBack(6);
	l1.pushBack(9);
	l1.pushFront(7);
	l1.pushFront(8);
	l1.pushBack(2);
	l1.print();
	return 0;
}
