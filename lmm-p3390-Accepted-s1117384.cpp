#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 100005;

int n;
int A[MAXN];

int main() {

    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> A[i];

    sort(A, A + n);

    int minimo = A[0], maximo = 0;

    bool flag = true;
    for(int i = 0; i < n; i++)
        if(A[i] < i + 1) {
            flag = false;
            break;
        }

    if(!flag) {
        printf("S\n");
        return 0;
    }

    bool primero = true;
    int val = ((minimo / (n + 1)) * 2) % 2;
    if(val == 1)
        primero = false;

    int turnos = minimo % (n + 1), quitar = minimo - turnos;
    for(int i = 0; i < n; i++)
        A[i] -= quitar;

    for(int i = 0; i < n; i++)
        if(A[i] < i + 1) {
            flag = false;
            break;
        }

    if(primero)
        if(flag)
            cout << "N\n";
        else
            cout << "S\n";
    else
        if(flag)
            cout << "S\n";
        else
            cout << "N\n";

    return 0;
}