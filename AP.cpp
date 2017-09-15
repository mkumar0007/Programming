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
    int llap=2;
    int L[n][n];
    for(int i=0;i<n;i++)
    {
        L[i][n-1]=2;
    }
    for(int j=n-2;j>=1;j--)
    {
        int i=j-1,k=j+1;
        while(i>=0&&k<=n-1)
        {
            if(a[i]+a[k]<2*a[j])
            {
                k++;
            }
            else if(a[i]+a[k]>2*a[j])
            {
                L[i][j]=2;
                i--;
            }
            else
            {
                L[i][j]=L[j][k]+1;
                llap=max(llap,L[i][j]);
                i--;
                k++;
            }
        }
        while(i>=0)
        {
            L[i][j]=2;
            i--;
        }
    }
    cout<<llap;
    return 0;
}
