#include <vector>

#include "Graph.h"

void Graph::addNode(Node node)
{
	if (node.getName() == "" || node.getName() == " ") return;
	nodes.push_back(node);
}

void Graph::addEdge(Edge edge)
{
	edges.push_back(edge);
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