#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    string str;
    getline(cin,str);
    int n=str.length();
    int ac=0,bc=0,cc=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='a')
        {
            ac=1+2*ac;
        }
        else if(str[i]=='b')
        {
            bc=ac+2*bc;
        }
        else if(str[i]=='c')
        {
            cc=bc+2*cc;
        }
    }
    cout<<cc;
    cin.tie(NULL);
    return 0;
}
