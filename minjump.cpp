#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int maxreach=a[0];
    int step=a[0];
    int jump=1;
    for(int i=1;i<n;i++)
    {
        maxreach=max(maxreach,i+a[i]);
        step--;
        if(step==0)
        {
            jump++;
            if(step>=maxreach-i)
            {
                return -1;
            }
            step=maxreach-i;
        }
    }
    cout<<jump;
    return 0;
}
