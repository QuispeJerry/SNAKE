#include <iostream>
#include <conio.h>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include "Juego.h"
using namespace std;
using namespace System; /*para usar: Console::SetCursorPosition(10, 20);*/
void gotoxy(int x, int y)
{
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);
}
int main()
{
	system("pause>0");
	srand(time(NULL));
	Juego* obj = new Juego();
	int x=0, y=0;
	bool aux = false;
	char tecla;
	char anterior;
	while (true)
	{
		
		obj->mostrar();
		if (obj->colision_C_A())obj->agregar();
		
		if (kbhit())
		{
			Console::CursorVisible = false;
			tecla = getch();
			tecla = toupper(tecla);
			switch (tecla)
			{
			case 'A':
				if (anterior == 'D')goto pasar;
				x=-1; y = 0; aux = true; break;
			case 'W':
				if (anterior == 'S')goto pasar;
				y=-1; x = 0; aux = true; break;
			case 'S':
				if (anterior == 'W')goto pasar;
				y=1; x = 0; aux = true; break;
			case 'D':
				if (anterior == 'A')goto pasar;
				x=1; y = 0; aux = true; break;
			default:break;
			}
			anterior = tecla;		
		}
	pasar:
		if (!aux)
		{
			obj->mover();
		}
		else {
			obj->mover(x, y);
		}
		obj->seguir();
		if (obj->colision())
		{
			system("pause>0");
			system("cls");
			Console::SetCursorPosition(25, 25);
			cout << "Game Over";
			exit(1);
		}
		_sleep(100);
	}

	//vector<Muro>* mapa = new vector<Muro>();

	//for (size_t i = 0; i < 37; i+=4)
	//{
	//	mapa->push_back(Muro(10, 1+i));//base
	//}

	//for (size_t i = 0; i < 37; i += 4)
	//{
	//	mapa->push_back(Muro(160, 1 + i));//base
	//}

	//for (size_t i = 0; i < 145; i += 4)
	//{
	//	mapa->push_back(Muro(14+i, 1));//base
	//}

	//for (size_t i = 0; i < 145; i += 4)
	//{
	//	mapa->push_back(Muro(14 + i, 37));//base
	//}

	//while (true)
	//{
	//	for (size_t i = 0; i < mapa->size(); i++)
	//	{
	//		mapa->at(i).mostrar();
	//	}
	//}
	//

	//system("pause>0");
	return 0;
}