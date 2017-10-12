#include<bits/stdc++.h>
using namespace std;

bool pal(char s[])
{
    int l=0;
    int h=strlen(s)-1;
    while(l<h)
    {
        if(*(s+l) != *(s+h))
            return false;
        l++;
        h--;
    }
    return true;
}
int append(char *str)
{
    static int n=0;
    if(pal(str))
        return n;
    str++;
    return 1+append(str);
}
int main()
{
    ios_base::sync_with_stdio(false);
    char str[20];
    cin>>str;
    cout<<append(str);
    cin.tie(NULL);
    return 0;
}
