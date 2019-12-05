#include <bits/stdc++.h>

using namespace std;

string A[107];



int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        string cad;
        cin >> cad;
        int x = 0;

        if(cad[0] == '-')
            x = 1;

        sort(cad.begin() + x, cad.end());
        if(x == 0){
            if(cad[0] == '0' && cad.size() != 1){
                for(int i = 0; i < cad.size(); i++)
                    if(cad[i] != '0'){
                        swap(cad[0], cad[i]);
                        break;

                    }
            }
            cout << cad << "\n";
        }else{
            reverse(cad.begin() + 1, cad.end());
            cout << cad << "\n";

        }

    }

    /*string a = "sunny", b = "rainy", c = "cloudy";
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> A[i];

    int sol = 0;
    for(int i = 0; i < N; i++){
        if(i == 0 && A[i] == a){
            sol++;
            cout << i + 1 << endl;
        }else if(A[i - 1] == a && A[i] == a){
            sol++;
            cout << i + 1 << endl;
        }
        else if(A[i - 1] == b && A[i] == b){
            sol++;
            cout << i + 1 << endl;
        }
        else if(i > 2 && A[i - 3] == c && A[i - 2] == c && A[i - 1] == c && A[i] == b){
            sol++;
            cout << i  + 1<< endl;
        }
        else if(A[i] == c){
            sol++;
            cout << i  + 1<< endl;
        }

    }
    cout << sol << "\n";
*/



    return 0;
}
