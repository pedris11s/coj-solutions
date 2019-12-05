#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

    string A, B;
    cin >> A >> B;
    int sza = A.size(), szb = B.size();

    int sol = 0, j = 0;
    for(int i = 0; i < sza; i++){
        if(A[i] == B[0]){
            string aux = A.substr(i, szb);
            if(aux == B)
                sol++, i += szb - 1;
        }
    }
    cout << sol << "\n";


	return 0;
}
