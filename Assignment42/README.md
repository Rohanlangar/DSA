# Assignment No : 31
### Title : Write a Program to implement Prim’s algorithm to find minimum spanning tree of a user defined graph using adjacency list.

---

### Theory :
A **graph** is a set of vertices connected by edges.  
**Prim’s algorithm** finds a **Minimum Spanning Tree (MST)** of a weighted undirected graph.  
It selects edges with **minimum weight** to connect all vertices without forming a cycle.

**Adjacency List Representation:**
- Each vertex stores a list of edges connecting it to adjacent vertices.  
- Efficient for sparse graphs.

---

### Algorithm :
1. Initialize all keys as infinite and MST set as false.  
2. Pick a vertex with minimum key not yet included in MST.  
3. Include the vertex in MST.  
4. Update keys of adjacent vertices if edge weight is less than current key.  
5. Repeat until all vertices are included.  
6. Display edges in MST with their weights.

### Code 
```
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge_rrl {
    int vertex_rrl;
    int weight_rrl;
};

int selectMinVertex_rrl(vector<int> &key_rrl, vector<bool> &mstSet_rrl, int vertices_rrl) {
    int min_rrl = INT_MAX, minIndex_rrl = -1;
    for (int v_rrl = 0; v_rrl < vertices_rrl; v_rrl++) {
        if (!mstSet_rrl[v_rrl] && key_rrl[v_rrl] < min_rrl) {
            min_rrl = key_rrl[v_rrl];
            minIndex_rrl = v_rrl;
        }
    }
    return minIndex_rrl;
}

void primMST_rrl(int vertices_rrl, vector<vector<Edge_rrl>> &adj_rrl) {
    vector<int> parent_rrl(vertices_rrl);
    vector<int> key_rrl(vertices_rrl, INT_MAX);
    vector<bool> mstSet_rrl(vertices_rrl, false);

    key_rrl[0] = 0;
    parent_rrl[0] = -1;

    for (int count_rrl = 0; count_rrl < vertices_rrl - 1; count_rrl++) {
        int u_rrl = selectMinVertex_rrl(key_rrl, mstSet_rrl, vertices_rrl);
        mstSet_rrl[u_rrl] = true;

        for (auto edge_rrl : adj_rrl[u_rrl]) {
            int v_rrl = edge_rrl.vertex_rrl;
            int weight_rrl = edge_rrl.weight_rrl;
            if (!mstSet_rrl[v_rrl] && weight_rrl < key_rrl[v_rrl]) {
                key_rrl[v_rrl] = weight_rrl;
                parent_rrl[v_rrl] = u_rrl;
            }
        }
    }

    cout << "Edge \tWeight\n";
    for (int i_rrl = 1; i_rrl < vertices_rrl; i_rrl++)
        cout << parent_rrl[i_rrl] << " - " << i_rrl << "\t" << key_rrl[i_rrl] << endl;
}

int main() {
    int vertices_rrl, edges_rrl, u_rrl, v_rrl, w_rrl;
    cout << "Enter number of vertices: ";
    cin >> vertices_rrl;
    cout << "Enter number of edges: ";
    cin >> edges_rrl;

    vector<vector<Edge_rrl>> adj_rrl(vertices_rrl);

    cout << "Enter edges (u v weight):\n";
    for (int i_rrl = 0; i_rrl < edges_rrl; i_rrl++) {
        cin >> u_rrl >> v_rrl >> w_rrl;
        Edge_rrl e1_rrl = {v_rrl, w_rrl};
        Edge_rrl e2_rrl = {u_rrl, w_rrl};
        adj_rrl[u_rrl].push_back(e1_rrl);
        adj_rrl[v_rrl].push_back(e2_rrl);
    }

    primMST_rrl(vertices_rrl, adj_rrl);
    return 0;
}

```
### Output 

