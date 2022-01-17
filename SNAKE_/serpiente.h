#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;
using namespace System;
class serpiente
{
private:
	int x,_x;
	int y,_y;
	char objeto;
public:
	serpiente(char objeto, int x = rand() % 134 + 14,int y = rand() % 32 + 5):objeto(objeto),x(x),y(y)
	{
		_x = x;
		_y = y;
	}

	~serpiente(){}

	void position(int x=0, int y=0) 
	{ 
		/*if (!(x == 0)) { _x = this->x; this->x += x;}
		if (!(y == 0)) { _y = this->y; this->y += y;}*/

		if (!(x == 0 && y == 0))
		{
			_x = this->x;
			_y = this->y;//para guardar la ultima posicion en la que estuvo la cabeza...
		}

		this->x += x;
		this->y += y;
		
	}

	void position_seguir(int x, int y)
	{
		_x = this->x;
		_y = this->y;
		this->x = x;
		this->y = y;
	}
	void mostrar()
	{
		Console::CursorVisible = false;
		int aux_x=_x, aux_y = _y;
		Console::SetCursorPosition(aux_x, aux_y);//medio
		cout << "  ";
		
		Console::SetCursorPosition(x, y);
		cout << objeto;
		//aux_x = _x, aux_y = _y;
		//Console::SetCursorPosition(aux_x++, aux_y);//derecha medio
		//cout << "  ";
		//aux_x = _x, aux_y = _y;
		//Console::SetCursorPosition(aux_x--, aux_y);//izquierda medio
		//cout << "  ";
		//aux_x = _x, aux_y = _y;
		//Console::SetCursorPosition(aux_x, aux_y--);//arriba medio
		//cout << "  ";
		//aux_x = _x, aux_y = _y;
		//Console::SetCursorPosition(aux_x, aux_y++);//abajo medio
		//cout << "  ";
		//aux_x = _x, aux_y = _y;
		//Console::SetCursorPosition(aux_x--, aux_y--);//esquina izquierda arriba
		//cout << "  ";
		//aux_x = _x, aux_y = _y;
		//Console::SetCursorPosition(aux_x++, aux_y--);//esquina derecha arriba
		//cout << "  ";
		//aux_x = _x, aux_y = _y;
		//Console::SetCursorPosition(aux_x++, aux_y++);//esquina derecha abajo
		//cout << "  ";
		//aux_x = _x, aux_y = _y;
		//Console::SetCursorPosition(aux_x--, aux_y++);//esquina izquierda abajo
		//cout << "  ";
		//aux_x = _x, aux_y = _y;
		//system("cls");

		
	}
	bool colision(int x, int y)
	{
		if (this->x == x && this->y == y)return true;
		else return false;
	}
	int getX() { return x; }
	int getY() { return y; }
	int get_X() { return _x; }
	int get_Y() { return _y; }
};
