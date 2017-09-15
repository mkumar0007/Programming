#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,y;
    cin>>x>>y;
    vector<vector<int> > B(x,vector<int>(y));
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            cin>>B[i][j];
        }
    }
    int A;
    cin>>A;
    vector<vector<int> > solution;
    int n=B.size();
    int m=B[0].size();
    int i;
    for(i=0;i<n;i++)
    {
        solution.push_back(B[i]);
    }
    int k,j;
    int t;
    for(k=1;k<=A;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(i-1>=0)
                    solution[i][j]=max(solution[i][j],B[i-1][j]);
                if(i+1<n)
                    solution[i][j]=max(solution[i][j],B[i+1][j]);
                if(j-1>=0)
                    solution[i][j]=max(solution[i][j],B[i][j-1]);
                if(j+1<m)
                    solution[i][j]=max(solution[i][j],B[i][j+1]);
            }
        }
        B=solution;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<solution[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
