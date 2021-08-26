#include "TreeAVL.h"

TreeAVL::TreeAVL()
	: _root(NULL), n(0) {}

void TreeAVL::addRoot(int valor)
{
	_root = new Node(valor); n++;
}

void TreeAVL::addRightNode(int valor, Node* puntero)
{
	puntero->right = new Node(valor);
	puntero->right->par = puntero;
	n++;
	balancear(puntero->right);
}

void TreeAVL::addLeftNode(int valor, Node* puntero)
{
	puntero->left = new Node(valor);
	puntero->left->par = puntero;
	n++;
	balancear(puntero->left);
}

void TreeAVL::push(int valor)
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

void TreeAVL::remove(int valor)
{
	Node* actual = _root;
	while (true)
	{
		if (actual->value == valor)
		{
			Node* balanceo = actual->par;
			quitar(actual);
			balancear(balanceo);
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

void TreeAVL::balancear(Node* actual)
{

	if (std::abs(balance(actual)) > 1)
	{
		if (balance(actual) > 1)
		{
			if (actual->left != NULL && actual->left->left != NULL)
			{
				derecha(actual);
			}

			else
			{
				izquierdaDerecha(actual->left);
			}
		}

		else if (balance(actual) < 1)
		{
			if (actual->right != NULL && actual->right->right != NULL)
			{
				izquierda(actual);
			}

			else
			{
				derechaIzquierda(actual->right);
			}
		}
	}

	if (actual->par != NULL) balancear(actual->par);
}

int TreeAVL::altura(Node* actual)
{
	if (actual->right == NULL && actual->left == NULL) return 0;

	int h = 0;
	
	if (actual->right != NULL)
	{
		h = std::max(h, altura(actual->right));
	}

	if (actual->left != NULL)
	{
		h = std::max(h, altura(actual->left));
	}

	return 1 + h;
}

int TreeAVL::balance(Node* actual)
{

	if (actual->right != NULL && actual->left != NULL) 
	{
		return ((altura(actual->left)) - (altura(actual->right)));
	}
	
	else if (actual->right != NULL && actual->left == NULL)
	{
		return ((-1) - (altura(actual->right)));
	}

	else if (actual->right == NULL && actual->left != NULL)
	{
		return ((altura(actual->left)) - (-1));
	}

	else
	{
		return 0;
	}
}

void TreeAVL::derecha(Node* actual)
{
	if (actual != _root)
	{
		if (actual->par->left == actual)
		{
			actual->par->left = actual->left;
		}

		else
		{
			actual->par->right = actual->left;
		}
	}

	actual->left->par = actual->par;
	if (actual == _root) _root = actual->left;
	actual->par = actual->left;

	if (actual->par->right != NULL)
	{
		actual->left = actual->par->right;
		actual->left->par = actual;
	}

	else
	{
		actual->left = NULL;
	}

	actual->par->right = actual;
}

void TreeAVL::izquierdaDerecha(Node* actual)
{
	Node* next = actual->par;
	izquierda(actual);
	derecha(next);
}

void TreeAVL::izquierda(Node* actual)
{
	if (actual != _root)
	{
		if (actual->par->left == actual)
		{
			actual->par->left = actual->right;
		}

		else
		{
			actual->par->right = actual->right;
		}
	}
	actual->right->par = actual->par;
	if (actual == _root) _root = actual->right;
	actual->par = actual->right;

	if (actual->par->left != NULL)
	{
		actual->right = actual->par->left;
		actual->right->par = actual;
	}

	else
	{
		actual->right = NULL;
	}

	actual->par->left = actual;
}

void TreeAVL::derechaIzquierda(Node* actual)
{
	derecha(actual);
	izquierda(actual->par->par);
}

void TreeAVL::quitar(Node* actual)
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

void TreeAVL::EnOrden(Node* actual, std::vector<int>& lista) const
{
	if (actual->left != NULL) EnOrden(actual->left, lista);
	lista.push_back(actual->value);
	if (actual->right != NULL) EnOrden(actual->right, lista);
}

void TreeAVL::InOrder(std::vector<int>& lista) const
{
	EnOrden(_root, lista);
}
