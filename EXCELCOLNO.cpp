#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    string str;
    getline(cin,str);
    int res=0;
    for(int i=0;i<str.length();i++)
    {
        res*=26;
        res+=str[i]-'A'+1;
    }
    cout<<res;
    cin.tie(NULL);
    return 0;
}
