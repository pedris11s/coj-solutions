#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string A[5];
    for(int i = 0; i < 5; i++)
        cin >> A[i];


    vector <int> sol;
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < A[i].size() - 2; j++)
            if(A[i].substr(j, 3) == "FBI")
            {
                sol.push_back(i + 1);
                break;
            }

    if(sol.size() == 0)
        cout << "HE GOT AWAY!\n";
    else
        for(int i = 0; i < sol.size(); i++)
            if(i == sol.size() - 1)
                cout << sol[i] << endl;
            else
                cout << sol[i] << ' ';


    return 0;
}
