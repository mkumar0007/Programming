#include<bits/stdc++.h>
using namespace std;

void filter(char *str)
{
    int n=strlen(str);
    int i=-1;
    int j=0;
    while(j<n)
    {
        if(j<n-1 && str[j]=='a' && str[j+1]=='c')
        {
            j+=2;
        }
        else if(str[j]=='b')
        {
            j++;
        }
        else if(i>=0 && str[j]=='c' && str[i]=='a')
        {
            i--;
            j++;
        }
        else
        {
            str[++i]=str[j++];
        }
    }
    str[++i]='\0';
}

int main()
{
    ios_base::sync_with_stdio(false);
    char str[20];
    cin>>str;
    filter(str);
    cout<<str;
    cin.tie(NULL);
    return 0;
}
