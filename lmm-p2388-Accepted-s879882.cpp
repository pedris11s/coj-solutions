#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int B, C;
        cin >> B >> C;

        if(B <= C)
        {
            cout << "1\n";
            continue;
        }
        int sol = 0;
        queue <int> cola;
        cola.push(B);
        while(!cola.empty())
        {
            int x = cola.front();
            cola.pop();

            if(x % 2 == 0)
            {
                if(x / 2 <= C)sol += 2;
                else cola.push(x / 2), cola.push(x / 2);
            }
            else
            {
                if(x / 2 <= C)sol++;
                else cola.push(x / 2);

                if(x / 2 + 1 <= C)sol++;
                else cola.push(x / 2 + 1);
            }
        }
        cout << sol << "\n";
    }

    return 0;
}
