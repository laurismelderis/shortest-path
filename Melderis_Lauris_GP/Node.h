#pragma once

#include <iostream>
#include <string>
#include <vector>

class Node
{
private:
	std::string name;
public:
	Node() {}
	Node(std::string name);
	void print();
	inline std::string getName() { return this->name; }
	friend bool operator== (const Node& n1, const Node& n2);
	friend bool operator!= (const Node& n1, const Node& n2);
};