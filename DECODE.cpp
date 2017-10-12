#include<bits/stdc++.h>
using namespace std;

void decode(string s){
    int len=s.length();
    int mid,x=0,c=1;
    if(len%2==0)
        mid=len/2;
    else
        mid=(len/2)+1;
    char res[len+1];
    if(len%2==0)
    {
        res[mid]=s.at(0);
        for(int i=1;i<len;i++)
        {
            if(i%2==0)
            {
                res[mid-c]=s.at(i);
            }
            else
            {
                res[mid+c]=s.at(i);
            }
            x++;
            if(x==2)
            {
                c++;
                x=0;
            }
        }
    }
    else
    {
        res[mid]=s.at(0);
        for(int i=1;i<len;i++)
        {
            if(i%2==1)
            {
                res[mid-c]=s.at(i);
            }
            else
            {
                res[mid+c]=s.at(i);
            }
            x++;
            if(x==2)
            {
                c++;
                x=0;
            }
        }
    }
    cout<<res;
    return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    string s;
    getline(cin,s);
    decode(s);
    cin.tie(NULL);
    return 0;
}

