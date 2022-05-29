// Melderis Lauris GP
// 191RDB078 3rd group

#include <iostream>
using namespace std;

#include "Graph.h"
#include "Node.h"
#include "CSV.h"
#include "Utils.h"
Graph getGraph(string path, bool isDirected)
{
	Graph graph;
	vector<string> content = CSV::read(path);
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
		if (!isDirected) graph.addEdge(Edge(nodeTo, nodeFrom, weight));
	}
	return graph;
}

vector<Edge> getEdges(string path, bool isDirected)
{
	vector<Edge> edges;
	vector<string> content = CSV::read(path);

	content.erase(content.begin());
	for (string el : content)
	{
		vector<string> words = Utils::seperate(el, ',');
		string nodeFrom = words[0];
		string nodeTo = words[1];
		int weight = stoi(words[6]);
		Edge edge(nodeFrom, nodeTo, weight);
		edges.push_back(edge);
		if (!isDirected) edges.push_back(Edge(nodeTo, nodeFrom, weight));
	}
	return edges;
}

vector<Node> getNodes(string path)
{
	vector<Node> nodes;
	vector<string> content = CSV::read(path);

	content.erase(content.begin());
	for (string el : content)
	{
		vector<string> words = Utils::seperate(el, ',');
		string name = words[0];
		string label = words[1];
		Node node(name, label);
		nodes.push_back(node);
	}
	return nodes;
}

int main()
{
	string karatePath = "C:\\Users\\Lauris\\Desktop\\short_path\\src\\graphs\\karate.csv";
	string examplePath = "C:\\Users\\Lauris\\Desktop\\example_graph_edges.csv";
	string miserablesEdgesPath = "C:\\Users\\Lauris\\Desktop\\short_path\\src\\graphs\\miserables-edges.csv";
	string miserablesNodesPath = "C:\\Users\\Lauris\\Desktop\\short_path\\src\\graphs\\miserables-nodes.csv";

	Graph karateGraph = getGraph(karatePath, true);
	Node sourceNode1 = karateGraph.findNodeByName("9");
	Node destinationNode1 = karateGraph.findNodeByName("2");

	// Prints shortest path between nodes id 9 and node id 2
	karateGraph.djikstra(sourceNode1, destinationNode1, false);

	// Prints diameter of karate club
	karateGraph.djikstra(sourceNode1, destinationNode1, true);

	Graph miserablesGraph;
	// Second paramater is boolean which says if the graph is directed or undirected
	vector<Edge> miserablesEdges = getEdges(miserablesEdgesPath, false);
	miserablesGraph.setEdges(miserablesEdges);

	vector<Node> miserablesNodes = getNodes(miserablesNodesPath);
	miserablesGraph.setNodes(miserablesNodes);

	Node sourceNode2 = miserablesGraph.findNodeByLabel("Cravatte");
	Node destinationNode2 = miserablesGraph.findNodeByLabel("Jondrette");

	// Prints the path cost between Cravatte and Jondrette
	// Second paramater is boolean which says if the weight to all edges is one
	miserablesGraph.djikstra(sourceNode2, destinationNode2, false);

	// Prints diameter of Les Miserables graph
	miserablesGraph.djikstra(sourceNode2, destinationNode2, true);
}