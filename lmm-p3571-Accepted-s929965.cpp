#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2050;

int N;
double arr[MAXN], sol[MAXN];

int main()
{
    //freopen(".in", "r", stdin);

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%lf", &arr[i]);
    /*for(int i = 0; i < N; i++)
                cout << arr[i] << " ";
                //printf("%.2lf ", sol[i]);
        cout << endl;

*/
    int n = 2;
    while(n <= N)
    {
        int ind = 0;
        for(int i = 0; i < n / 2; i++)
        {
            double x = arr[i];
            double y = arr[i + n / 2];

            //cout << "arrr >> " << x << " " << y << endl;
            double a = x + y;
            double b = x - y;

            //cout << "AAAA  " << a << endl;
            //cout << "BBBB  " << b << endl;

            sol[2 * ind] = a;
            sol[2 * ind + 1] = b;
            ind++;
            //cout <<  "ETSA ES I >>> " << i << endl;
        }
        for(int i = 0; i < n; i++)
            arr[i] = sol[i];

        //fill(sol, sol + N, 0);
/*
        for(int i = 0; i < N; i++)
                cout << arr[i] << " ";
                //printf("%.2lf ", sol[i]);
        cout << endl;
        system("pause");*/
        n *= 2;
    }
    cout << arr[0];
    for(int i = 1; i < N; i++)
        cout << " " << arr[i];


    return 0;
}
