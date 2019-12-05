#include <cstdio>

#define pi 3.14159265359
using namespace std;

double r,h,RAD,sol;
int test,n;

int main(){

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        RAD = 0;
        for ( int i = 1;i <= n;i++ ){
            scanf("%lf%lf", &r, &h);
            RAD += r*r*h;
        }
        sol = pi*RAD;
        printf("%.2lf\n", sol);
    }

    return 0;
}