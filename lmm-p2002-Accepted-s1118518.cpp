#include <stdio.h>
#include <algorithm>

using namespace std;

int n, cont, sol, last, list[1005];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &list[i]);
    for(int i = 1; i <= n; i++) {
        cont = 0;
        last = -1;
        for(int j = 1; j <= n; j++) {
            if(list[j] == list[i])continue;
            if(list[j] == last)cont++;
            else {
                cont = 1;
                last = list[j];
            }
            sol = max(sol, cont);
        }
    }
    printf("%d\n", sol);
}