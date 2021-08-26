#pragma once

#include <cstdlib>
#include <vector>

class LinkedBinarySearchTree
{
protected:
	//Nodo para el árbol binario de búsqueda
	struct Node 
	{
		int value;
		Node* par;
		Node* left;
		Node* right;
		Node() : value(), par(NULL), left(NULL), right(NULL) {}
		Node(int valor) : value(valor), par(NULL), left(NULL), right(NULL) {}
	};

public:
	LinkedBinarySearchTree();
	void push(int valor);
	void remove(int valor);
	void InOrder(std::vector<int>& lista) const;
protected:
	void quitar(Node* actual);
	void EnOrden(Node* actual, std::vector<int>& lista) const;
	void addRoot(int valor);
	void addRightNode(int valor, Node* puntero);
	void addLeftNode(int valor, Node* puntero);
private:
	Node* _root;
	int n;
};

