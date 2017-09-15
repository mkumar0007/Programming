#include<bits/stdc++.h>
using namespace std;
int m=0;
void swap(char *x, char *y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
void permute(char *s,int l,int r)
{
    if(l==r)
    {
        m++;
        cout<<s<<endl;
    }
    else
    {
        for(int i=l;i<=r;i++)
        {
            swap((s+l),(s+i));
            permute(s,l+1,r);
            swap((s+l),(s+i));
        }
    }
}
int main()
{
    char s[100];
    gets(s);
    permute(s,0,3);
    cout<<m;
    return 0;
}
