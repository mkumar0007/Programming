#include<bits/stdc++.h>
using namespace std;

void print(char str[],char buff[],int i,int j,int n)
{
    if(i==n)
    {
        buff[j]='\0';
        cout<<buff<<endl;
        return ;
    }
    buff[j]=str[i];
    print(str,buff,i+1,j+1,n);
    buff[j]=' ';
    buff[j+1]=str[i];
    print(str,buff,i+1,j+2,n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    char str[20];
    cin>>str;
    int n=strlen(str);
    char buff[2*n];
    buff[0]=str[0];
    print(str,buff,1,1,n);
    cin.tie(NULL);
    return 0;
}
