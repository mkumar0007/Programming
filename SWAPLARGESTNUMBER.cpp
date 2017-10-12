#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    string s;
    cin>>s;
    int n=s.length();
    int right=n-1;
    int rightmax[n];
    rightmax[n-1]=-1;
    for(int i=n-2;i>=0;i--)
    {
        if(s[i]-'0'<s[right]-'0')
        {
            rightmax[i]=right;
        }
        else
        {
            rightmax[i]=-1;
            right=i;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(rightmax[i]!=-1){
            swap(s[i],s[rightmax[i]]);
            break;}
    }
    cout<<s;
    return 0;
}
