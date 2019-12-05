#include <bits/stdc++.h>

using namespace std;

int sol[10];



int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        int cas;string cad;
        cin >> cas >> cad;

        for(int i = 2; i < 40; i++){
            string v = cad.substr(i - 2, 3);
            if(v == "TTT")
                sol[0]++;
            else if(v == "TTH")
                sol[1]++;
            else if(v == "THT")
                sol[2]++;
            else if(v == "THH")
                sol[3]++;
            else if(v == "HTT")
                sol[4]++;
            else if(v == "HTH")
                sol[5]++;
            else if(v == "HHT")
                sol[6]++;
            else if(v == "HHH")
                sol[7]++;
        }
        cout << cas << " " << sol[0];
        for(int i = 1; i < 8; i++)
            cout << " " << sol[i];
        cout << "\n";
        fill(sol, sol + 10, 0);
    }




    return 0;
}
