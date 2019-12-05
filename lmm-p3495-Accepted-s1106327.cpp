//============================================================================
// Name        : asdf.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define ll long long
#define MAXN 1007

string A;int N;

map<string, int> mapa;
string key[]= {"H" ,
	    "He"    ,
	    "Li"   ,
	    "Be"    ,
	    "B"    ,
	    "C"     ,
	    "N"    ,
	    "O"     ,
	    "F"    ,
	    "Ne"   ,
	    "Na"   ,
	    "Mg"    ,
	    "Al"   ,
	    "Si"    ,
	    "P"    ,
	    "S"    ,
	    "Cl"   ,
	    "Ar"   ,
	    "K"    ,
	    "Ca"   };

string NAMe[] = {
	    "Hydrogen"
	    , "Helium"
	    ,    "Lithium"
	    ,    "Beryllium"
	    ,     "Boron"
	    ,     "Carbon"
	   ,     "Nitrogen"
	    ,    "Oxygen"
	    ,     "Fluorine"
	    ,    "Neon"
	    ,    "Sodium"
	    ,   "Magnesium"
	    ,    "Aluminum"
	    ,    "Silicon"
	    ,    "Phosphorus"
	    ,    "Sulfur"
	    ,   "Chlorine"
	    ,   "Argon"
	    ,    "Potassium"
	   ,   "Calcium"};
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for(int j = 0 ; j < N ;j++)
	{
		cin >> A;
		mapa.clear();
		int t = A.length();
		for(int i = 0 ; i < t; i++){
			string s = "";
			if(A[i] <= 'Z' && A[i] >= 'A')
			{
				s += A[i];
				if(	i+1 != t && A[i+1] <= 'z' && A[i+1] >= 'a'){
					s += A[i+1];
					i++;
				}
				if(!mapa[s])
				{
					if(A[i+1] <= '9' && A[i+1] >= '2')
						mapa[s] = A[i+1]-'0';else
					mapa[s] = 1;
				}else {
					if(A[i+1] <= '9' && A[i+1] >= '2')
						mapa[s] += A[i+1]-'0';else
						mapa[s] += 1;
				}
			}
		}
		cout << "Case #" << j+1 << ":\n";
				for(int i = 0 ; i < 20; i++)
					if(mapa[key[i]]) cout << mapa[key[i]] <<" " << NAMe[i]<< endl;
	}

	return 0;
}
