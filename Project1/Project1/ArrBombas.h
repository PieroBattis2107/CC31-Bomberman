
#ifndef __ARRBOMBAS_H__ 
#define __ARRBOMBAS_H__
#include <vector>  
#include "Lista.h"
#include "Bomba.h"
using namespace std;
class CArrBombas
{
public:
	CArrBombas() {
		arregloBombas = new Lista<CBomba*>;
		totalBombas = 1;
	}
	~CArrBombas() {}
	void crear_una_bomba(int x, int y) {
		if (arregloBombas->longitud() < totalBombas) {//limite de bombas
			arregloBombas->agregarFinal(new CBomba(x, y));
		}
	}
	void dibujar_una_bomba(Graphics^g, Bitmap^bmpBomba, Bitmap^bmpExplosion, int xJugador, int yJugador, int **matriz) {
		for (int i = 0; i < arregloBombas->longitud(); i++)
		{
			switch (arregloBombas->obtenerPos(i)->getEstado())
			{
			case Estado::normal:
				arregloBombas->obtenerPos(i)->dibujarBomba(g, bmpBomba, xJugador, yJugador, matriz);
				arregloBombas->obtenerPos(i)->animar();
				break;
			case Estado::explosion:
				arregloBombas->obtenerPos(i)->DibujarExplosion(g, bmpExplosion, matriz);
				arregloBombas->obtenerPos(i)->animarExplosion();
				break;
			case Estado::desaparecer:
				arregloBombas->eliminarPos(i);
				break;
			}
		}
	}
	Lista<CBomba*>* getarregloBombas() {
		return arregloBombas;
	}

	void setBombas(int v) {
		totalBombas = v;
	}
	int getBomba() {
		return totalBombas;
	}
	int guardar;
private:
	Lista<CBomba*>* arregloBombas;
	int totalBombas;
};

#endif // !__ARRBOMBAS_H__ 
