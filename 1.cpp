#include <iostream>

// Definición de la clase Node
template<typename T>
class Node {
public:
	// Constructor
	Node(T data) : data(data), next(nullptr), prev(nullptr) {}
	
	// Getter y Setter
	T getData() const { return data; }
	void setData(T newData) { data = newData; }
	
	Node<T>* getNext() const { return next; }
	void setNext(Node<T>* newNext) { next = newNext; }
	
	Node<T>* getPrev() const { return prev; }
	void setPrev(Node<T>* newPrev) { prev = newPrev; }
	
private:
		T data;
		Node<T>* next;
		Node<T>* prev;
};

// Definición de la clase LinkedList
template<typename T>
class DoubleLinkedList {
private:
	Node<T>* head;
	Node<T>* tail;
public:
	// Constructor
	DoubleLinkedList() : head(nullptr), tail(nullptr) {}
	
	// Destructor
	~DoubleLinkedList() {
		Node<T>* current = head;
		Node<T>* nextNode;
		
		while (current != nullptr) {
			nextNode = current->getNext();
			delete current;
			current = nextNode;
		}
	}
	
	// Método para imprimir la lista
	void print_list() const {
		Node<T>* temp = head;
		while (temp != nullptr) {
			std::cout << temp->getData() << " <-> ";
			temp = temp->getNext();
		}
		std::cout << "nullptr" << std::endl;
	}
	
	// Método para insertar al frente
	void push_front(T data) {
		Node<T>* newNode = new Node<T>(data);
		
		if(head == nullptr){
			head = newNode;
			tail = newNode;
			return;
		}
		head -> setPrev(newNode);
		newNode->setNext(head);
		head = newNode;
	}
	
	// Método para insertar al frente
	void push_back(T data) {
		Node<T>* newNode = new Node<T>(data);
		
		if(head == nullptr){
			head = newNode;
			tail = newNode;
			return;
		}
		tail -> setNext(newNode);
		newNode->setPrev(tail);
		tail = newNode;
	}
	
	void pop_back() {
		if(head == nullptr ){
			return;
		}
		if(head == tail ){
			Node<T>* newNode = tail;
			head = nullptr;
			tail = nullptr;
			delete newNode;
			return;
		}
		Node<T>* newNode = tail->getPrev();
		newNode -> setNext(nullptr);
		tail = newNode;
		newNode=newNode ->getNext();
		delete newNode;
		return;
	}
	void pop_front() {
		if(head == nullptr ){
			return;
		}
		if(head == tail ){
			Node<T>* newNode = tail;
			head = nullptr;
			tail = nullptr;
			delete newNode;
			return;
		}
		Node<T>* newNode = head->getNext();
		newNode -> setPrev(nullptr);
		head = newNode;
		newNode=newNode ->getPrev();
		delete newNode;
		return;
	}
	
	void print_reverse() {
		Node<T>* temp = tail;
		while (temp != nullptr) {
			std::cout << temp->getData() << " <-> ";
			temp = temp->getPrev();
		}
		std::cout << "nullptr" << std::endl;
		return;
	}
	bool empty() {
		if(head == tail && head== nullptr){
			return true;
		}
		return false; 
	}
	T getfront() const { return (head==nullptr)?(0):(head->getData()); }
	T getback() const {  
		try {
			(head==nullptr)?(throw "Lista vacía"):(return head->getData()); 
		}
		catch{
			std::cerr << "Error: " ;
			return T();
		}
	}
	//remove		el dato
	//insert		
	void clear(){
		while(!empty()){
			pop_front();
			pop_back();
		}
	}
	
};

int main() {
	DoubleLinkedList<int>* mi_lista = new DoubleLinkedList<int>;
	
	mi_lista->push_front(1);
	mi_lista->push_front(2);
	mi_lista->push_back(3);
	mi_lista->clear();
	mi_lista->print_list();
	mi_lista->print_reverse();
	std::cout<<"\n";
	std::cout<<mi_lista->empty()<<"\n";
	std::cout<<mi_lista->getfront()<<"\n";
	std::cout<<mi_lista->getback()<<"\n";
	mi_lista->pop_back();
	mi_lista->pop_front();
	mi_lista->print_list();
	
	
	delete mi_lista;
	
	return 0;
}
