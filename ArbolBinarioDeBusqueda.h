#pragma once

#include <cstddef>

class Pareja {
public:
	Pareja(int llave, int valor)
		: key(llave), value(valor) {}

private:
	int key;
	int value;

	friend class ArbolBinarioDeBusqueda;
};

class ArbolBinarioDeBusqueda {
private:
	class Node {
	public:
		Node(Pareja datos)
			: value(datos) {}
	private:
		Node* izquierdo = NULL;
		Node* derecho = NULL;
		Pareja value; 
	};
public:
	ArbolBinarioDeBusqueda(int llave, int valor)
	{
		Pareja raiz = Pareja(llave, valor);
		Node raiz_2 = Node(raiz);

	}

private:
	*Node root;

};