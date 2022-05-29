#pragma once

#include <iostream>
#include <string>
#include <vector>

class Node
{
private:
	std::string name;
	std::string label;
public:
	Node() { this->name = ""; }
	Node(std::string name);
	Node(std::string name, std::string label);
	void print();
	inline std::string getName() { return this->name; }
	inline std::string getLabel() { return this->label; }
	friend bool operator== (const Node& n1, const Node& n2);
	friend bool operator!= (const Node& n1, const Node& n2);
};