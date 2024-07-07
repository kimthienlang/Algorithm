#include <bits/stdc++.h>

using namespace std;

// Function to perform breadth-first search
void BFS(vector<vector<int>>& graph, int startVertex) {
    int numVerties = graph.size();
    bool visited[numVerties];
    memset(visited, false, sizeof(visited)/sizeof(visited[0]));
    queue<int> queue;

    queue.push(startVertex);
    visited[startVertex] = true;

    while (!queue.empty())
    {
        int currentVertext = queue.front();
        cout << currentVertext << " - ";
        queue.pop();
        for (int i = 1; i < numVerties; ++i) {
            if (graph[currentVertext][i] && !visited[i]) 
            {
                queue.push(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    int numVertices = 14;
    int edges = 19;

    vector<vector<int>> graph(numVertices, vector<int>(numVertices, 0));
    
    for (int i = 0; i < edges; ++i) {
        int source, destination;
        cin >> source >> destination;
        graph[source][destination] = 1;
        graph[destination][source] = 1;
    }


    int startVertex = 3;

    cout << "BFS traversal starting from vertex " << startVertex << ": ";
    BFS(graph, startVertex);

    return 0;
}

/*
    1 6
    1 2
    1 3
    1 4
    1 10
    2 6
    2 3
    3 4
    4 10
    2 7
    2 5
    3 5
    4 5
    4 8
    4 9
    7 5
    5 8
    5 12
    8 11
*/