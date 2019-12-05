#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 7;

int N, Q;
int A[MAXN];

struct abi{
    int tree[MAXN];

    int query(int pos)
    {
        int sum = 0;
        for(int i = pos; i >= 1; i -= (i & -i))
            sum += tree[i];
        return sum;
    }

    void update(int pos, int value)
    {
        for(int i = pos; i <= N; i += (i & -i))
            tree[i] += value;
    }
}cero, neg;

int main()
{
    while(cin >> N >> Q)
    {
        for(int i = 1; i <= N; i++)
            neg.tree[i] = cero.tree[i] = 0;

        for(int i = 1; i <= N; i++)
        {
            cin >> A[i];
            if(A[i] < 0)
                neg.update(i, 1);
            else if(A[i] == 0)
                cero.update(i, 1);
        }

        while(Q--)
        {
            char q;int a, b;
            cin >> q >> a >> b;
            string sol = "";
            if(q == 'P')
            {
                int cc = cero.query(b) - cero.query(a - 1);
                if(cc > 0)
                    cout << '0';
                else
                {
                    int n = neg.query(b) - neg.query(a - 1);
                    if(n & 1)
                        cout << '-';
                    else
                        cout << '+';
                }
            }
            else
            {
                if(A[a] < 0 && b > 0)
                    neg.update(a, -1);
                else if(A[a] < 0 && b == 0)
                {
                    cero.update(a, 1);
                    neg.update(a, -1);
                }
                else if(A[a] == 0 && b < 0)
                {
                        cero.update(a, -1);
                        neg.update(a, 1);
                }
                else if(A[a] == 0 && b > 0)
                    cero.update(a, -1);
                else if(A[a] > 0 && b < 0)
                    neg.update(a, 1);
                else if(A[a] > 0 && b == 0)
                    cero.update(a, 1);
                A[a] = b;
            }
        }
        cout << endl;
    }

    return 0;
}
