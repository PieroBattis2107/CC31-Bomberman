#ifndef __ARRENEMIGOS_H__
#define __ARRENEMIGOS_H__ 
#include "Enemigo.h" 
#include <vector>
using namespace std;
class CArrEnemigos
{
public: 
	CArrEnemigos(){ 
		arregloEnemigos = vector<CEnemigo*>();
	}
	~CArrEnemigos(){} 
	void crearEnemigos() {
		CEnemigo* nuevo = new CEnemigo(); 
		arregloEnemigos.push_back(nuevo);
	}
	void dibujar(Graphics^g, Bitmap^bmpEnemigo, int**matriz) {
		for (int i = 0; i < arregloEnemigos.size(); i++)
		{
			arregloEnemigos.at(i)->dibujar(g, bmpEnemigo, matriz); 
			arregloEnemigos.at(i)->animar();
		}
	}
	vector<CEnemigo*>getarregloEnemigos() {
		return arregloEnemigos;
	}
private: 
	vector<CEnemigo*>arregloEnemigos;
};

#endif // !__ARRENEMIGOS_H__
