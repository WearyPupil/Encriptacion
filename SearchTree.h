#pragma once

#include "LinkedBinaryTree.h"

template <typename K, typename V>
class Entry										//Un par de valor y llave
{
public:											//Tipos p�blicos
	typedef K key;								//Tipo Key
	typedef V Value;							//Tipo Value
public:											//Funciones p�blicas
	Entry(const K& k = K(), const V& v = V())   //Constructor
		: _key(k), _value(v) { }
	const K& key() const { return _key; }		//Acceder a la llave (solo lectura)
	const V& value() const { return _value; }   //Acceder al valor (solo lectura)
	void setKey(const K& k) { _key = k; }       //Cambiar llave
	void setValue(const V& v) { _value = v; }   //Cambiar valor
private:										//valores privados
	K _key;										//llave
	V _value;									//valor
};

template <typename E>
class SearchTree								//�rbol Binario de B�squeda
{
public:											//Tipos p�blicos
	typedef typename E::Key K;					//Una llave
	typedef typename E::Value V;				//Un valor
	class Iterator;								//Un iterador/posici�n
public:
	SearchTree();								//Constructor
	int size() const;							//N�mero de entradas
	bool empty() const;							//�Se encuentra vaci� el �rbol?
	Iterator find(const K& k);					//Encontrar la entrada con llave k
	Iterator insert(const K& k, const V& x);	//insertar (k,x)
	void erase(const K& k) throw(NonexistentElement); //Remover la llave en la entrada k
	void erase(const Iterator& p);				//Remover entrada en p
	Iterator begin();							//Iterador al primer elemento
	Iterator end();								//Iterador al �ltimo elemento
protected:										//Utilidades locales
	typedef LinkedBinaryTree BinaryTree;			//LinkedBinaryTree
	typedef typename BinaryTree::Position TPos;	//Posici�n en el �rbol
	TPos root() const;							//Obtener ra�z virtual
	TPos finder(const K& k, const TPos& v);		//Utilidad encontrar
	TPos inserter(const K& k, const V& x);		//Utilidad insertar
	TPos eraser(TPos& v);						//Utilidad eliminar
	TPos restructure(const TPos& v)				//Utilidad reestructurar
		throw(BoundaryViolation);
private:										//Datos privados
	BinaryTree T;								//�rbol binario
	int n;										//N�mero de entradas
public:
	class Iterator								//Iterador/posici�n
	{
	private:
		TPos v;									//Entrada
	public:
		Iterator(const TPos& vv) : v(vv) { }	//Constructor
		const E& operator*() const { return *v; } //Acceder a entrada (solo lectura)
		E& operator*() { return *v; }			//Accedar a la entrada (lectura/escritura)
		bool operator==(const Iterator& p) const	// �Son iteradores iguales?
			{ return v == p.v; }				
		Iterator& operator++();					//Sucesor en orden
		friend class SearchTree;				//Dar acceso a SearchTree
	};
};