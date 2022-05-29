#pragma once

#include <vector>
#include <string>
#include <iostream>

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
	void setNodes(std::vector<Node> nodes);
	void setEdges(std::vector<Edge> edges);

	Node findNodeByName(std::string name);
	Node findNodeByLabel(std::string label);
	void printNodes();
	void printEdges();
	bool nodeExists(Node node);
	void djikstra(Node source, Node destinationNode,  bool isWeightOne);
};