#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(vector<vector<int>> &graph, int start, int vertices)
{
    vector<bool> visited(vertices, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";

    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int neighbor : graph[current])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main()
{
    int vertices, edges;
    cout << "Enter number of vertices: ";
    cin >> vertices;

    vector<vector<int>> graph(vertices);

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    BFS(graph, start, vertices);
    return 0;
}
