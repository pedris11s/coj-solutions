#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100007;
const int MOD = 3;

int N, K;
string cad;
int abi[MAXN], A[MAXN];

void update(int pos, int val)
{
    for(int i = pos; i <= N; i += (i & -i))
        abi[i] += val;
}

int query(int pos)
{
    int sum = 0;
    for(int i = pos; i > 0; i -= (i & -i))
        sum += abi[i];
    return sum;
}

int modPow(int exp)
{
    if(exp == 0)
        return 1;
    if(exp & 1)
        return (2 * (modPow(exp - 1) % 3)) % 3;
    int r = modPow(exp / 2);
    return ((r % 3) * (r % 3)) % 3;

}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> N >> K;
    cin >> cad;
    for(int i = 0; i < (int)cad.size(); i++)
        A[i + 1] = (cad[i] == '1') ? 1 : 0;

    for(int i = 1; i <= N; i++)
        if(A[i])
            update(i, modPow(N - i));

    while(K--)
    {
        char c;
        cin >> c;
        if(c == 'P')
        {
            int sum = query(N);
            if(sum % 3 == 0)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
        else if(c == 'C')
        {
            int ind;
            cin >> ind;
            ind = N - ind;
            if(A[ind]){
                update(ind, -modPow(N - ind));
                A[ind] = 0;
            }
            else
            {
                update(ind, modPow(N - ind));
                A[ind] = 1;
            }
        }
        else
        {
            int ind, val;
            cin >> ind >> val;
            ind = N - ind;
            if(A[ind] == val);
            else{
                if(A[ind] == 0 && val == 1)
                {
                    update(ind, modPow(N - ind));
                    A[ind] = 1;
                }
                else{
                    update(ind, -modPow(N - ind));
                    A[ind] = 0;
                }


            }


        }
    }



    return 0;
}
