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
bool operator== (const Node& n1, const Node& n2)
{
	return n1.name == n2.name;
}
bool operator!= (const Node& n1, const Node& n2)
{
	return n1.name != n2.name;
}