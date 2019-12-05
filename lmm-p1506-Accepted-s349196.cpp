//by pter

#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int cq;
    cin >> cq;

    string correct;
    cin >> correct;

    int t;
    cin >> t;

    while(t--)
    {
        string exam;
        cin >> exam;

        float nota = 0;

        if(exam == correct)
            nota = cq;
        else
        {
            for(int i = 0; i < cq; i++)
                if(exam[i] == correct[i])
                    nota++;
                else if(exam[i] != correct[i] && exam[i] != '#')
                    nota -= 0.25;
        }
        printf("%.2f\n", nota);
    }
    return 0;
}
