#include <iostream>
#include <string>
#include <cmath>    //Floor
#include <stdlib.h> //CLS, Pause
#include "LinkedBinarySearchTree.h"
#include "TreeAVL.h"

typedef LinkedBinarySearchTree ABB; //Conveniencia
typedef TreeAVL AVL; //Conveniencia

//Logo
void logo()
{
	std::cout << "   _____                  _         " << std::endl;
	std::cout << "  / ____|                | |        " << std::endl;
	std::cout << " | |     _ __ _   _ _ __ | |_ ___   " << std::endl;
	std::cout << " | |    | '__| | | | '_ \| __/ _ \  " << std::endl;
	std::cout << " | |____| |  | |_| | |_) | || (_) | " << std::endl;
	std::cout << "101010100101010101010100101010100101" << std::endl;
	std::cout << "               __/ | |              " << std::endl;
	std::cout << "              |___/|_|              " << std::endl;
	std::cout << std::endl;
	std::cout << "Bienvenido a Crypto" << std::endl;
	std::cout << std::endl;
}

// Ecriptar cadena con ABB
void encriptarConABB()
{
	// Pedir cadena al usuario
	std::cout << "Ingrese una cadena de caracteres a encriptar" << std::endl;
	std::string cadena;
	std::getline(std::cin, cadena);

	system("CLS");

	// Enseñar cadena de caracteres en ASCII al usuario
	std::cout << "Su cadena de caracteres en ASCII es:" << std::endl;
	std::cout << "[ ";
	for (unsigned int i = 0; i < cadena.size(); i++)
	{
		std::cout << int(cadena[i]) << " ";
		// Encriptar cadena sumando la posición relativa
		cadena[i] = cadena[i] + (i + 1);
	}
	std::cout << ']' << std::endl;

	// Enseñar cadena de caracteres en ASCII al usuario
	std::cout << std::endl;
	std::cout << "Su cadena de caracteres en ASCII despues de sumar la posicion relativa:" << std::endl;
	std::cout << "[ ";
	for (int i : cadena)
	{
		std::cout << i << " ";
	}
	std::cout << ']';

	std::cout << std::endl << std::endl;

	std::cout << "La cadena de caracteres resultante es:" << std::endl;
	std::cout << cadena << std::endl << std::endl;
	system("pause");

	// Construir un arbol binario de busqueda con estos valores

	
	ABB abb = ABB();

	for (char n : cadena)
	{
		abb.push(int(n));
	}

	std::vector<int> resultado;
	abb.InOrder(resultado);
	

	std::string crypteado;

	for (int n : resultado)
	{
		crypteado += char(n);
	}

	system("CLS");
	std::cout << "Su cadena de caracteres InOrder es:" << std::endl;
	std::cout << crypteado << std::endl << std::endl;

	std::cout << "En ASCII:" << std::endl;
	std::cout << "[ ";
	for (int n : crypteado)
	{
		std::cout << n << " ";
	}
	std::cout << "]" << std::endl << std::endl;
	system("pause");

	std::vector<int> llave;

	std::string morfismo = cadena;

	for (char c : crypteado)
	{ 
		for (unsigned int i = 0; i < morfismo.size(); i++)
		{
			if (c == morfismo[i])
			{
				llave.push_back(i + 1);
				morfismo[i] = '♔';
				break;
			}
		}
	}

	system("CLS");
	std::cout << "Su llave es:" << std::endl;
	std::cout << "[ ";
	for (int i : llave)
	{
		std::cout << i << " ";
	}
	std::cout << "]" << std::endl << std::endl;
	
	system("Pause");
	// Proteccion

	system("CLS");
	std::cout << "Como mecanismo de proteccion se eliminara el siguiente elemento del arbol" << std::endl;
	std::cout << cadena[(llave[std::floor((cadena.size() - 1) / 2)])-1] << std::endl << std::endl;
	std::cout << "Valor en ASCII" << std::endl;
	std::cout << int(cadena[(llave[std::floor((cadena.size() - 1) / 2)])-1]) << std::endl << std::endl;
	abb.remove(int(cadena[(llave[std::floor((cadena.size() - 1) / 2)]) - 1]));

	system("pause");

	system("CLS");

	// Preorden despues del borrado

	std::vector<int> final;

	abb.InOrder(final);
	
	std::string ultimo;

	for (int n : final)
	{
		ultimo += char(n);
	}

	std::cout << "Su cadena de caracteres InOrder despues del borrado es" << std::endl;
	std::cout << ultimo << std::endl << std::endl;

	std::cout << "En ASCII" << std::endl << std::endl;
	
	std::cout << "[ ";
	for (int n : final)
	{
		std::cout << n << " ";
	}
	std::cout << "]" << std::endl << std::endl;
	system("pause");

}

void encriptarConAVL()
{
	// Pedir cadena al usuario
	std::cout << "Ingrese una cadena de caracteres a encriptar" << std::endl;
	std::string cadena;
	std::getline(std::cin, cadena);

	system("CLS");

	// Enseñar cadena de caracteres en ASCII al usuario
	std::cout << "Su cadena de caracteres en ASCII es:" << std::endl;
	std::cout << "[ ";
	for (unsigned int i = 0; i < cadena.size(); i++)
	{
		std::cout << int(cadena[i]) << " ";
		// Encriptar cadena sumando la posición relativa
		cadena[i] = cadena[i] + (i + 1);
	}
	std::cout << ']' << std::endl;

	// Enseñar cadena de caracteres en ASCII al usuario
	std::cout << std::endl;
	std::cout << "Su cadena de caracteres en ASCII despues de sumar la posicion relativa:" << std::endl;
	std::cout << "[ ";
	for (int i : cadena)
	{
		std::cout << i << " ";
	}
	std::cout << ']';

	std::cout << std::endl << std::endl;

	std::cout << "La cadena de caracteres resultante es:" << std::endl;
	std::cout << cadena << std::endl << std::endl;
	system("pause");

	// Construir un arbol binario de busqueda con estos valores


	AVL abb = AVL();

	for (char n : cadena)
	{
		abb.push(int(n));
	}

	std::vector<int> resultado;
	abb.InOrder(resultado);


	std::string crypteado;

	for (int n : resultado)
	{
		crypteado += char(n);
	}

	system("CLS");
	std::cout << "Su cadena de caracteres InOrder es:" << std::endl;
	std::cout << crypteado << std::endl << std::endl;

	std::cout << "En ASCII:" << std::endl;
	std::cout << "[ ";
	for (int n : crypteado)
	{
		std::cout << n << " ";
	}
	std::cout << "]" << std::endl << std::endl;
	system("pause");

	std::vector<int> llave;

	std::string morfismo = cadena;

	for (char c : crypteado)
	{
		for (unsigned int i = 0; i < morfismo.size(); i++)
		{
			if (c == morfismo[i])
			{
				llave.push_back(i + 1);
				morfismo[i] = '♔';
				break;
			}
		}
	}

	system("CLS");
	std::cout << "Su llave es:" << std::endl;
	std::cout << "[ ";
	for (int i : llave)
	{
		std::cout << i << " ";
	}
	std::cout << "]" << std::endl << std::endl;

	system("Pause");
	// Proteccion

	system("CLS");
	std::cout << "Como mecanismo de proteccion se eliminara el siguiente elemento del arbol" << std::endl;
	std::cout << cadena[(llave[std::floor((cadena.size() - 1) / 2)]) - 1] << std::endl << std::endl;
	std::cout << "Valor en ASCII" << std::endl;
	std::cout << int(cadena[(llave[std::floor((cadena.size() - 1) / 2)]) - 1]) << std::endl << std::endl;
	abb.remove(int(cadena[(llave[std::floor((cadena.size() - 1) / 2)]) - 1]));

	system("pause");

	system("CLS");

	// Preorden despues del borrado

	std::vector<int> final;

	abb.InOrder(final);

	std::string ultimo;

	for (int n : final)
	{
		ultimo += char(n);
	}

	std::cout << "Su cadena de caracteres InOrder despues del borrado es" << std::endl;
	std::cout << ultimo << std::endl << std::endl;

	std::cout << "En ASCII" << std::endl << std::endl;

	std::cout << "[ ";
	for (int n : final)
	{
		std::cout << n << " ";
	}
	std::cout << "]" << std::endl << std::endl;
	system("pause");
}

void desencriptar()
{
	// Pedir cadena al usuario
	std::cout << "Ingrese una cadena de caracteres a desencriptar" << std::endl;
	std::string crypteado;
	std::getline(std::cin, crypteado);

	system("CLS");

	//Ingresar llave
	std::cout << "Ingrese los numeros de la llave separados por la tecla enter" << std::endl;

	int entrada;

	std::vector<int> llave;
	
	for (unsigned int i = 0; i < crypteado.size(); i++) 
	{
		std::cin >> entrada;
		llave.push_back(entrada);
	}

	system("CLS");
	// Imprimir llave y cadena de caracteres

	std::cout << "Su llave es:" << std::endl;
	std::cout << "[ ";
	for (int i : llave)
	{
		std::cout << i << " ";
	}
	std::cout << ']';

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Su cadena de caracteres es:" << std::endl;
	std::cout << crypteado << std::endl << std::endl;

	system("pause");
	system("CLS");

	std::string cadena = crypteado;

	for (unsigned int i = 0; i < crypteado.size(); i++)
	{
		cadena[(llave[i] - 1)] = crypteado[i];
	}

	std::cout << "Su cadena despues de mappear con la llave es:" << std::endl;
	std::cout << cadena << std::endl << std::endl;

	std::cout << "Su cadena de caracteres en ASCII es:" << std::endl;
	std::cout << "[ ";
	for (unsigned int i = 0; i < cadena.size(); i++)
	{
		std::cout << int(cadena[i]) << " ";
		// Desencriptar cadena sumando la posición relativa
		cadena[i] = cadena[i] - (i + 1);
	}
	std::cout << ']' << std::endl;

	std::cout << std::endl;
	std::cout << "Su cadena de caracteres en ASCII despues de restar la posicion relativa:" << std::endl;
	std::cout << "[ ";
	for (int i : cadena)
	{
		std::cout << i << " ";
	}
	std::cout << ']';

	std::cout << std::endl << std::endl;

	std::cout << "La cadena de caracteres resultante es:" << std::endl;
	std::cout << cadena << std::endl << std::endl;
	system("pause");
	system("CLS");

}

int main()
{
	bool activo = true;

	while (activo)
	{
		logo();
		std::cout << "Que desea hacer?" << std::endl << std::endl;
		std::cout << "\ta encriptar con ABB" << std::endl;
		std::cout << "\tb encriptar con AVL" << std::endl;
		std::cout << "\tc desencriptar" << std::endl;
		std::cout << "\te salir" << std::endl;

		std::string seleccion;

		std::getline(std::cin, seleccion);
		std::cout << "\n" << std::endl;

		if (seleccion == "a")
		{
			system("CLS");
			encriptarConABB();
			system("CLS");
		}

		else if (seleccion == "b")
		{
			system("CLS");
			encriptarConAVL();
			system("CLS");
		}

		else if (seleccion == "c")
		{
			system("CLS");
			desencriptar();
			system("CLS");
		}

		else if (seleccion == "e")
		{
			activo = false;
		}

		else
		{
			system("CLS");
			std::cout << "Por favor, ingrese un comando valido" << std::endl;
			system("pause");
			system("CLS");
		}
	}	
}