#include<bits/stdc++.h>
using namespace std;
const int MAX=1000;
long long int Prod[MAX];
int getproduct(long long int n)
{
    if(n<10)
        return n;
    if(Prod[n]!=0)
        return Prod[n];
    long long int p=(n%10)*getproduct(n/10);
    Prod[n]=p;
    return p;
}
int main()
{
    ios_base::sync_with_stdio(false);
    long long int n;
    cin>>n;
    vector<long long int> res;
    for(int i=2;i<=n/2;i++)
    {
        if(i*getproduct(i)==n)
        {
            res.push_back(i);
        }
    }
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
    return 0;
}
