#include <bits/stdc++.h>

using namespace std;
#define MAXN 1003
#define endl '\n'

int T;
char N[MAXN], K[MAXN];

int M[MAXN][3], l;

map<pair<int , int>, int> mapa;

int main(){

	ios_base::sync_with_stdio(0);cin.tie(0);

	cin >> T;
	while(T--)
	{
		cin >> N >> K;

		int f = K[strlen(K)-1]-'0';
		mapa.clear();

		//cout << f << endl;
		memset(M, 0 , sizeof(M));

		int inix = 1 , finx = f;
		mapa[make_pair(inix, finx)] = 0;

		M[0][0] = 1, M[0][1] = f;

		l = 1;

		int ii = 0 ;
		while(true)
		{
			inix = (inix * finx) % 7;

			swap(inix,finx);
			if(mapa.find(make_pair(inix, finx)) != mapa.end()){
				ii = mapa[make_pair(inix, finx)];
				break;
			}
			else
				mapa[make_pair(inix, finx)] = l;

			M[l][0] = inix,
			M[l][1] = finx;
			l++;
		}

		int sol = 0;

			for(int i = 0, t = strlen(N) ; i < t ; i++)
				sol = ((sol*7) + N[i]-'0') % (l - ii);

			sol -= (ii % (l - ii));
			sol += (l - ii);
			sol %= (l - ii);

		if((sol + ii) - 1 >= 0){

/*
			cout << sol << endl;
			cout << ii << endl;
			/*for(int i = 0 ; i < l ; i++)
				cout << M[i][1] << " ";*/

		if(strlen(N) == 1 && N[0] == '0' )
			cout << 1 << endl;
		else
			cout << M[(sol + ii)-1][1] % 7 << endl;
		}
		else
			cout << M[0][0] << endl;
	}

	return 0;
}

