#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    void topologicalsortutil(int v,bool visited[],stack<int> &st);
public:
    Graph(int V)
    {
        this->V=V;
        adj=new list<int>[V];
    }
    void addEdge(int v,int w);
    void topologicalsort();
};

void Graph::addEdge(int v,int w)
{
    adj[v].push_back(w);
}

void Graph::topologicalsortutil(int v,bool visited[],stack<int> &st)
{
    visited[v]=true;
    list<int>:: iterator i;
    for(i=adj[v].begin();i!=adj[v].end();i++)
    {
        if(!visited[*i])
            topologicalsortutil(*i,visited,st);
    }
    st.push(v);
}

void Graph::topologicalsort()
{
    bool *visited=new bool[V];
    stack<int> st;
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
    }
    for(int i=0;i<V;i++)
    {
        if(visited[i]==false)
            topologicalsortutil(i,visited,st);
    }
    while(st.empty()==false)
    {
        cout<<(char)('a'+st.top())<<" ";
        st.pop();
    }
}

void printorder(string words[],int n,int edge)
{
    Graph g(edge);
    for(int i=0;i<n-1;i++)
    {
        string word1=words[i],word2=words[i+1];
        for(int j=0;j<min(word1.length(),word2.length());j++)
        {
            if(word1[j]!=word2[j])
            {
                g.addEdge(word1[j]-'a',word2[j]-'a');
                break;
            }
        }
    }
    g.topologicalsort();
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    string words[n];
    for(int i=0;i<n;i++)
    {
        cin>>words[i];
    }
    printorder(words,n,n-1);
    cin.tie(NULL);
    return 0;
}
