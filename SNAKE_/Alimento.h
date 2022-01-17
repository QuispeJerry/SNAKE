#pragma once
#include <cstdlib>
using namespace System;
class Comida
{
private:
	int x;
	int y;
	char forma;
public:
	Comida() {
		x = rand()% 134 + 14;
		y = rand()%32+5;
		forma = 'A';
	}
	~Comida(){}
	int getY() { return y; }
	int getX() { return x; }
	void mostrar() 
	{ 
		Console::SetCursorPosition(x, y);
		cout << forma; 
	}
	void borrar()
	{
		Console::SetCursorPosition(x, y);
		cout << " ";
	}
};