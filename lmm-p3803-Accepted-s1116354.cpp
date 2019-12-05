#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;

int arr[MAX] , freq[MAX * 10];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
       cin >> n;

      for(int i = 0 ; i < n ; i++)
         cin>>arr[i];

      int a = 0, b = 0, sol = 0;
      while(b < n)
      {
		 if(freq[arr[b]])
		 {
            while(arr[a] != arr[b]){
              freq[arr[a]] = 0;
              a++;
            }
            freq[a] = 0;
	         a++;
		 }
		 sol = max(sol , b - a + 1);
		 freq[arr[b]]++;
		 b++;
	  }
      cout << sol << "\n";
      for(int i = 0 ; i < n; i++)
        freq[arr[i]] = 0;
    }
    return 0;
}

