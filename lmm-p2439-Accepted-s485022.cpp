#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

int t, l, s;

void fractal(double n,int ite)
{
    //cout<< n<<" "<<s<<endl;
    //system("pause");
    if(n >= s){
        printf("%d\n",ite - 1);
        return;
    }
    fractal(n + 2 * n / 3, ++ite);
}

int main()
{
    scanf("%d",&t);
    for(int i = 1;i <= t;i++){
        scanf("%d%d",&l,&s);
        if(l == s)
            printf("0\n");
        else
            fractal(l,0);
    }
    return 0;
}
