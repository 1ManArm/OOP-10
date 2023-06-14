#include "Node.h"

Node::Node(int data) : _data(data), _next(nullptr), _prev(nullptr) {}

int Node::getData(){
	return _data;
}
