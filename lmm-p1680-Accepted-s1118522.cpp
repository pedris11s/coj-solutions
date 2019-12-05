
#include <bits/stdc++.h>
using namespace std;

char A[101], B[101],*w, aux[101];
int la,lb,p;

int main()
{
	while(scanf("%s%s",A,B)!=EOF){
		lb=strlen(B);
		while ((w=strstr(A,B))!=NULL){
			strcpy(aux,w+lb);
			strcpy(w,aux);
		}
		printf("%s\n",A);
	}
	return 0;
}
