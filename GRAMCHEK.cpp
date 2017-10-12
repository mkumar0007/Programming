#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    string str;
    getline(cin,str);
    int n=str.length();
    if(str[0]<'A' && str[0]>'Z')
        return -1;
    if(str[n-1]!='.')
        return -1;
    int prev=0, cur=0;
    int index=1;
    while(str[index])
    {
        if(str[index]>='A' && str[index] <= 'Z')
        {
            cur=0;
        }
        else if(str[index]>='a' && str[index]<='z')
        {
            cur=2;
        }
        else if(str[index]==' ')
        {
            cur=1;
        }
        else if(str[index]=='.')
        {
            cur=3;
        }
        if(prev==cur && cur!=2)
            return -1;
        if(cur==3 && prev!=1)
            return (str[index+1]=='\0');
        index++;
        prev=cur;
    }
    return -1;
}
