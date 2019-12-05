#include <bits/stdc++.h>

using namespace std;

bool is_pal(string cad)
{
    int i = 0, j = cad.size() - 1;
    while(i < j)
    {
        if(cad[i] != cad[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int main()
{
    string a, b;
    cin >> a >> b;
    bool sol = is_pal(a + b);
    if(sol)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
