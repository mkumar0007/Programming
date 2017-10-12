#include<bits/stdc++.h>
using namespace std;

bool match(char *a,char *b)
{
    if(*a=='\0' && *b=='\0')
        return true;
    if(*a=='*' && *(a+1)!='\0' && *b=='\0')
        return false;
    if(*a=='?' || *a==*b)
        return match(a+1,b+1);
    if(*a=='*')
        return match(a+1,b) || match(a,b+1);
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    char a[50],b[50];
    cin>>a>>b;
    match(a,b)?cout<<"YES":cout<<"NO";
    cin.tie(NULL);
    return 0;
}
