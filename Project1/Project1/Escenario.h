#ifndef __ESCENARIO_H__
#define __ESCENARIO_H__
#include <ctime>
#include <stdlib.h>
#define filas 15
#define columnas 17
using namespace System::Drawing;
class CEscenario
{
public:
	CEscenario() {
		matriz = new int*[filas];
	}
	~CEscenario() {};

	void generarMatriz() {
		srand(time(NULL()));
		for (int i = 0; i < filas; i++)
		{
			matriz[i] = new int[columnas];
		}
		for (int i = 0; i < filas; i++)
		{
			for (int j = 0; j < columnas; j++)
			{
				if (i == 0 || j == 0 || i == filas - 1 || j == columnas - 1)//Bordes
					matriz[i][j] = 1;

				else {
					if (i % 2 == 0 && j % 2 == 0)
						matriz[i][j] = 1;
					else {
						if ((i == 1 && (j == 1 || j == 2)) || (j == 1 && i == 2) || (i == filas - 2 && (j == columnas - 3 || j == columnas - 2)) || (i == filas - 3 && j == columnas - 2))//zona para moverse
							matriz[i][j] = 0;
						else
							matriz[i][j] = rand() % 2 + 2;
					}
				}
			}
		}
	}
	void PintarBase(Graphics^g, Bitmap^bmpBase) {
		int X, Y = 0;
		for (int i = 0; i < filas; i++)
		{
			X = 0;
			for (int j = 0; j < columnas; j++) {
				if (matriz[i][j] == 0 || matriz[i][j] == 2)
					g->DrawImage(bmpBase, X, Y, 50, 50);
				X += 50;
			}
			Y += 50;
		}
	}

	void PintarMatriz(Graphics^g, Bitmap^bmpSolido, Bitmap^bmpDestruible) {
		int X, Y = 0;
		for (int i = 0; i < filas; i++)
		{
			X = 0;
			for (int j = 0; j < columnas; j++) {

				if (matriz[i][j] == 1)
					g->DrawImage(bmpSolido, X, Y, 50, 50);
				else {
					if (matriz[i][j] == 3)
						g->DrawImage(bmpDestruible, X, Y, 50, 50);
				}
				X += 50;
			}
			Y += 50;
		}
	}
	int **getmatriz() {
		return matriz;
	}

private:
	int **matriz;
};



#endif // !__ESCENARIO_H__

