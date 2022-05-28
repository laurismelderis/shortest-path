#pragma once

#include <vector>
#include <string>

#include "Node.h"
#include "Edge.h"

class Graph
{
private:
	std::vector<Node> nodes;
	std::vector<Edge> edges;

public:
	void addNode(Node node);
	void addEdge(Edge edge);
	void printNodes();
	void printEdges();
	bool nodeExists(Node node);
};