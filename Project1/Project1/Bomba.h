#ifndef __BOMBA_H__ 
#define __BOMBA_H__  
using namespace System::Drawing;
enum Estado { normal, explosion, desaparecer, apagado };

class CBomba
{
public:
	CBomba(int x, int y) {
		this->x = x + 12;
		this->y = y + 26;
		estado = Estado::apagado;
		ancho = 66 / 3;
		alto = 24;
		indiceX = 0;
		tiempo_antes_de_explotar = 0;//contador 
									 //DATOS INCIALES PARA EL EXPLOSION 
		indiceEX = 0;
		indiceEY = 0;
		altoExplosion = 160 / 8;
		anchoExplosion = 80 / 4;
	}
	~CBomba() {}
	Rectangle Rectangulo() {
		return Rectangle(x, y, 40, 40);
	}
	//2 espacion donde puede caminar  
	//0 donde inica el jugador
	bool validarLugar(int xJugador, int yJugador, int **matriz) {
		if (matriz[yJugador / 50][xJugador / 50] == 0 || matriz[yJugador / 50][xJugador / 50] == 2)
			return true;
		else
			return false;
	}
	void setEstado(Estado estado) { this->estado = estado; }
	void dibujarBomba(Graphics^g, Bitmap^bmpBomba, int xJugador, int yJugador, int **matriz) {
		if (validarLugar(xJugador, yJugador, matriz) == true) {
			Rectangle porcionAUsar = Rectangle(indiceX *ancho, 0, ancho, alto);
			Rectangle aumento = Rectangle(x, y, 40, 40);
			g->DrawImage(bmpBomba, aumento, porcionAUsar, GraphicsUnit::Pixel);
		}
		//al bomba se animara 6 veces nates de explotar
		if (tiempo_antes_de_explotar == 6) { estado = Estado::explosion; }
	}
	void animar() {
		if (indiceX >= 0 && indiceX < 2)
			indiceX++;
		else
		{
			tiempo_antes_de_explotar++;
			indiceX = 0;
		}
	}

	void DibujarExplosion(Graphics ^g, Bitmap ^bmpExplosionCentro, int **matriz) {

		Rectangle porcionUsarCentro = Rectangle(indiceEX*anchoExplosion, indiceEY*altoExplosion, anchoExplosion, altoExplosion); // indiceY=0
		Rectangle centro = Rectangle(x, y, 50, 50);
		g->DrawImage(bmpExplosionCentro, centro, porcionUsarCentro, GraphicsUnit::Pixel);
		if (matriz[y / 50][(x - 50) / 50] != 1) {
			Rectangle porcionUsarIzquierda = Rectangle(indiceEX*anchoExplosion, indiceEY + 2 * altoExplosion, anchoExplosion, altoExplosion); //indiceY = 2
			Rectangle izquierda = Rectangle(x - 50, y, 50, 50);
			g->DrawImage(bmpExplosionCentro, izquierda, porcionUsarIzquierda, GraphicsUnit::Pixel);

			if (matriz[y / 50][(x - 50) / 50] == 3) { matriz[y / 50][(x - 50) / 50] = 2; }
		}
		if (matriz[y / 50][(x + 50) / 50] != 1) {
			Rectangle porcionUsarDerecha = Rectangle(indiceEX*anchoExplosion, indiceEY + 4 * altoExplosion, anchoExplosion, altoExplosion); //indiceY = 4
			Rectangle derecha = Rectangle(x + 50, y, 50, 50);
			g->DrawImage(bmpExplosionCentro, derecha, porcionUsarDerecha, GraphicsUnit::Pixel);

			if (matriz[y / 50][(x + 50) / 50] == 3) { matriz[y / 50][(x + 50) / 50] = 2; }

		}
		if (matriz[y / 50][(x + 50) / 50] != 1) {
			Rectangle porcionUsarPuntaDerecha = Rectangle(indiceEX*anchoExplosion, indiceEY + 3 * altoExplosion, anchoExplosion, altoExplosion); //indiceY = 3
			Rectangle Puntaderecha = Rectangle(x + 100, y, 50, 50);
			g->DrawImage(bmpExplosionCentro, Puntaderecha, porcionUsarPuntaDerecha, GraphicsUnit::Pixel);

			if (matriz[y / 50][(x + 100) / 50] == 3 && matriz[y / 50][(x + 50) / 50] != 1)
			{

				matriz[y / 50][(x + 100) / 50] = 2;
			}
		}

		if (matriz[y / 50][(x - 50) / 50] != 1) {
			Rectangle porcionUsarPuntaIzquierda = Rectangle(indiceEX*anchoExplosion, indiceEY + 1 * altoExplosion, anchoExplosion, altoExplosion); //indiceY = 1
			Rectangle Puntaizquierda = Rectangle(x - 100, y, 50, 50);
			g->DrawImage(bmpExplosionCentro, Puntaizquierda, porcionUsarPuntaIzquierda, GraphicsUnit::Pixel);

			if (matriz[y / 50][(x - 100) / 50] == 3 && matriz[y / 50][(x - 50) / 50] != 1)
			{
				matriz[y / 50][(x - 100) / 50] = 2;
			}
		}

		Rectangle porcionUsarVerticales = Rectangle(indiceEX*anchoExplosion, indiceEY + 6 * altoExplosion, anchoExplosion, altoExplosion); //indiceY = 1
		Rectangle VerticalSuperior = Rectangle(x, y - 50, 50, 50);
		Rectangle VerticalInferior = Rectangle(x, y + 50, 50, 50);

		if (matriz[(y - 50) / 50][x / 50] != 1) { g->DrawImage(bmpExplosionCentro, VerticalSuperior, porcionUsarVerticales, GraphicsUnit::Pixel); }
		if (matriz[(y - 50) / 50][x / 50] == 3) { matriz[(y - 50) / 50][x / 50] = 2; }
		if (matriz[(y + 50) / 50][x / 50] != 1) { g->DrawImage(bmpExplosionCentro, VerticalInferior, porcionUsarVerticales, GraphicsUnit::Pixel); }
		if (matriz[(y + 50) / 50][x / 50] == 3) { matriz[(y + 50) / 50][x / 50] = 2; }


		if (matriz[(y - 50) / 50][x / 50] != 1) {
			Rectangle porcionUsarPuntaSuperior = Rectangle(indiceEX*anchoExplosion, indiceEY + 5 * altoExplosion, anchoExplosion, altoExplosion); //indiceY = 5
			Rectangle PuntaSuperior = Rectangle(x, y - 100, 50, 50);
			g->DrawImage(bmpExplosionCentro, PuntaSuperior, porcionUsarPuntaSuperior, GraphicsUnit::Pixel);

			if (matriz[(y - 100) / 50][x / 50] == 3 && matriz[(y - 50) / 50][x / 50] != 1) { matriz[(y - 100) / 50][x / 50] = 2; }
		}


		if (matriz[(y + 50) / 50][x / 50] != 1) {
			Rectangle porcionUsarPuntaInferior = Rectangle(indiceEX*anchoExplosion, indiceEY + 7 * altoExplosion, anchoExplosion, altoExplosion); //indiceY = 7
			Rectangle PuntaInferior = Rectangle(x, y + 100, 50, 50);
			g->DrawImage(bmpExplosionCentro, PuntaInferior, porcionUsarPuntaInferior, GraphicsUnit::Pixel);
			if (matriz[(y + 100) / 50][x / 50] == 3 && matriz[(y + 50) / 50][x / 50] != 1) {
				matriz[(y + 100) / 50][x / 50] = 2;
			}
		}
	}
	void animarExplosion() {
		if (indiceEX >= 0 && indiceEX < 3)
			indiceEX++;
		else
		{
			estado = Estado::desaparecer;
		}
	}

	Estado getEstado() {
		return estado;
	}

	int getX() {
		return x;
	}
	int getY() {
		return y;
	}

	void setX(int v) {
		x = v;
	}

	void setY(int v) {
		y = v;
	}

	void settiempo(int p) {
		tiempo_antes_de_explotar = p;
	}

private://datos de la explosion 
	int indiceEX;
	int indiceEY;

	int altoExplosion;
	int anchoExplosion;

private: //datos de la bomba
	int x;
	int y;

	int ancho;
	int alto;
	int largo;

	int indiceX;//no hay en eje y solo en x 

	int tiempo_antes_de_explotar;

	Estado estado;

};





#endif