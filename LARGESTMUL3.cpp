#include<bits/stdc++.h>
using namespace std;
int rem[2];
bool  largestmultiple(int a[],int n)
{
    sort(a,a+n);
    int sum=accumulate(a,a+n,0);
    if(sum%3==0)
        return true;
    int remainder=sum%3;
    if(remainder==1)
    {
        for(int i=0;i<n;i++)
        {
            if(a[i]%3==1)
            {
                rem[0]=i;
                return true;
            }
            if(a[i]%3==2)
            {
                if(rem[0]!=-1)
                    rem[0]=i;
                else if(rem[1]!=-1)
                    rem[1]=i;
            }
        }
    }
    else if(remainder==2)
    {
        for(int i=0;i<n;i++)
        {
            if(a[i]%3==2)
            {
                rem[0]=i;
                return true;
            }
            if(a[i]%3==1)
            {
                if(rem[0]!=-1)
                    rem[0]=i;
                else if(rem[1]!=-1)
                    rem[1]=i;
            }
        }
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    rem[0]=-1;
    rem[1]=-1;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    largestmultiple(a,n);
    for(int i=n-1;i>=0;i--)
    {
        if(i!=rem[0]&&i!=rem[2])
            cout<<a[i]<<" ";
    }
    return 0;
}
