#include <bits/stdc++.h>

using namespace std;

char cad[1000];

int main()
{
    scanf(" %[^\n]", cad);

    int size = strlen(cad);
    stack <int> pila;
    for(int i = 0; i < size; i++)
        if(cad[i] == '(')
            pila.push(i);
        else if(cad[i] == ')')
        {
            int pos = pila.top();
            pila.pop();
            reverse(cad + pos + 1, cad + i);
            //cout << cad << endl;
            //system("pause");
        }
    for(int i = 0; i < size; i++)
        if(cad[i] == '(' || cad[i] == ')')
            continue;
        else
            printf("%c", cad[i]);
    printf("\n");
    return 0;

}
