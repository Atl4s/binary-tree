#include "pch.h"
#include "Node.h"

Node::Node()
{
}

Node::~Node()
{
	clear();
}

std::string Node::print(int level)
{
	std::string temp = std::string(level, '-') + std::to_string(m_id) + ": " + m_value + '\n';

	if (m_left) {
		temp += "<L>" + m_left->print(level + 1);
	}

	if (m_right){
		temp += "<R>" + m_right->print(level + 1);
	}

	return temp;
}

void Node::insert(int id, std::string value)
{
	if (id < m_id) {
		Node *left = m_left;
		if (left) {
			left->insert(id, value);
		}
		else {
			Node *node = new Node(id, value);
			node->setParent(this);
			m_left = node;
		}
	} else {
		Node *right = m_right;
		if (right) {
			right->insert(id, value);
		}
		else {
			Node *node = new Node(id, value);
			node->setParent(this);
			m_right = node;
		}
	}
}

void Node::remove(int id)
{
	if (id == m_id) {
		if (m_left && m_right) {
			Node* temp = m_left;
			while (temp->getRight()) {
				temp = temp->getRight();
			}
			m_id = temp->getId();
			m_value = temp->getValue();
			temp->remove(temp->getId());
		}
		else {
			if (m_left) {
				Node* left = m_left;
				m_id = left->getId();
				m_value = left->getValue();
				m_left = left->getLeft();
				m_right = left->getRight();
				delete left;

			} else if (m_right){
				Node* right = m_right;
				m_id = right->getId();
				m_value = right->getValue();
				m_left = right->getLeft();
				m_right = right->getRight();
				delete right;
			}
			else {
				if (m_parent) {
					if (m_parent->getLeft() == this) {
						m_parent->setLeft(nullptr);
					} else {
						m_parent->setRight(nullptr);
					}
					delete this;
				}
			}
		}
	} else if (id < m_id) {
		if (m_left) {
			m_left->remove(id);
		}
	} else {
		if (m_right) {
			m_right->remove(id);
		}
	}
}

void Node::clear()
{
	if (m_left) {
		m_left->clear();
		delete m_left;
		m_left = nullptr;
	}
	if (m_right) {
		m_right->clear();
		delete m_right;
		m_right = nullptr;
	}
}
