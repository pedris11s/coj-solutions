//by pter



#include <cstdio>

#include <vector>

#include <queue>

#include <algorithm>

#include <iostream>



using namespace std;



const int FILAS = 11;

const int COLUMNAS = 11;

const int MAX_MOV = 8;



typedef pair <int, int> position;



#define x first

#define y second



int filas = 8, columnas = 8;

position ini, dest;

char aux_ini[4], aux_dest[4];



queue < position > destinos;

bool M[FILAS][COLUMNAS];

position MRecorrido[FILAS][COLUMNAS];

position caballo;

vector < position > camino;



int DX[8] = {-2, -2, -1, 1, 2, 2, 1, -1};

int DY[8] = {1, -1, 2, 2, 1, -1, -2, -2};



inline bool SaltoValido(int x, int y)

{

    if(x <= filas && x >= 1 && y <= columnas && y >= 1)

        return true;



    return false;

}



void Registrar(position salto, position caballo)

{

    MRecorrido[salto.x][salto.y] = caballo;

}



bool hay_camino(position ini, position dest)

{

	while( !destinos.empty() )

		destinos.pop();

	

	destinos.push(ini);

    

    for(int i = 0; i < FILAS; i++)

		for(int j = 0; j < COLUMNAS; j++)

			M[i][j] = 0;

			

    M[ini.x][ini.y] = true;



    while(!destinos.empty())

    {

        caballo = destinos.front();

        destinos.pop();



        for(int i = 0; i < MAX_MOV; i++)

        {

            position salto;

            salto.x = caballo.x + DX[i];

            salto.y = caballo.y + DY[i];



            if ( SaltoValido(salto.x, salto.y) )

            {

                if(salto.x == dest.x && salto.y == dest.y)

                {

                    Registrar(dest, caballo);

                    return true;

                }



                if(M[salto.x][salto.y] == false)

                {

                    Registrar(salto, caballo);

                    destinos.push(salto);

                    M[salto.x][salto.y] = true;

                }

            }

        }

    }

    return false;

}



int cant_saltos(position ini, position dest)

{

    position next = dest;

	int cSaltos = 0;

	

    while(ini != next)

    {

        next = MRecorrido[next.x][next.y];

        cSaltos++;

	}

	return cSaltos;

}



int main()

{

    //char a = 'a';

    //printf("%d", a);

    

    while(true)

    {

		scanf("%s%s", aux_ini, aux_dest);

		

		if(aux_ini[0] == '#')

			break;

			

		ini.x = aux_ini[0] - 96;

		ini.y = aux_ini[1] - 48;

		dest.x = aux_dest[0] - 96;

		dest.y = aux_dest[1] - 48;

		

		hay_camino(ini, dest);

		printf("To get from %s to %s takes %d knight moves.\n", aux_ini, aux_dest, cant_saltos(ini,dest));

	}

	

    return 0;

}

