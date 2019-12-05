#include <bits/stdc++.h>

using namespace std;

set<int> arbol[1000005];
set<int>::iterator it;
set<int>::iterator it2;

int arr[1000005];

int izquierda[1000005];
int num[1000005];
int new_value;
int ST[4000005];
int R,L;

void create(int n, int izq, int der)
{
    if(izq>der)return;
    if(izq==der)
    {
        ST[n] = izquierda[izq];
        return;
    }
    int m = (izq+der)/2;
    create(2*n,izq,m);
    create(2*n+1,m+1,der);
    ST[n] = max(ST[2*n], ST[2*n+1]);
}

void update(int n, int izq, int der)
{
    if(izq>der)return;
    if(izq>R || der<L) return;
    if(L<=izq&&der<=R)
    {
        ST[n] = new_value;
        return;
    }
    int m = (izq+der)/2;
    update(2*n,izq,m);
    update(2*n+1,m+1,der);
    ST[n] = max(ST[2*n], ST[2*n+1]);
}

int query(int n, int izq, int der)
{
    if(izq>der)return -1;
    if(izq>R || der < L)return -1;
    if(L<=izq&&der<=R)
    {
        return ST[n];
    }
    int m = (izq+der)/2;
    return max(query(2*n,izq,m), query(2*n+1,m+1,der));
}

char op[10];

int main()
{
    memset(num,-1,sizeof(num));
    int n, r;
    scanf("%d%d", &n, &r);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        izquierda[i] = num[arr[i]];
        arbol[arr[i]].insert(i);
        num[arr[i]] = i;
    }

    create(1,0,n-1);
    while(r--)
    {
        scanf("%s", op);
        if(op[0]=='E')
        {
            int pos;
            scanf("%d", &pos);
            pos--;
            L = 0, R = pos;
            int val = query(1,0,n-1);
            printf("%d\n", pos-val);
        }else{
            int pos,val;
            scanf("%d%d", &pos,&val);
            pos--;
            if(arr[pos]==val)continue;
            arbol[arr[pos]].erase(pos);
            it = lower_bound(arbol[arr[pos]].begin(), arbol[arr[pos]].end(), pos);
            if(it!=arbol[arr[pos]].end())
            {
                it2 = it;
                if(it2!=arbol[arr[pos]].begin())
                {
                    it2--;
                    new_value = *it2;
                    if(new_value<pos)
                    {
                        L = *it;
                        R = *it;
                        update(1,0,n-1);
                    }else{
                        new_value = -1;
                        L = *it;
                        R = *it;
                        update(1,0,n-1);
                    }

                }else{
                    new_value = -1;
                    L = *it;
                    R = *it;
                    update(1,0,n-1);
                }
            }
            it = lower_bound(arbol[val].begin(), arbol[val].end(), pos);
            if(it!=arbol[val].end())
            {
                new_value = pos;
                L = *it;
                R = *it;
                update(1,0,n-1);
            }
            it2 = it;
            if(it2!=arbol[val].begin())
            {
                it2--;
                new_value = *it2;
                if(new_value<pos)
                {
                    L = pos,R = pos;
                    update(1,0,n-1);
                }else{
                    new_value = -1;
                    L = pos, R = pos;
                    update(1,0,n-1);
                }
            }else{
                new_value = -1;
                L = pos, R = pos;
                update(1,0,n-1);
            }
            arbol[val].insert(pos);
            arr[pos] = val;
        }
    }
    return 0;
}


