#include "Edge.h"

Edge::Edge() {}

Edge::Edge(Node from, Node to, int weight)
{
	this->nodeFrom = from;
	this->nodeTo = to;
	this->weight = weight;
}

void Edge::print()
{
	std::cout << "From: " << nodeFrom.getName() << " To: " << nodeTo.getName() << " Weight: " << weight << std::endl;
}