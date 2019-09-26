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
		//oArrBombas = new CArrBombas();
		oArrMejoras = new CArrMejoras();
		oArrEnemigos = new CArrEnemigos();
		nivel = 1;
		habilidad = false;
	}
	~CControladora() {}
	void CambiarNivel() {
		oEscenario->generarMatriz();
	}
	void prendela() {
		//oArrBombas->crear_una_bomba(oJugador->getX(), oJugador->getY());
		//oJugador->getBomba()->pop();
	}

	void disminuir_Vidas_Por_Enemigo() {
		for (int i = 0; i < oArrEnemigos->getarregloEnemigos()->longitud(); i++)
		{
			if (oJugador->retornarRectangulo().IntersectsWith(oArrEnemigos->getarregloEnemigos()->obtenerPos(i)->retornarRectangulo()))
				oJugador->disminuirvidas();
		}
	}
	void disminuir_vidas_Por_Bomba() {
		int PuntaIzquierda, PuntaDerecha, CentroInicioY, CentroFinalY,
			PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX;
		for (int i = 0; i < oArrBombas->getarregloBombas()->longitud(); i++)
		{
			PuntaIzquierda = oArrBombas->getarregloBombas()->obtenerPos(i)->getX() - 100;
			PuntaDerecha = oArrBombas->getarregloBombas()->obtenerPos(i)->getX() + 150;
			PuntaSuperior = oArrBombas->getarregloBombas()->obtenerPos(i)->getY() - 100;
			PuntaInferior = oArrBombas->getarregloBombas()->obtenerPos(i)->getY() + 150;
			CentroInicioY = oArrBombas->getarregloBombas()->obtenerPos(i)->getY() + 150;
			CentroInicioX = oArrBombas->getarregloBombas()->obtenerPos(i)->getX();
			CentroFinalX = oArrBombas->getarregloBombas()->obtenerPos(i)->getX() + 50;
			CentroFinalY = oArrBombas->getarregloBombas()->obtenerPos(i)->getX() + 50;

			if (oArrBombas->getarregloBombas()->obtenerPos(i)->getEstado() == Estado::explosion)
			{
				oJugador->disminuirvidas(PuntaIzquierda, PuntaDerecha, CentroInicioY, CentroFinalY,
					PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX);
			}
		}
	}
	/*void patear() {
	if (habilidad == true) {
	for (int i = 0; i < oArrBombas->getarregloBombas().size(); i++)
	{
	if (oArrBombas->getarregloBombas().at(i)->getEstado() == Estado::normal &&oJugador->retornarRectangulo().IntersectsWith(oArrBombas->getarregloBombas().at(i)->getRectangulo()))
	{
	if (oJugador->getDireccion() == Direcciones::Abajo && oEscenario->getValue((oArrBombas->getarregloBombas().at(i)->getY() + 50) / 50, (oArrBombas->getarregloBombas().at(i)->getX()) / 50) == 2) {
	oArrBombas->getarregloBombas().at(i)->setY(oArrBombas->getarregloBombas().at(i)->getY() + 50);
	oArrBombas->getarregloBombas().at(i)->settiempo(0);
	}
	if (oJugador->getDireccion() == Direcciones::Arriba&& oEscenario->getValue((oArrBombas->getarregloBombas().at(i)->getY() - 50) / 50, (oArrBombas->getarregloBombas().at(i)->getX()) / 50) == 2) {
	oArrBombas->getarregloBombas().at(i)->setY(oArrBombas->getarregloBombas().at(i)->getY() - 50);
	oArrBombas->getarregloBombas().at(i)->settiempo(0);
	}
	if (oJugador->getDireccion() == Direcciones::Derecha&& oEscenario->getValue((oArrBombas->getarregloBombas().at(i)->getY()) / 50, (oArrBombas->getarregloBombas().at(i)->getX() + 50) / 50) == 2) {
	oArrBombas->getarregloBombas().at(i)->setX(oArrBombas->getarregloBombas().at(i)->getX() + 50);
	oArrBombas->getarregloBombas().at(i)->settiempo(0);
	}
	if (oJugador->getDireccion() == Direcciones::Izquierda&& oEscenario->getValue((oArrBombas->getarregloBombas().at(i)->getY()) / 50, (oArrBombas->getarregloBombas().at(i)->getX() - 50) / 50) == 2) {
	oArrBombas->getarregloBombas().at(i)->setX(oArrBombas->getarregloBombas().at(i)->getX() - 50);
	oArrBombas->getarregloBombas().at(i)->settiempo(0);
	}
	}
	}
	}
	}*/

	/*void aggarraMejoras() {
	for (int i = 0; i < oArrMejoras->getvector_mejoras().size(); i++) {
	if (oJugador->retornarRectangulo().IntersectsWith(oArrMejoras->getvector_mejoras().at(i)->devolverR))
	{
	switch (oArrMejoras->getvector_mejoras().at(i)->getTipoMejora)
	{
	case 1://agrega bomba
	oArrBombas->setBombas(oArrBombas->getBomba() + 1); break;
	//case 2://mover
	//habilidad = true; break;
	case 3://disminuye vida
	oJugador->setVidas(oJugador->getVidas() - 1); break;
	case 4://patines
	oJugador->setAcelera(oJugador->getAcelera() + 3); break;
	case 5://Mas vidas
	oJugador->setVidas(oJugador->getVidas() + 1); break;
	default:
	break;
	}
	}
	}
	}*/

	void dibujar(Graphics^ g, Bitmap^bmpBase, Bitmap^bmpSolido, Bitmap^bmpBomba, Bitmap^bmpExplosion, Bitmap^bmpDestruible,
		Bitmap^bmpJugador, Bitmap^ bmpMejoras, Bitmap^ bmpEnemigo) {
		oEscenario->PintarBase(g, bmpBase);
		oArrMejoras->dibujar(g, bmpMejoras, oEscenario->getmatriz());
		oEscenario->PintarMatriz(g, bmpSolido, bmpDestruible);
		oJugador->moverJugador(g, bmpJugador, oEscenario->getmatriz());

		oJugador->drawBomba(g, bmpBomba, bmpExplosion, oJugador->getX(), oJugador->getY(), oEscenario->getmatriz());
		prendela();

		//oArrBombas->dibujar_una_bomba(g, bmpBomba, bmpExplosion, oJugador->getX(), oJugador->getY(), oEscenario->getmatriz());
		oArrEnemigos->dibujar(g, bmpEnemigo, oEscenario->getmatriz());

		//disminuir_vidas_Por_Bomba();
		//disminuir_Vidas_Por_Enemigo();

		//aggarraMejoras();
		//patear();

	}
	void crear_enemigos_y_mejoras() {
		oArrEnemigos->crearEnemigos();
		oArrMejoras->crearMejoras();
	}



	CJugador *getoJugador() {
		return oJugador;
	}
	CArrMejoras* getArrMejoras() {
		return oArrMejoras;
	}
	int getNivel() {
		return nivel;
	}
	CArrEnemigos*getoArrEnemigos() {
		return oArrEnemigos;
	}



private:
	CEscenario *oEscenario;
	CJugador* oJugador;
	CArrBombas *oArrBombas;
	CArrMejoras* oArrMejoras;
	CArrEnemigos* oArrEnemigos;
	int nivel;
	bool habilidad;
};



#endif // !__CONTROLADORA_H__

