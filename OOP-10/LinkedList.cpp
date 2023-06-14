#include "LinkedList.h"

LinkedList::LinkedList() : _head(nullptr), _tail(nullptr), _size(0){}

void LinkedList::addTail(int data){
	Node* newTail = new Node(data);
	_size++;
	if (_head == nullptr) {
		_head = newTail;
		_tail = newTail;
		return;
	}
	_tail->_prev = newTail;
	newTail->_next = _tail;
	_head->_next = newTail;
	_tail = newTail;
}

void LinkedList::addHead(int data){
	Node* newHead = new Node(data);
	_size++;
	if (_head == nullptr) {
		_head = newHead;
		_tail = newHead;
		return;
	}
	_head->_next = newHead;
	newHead->_prev = _head;
	newHead->_next = _tail;
	_head = newHead;
}

void LinkedList::showList(){
	if (_size == 0) {
		std::cout << "Нет элементов" << std::endl;
		return;
	}
	int index = 0;
	for (Node* nodePtr = _head; index != _size; nodePtr = nodePtr->_next, index++)
		std::cout << "Данные: " << nodePtr->getData() << std::endl;
}

void LinkedList::deleteElement(int index){

	if (_size == 1) {
		_size--;
		delete(_head);
		return;
	}

	Node* deleted = findElement(index);
	Node* prevDeleted = deleted->_prev;
	Node* nextDeleted = deleted->_next;
	prevDeleted->_next = nextDeleted;
	nextDeleted->_prev = prevDeleted;
	if (deleted == _head)
		_head = deleted->_prev;
	else if (deleted == _tail)
		_tail = deleted->_next;
	_size--;
	delete(deleted);
}

void LinkedList::deleteList(){
	Node* nodePtr = _tail;
	while (_size > 0) {
		nodePtr = nodePtr->_next;
		delete(_tail);
		_tail = nodePtr;
		_size--;
	}
}

Node* LinkedList::findElement(int index){
	if (index <= 0 || index > _size) return nullptr;

	if (index == 1) return _head;
	else if (index == _size) return _tail;
	Node* nodePtr = _head;
	index--;
	while (index != 0) {
		nodePtr = nodePtr->_prev;
		index--;
	}
	return nodePtr;
}
