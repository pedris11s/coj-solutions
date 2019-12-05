//    __final_insertion_sort();
#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6 + 5;

int pos[MAX], lista[MAX];

bool comp(int a, int b) {
    return lista[a] < lista[b];
}

int bf(int ini, int fin, int val) {
    if(ini > fin)
        return 0;
    int cont = 0;
    for(int i = ini; i <= fin; i++)
        if(lista[i] <= val)
            cont++;
    return cont;
}

int n, q, a, b, c, sq;

int busca(int a, int b, int val) {
    int ini(a), med, fin(b);
    while(ini + 1 < fin) {
        med = (ini + fin) / 2;
        if(lista[pos[med]] > val)
            fin = med - 1;
        else
            ini = med;
    }
    for(int i = fin; i >= ini; i--)
        if(lista[pos[i]] <= val)
            return i - a + 1;
    return 0;
}

char T[4];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> q;

    for(int i = 1; i <= n; i++) {
        cin >> lista[i];
        pos[i] = i;
    }

    sq = sqrt(n);
    for(int i = 1; i <= n; i += sq) {
        sort(pos + i, pos + min(i + sq - 1, n) + 1, comp);
    }
        

    while(q--) {
        cin >> T >> a >> b;
        if(*T == 'Q') {
            cin >> c;
            if(a > b)swap(a, b);
            int sol = 0;
            for(int i = 1; i <= n; i += sq) {
                if(min(i + sq - 1, n) < a || i > b)continue;
                if(a <= i && min(i + sq - 1, n) <= b)
                    sol += busca(i, min(i + sq - 1, n), c);
                else
                    sol += bf(max(i, a), min(i + sq - 1, b), c);
            }
            printf("%d\n", sol);
        }
        else {
            lista[a] = b;
            for(int i = 1; i <= n; i += sq)
                if(i <= a && a <= min(i + sq - 1, n)) {
                    sort(pos + i, pos + min(i + sq - 1, n) + 1, comp);
                    break;
                }
        }
    }
}
