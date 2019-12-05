#include <bits/stdc++.h>

using namespace std;

const int MAXN = 15;

int N, M, A[MAXN];
vector <int> adlist[MAXN];

bool check(){
    bool mk[15];
    fill(mk, mk + N + 1, false);

    mk[A[1]] = true;
    /*for(int i = 1; i <= N; i++)
        cout << A[i] << " ";
    cout << endl;
    system("pause");*/
    for(int i = 1; i <= N; i++){
        //cout << "A[i] >> " << A[i] << "\n";
        for(int j = 0; j < adlist[A[i]].size(); j++){
            //cout << "hijos ->> " << adlist[A[i]][j] << "\n";
            //system("pause");
            if(mk[adlist[A[i]][j]] == true)
                return false;
        }

        mk[A[i]] = true;
    }
    return true;
}

int main()
{
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        adlist[a].push_back(b);
    }

    for(int i = 1; i <= N; i++)
        A[i] = i;
    int sol = 0;
    do{
        if(check()){
            /*for(int i = 1; i <= N; i++)
                cout << A[i] << " ";
            cout << endl;*/
            sol++;
        }

    }while(next_permutation(A + 1, A + N + 1));

    cout << sol << "\n";

    return 0;
}

/*
10 14
1 2
1 3
1 4
2 5
3 5
3 6
4 6
5 7
5 8
6 8
6 9
7 10
8 10
9 10
*/
