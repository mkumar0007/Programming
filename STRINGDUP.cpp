#include<bits/stdc++.h>
using namespace std;
#define MAX_CHAR 256
int main()
{
    ios_base::sync_with_stdio(false);
    char str[20];
    cin>>str;
    int i=0;
    int bin[MAX_CHAR]={0};
    int r=0;
    char temp;
    while(*(str + i))
    {
        temp=*(str + i);
        if(bin[temp]==0)
        {
            bin[temp]=1;
            *(str + r)=*(str + i );
            r++;
        }
        i++;
    }
    *(str + r)='\0';
    cout<<str;
    return 0;
}
