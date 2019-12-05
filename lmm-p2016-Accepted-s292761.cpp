#include <cstdio>

using namespace std;

#define ll long long

char a[23],b[23];
ll puntos[3];

ll VALOR(char x){
	if (x == 'P') return 1;
	if (x == 'B' || x == 'N') return 3;
	if (x == 'T') return 5;
	if (x == 'Q') return 11;
	if (x == 'K') return 0;
	return 0;
}

int main() {
	ll anillo[8][8] = { {1, 1, 1, 1, 1, 1, 1, 1 },
						{1, 2, 2, 2, 2, 2, 2, 1 },
						{1, 2, 3, 3, 3, 3, 2, 1 },
						{1, 2, 3, 4, 4, 3, 2, 1 },
						{1, 2, 3, 4, 4, 3, 2, 1 },
						{1, 2, 3, 3, 3, 3, 2, 1 },
						{1, 2, 2, 2, 2, 2, 2, 1 },
						{1, 1, 1, 1, 1, 1, 1, 1 } };

	while(scanf("%s%s",a,b) != EOF){
		//if (a[0] == '-') break;
		int color = (b[0] == 'B');
		int c = a[0] - 'a';
		int f = 8 - (a[1] - '0');
		puntos[color] += VALOR(b[1]) * anillo[f][c];
	}

	printf("%lld %lld\n",puntos[0],puntos[1]);
	if (puntos[0] > puntos[1])
		puts("Advantage for white pieces");
	else if (puntos[0] < puntos[1])
		puts("Advantage for black pieces");
	else
		puts("No decisive advantages");

	return 0;
}
