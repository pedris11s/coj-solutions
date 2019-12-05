#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

map <int, double> mk;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        mk.clear();
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            int id;double value;

            scanf("%d%lf", &id, &value);
            if(mk.find(id) != mk.end())
            {
                if(value < mk[id])
                    mk[id] = value;
            }
            else
                mk[id] = value;
        }
        map <int, double> :: iterator it;
        double sol = 0.0;
        for(it = mk.begin(); it != mk.end(); it++)
            sol += (*it).second;
        printf("%.2lf\n", sol);
    }


    return 0;
}
