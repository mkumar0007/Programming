#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    string str;
    getline(cin,str);
    string res="";
    int n=str.length();
    int len=0;
    for(int i=0;i<n;i++)
    {
        res.push_back(str[i]);
        len=1;
        while(str[i]==str[i+1])
        {
            i++;
            len++;
        }
        res.push_back(len+'0');
    }
    cout<<res;
    cin.tie(NULL);
    return 0;
}
