#include<bits/stdc++.h>
using namespace std;
bool issubseq(string X,string Y)
{
    int m=X.length();
    int n=Y.length();
    int i=0,j=0;
    for(i=0;i<n&&j<m;i++)
    {
        if(X[j]==Y[i])
            j++;
    }
    return j==m;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<string> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    string str;
    cin>>str;
    string res="";
    int len=0;
    for(int i=0;i<n;i++)
    {
        if(issubseq(a[i],str)&&len<a[i].length())
        {
            len=a[i].length();
            res=a[i];
        }
    }
    cout<<res;
    cin.tie(NULL);
    return 0;
}
