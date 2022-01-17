#pragma once
#include <iostream>
using namespace System;
using namespace std;
class Muro
{
private:
	int width;
	int height;
	int x;
	int y;
	char objeto;
public:
	Muro(int x,int y):x(x),y(y)
	{
		width = 4;
		height = 4;
		objeto = char(219);
	}
	~Muro(){}
	void mostrar()
	{
		
		for (size_t i = 0; i < height; i++)
		{
			Console::CursorVisible = false;
			Console::SetCursorPosition(x, y + i);
			for (size_t e = 0; e < width; e++)
			{
				cout << objeto;
			}
			cout << '\n';
		}
	}
};
