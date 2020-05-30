#pragma once
#include <iostream>
#include <string>

class Node
{
private:
	Node *m_left;
	Node *m_right;
	Node *m_parent;
	int m_id;
	std::string m_value;
public:
	Node();
	Node(int id, std::string value) : m_id(id), m_value(value) {};
	~Node();
	
	int getId() { return m_id; };
	Node* setId(int id) { 
		m_id = id;
		return this;
	}

	std::string getValue() { return m_value; };
	Node* setValue(std::string value) {
		m_value = value;
		return this;
	}

	Node* getLeft() { return m_left; };
	Node* setLeft(Node *left) {
		m_left = left;
		return this;
	}

	Node* getRight() { return m_right; };
	Node* setRight(Node *right) {
		m_right = right;
		return this;
	}

	Node* getParent() { return m_parent; };
	Node* setParent(Node *parent) {
		m_parent = parent;
		return this;
	}

	std::string print(int level = 0);
	void insert(int id, std::string value);
	void remove(int id);
	void clear();

	friend std::ostream& operator<<(std::ostream &os, Node *node)
	{
		return os << node->print() << std::endl;
	}
};

