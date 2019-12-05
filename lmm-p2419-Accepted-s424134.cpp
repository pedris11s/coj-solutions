#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

struct mycomp{
    bool operator ()(const string &a, const string &b)const
    {
        int sza = a.size(), szb = b.size();
        for(int i = 0; i < min(sza, szb); i++)
            if(a[i] != b[i])
                return a[i] < b[i];

        return sza > szb;
    }
};

char s[30];
multiset <string, mycomp> myset;

int main()
{
    //freopen("d.in", "r", stdin);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            myset.insert(s);
        }
        string sol = "";
        while(!myset.empty())
        {
            multiset <string> :: iterator it = myset.begin();

            string s = (*it);
            sol += s[0];
            s.erase(s.begin());
            myset.erase(myset.begin());
            if(s.size() > 0)
                myset.insert(s);
        }
        cout << sol << endl;
    }

    return 0;
}
