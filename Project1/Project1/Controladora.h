#ifndef __CONTROLADORA_H__
#define __CONTROLADORA_H__
#include "Escenario.h"
#include "Jugador.h" 
#include "ArrBombas.h"
#include "ArrMejoras.h" 
#include "ArrEnemigos.h"
class CControladora
{
public:
	CControladora() {
		oEscenario = new CEscenario();
		oJugador = new CJugador(50, 50); 
		oArrBombas = new CArrBombas();
		oArrMejoras = new CArrMejoras(); 
		oArrEnemigos = new CArrEnemigos();
		nivel = 1;
	}
	~CControladora() {}
	void CambiarNivel() {
		oEscenario->generarMatriz();
	} 
	void agregarBomba() {
		oArrBombas->crear_una_bomba(oJugador->getX(), oJugador->getY());
	} 

	void disminuir_Vidas_Por_Enemigo(){  
		for (int i = 0; i < oArrEnemigos->getarregloEnemigos().size(); i++)
		{
			if (oJugador->retornarRectangulo().IntersectsWith(oArrEnemigos->getarregloEnemigos().at(i)->retornarRectangulo()))
				oJugador->disminuirvidas();
		}
	}
	void disminuir_vidas_Por_Bomba(){ 
		int PuntaIzquierda, PuntaDerecha, CentroInicioY, CentroFinalY,
			PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX;
		for (int i = 0; i < oArrBombas->getarregloBombas().size(); i++)
		{
			PuntaIzquierda = oArrBombas->getarregloBombas().at(i)->getX() - 100;
			PuntaDerecha = oArrBombas->getarregloBombas().at(i)->getX() + 150;
			PuntaSuperior = oArrBombas->getarregloBombas().at(i)->getY() - 100;
			PuntaInferior = oArrBombas->getarregloBombas().at(i)->getY() + 150;
			CentroInicioY = oArrBombas->getarregloBombas().at(i)->getY() + 150;
			CentroInicioX = oArrBombas->getarregloBombas().at(i)->getX();
			CentroFinalX = oArrBombas->getarregloBombas().at(i)->getX() + 50;
			CentroFinalY = oArrBombas->getarregloBombas().at(i)->getX() + 50;

			if (oArrBombas->getarregloBombas().at(i)->getEstado() == Estado::explosion)
			{
				oJugador->disminuirvidas(PuntaIzquierda, PuntaDerecha, CentroInicioY, CentroFinalY,
					PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX);
			}
		}
	}

	void dibujar(Graphics^ g, Bitmap^bmpBase, Bitmap^bmpSolido, Bitmap^bmpBomba, Bitmap^bmpExplosion, Bitmap^bmpDestruible, 
		Bitmap^bmpJugador, Bitmap^ bmpMejoras, Bitmap^ bmpEnemigo) {
		oEscenario->PintarBase(g, bmpBase);
		oArrMejoras->dibujar(g, bmpMejoras, oEscenario->getmatriz());
		oEscenario->PintarMatriz(g, bmpSolido, bmpDestruible);
		oJugador->moverJugador(g, bmpJugador, oEscenario->getmatriz()); 
		oArrBombas->dibujar_una_bomba(g, bmpBomba, bmpExplosion, oJugador->getX(), oJugador->getY(), oEscenario->getmatriz());
		oArrEnemigos->dibujar(g, bmpEnemigo, oEscenario->getmatriz ());
	  
		disminuir_vidas_Por_Bomba();
		disminuir_Vidas_Por_Enemigo();
		
	} 
	void crear_enemigos_y_mejoras() {
		oArrEnemigos->crearEnemigos();
		oArrMejoras->crearMejoras();
	} 
	


	CJugador *getoJugador() {
		return oJugador;
	}
	CArrMejoras* getArrMejoras(){
		return oArrMejoras;
	}
	int getNivel() {
		return nivel;
	} 
	CArrEnemigos*getoArrEnemigos (){  
		return oArrEnemigos;
	} 

	
private:
	CEscenario *oEscenario;
	CJugador* oJugador; 
	CArrBombas *oArrBombas;
	CArrMejoras* oArrMejoras; 
	CArrEnemigos* oArrEnemigos;
	int nivel;
};



#endif // !__CONTROLADORA_H__

