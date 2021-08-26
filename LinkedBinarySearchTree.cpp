#include "LinkedBinarySearchTree.h"

LinkedBinarySearchTree::LinkedBinarySearchTree()
	: _root(NULL), n(0) {}

void LinkedBinarySearchTree::addRoot(int valor)
{
	_root = new Node(valor); n++;
}

void LinkedBinarySearchTree::addRightNode(int valor, Node* puntero)
{
	puntero->right = new Node(valor);
	puntero->right->par = puntero;
	n++;
}

void LinkedBinarySearchTree::addLeftNode(int valor, Node* puntero)
{
	puntero->left = new Node(valor);
	puntero->left->par = puntero;
	n++;
}

void LinkedBinarySearchTree::push(int valor)
{
	if (n == 0)
	{
		addRoot(valor);
		return;
	}

	Node* current = _root;

	while (true)
	{
		if (valor >= current->value)
		{
			if (current->right == NULL)
			{
				addRightNode(valor, current);
				return;
			}
			
			else
			{
				current = current->right;
				continue;
			}
		}

		else
		{
			if (current->left == NULL)
			{
				addLeftNode(valor, current);
				return;
			}

			else
			{
				current = current->left;
				continue;
			}
		}
	}
}

void LinkedBinarySearchTree::remove(int valor)
{
	Node* actual = _root;
	while (true)
	{
		if (actual->value == valor)
		{
			quitar(actual);
			return;
		}

		if (valor > actual->value)
		{
			if (actual->right == NULL) return;

			actual = actual->right;
		}

		else
		{
			if (actual->left == NULL) return;

			actual = actual->left;
		}
	}
}

void LinkedBinarySearchTree::quitar(Node* actual)
{
	if (actual->left == NULL && actual->right == NULL)
	{
		if (actual == _root)
		{
			delete actual;
			n--;
			return;
		}

		if (actual->par->right == actual)
		{
			actual->par->right = NULL;
		}

		else
		{
			actual->par->left = NULL;
		}

		delete actual;

	}

	else if (actual->left == NULL && actual->right != NULL)
	{
		if (actual == _root)
		{
			_root = actual->right;
			actual->right->par = NULL;
			
			delete actual;
			n--;
			return;
		}

		if (actual->par->right == actual)
		{
			actual->par->right = actual->right;
			actual->right->par = actual->par;
		}

		else
		{
			actual->par->left = actual->right;
			actual->right->par = actual->par;
		}

		delete actual;
	}

	else if (actual->left != NULL && actual->right == NULL)
	{
		if (actual == _root)
		{
			_root = actual->left;
			actual->left->par = NULL;

			delete actual;
			n--;
			return;
		}

		if (actual->par->right == actual)
		{
			actual->par->right = actual->left;
			actual->left->par = actual->par;
		}

		else
		{
			actual->par->left = actual->left;
			actual->left->par = actual->par;
		}

		delete actual;
	}

	else if (actual->left != NULL && actual->right != NULL)
	{
		Node* sucesor = actual;
		sucesor = actual->right;

		while (sucesor->left != NULL)
		{
			sucesor = sucesor->left;
		}

		if (sucesor->right != NULL)
		{
			if (sucesor->par->right == sucesor)
			{
				sucesor->par->right = sucesor->right;
				sucesor->right->par = sucesor->par;
			}

			else
			{
				sucesor->par->left = sucesor->right;
				sucesor->right->par = sucesor->par;
			}
		}

		else
		{
			sucesor->par->left = NULL;
		}

		if (actual == _root)
		{
			_root = sucesor;
			sucesor->par = NULL;
			sucesor->left = actual->left;
			if (sucesor->left != NULL)
			{
				sucesor->left->par = sucesor;
			}
			sucesor->right = actual->right;
			if (sucesor->right != NULL)
			{
				sucesor->right->par = sucesor;
			}

			delete actual;
			n--;
			return;
		}

		sucesor->par = actual->par;
		if (actual->par->right == actual)
		{
			actual->par->right = sucesor;
		}

		else
		{
			actual->par->left = sucesor;
		}

		if (actual->right == sucesor && sucesor->right == NULL)
		{
			actual->right = NULL;
		}

		sucesor->left = actual->left;
		if (sucesor->left != NULL)
		{
			sucesor->left->par = sucesor;
		}
		sucesor->right = actual->right;
		if (sucesor->right != NULL)
		{
			sucesor->right->par = sucesor;
		}
		delete actual;
	}

	n--;
	return;
}

void LinkedBinarySearchTree::EnOrden(Node* actual, std::vector<int>& lista) const
{
	if (actual->left != NULL) EnOrden(actual->left, lista);
	lista.push_back(actual->value);
	if (actual->right != NULL) EnOrden(actual->right, lista);
}

void LinkedBinarySearchTree::InOrder(std::vector<int>& lista) const
{
	EnOrden(_root, lista);
}