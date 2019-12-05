#include <bits/stdc++.h>

using namespace std;

bool opuestas(string a, string b){
    for(int i = 0; i < a.size(); i++)
        if(a[i] == b[i])
            return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int N;
    cin >> N;

    string a, b;
    cin >> a >> b;

    if(N & 1){
        if(opuestas(a, b))
            cout << "Deletion succeeded\n";
        else
            cout << "Deletion failed\n";
    }
    else{
        if(a == b)
            cout << "Deletion succeeded\n";
        else
            cout << "Deletion failed\n";
    }


    return 0;
}
