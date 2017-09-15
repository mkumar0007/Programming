#include<bits/stdc++.h>
using namespace std;
int check(string X,string Y,int m,int n)
{
    if(m==0)
        return n;
    if(n==0)
        return m;
    if(X[m-1]==Y[n-1])
        return check(X,Y,m-1,n-1);
    else
        return 1+min(check(X,Y,m-1,n),min(check(X,Y,m,n-1),check(X,Y,m-1,n-1)));
}
int main()
{
    string X,Y;
    cin>>X>>Y;
    int m=X.length();
    int n=Y.length();
    int y=check(X,Y,m,n);
    cout<<y;
    return 0;
}
