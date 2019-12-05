 # include <cstdio>
 using namespace std;

 int n, ca, cd, i, vi;

 int main(){

    scanf("%d", &n);
    cd = n*2;

    ca = cd%3;
    if(ca == 2)
        printf("3");
    if(ca == 1)
        printf("1");

    for(i = 1; i <= cd/3; i++)
        printf("7");
    printf("\n");
 }
