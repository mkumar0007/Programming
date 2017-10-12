#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    cin>>a>>b;
    int n=a.length();
    string res="";
    int carry=0;
    for(int i=n-1;i>=0;i--)
    {
        int x=a[i]-'0';
        int y=b[i]-'0';
        int sum=(x^y^carry)+'0';
        res=(char)sum+res;
        carry=(x&y)|(x^carry)|(y^carry);
    }
    if(carry)
        res='1'+res;
    cout<<res;
    return 0;
}
