#ifndef __ARRMEJORAS_H__
#define __ARRMEJORAS_H__
#include "Mejora.h"
#include <vector>
#include "Lista.h"
using namespace std;
class CArrMejoras {
public:
	CArrMejoras() {
		lista_mejoras = new Lista<CMejora*>;
	}
	~CArrMejoras() {}
	void crearMejoras() {
		CMejora* nueva_mejora = new CMejora();
		lista_mejoras->agregarFinal(nueva_mejora);
	}
	void dibujar(Graphics^ g, Bitmap^ bmpMejoras, int** matriz) {
		for (int i = 0; i < lista_mejoras->longitud(); i++) {
			lista_mejoras->obtenerPos(i)->dibujar(g, bmpMejoras, matriz);
			lista_mejoras->obtenerPos(i)->animar();
		}
	}
	Lista<CMejora*>* getvector_mejoras() {
		return lista_mejoras;
	}
private:
	Lista<CMejora*>* lista_mejoras;
};

#endif // !__ARRMEJORAS_H__

