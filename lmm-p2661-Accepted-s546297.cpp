#include<iostream>

using namespace std;

int BigNumModInt(string A)
{
	int res = 0;
	int p10 = 1;

	for (int i = A.length() - 1 ; i >= 0 ; i--){
		res = (res + (A[i] - '0') * p10) % 3;
		p10 = (p10 * 10) % 3;
	}
	return res;
}

int main()
{
	string A;
	while(cin >> A)
	{
        int x = BigNumModInt(A);
        if(A == "0")
            cout << "1\n";
        else if(x == 2)
            cout << "4\n";
        else if(x == 0)
            cout << "1\n";
        else if(x == 1)
            cout << "7\n";
	}

	return 0;
}
