#include <cstdio>
#include <iostream>

using namespace std;

int a[105], sol, i;

void Part1(){
   if(a[i] == a[i-1] && a[i] == a[i-2] && a[i] == a[i-3])
       sol++;
}

void Part2()
{
    if(a[i] == a[i-1])
        sol++;
}

void Part3()
{
    if(i > 2 && a[i] == a[i-1]+1 && a[i-1] == a[i-2])
        sol++;
    if(i > 1 && a[i] == a[i-1]-1)
        sol++;
}

void Part4()
{
    if(i > 2 && a[i] == a[i-1] && a[i] == a[i-2]-1)
        sol++;
    if(i > 1 && a[i] == a[i-1]+1)
        sol++;
}

void Part5()
{
    if(i > 2 && a[i] == a[i-1] && a[i] == a[i-2])
        sol++;
    if(i > 2 && a[i] == a[i-2] && a[i] == a[i-1]+1)
        sol++;
    if(i > 1 && a[i] == a[i-1]-1)
        sol++;
    if(i > 1 && a[i] == a[i-1]+1)
        sol++;
}

void Part6()
{
    if(i > 2 && a[i] == a[i-1] && a[i] == a[i-2])
        sol++;
    if(i > 2 && a[i] == a[i-1] && a[i-2] == a[i]-1)
        sol++;
    if(i > 1 && a[i] == a[i-1])
        sol++;
    if(i > 1 && a[i] == a[i-1]-2)
        sol++;
}

void Part7(){
    if(i > 2 && a[i] == a[i-1] && a[i] == a[i-2])
        sol++;
    if(i > 2 && a[i] == a[i-1]-1 && a[i-1] == a[i-2])
        sol++;
    if(i > 1 && a[i] == a[i-1])
        sol++;
    if(i > 1 && a[i] == a[i-1]+2)
    sol++;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(i = 1; i <= n; i++)
        cin >> a[i];

    if(m == 1)
        sol = n;

    for(i = 1; i <= n; i++)
    {
        if(m == 1 && i > 3)
            Part1();
        if(m == 2 && i > 1)
            Part2();
        if(m == 3)
            Part3();
        if(m == 4)
            Part4();
        if(m == 5)
            Part5();
        if(m == 6)
            Part6();
        if(m == 7)
            Part7();
    }
    cout << sol << endl;
}
