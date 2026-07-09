#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<vector<int>> &graph, vector<bool> &visited, int node)
{
    visited[node]=true;
    cout<<node<<" ";
    for(int neighbor: graph[node])
        if(!visited[neighbor])
            DFS(graph, visited, neighbor);
}

int main()
{
    int vertices, edges;
    cout<<"Enter number of vertices: ";
    cin>>vertices;
    vector<vector<int>> graph(vertices);

    cout<<"Enter number of edges: ";
    cin>>edges;
    cout<<"Enter edges (u v):"<<endl;
    for(int i=0;i<edges;i++){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start;
    cout<<"Enter starting vertex: ";
    cin>>start;

    vector<bool> visited(vertices,false);
    cout<<"DFS Traversal: ";
    DFS(graph, visited, start);
    return 0;
}
