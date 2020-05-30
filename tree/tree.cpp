// tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Node.h"
#include <iostream>
#include <string>

int main()
{
	Node *tree = nullptr;

	int choice = 0;

	while (choice != 5) {
		std::cout << "1 - add" << std::endl;
		std::cout << "2 - remove" << std::endl;
		std::cout << "3 - print" << std::endl;
		std::cout << "4 - clear" << std::endl;
		std::cout << "5 - exit" << std::endl;
		std::cout << "print your choice" << std::endl;
		std::cin >> choice;

		int id;
		std::string value;
		switch (choice) {
		case 1:
			std::cout << "print id" << std::endl;
			std::cin >> id;
			std::cout << "print value" << std::endl;
			std::cin >> value;
			if (tree) {
				tree->insert(id, value);
			} else {
				tree = new Node(id, value);
			}
			break;
		case 2:
			std::cout << "print id" << std::endl;
			std::cin >> id;
			if (tree) {
				tree->remove(id);
			}
			else {
				std::cout << "tree is empty" << std::endl;
			}
			break;
		case 3:
			std::cout << tree;
			break;
		case 4:
			delete tree;
			tree = nullptr;
			break;
		case 5:
			break;
		}
	}

}
