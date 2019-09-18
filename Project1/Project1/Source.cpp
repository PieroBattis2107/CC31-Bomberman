#include <conio.h>
#include <iostream>
#include "Juego.h"

using namespace System;
using namespace std;
using namespace Project1;

void main(){
	Application::EnableVisualStyles();
	Application::Run(gcnew Juego());

}