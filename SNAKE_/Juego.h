#pragma once
#include <vector>
#include "serpiente.h"
#include "Alimento.h"
#include "muro.h"
class Juego
{
private:
	vector<serpiente>* snake;
	Comida* alimento;
	vector<Muro>* mapa;
public:
	Juego()
	{
		snake = new vector<serpiente>();
		snake->push_back(serpiente('x'));//la cabeza de la serpiente
		alimento = new Comida();
		mapa = new vector<Muro>();

		//mapa
		for (size_t i = 0; i < 37; i += 4) { mapa->push_back(Muro(10, 1 + i)); }
		for (size_t i = 0; i < 37; i += 4) { mapa->push_back(Muro(160, 1 + i)); }
		for (size_t i = 0; i < 145; i += 4) { mapa->push_back(Muro(14 + i, 1)); }
		for (size_t i = 0; i < 145; i += 4) { mapa->push_back(Muro(14 + i, 37)); }
	}
	~Juego(){}
	void agregar()
	{
		alimento = new Comida();
		snake->push_back(serpiente('o',snake->at(0).get_X(), snake->at(0).get_Y()));
	}
	bool colision()
	{
		if (snake->at(0).getX() < 13 || snake->at(0).getX() > 160)return true;
		if (snake->at(0).getY() < 4 || snake->at(0).getY() > 37)return true;
		//consigo mismo
		for (size_t i = 0; i < snake->size(); i++)
		{
			for (size_t e = 0; e < snake->size()-1; e++)
			{
				if (i == e)++e;
				if ((snake->at(i).colision(snake->at(e).getX(), snake->at(e).getY())))return true;
			}
		}
		return false;
	}
	bool colision_C_A(){
		return ((snake->at(0).getX() == alimento->getX())&&(snake->at(0).getY() == alimento->getY()))?true:false;
	}
	void seguir()
	{
		for (size_t i = 1; i < snake->size(); i++)
		{
			snake->at(i).position_seguir(snake->at(i - 1).get_X(), snake->at(i - 1).get_Y());
		}
	}
	void mostrar()
	{
		for (size_t i = 0; i < mapa->size(); i++)
		{
			mapa->at(i).mostrar();
		}
		for (size_t i = 0; i < snake->size() ; i++)
		{
			snake->at(i).mostrar();
		}
		alimento->mostrar();
	}
	void mover(int x=0, int y=0)
	{
		snake->at(0).position(x, y);
	}
};
