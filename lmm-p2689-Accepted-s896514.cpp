#include <bits/stdc++.h>

using namespace std;

struct state{
    char beg, end;
    int desp, ns;
    state(char a, char b, int c, int d)
    {
        beg = a; end = b; desp = c; ns = d;
    }
};

vector <state> MT[10];

int main()
{
    MT[0].push_back(state('a', 'a', 0, 1));

    MT[1].push_back(state('a', 'X', 1, 4));
    MT[1].push_back(state('Y', 'Y', 1, 2));

    MT[2].push_back(state('Y', 'Y', 1, 2));
    MT[2].push_back(state('Z', 'Z', 1, 2));
    MT[2].push_back(state('a', 'a', 0, 3));
    MT[2].push_back(state('b', 'b', 0, 3));
    MT[2].push_back(state('c', 'c', 0, 3));

    MT[4].push_back(state('a', 'a', 1, 4));
    MT[4].push_back(state('Y', 'Y', 1, 4));
    MT[4].push_back(state('b', 'Y', 1, 5));

    MT[5].push_back(state('b', 'b', 1, 5));
    MT[5].push_back(state('Z', 'Z', 1, 5));
    MT[5].push_back(state('c', 'Z', -1, 6));

    MT[6].push_back(state('a', 'a', -1, 6));
    MT[6].push_back(state('b', 'b', -1, 6));
    MT[6].push_back(state('Y', 'Y', -1, 6));
    MT[6].push_back(state('Z', 'Z', -1, 6));
    MT[6].push_back(state('X', 'X', 1, 1));

    int t;
    cin >> t;

    while(t--){

        string cad;
        cin >> cad;

        int q = 0, i = 0;
        //cout << "q" << q << " " << i << " " << cad << endl;
        while(true)
        {
            bool flag = false;

            for(int k = 0; k < MT[q].size(); k++)
                if(cad[i] == MT[q][k].beg)
                {
                    cad[i] = MT[q][k].end;
                    i = i + MT[q][k].desp;
                    q = MT[q][k].ns;
                    flag = true;
                    break;
                }
            if(!flag)
                break;

            //cout << "q" << q << " " << i << " " << cad << endl;
            //system("pause");
        }
        cout << "q" << q << " " << cad << endl;
        //cout <<
    }

    return 0;
}
