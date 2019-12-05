//by pter



/*

4 4 1 2

..*.

*...

.**.

....



4 3 1 4

....

..*.

.**.



1 4 1 2 

.

.

.

.



*/

#include <cstdio>
#include <queue>
#include <iostream>
#include <vector>

#include <algorithm>

using namespace std;

const int MAX = 110;
const int MAX_MOV = 8;


typedef pair < int, int > position;


#define x first

#define y second

#define endl '\n'


int cf, cc;
int fi, ci;

int max_week = 0;



queue < position > cola;


char M[MAX][MAX];

int Week[MAX][MAX];

int DX[8] = {-1, -1, -1, 0, 1, 1, 1, 0};

int DY[8] = {-1, 0, 1, 1, 1, 0, -1, -1};



inline bool Mov_Valido(int x, int y)

{

    if(x <= cf && x >= 1 && y <= cc && y >= 1 && M[x][y] == '.')

        return true;



    return false;

}



int cWeek()

{

    position inicio = make_pair(cf - fi + 1, ci);

    cola.push(inicio);



    M[cf - fi + 1][ci] = 'M';



    while( !cola.empty() )

    {

        position actual = cola.front();

        cola.pop();



        for(int i = 0; i < MAX_MOV; i++)

        {

            position move;

            move.x = actual.x + DX[i];

            move.y = actual.y + DY[i];



            if( Mov_Valido(move.x, move.y) )

            {

                cola.push(move);

                M[move.x][move.y] = 'M';

              

                Week[move.x][move.y] = Week[actual.x][actual.y] + 1;

				

				if(Week[move.x][move.y] > max_week)

                    max_week = Week[move.x][move.y];

            }

        }

    }

    return max_week;

}


int main()
{
	cin >> cc >> cf >> ci >> fi;

	for(int i = 1; i <= cf; i++)
		for(int j = 1; j <= cc; j++)

            cin >> M[i][j];



    int solution = cWeek();

    cout << solution << endl;



	return 0;
}