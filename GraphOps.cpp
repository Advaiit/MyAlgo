#include <iostream>
#include <list>
using namespace std;

class Graph
{
    int v;
    list<int> *adjList;

    void DFSUtil(int s, bool visited[]);

public:
    Graph(int v);
    bool addEdge(int s, int d);
    bool DFS(int s);
    bool BFS(int s);
};

Graph::Graph(int nVertex)
{
    v = nVertex;
    adjList = new list<int>[v];
}

bool Graph::addEdge(int s, int d)
{
    if(s > v || d > v)
        return false;

    adjList[s].push_back(d);

    return true;
}

bool Graph::BFS(int s)
{
    bool visited[v] = {false};
    list<int> queue;

    for(int i = 0; i < v; i++)
        visited[i] = false;
    
    queue.push_back(s);
    visited[s] = true;

    list<int>::iterator i;
    cout<<"BFS: \n";

    while(!queue.empty())
    {
        s = queue.front();
        cout<<s<<" ";
        queue.pop_front();

        for(i = adjList[s].begin(); i != adjList[s].end(); ++i)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }

    cout<<"\n";

    return true;
}

void Graph::DFSUtil(int s, bool visited[])
{
    visited[s] = true;
    cout<<s<<" ";

    list<int>::iterator i;

    for(i = adjList[s].begin() ; i != adjList[s].end(); i++)
    {
        if(!visited[*i])
        {
            DFSUtil(*i, visited);
        }
    }
}

bool Graph::DFS(int s)
{
    bool visited[v] = {false};

    for(int i = 0; i < v; i++)
    {
        if(!visited[i])
            DFSUtil(s, visited);
    }

    return true;
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    //g.BFS(2);
    g.DFS(2);
}