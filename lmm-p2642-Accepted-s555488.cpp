#include<iostream>

using namespace std;

int BigNumModInt(string A)
{
	int res = 0;
	int p2 = 1;

	for (int i = A.length() - 1 ; i >= 0 ; i--){
		res = (res + (A[i] - '0') * p2) % 3;
		p2 = (p2 * 2) % 3;
	}
	return res;
}

int main()
{
    int t;
    cin >> t;
	string A;
	while(t--)
	{
	    cin >> A;
        int x = BigNumModInt(A);
        if(x == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
	}

	return 0;
}
