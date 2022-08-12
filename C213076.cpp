#include<bits/stdc++.h>
using namespace std;


bool isPrime(int n) {
    if(n==1)
        return false;
    for(int i=2;i*i<=n;i++)
        if(n%i==0)
            return false;
    return true;
}

int main()
{
    ifstream fr("input.txt",ios::in);

    int num;    
    fr >> num;

    ofstream ft("output.txt",ios::out);
    if(isPrime(num))
        ft << num << " is a prime number." << endl;
    else
        ft << num << " is a complex number." << endl;
    return 0;
}