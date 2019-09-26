#pragma once
#include<iostream>
#include<functional>
using namespace std;
typedef unsigned int uint;
template<typename T, T NADA = 0 >
class Lista {
	struct Nodo;
	typedef function<int(T, T)> Comp;
	Nodo* ini;
	uint lon;
	Comp comparar;
public:
	Lista() : ini(nullptr), lon(0), comparar([](T a, T b) {return a - b; }) {}
	Lista(Comp comparar) : ini(nullptr), lon(0), comparar(comparar) {}
	~Lista();
	uint longitud();
	bool esVacia();
	void agregarInicial(T elem);
	void agregarPos(T elem, uint pos);
	void agregarFinal(T elem);
	void modificarInicial(T elem);
	void modificarPos(T elem, uint pos);
	void modificarFinal(T elem);
	void eliminarInicial();
	void eliminarPos(uint pos);
	void eliminarFinal();
	T obtenerInicial();
	T obtenerPos(uint pos);
	T obtenerFinal();
	T buscar(T elem);
};
template<typename T, T NADA>
struct Lista<T, NADA>::Nodo {
	T     elem;
	Nodo* sig;
	Nodo(T elem = NADA, Nodo* sig = nullptr) : elem(elem), sig(sig) {}
};
template<typename T, T NADA>
Lista<T, NADA>::~Lista() {
	Nodo* aux = ini;
	while (aux != nullptr) {
		aux = ini;
		ini = ini->sig;
		delete aux;
	}
}
template<typename T, T NADA>
uint Lista<T, NADA>::longitud() {
	return lon;
}
template<typename T, T NADA>
bool Lista<T, NADA>::esVacia() {
	return lon == 0;
}
template<typename T, T NADA>
void Lista<T, NADA>::agregarInicial(T elem) {
	Nodo* nuevo = new Nodo(elem, ini);
	if (nuevo != nullptr) {
		ini = nuevo;
		lon++;
	}
}
template<typename T, T NADA>
void Lista<T, NADA>::agregarPos(T elem, uint pos) {
	if (pos > lon) return;
	else if (pos == 0) {
		agregarInicial(elem);
	}
	else {
		Nodo* aux = ini;
		for (int i = 1; i < pos; i++) {
			aux = aux->sig;
		}
		Nodo* nuevo = new Nodo(elem, aux->sig);
		if (nuevo != nullptr)
		{
			aux->sig = nuevo;
			lon++;
		}
	}
}
template<typename T, T NADA>
void Lista<T, NADA>::agregarFinal(T elem) {
	if (lon >= 0) {
		agregarPos(elem, lon);
	}
}
template<typename T, T NADA>
void Lista<T, NADA>::modificarFinal(T elem) {
	if (lon > 0) {
		ini->elem = elem;
	}
}
template<typename T, T NADA>
void Lista<T, NADA>::modificarPos(T elem, uint pos) {
	if (pos >= 0 && pos < lon) {
		Nodo* aux = ini;
		for (int i = 0; i < pos; i++) {
			aux = aux->sig;
		}
		aux->elem = elem;
	}
}
template<typename T, T NADA>
void Lista<T, NADA>::eliminarInicial() {
	if (lon > 0) {
		Nodo* aux = ini;
		ini = ini->sig;
		delete aux;
		lon--;
	}
}
template<typename T, T NADA>
void Lista<T, NADA>::eliminarPos(uint pos) {
	if (lon > 0) {
		if (pos == 0) {
			eliminarInicial();
		}
		if (pos < lon) {
			Nodo* aux = ini;
			Nodo* aux2 = aux;
			for (int i = 0; i < pos - 1; i++) {
				aux = aux->sig;
				if (i < pos - 2) aux2 = aux2->sig;
			}
			aux2->sig = aux2->sig->sig;
			delete aux;
			lon--;
		}
	}
}
template<typename T, T NADA>
void Lista<T, NADA>::eliminarFinal() {
	eliminarPos(lon);
}
template<typename T, T NADA>
T Lista<T, NADA>::obtenerInicial() {
	return obtenerPos(0);
}
template<typename T, T NADA>
T Lista<T, NADA>::obtenerPos(uint pos) {
	if (pos >= 0 && pos < lon) {
		Nodo* aux = ini;
		for (int i = 0; i < pos; i++) {
			aux = aux->sig;
		}
		return aux->elem;
	}
	else {
		return NADA;
	}
}
template<typename T, T NADA>
T Lista<T, NADA>::obtenerFinal() {
	return obtenerPos(lon - 1);
}
template<typename T, T NADA>
T Lista<T, NADA>::buscar(T elem) {
	Nodo* aux = ini;
	while (aux != nullptr) {
		if (comparar(aux->elem, elem) == 0) {
			return aux->elem;
		}
		aux = aux->sig;
	}
	return NADA;
}
