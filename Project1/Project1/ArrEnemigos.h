#ifndef __ARRENEMIGOS_H__
#define __ARRENEMIGOS_H__ 
#include "Enemigo.h" 
#include <vector>
#include "Lista.h"
using namespace std;
class CArrEnemigos
{
public:
	CArrEnemigos() {
		arregloEnemigos = new Lista<CEnemigo*>;
	}
	~CArrEnemigos() {}
	void crearEnemigos() {
		arregloEnemigos->agregarFinal(new CEnemigo());
	}
	void dibujar(Graphics^g, Bitmap^bmpEnemigo, int**matriz) {
		for (int i = 0; i < arregloEnemigos->longitud(); i++)
		{
			arregloEnemigos->obtenerPos(i)->dibujar(g, bmpEnemigo, matriz);
			arregloEnemigos->obtenerPos(i)->animar();
		}
	}
	Lista<CEnemigo*>* getarregloEnemigos() {
		return arregloEnemigos;
	}
private:
	Lista<CEnemigo*>* arregloEnemigos;
};

#endif // !__ARRENEMIGOS_H__
