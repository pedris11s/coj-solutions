#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    scanf("\n");
    while(t--)
    {
        string cad;
        getline(cin, cad);
        int size = cad.size();

        string aux = "";
        vector <string> V;
        for(int i = 0; i < size; i++)
        {
            if(cad[i] == ' ')
            {
                V.push_back(aux);
                aux = "";
            }
            else if(i == size - 1)
            {
                aux += cad[i];
                V.push_back(aux);
                aux = "";
            }
            else
                aux += cad[i];
        }
        //for(int i = 0; i < V.size(); i++)
        //    cout << V[i] << endl;

        cout << V[0].substr(0, 3);
        for(int i = 1; i < V.size(); i++)
            if(i == V.size() - 1)
                cout << V[i];
            else
                cout << V[i] << "*";
        cout << V[0].substr(3) << endl;

    }

    return 0;
}
