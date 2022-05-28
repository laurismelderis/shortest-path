#pragma once

#include "Node.h"

class Edge
{
private:
	Node nodeFrom;
	Node nodeTo;
	int weight;
public:
	Edge();
	Edge(Node from, Node to, int weight);
	void print();
};