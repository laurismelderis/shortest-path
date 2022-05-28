#include "Node.h"

using namespace std;

Node::Node(string name)
{
	this->name = name;
}
void Node::print()
{
	cout << "Node name: " << this->name << std::endl;
}