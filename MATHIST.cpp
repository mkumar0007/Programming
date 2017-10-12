#include<bits/stdc++.h>
using namespace std;
bool comp(int a,int b)
{
    return a>b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int r,c;
    cin>>r>>c;
    int a[r][c];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>a[i][j];
        }
    }
    int hist[r+1][c+1];
    for(int i=0;i<c;i++)
    {
        hist[0][i]=a[0][i];
    }
    for (int i=1; i<r; i++)
    {
        for (int j=0; j<c; j++)
            hist[i][j] = (a[i][j]==0)? 0: hist[i-1][j]+1;
    }
    for(int i=0;i<r;i++)
    {
        sort(hist[i],hist[i]+c,comp);
    }
    int curr_area, max_area = 0;
    for (int i=0; i<r; i++)
    {
        for (int j=0; j<c; j++)
        {
            curr_area = (j+1)*hist[i][j];
            if (curr_area > max_area)
                max_area = curr_area;
        }
    }
    cout<<max_area;
    cin.tie(NULL);
    return 0;
}
