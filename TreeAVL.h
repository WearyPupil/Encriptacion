#pragma once

#include <cstdlib>
#include <vector>

class TreeAVL
{
protected:
	// Nodo para el arbol balanceado
	struct Node
	{
		int value;
		Node* par;
		Node* left;
		Node* right;
		Node() : value(), par(NULL), left(NULL), right(NULL) {};
		Node(int valor) : value(valor), par(NULL), left(NULL), right(NULL) {}
	};

public:
	TreeAVL();
	void push(int valor);
	void remove(int valor);
	void InOrder(std::vector<int>& lista) const;
protected:
	void balancear(Node *actual);
	int altura(Node* actual);
	int balance(Node* actual);
	void derecha(Node* actual);
	void izquierdaDerecha(Node* actual);
	void izquierda(Node* actual);
	void derechaIzquierda(Node* actual);
	void quitar(Node* actual);
	void EnOrden(Node* actual, std::vector<int>& lista) const;
	void addRoot(int valor);
	void addRightNode(int valor, Node* puntero);
	void addLeftNode(int valor, Node* puntero);
private:
	Node* _root;
	int n;
};

