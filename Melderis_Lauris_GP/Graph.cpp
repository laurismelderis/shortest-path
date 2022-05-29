#include "Graph.h"

using namespace std;

void Graph::addNode(Node node)
{
	if (node.getName() == "" || node.getName() == " ") return;
	nodes.push_back(node);
}

void Graph::addEdge(Edge edge)
{
	edges.push_back(edge);
}

void Graph::setNodes(vector<Node> nodes)
{
	this->nodes = nodes;
}

void Graph::setEdges(vector<Edge> edges)
{
	this->edges = edges;
}

Node Graph::findNodeByName(string name)
{
	for (Node node : nodes)
	{
		if (node.getName() == name)
		{
			return node;
		}
	}
}

Node Graph::findNodeByLabel(string label)
{
	for (Node node : nodes)
	{
		if (node.getLabel() == label)
		{
			return node;
		}
	}
}

void Graph::printNodes()
{
	for (Node node : nodes)
	{
		node.print();
	}
}

void Graph::printEdges()
{
	for (Edge edge : edges)
	{
		edge.print();
	}
}

bool Graph::nodeExists(Node node)
{
	for (Node sNode : nodes)
	{
		if (sNode.getName() == node.getName())
		{
			return true;
		}
	}
	return false;
}

struct Vertex
{
	string name;
	int cost;
	string prevNode;
	Vertex(string name)
	{
		this->name = name;
		this->cost = INT_MAX;
	}
	void print()
	{
		cout << "NodeID: " << name << " Cost: " << cost << endl;
	}
};

Node getSmallestNode(vector<Vertex> shortestVertices, vector<Node> nodes)
{
	Node theSmallestNode;
	int minCost = INT_MAX;
	// Find the smallest node
	for (Vertex vert : shortestVertices)
	{
		if (vert.cost < minCost) {
			for (Node node : nodes)
			{
				if (vert.name == node.getName()) {
					minCost = vert.cost;
					theSmallestNode = node;
				}

			}
		}
	}
	return theSmallestNode;
}

Vertex getVertex(Node node, vector<Vertex> vertices) {
	for (Vertex vert : vertices)
	{
		if (vert.name == node.getName()) {
			return vert;
		}
	}
}

void Graph::djikstra(Node sourceNode, Node destinationNode, bool isWeightOne)
{
	vector<Vertex> shortestVertices;
	vector<Node> visitedNodes;
	vector<Node> unvisitedNodes;

	// Initialize shortest shortestVertices
	for (Node node : nodes)
	{
		Vertex vertex(node.getName());
		shortestVertices.push_back(vertex);
	}

	// Initialize unvisited nodes
	for (Node node : nodes)
	{
		unvisitedNodes.push_back(node);
	}
	// Remove the source node
	unvisitedNodes.erase(remove(unvisitedNodes.begin(), unvisitedNodes.end(), sourceNode));
	visitedNodes.push_back(sourceNode);

	// Get the first node edges
	vector<Edge> currentNodeEdges;
	for (Edge edge : edges)
	{
		if (edge.getNodeFrom().getName() == sourceNode.getName())
		{
			currentNodeEdges.push_back(edge);
		}
	}

	// Update shortest shortestVertices for the first time
	for (Edge edge : currentNodeEdges)
	{
		for (int j = 0; j < shortestVertices.size(); j++)
		{
			if (edge.getNodeTo().getName() == shortestVertices[j].name)
			{
				shortestVertices[j].cost = edge.getWeight();
			}
		}
	}


	Node theSmallestNode;
	while (!unvisitedNodes.empty())
	{
		Node theSmallestNode = getSmallestNode(shortestVertices, unvisitedNodes);
		if (theSmallestNode.getName() == "") break;

		currentNodeEdges.clear();
		// Get the smallest node edges
		for (Edge edge : edges)
		{
			if (edge.getNodeFrom().getName() == theSmallestNode.getName())
			{
				currentNodeEdges.push_back(edge);
			}
		}

		// Update shortestVertices
		for (Edge edge : currentNodeEdges)
		{
			for (int j = 0; j < shortestVertices.size(); j++)
			{
				if (edge.getNodeTo().getName() == shortestVertices[j].name)
				{
					int newCost = 0;
					if (isWeightOne) {
						newCost = getVertex(theSmallestNode, shortestVertices).cost + 1;
					}
					else {
						newCost = getVertex(theSmallestNode, shortestVertices).cost + edge.getWeight();
					}
					if (newCost < shortestVertices[j].cost)
					{
						shortestVertices[j].cost = newCost;
					}
				}
			}
		}
		unvisitedNodes.erase(remove(unvisitedNodes.begin(), unvisitedNodes.end(), theSmallestNode));
		visitedNodes.push_back(theSmallestNode);

	}

	int shortestPath = 0;
	for (auto vert : shortestVertices)
	{
		if (vert.name == destinationNode.getName())
		{
			shortestPath = vert.cost;
		}
	}
		
	if (isWeightOne) {
		cout << "Diameter in the graph is: ";
		cout << shortestPath << endl;
	}
	else {
		cout << "Shortest path from " << sourceNode.getLabel() << " to " << destinationNode.getLabel() << " is: ";
		cout << shortestPath << endl;
	}
}