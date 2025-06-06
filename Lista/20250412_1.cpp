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
	int size;

	List(){
		start = NULL;
		end = NULL;
		size = 0;
	}

	bool isEmpty(){
		return start == NULL && end == NULL;
	}

	void pushBack(int value){
		Node* n = new Node(value);
		size++;
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
		size++;
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

	int getSize(){
		return size;
	}

	void popFront(){
		if(isEmpty()) return;

		if(getSize() == 1){
			delete(start);
			start = NULL;
			end = NULL;
			size = 0;
			return;
		}

		Node* aux = start;
		start = start->next;
		delete(aux);
		size--;
	}

	void popBack(){
		if(isEmpty()) return;

		if(getSize() == 1){
			delete(end);
			start = NULL;
			end = NULL;
			size = 0;
			return;
		}

		Node* aux = start;
		while(aux->next != end){
			aux = aux->next;
		}

		delete(end);
		end = aux;
		end->next = NULL;
		size--;
	}

	void addSizeItem(){
		pushBack(getSize());
	}

	void addSubListSize(sizeList){
        for(int i = 1 ; i <= sizeList ; i++){
            pushBack(i);
        }
	}

	void deleteTail(int sizeEnd){
		if(getSize() == 0) return;

		if(getSize() <= sizeEnd){
			while(start != NULL){
				Node* aux = start;
				start = start->next;
				delete(aux);
			}
			start = NULL;
			end = NULL;
			size = 0;
			return;
		}

		int endList = getSize() - sizeEnd;
		Node* aux = start;

		for(int i = 0 ; i < endList - 1 ; i++){
			aux = aux->next;
		}

		Node* startDelete = aux->next;
		end = aux;
		end->next = NULL;

		while(startDelete != NULL){
			Node* toDelete = startDelete;
			startDelete = startDelete->next;
			delete(toDelete);
			size--;
		}
	}

	void deleteSecItem(){
		if(getSize() <= 1) return;

		Node* secItem = start->next;
		start->next = secItem->next;
		delete(secItem);
		size--;
		return;
	}

	void insert(int value, int position){
		if(position <= 0){
			pushFront(value);
			return;
		}

		if(position >= getSize()){
			pushBack(value);
			return;
		}

		Node* n = new Node(value);
		size++;

		Node* before = start;
		for(int i = 0 ; i < position - 1 ; i++){
			before = before->next;
		}

		n->next = before->next;
		before->next = n;
	}

	void insertPenultimate(int value){
	    if(getSize() <= 1) return;

	    Node* aux = start;
        while(aux->next != end){
            aux = aux->next;
        }
        Node* n = new Node(value);
        aux->next = n;
        n->next = end;
        size++;
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
	l1.pushBack(5);
	l1.print();
	l1.popBack();
	l1.popFront();
	l1.print();
	l1.insert(1, 2);
	l1.print();
	l1.deleteTail(3);
	l1.print();
	l1.pushBack(5);
	l1.pushBack(6);
	l1.print();
	l1.deleteSecItem();
	l1.print();
	l1.addSizeItem();
	l1.print();
	return 0;
}
