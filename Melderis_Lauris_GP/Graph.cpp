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

Node Graph::findNode(string name)
{
	for (Node node : nodes)
	{
		if (node.getName() == name)
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
		this->cost = INT_MIN;
		this->prevNode = "";
	}
	void print()
	{
		cout << name << " " << cost << " " << prevNode << endl;
	}
};

void Graph::djikstra(Node sourceNode)
{
	vector<Vertex> vertices;
	vector<Node> visitedNodes;
	vector<Node> unvisitedNodes;

	// Initialize shortest vertices
	for (Node node : nodes)
	{
		vertices.push_back(Vertex(node.getName()));
	}

	// Initialize unvisited nodes
	for (Node node : nodes)
	{
		unvisitedNodes.push_back(node);
	}

	Node currentNode = sourceNode;

	// Loop through every node
	while ( ! unvisitedNodes.empty())
	{
		// Get current node edges
		vector<Edge> currentNodeEdges;
		for (Edge edge : edges)
		{
			if (edge.getNodeFrom().getName() == currentNode.getName())
			{
				currentNodeEdges.push_back(edge);
			}
		}

		// Update shortest vertices
		for (Edge edge : currentNodeEdges)
		{
			for (int j = 0; j < vertices.size(); j++)
			{
				if (edge.getNodeTo().getName() == vertices[j].name)
				{
					if (vertices[j].cost == INT_MIN) vertices[j].cost = edge.getWeight();
					else vertices[j].cost += edge.getWeight();
					cout << "Updated to: ";
					vertices[j].print();
				}
			}
		}

		// Add current node to the visited nodes list
		visitedNodes.push_back(currentNode);
		
		// Remove from current list unvisitedNode
		if (!unvisitedNodes.empty()) {
			// Node theNode = find(unvisitedNodes.begin(), unvisitedNodes.end(), currentNode);
			unvisitedNodes.erase(remove(unvisitedNodes.begin(), unvisitedNodes.end(), currentNode));
		}
		else {
			break;
		}
		// cout << visitedNodes.size() << endl;
		// cout << unvisitedNodes.size() << endl;

		// Next vertex should be with the smallest cost
		// Find vertex with smallest cost
		int smallestCost = INT_MAX;
		for (auto unvisitedNode : unvisitedNodes)
		{
			// Find the according node from vertex
			for (auto vert : vertices)
			{
				// If the smallest then assign the according next node
				if (unvisitedNode.getName() == vert.name)
				{
					if (vert.cost < smallestCost && vert.cost != INT_MIN)
					{
						smallestCost = vert.cost;
						currentNode = unvisitedNode;
						break;
					}
				}
			}
		}
	}
	// Print current shortest paths
	for (auto vert : vertices)
		vert.print();
}