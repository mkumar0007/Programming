#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    char str[10];
    int i=0;
    while(n>0)
    {
        if(n%26==0)
        {
            str[i++]='Z';
            n=(n/26)-1;
        }
        else
        {
            str[i++]=(n%26)-1+'A';
            n=n/26;
        }
    }
    str[i]='\0';
    reverse(str,str+strlen(str));
    cout<<str;
    cin.tie(NULL);
    return 0;
}
