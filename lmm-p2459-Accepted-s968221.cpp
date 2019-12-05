#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

struct par{
       int id;
       string c;
};

int con, c, S1[1000], s,  m[1000], M[1000];
char car;
string S;

int main(){

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    while (scanf ("%c", &car) != EOF){

           par A[1000];
           con=0;
           while (car != '\n'){
                  if (car != ' ' && car != '\n')
                      S += car;
                  scanf ("%c", &car);
                   if ((car == ' ' || car == '\n')&&S!=""){
                      con++;
                      A[con].c = S;
                      S = "";
                      A[con].id = 1;
                  }
           }
           car = 'a';
           while (car != '\n'){
                  scanf ("%c", &car);
                  if ((car == ' ' || car == '\n')&&S!=""){
                      con++;
                      A[con].c = S;
                      S = "";
                      A[con].id = 2;
                  }
                  else
                    if (car != '\n'&& car != ' ')
                     S += car;
           }
           car = 'a';
           while (car != '\n'){
                  scanf ("%c", &car);
                  if ((car == ' ' || car == '\n')&&S!=""){
                      con++;
                      A[con].c = S;
                      S = "";
                      A[con].id = 3;
                  }
                  else
                    if (car != '\n' && car != ' ')
                        S += car;

           }

           fill (m+1,m+500+1,0);
           fill (S1+1,S1+500+1,0);


           for (int i = 1; i <= con; i++){
                // cout << A[i].c <<"----->"<<A[i].id<<endl;
                fill (M+1, M+7, 0);
                s = 0;

                for (int j = 1; j <= con; j++){
                     if (A[i].c == A[j].c && i != j )
                         s++;
                }
                S1[A[i].id]+=(3-s);

           }
           scanf ("%c", &car);
           printf ("%d/%d/%d\n",S1[1],S1[2],S1[3]);
    }

    return 0;
}
