#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 100;

bool M[MAXN][MAXN];
int vcolumnas[MAXN];
bool estoesunaprueba;
int main()
{
//    freopen("entrad.in", "r", stdin);

    int size;
    while(true)
    {
        cin >> size;
        if(size == 0)
            break;

        int filabit = 0, columnabit = 0;

        int vfilas = 0, cantfi = 0, cantci = 0;
        int f,c;

        for(int c = 1; c <= size; c++)
            vcolumnas[c] = 0;

        for(f = 1; f <= size; f++)
        {
            for(int c = 1; c <= size; c++)
            {
                cin >> M[f][c];
                vfilas += M[f][c];
                vcolumnas[c] += M[f][c];
            }
            if(vfilas & 1)
            {
                cantfi++;
                filabit = f;
            }

            vfilas = 0;
        }
        for(int c = 1; c <= size; c++)
        {
            if(vcolumnas[c] & 1)
            {
                cantci++;
                if(cantci == 1)
                    columnabit = c;
            }
        }

        if(cantfi == 1 && cantci == 1)
            printf("Change bit (%d,%d)\n", filabit, columnabit);
        else if(cantfi > 1 || cantci > 1)
            printf("Corrupt\n");
        else
            printf("OK\n");
    }

 //   fclose(stdin);
    return 0;
}
