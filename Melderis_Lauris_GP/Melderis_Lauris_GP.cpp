// Melderis Lauris GP
// 191RDB078 3rd group

#include <iostream>
using namespace std;

#include "Graph.h"
#include "Node.h"
#include "CSV.h"
#include "Utils.h"
Graph getKarateGraph()
{
	Graph graph;
	vector<string> content = CSV::read("C:\\Users\\siamo\\Downloads\\Graphs\\karate.csv");
	// Remove csv headers
	content.erase(content.begin());

	for (string el : content)
	{
		vector<string> words = Utils::seperate(el, ',');
		string nodeFrom = words[0];
		string nodeTo = words[1];
		int weight = stoi(words[6]);
		Edge edge(nodeFrom, nodeTo, weight);
		Node from(nodeFrom);
		Node to(nodeTo);
		if (!graph.nodeExists(from))
		{
			graph.addNode(from);
		}
		if (!graph.nodeExists(to))
		{
			graph.addNode(to);
		}
		graph.addEdge(edge);
	}
	return graph;
}

int main()
{
	Graph karateGraph = getKarateGraph();
	Node sourceNode = karateGraph.findNode("9");
	karateGraph.djikstra(sourceNode);
}