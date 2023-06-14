#include <iostream>
#include <string>
#include <vector>
#include "LinkedList.h"



int main() {
	setlocale(LC_ALL, "Russian");
	
	LinkedList list;
	list.addHead(10);
	list.addTail(20);
	list.addTail(8);
	list.addTail(16);
	list.addTail(25);
	list.addTail(45);
	list.addTail(120);
	list.addTail(39);
	list.showList();
	std::cout << std::endl;
	std::cout << list.findElement(1)->getData() << std::endl;
	std::cout << std::endl;
	list.deleteElement(1);
	list.showList();

	return 0;
}