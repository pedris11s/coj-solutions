#include <bits/stdc++.h>

using namespace std;

int n, p, len[105];
char s[105][15], top_sort[105];

bool flag, multiple;
set <char> st;
set <char> :: iterator ite;
map <char, int> grado;
map < char, vector <char> > lista;
queue <char> q;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%s", s[i] + 1), len[i] = strlen(s[i] + 1);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= len[i]; j++)
            st.insert(s[i][j]);

    for(int i = 1; i < n; i++)
        for(int j = 1; j <= len[i] && j <= len[i + 1]; j++) {
            if(s[i][j] != s[i + 1][j]) {
                lista[s[i][j]].push_back(s[i + 1][j]);
                grado[s[i + 1][j]]++;
                break;
            }
        }

    for(ite = st.begin(); ite != st.end(); ite++) {
        if(!grado[*ite]) {
            q.push(*ite);
            if(flag)
                multiple = true;
            flag = true;
        }
    }

    while(!q.empty()) {
        char c = q.front();
        q.pop();
        top_sort[p++] = c;
        flag = false;
        for(int i = 0; i < lista[c].size(); i++) {
            char to = lista[c][i];
            grado[to]--;
            if(!grado[to]) {
                q.push(to);
                if(flag)
                    multiple = true;
                flag = true;
            }
        }
    }

    if(p != st.size())
        printf("!\n");
    else if(multiple)
        printf("?\n");
    else
        printf("%s\n", top_sort);
}
