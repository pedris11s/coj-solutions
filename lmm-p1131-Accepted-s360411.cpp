//by pter



#include <cstdio>

#include <iostream>

#include <vector>



using namespace std;



typedef long long huge;

typedef vector <huge> VH;



VH exp_N;

VH exp_NmK;

VH exp_K;



huge cantV(int n, int p)

{

    huge sum = 0;

    int pot = p;

    

    while(pot <= n)

    {

        sum += n / pot;

        pot *= p;

    }

    return sum;

}



bool prime(int n)

{

    if(n == 2)return true;

    if(n % 2 == 0)return false;

    

    for(int i = 3; i * i <= n; i += 2)

        if(n % i == 0)

            return false;

    return true;

}



int main()

{

    int n, k;

    while(cin >> n >> k)

    {

        exp_N.clear();

        exp_NmK.clear();

        exp_K.clear();

        

        for(int i = 2; i <= n; i++)

        {

            if(prime(i))

            {

                exp_N.push_back(cantV(n, i));

                exp_NmK.push_back(cantV(n - k, i));

                exp_K.push_back(cantV(k, i));

            }

        }

    

        huge cantD = 1;

    

        for(int i = 0; i < exp_N.size(); i++)

            cantD *= (exp_N[i] - (exp_NmK[i] + exp_K[i])) + 1;



        cout << cantD << endl;

    }

    return 0;

}