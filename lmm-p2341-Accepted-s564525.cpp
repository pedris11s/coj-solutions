#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

map <string, int> list;

int main()
{
    int N, Q;
    cin >> N >> Q;
    string cad; int value;
    for(int i = 0; i < N; i++)
    {
        cin >> cad >> value;
        list[cad] = value;
    }
    while(Q--)
    {
        cin >> cad;
        if(!(list.find(cad) != list.end()))
            cout << "not found\n";
        else
        {
            cin >> value;
            if(value == list[cad])
                cout << "ok\n";
            else
                cout << "wrong\n";
        }
    }




    return 0;
}
