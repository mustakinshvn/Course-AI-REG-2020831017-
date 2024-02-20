#include<bits/stdc++.h>
using namespace std;

// Graph represented as an adjacency list
vector<vector<int>> adj;

// Depth-Limited Search (DLS) function
bool DLS(int start, int goal, int depth_limit) {
    stack<pair<int, int>> stk; // Using a stack to perform DFS

    stk.push({start, 0});

    while (!stk.empty()) {
        pair<int, int> current = stk.top();
        stk.pop();

        int node = current.first;
        int depth = current.second;

        // Check if goal is found
        if (node == goal) {
            cout << "Goal is found at depth: " << depth << endl;
            return true;
        }

        // If depth limit is reached, skip exploring further
        if (depth >= depth_limit)
            continue;

        // Explore neighbors
        for (int neighbor : adj[node]) {
            stk.push({neighbor, depth + 1});
        }
    }

    return false; // Goal not found within depth limit
}

// Iterative Deepening Depth-First Search (IDS) function
bool IDS(int start, int goal, int max_depth) {
    for (int depth_limit = 0; depth_limit <= max_depth; ++depth_limit) {
        cout << "Searching with depth limit: " << depth_limit << endl;
        if (DLS(start, goal, depth_limit))
            return true;
    }
    return false; // Goal not found within maximum depth
}

int main() {
    // Number of vertices
    int n; 
    cin >> n;

    // The graph
    for(int i = 0; i < n; i++) {
        int u, v; 
        cin >> u >> v;

        int maxVertex = max(u, v);
        if (maxVertex >= adj.size()) {
            adj.resize(maxVertex + 1);
        }

        adj[u].push_back(v);
    }

    // Starting node
    int start; 
    cin >> start;

    // Goal node
    int goal;  
    cin >> goal;

    // Maximum depth
    int max_depth; 
    cin >> max_depth;

    if (IDS(start, goal, max_depth))
        cout << "Goal is found within maximum depth." << endl;
    else
        cout << "Goal is not found within maximum depth." << endl;

    return 0;
}


/*

Input

5

0 1
0 2
1 3
1 4
2 5

0
5
3 





Output
Searching with depth limit: 0
Searching with depth limit: 1
Searching with depth limit: 2
Goal is found at depth: 2
Goal is found within maximum depth.


*/

