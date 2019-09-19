#ifndef _JUGADOR_H_
#define _JUGADOR_H_
using namespace System::Drawing;
enum Direcciones{Arriba, Abajo, Izquierda, Derecha, Ninguna};
class CJugador {
public:
	CJugador (int x, int y){
		//Posici�n del Jugador
		this->x = x; this->y = y;
		//Movimiento del Jugador
		dx = 0; dy = 0;
		// Animaci�n del Sprite
		ancho = 18; alto = 26;
		indiceX = 0; indiceY = 0;
		
		direccion = Direcciones::Ninguna;
		ultima = Direcciones::Abajo;
	}
	~CJugador (){} 
	int getX() { return x + 2 * 3; }
	int getY() { return y + 15 * 3 + dy; } 
	void setDx(int dx) {
		this->dx = dx;
	} 
	void setDY(int dy) {
		this->dy = dy;
	}
	Direcciones getDireccion() {
		return direccion;
	}

	void setDireccion(Direcciones direccionActual){
		direccion = direccionActual;
	}
	void ValidarMovimiento(int** matriz) {
		int X, Y = 0;
		for (int i = 0; i < filas; i++) {
			X = 0;
			for (int j = 0; j < columnas; j++) {
				Rectangle c1 = Rectangle(X, Y, 50, 50);
				if (matriz[i][j] == 1 || matriz[i][j] == 3) {
					if (CDI.IntersectsWith(c1)) dx = 0;
					if (CAA.IntersectsWith(c1)) dy = 0;
				}
				X += 50;
			}
			Y += 50;
		}
	}
	void dibujarJugador(Graphics^ g, Bitmap^ bmpJugador, int**matriz) {
		CDI = Rectangle(x + 2 * 3 + dx, y + 15 * 3, (ancho - 4) * 3, (alto - 15) * 3);
		CAA = Rectangle(x + 2 * 3, y + 15 * 3 + dy, (ancho - 4) * 3, (alto - 15) * 3);

		g->DrawRectangle(Pens::Transparent, CDI);
		g->DrawRectangle(Pens::Transparent, CAA);

		ValidarMovimiento(matriz);

		Rectangle PorcionAUsar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
		Rectangle Aumento = Rectangle(x, y, ancho*3, alto*3);
		g->DrawImage(bmpJugador, Aumento, PorcionAUsar, GraphicsUnit::Pixel);
		x += dx; y += dy;
	}	
	void moverJugador(Graphics^ g, Bitmap^ bmpJugador, int** matriz) {
		direccion == Arriba ? ancho = 17 : ancho = 18;
		switch (direccion) {
		case Direcciones::Arriba:
			indiceY = 0;
			if (indiceX >= 1 && indiceX < 3)
				indiceX++;
			else
				indiceX = 1;
			dx = 0; dy = -10;
			ultima = Arriba;
			break;
		case Direcciones::Abajo:
			indiceX = 0;
			if (indiceY >= 1 && indiceY < 3)
				indiceY++;
			else
				indiceY = 1;
			dx = 0; dy = 10;
			ultima = Abajo;
			break;
		case Direcciones::Izquierda:
			indiceY = 3;
			if (indiceX >= 1 && indiceX < 3)
				indiceX++;
			else
				indiceX = 1;
			dx = -10; dy = 0;
			ultima = Izquierda;
			break;
		case Direcciones::Derecha:
			indiceY = 1;
			if (indiceX >= 1 && indiceX < 3)
				indiceX++;
			else
				indiceX = 1;
			dx = 10; dy = 0;
			ultima = Derecha;
			break;
		case Direcciones::Ninguna:
			dx = dy = 0;
			if (ultima == Direcciones::Abajo) {
				indiceX = 0;
				indiceY = 2;
			}
			if (ultima == Direcciones::Arriba) {
				indiceX = 0;
				indiceY = 0;
			}
			if (ultima == Direcciones::Derecha) {
				indiceX = 1;
				indiceY = 1;
			}
			if (ultima == Direcciones::Izquierda) {
				indiceX = 1;
				indiceY = 3;
			}
			break;
		}
		dibujarJugador(g, bmpJugador, matriz);
	}
private:
	int x, y;
	int dx, dy;
	int ancho, alto;
	int indiceX, indiceY;
	Direcciones direccion;
	Direcciones ultima;

	Rectangle CDI;
	Rectangle CAA;
};

#endif //!_JUGADOR_H_ 