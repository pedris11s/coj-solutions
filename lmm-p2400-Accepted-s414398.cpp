#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const char A[10][5] = {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
const char B[10][5] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

int sol = 99;
string Num;

bool isNumRom()
{
    string s = "";
    for(int i = 0; i <= 8; i++)
        for(int j = 0; j <= 8; j++)
        {
            s = A[i];
            s += B[j];
            if(s == Num)
                return true;
        }
    for(int i = 0; i <= 8; i++)
        if(Num == A[i] || Num == B[i])
            return true;

    return false;
}

bool is_min(){

    string s = "";
    for(int i = 0; i <= 8; i++)
        for(int j = 0; j <= 8; j++)
        {
            s = A[i];
            s += B[j];
            if(Num == s)
            {
                int v = (i + 1) * 10 + (j + 1);
                if(sol > v)
                {
                    sol = v;
                    return true;
                }
                return false;
            }
        }
    for(int j = 0; j <= 8; j++)
    {
        if(Num == A[j])
        {
            int v = (j + 1) * 10;
            if ( sol > v ){
                sol = v;
                return true;
            }
            return false;
        }
        if(Num == B[j])
        {
            int v = j + 1;
            if(sol > v){
                sol = v;
                return true;
            }
            return false;
        }
    }
    return false;
}

int main()
{
    //freopen("rimski.in", "r", stdin);
    //freopen("rimski.out", "w", stdout);

    cin >> Num;
    string answer = "XCIX";

    sort(Num.begin(), Num.end());
    do{
        if(isNumRom() && is_min())
            answer = Num;

    }while(next_permutation(Num.begin(), Num.end()));

    cout << answer.c_str() << endl;

    return 0;
}
