#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct AdjEdge_rrl { int vertex_rrl; int weight_rrl; };

void dijkstra_rrl(int vertices_rrl, vector<vector<AdjEdge_rrl>> &adj_rrl, int src_rrl, int dest_rrl) {
    vector<int> dist_rrl(vertices_rrl, INT_MAX);
    vector<int> parent_rrl(vertices_rrl, -1);
    vector<bool> visited_rrl(vertices_rrl, false);
    using pii_rrl = pair<int,int>;
    priority_queue<pii_rrl, vector<pii_rrl>, greater<pii_rrl>> pq_rrl;
    dist_rrl[src_rrl] = 0;
    pq_rrl.push({0, src_rrl});
    while (!pq_rrl.empty()) {
        auto top_rrl = pq_rrl.top(); pq_rrl.pop();
        int u_rrl = top_rrl.second;
        if (visited_rrl[u_rrl]) continue;
        visited_rrl[u_rrl] = true;
        if (u_rrl == dest_rrl) break;
        for (auto ed_rrl : adj_rrl[u_rrl]) {
            int v_rrl = ed_rrl.vertex_rrl;
            int w_rrl = ed_rrl.weight_rrl;
            if (!visited_rrl[v_rrl] && dist_rrl[u_rrl] != INT_MAX && dist_rrl[u_rrl] + w_rrl < dist_rrl[v_rrl]) {
                dist_rrl[v_rrl] = dist_rrl[u_rrl] + w_rrl;
                parent_rrl[v_rrl] = u_rrl;
                pq_rrl.push({dist_rrl[v_rrl], v_rrl});
            }
        }
    }
    if (dist_rrl[dest_rrl] == INT_MAX) {
        cout << "No path from " << src_rrl << " to " << dest_rrl << "\n";
        return;
    }
    cout << "Shortest distance from " << src_rrl << " to " << dest_rrl << " = " << dist_rrl[dest_rrl] << "\n";
    vector<int> path_rrl;
    for (int v_rrl = dest_rrl; v_rrl != -1; v_rrl = parent_rrl[v_rrl]) path_rrl.push_back(v_rrl);
    cout << "Path: ";
    for (int i_rrl = (int)path_rrl.size() - 1; i_rrl >= 0; i_rrl--) {
        cout << path_rrl[i_rrl];
        if (i_rrl) cout << " -> ";
    }
    cout << "\n";
}

int main() {
    int vertices_rrl = 0, edges_rrl = 0;
    vector<vector<AdjEdge_rrl>> adj_rrl;
    int choice_rrl = 0;
    while (true) {
        cout << "1. Input graph\n2. Display adjacency list\n3. Dijkstra shortest path\n4. Exit\nEnter choice: ";
        if (!(cin >> choice_rrl)) return 0;
        if (choice_rrl == 1) {
            cout << "Enter number of vertices: ";
            cin >> vertices_rrl;
            cout << "Enter number of edges: ";
            cin >> edges_rrl;
            adj_rrl.assign(vertices_rrl, vector<AdjEdge_rrl>());
            cout << "Enter edges (u v weight):\n";
            for (int i_rrl = 0; i_rrl < edges_rrl; i_rrl++) {
                int u_rrl, v_rrl, w_rrl;
                cin >> u_rrl >> v_rrl >> w_rrl;
                if (u_rrl >= 0 && u_rrl < vertices_rrl && v_rrl >= 0 && v_rrl < vertices_rrl) {
                    AdjEdge_rrl a1_rrl = {v_rrl, w_rrl};
                    adj_rrl[u_rrl].push_back(a1_rrl);
                }
            }
        } else if (choice_rrl == 2) {
            cout << "Adjacency List:\n";
            for (int i_rrl = 0; i_rrl < (int)adj_rrl.size(); i_rrl++) {
                cout << i_rrl << ": ";
                for (auto ed_rrl : adj_rrl[i_rrl]) cout << "(" << ed_rrl.vertex_rrl << "," << ed_rrl.weight_rrl << ") ";
                cout << "\n";
            }
        } else if (choice_rrl == 3) {
            if (vertices_rrl == 0) { cout << "Graph not defined\n"; continue; }
            int src_rrl, dest_rrl;
            cout << "Enter source vertex: "; cin >> src_rrl;
            cout << "Enter destination vertex: "; cin >> dest_rrl;
            if (src_rrl < 0 || src_rrl >= vertices_rrl || dest_rrl < 0 || dest_rrl >= vertices_rrl) {
                cout << "Invalid vertices\n";
                continue;
            }
            dijkstra_rrl(vertices_rrl, adj_rrl, src_rrl, dest_rrl);
        } else if (choice_rrl == 4) {
            return 0;
        } else {
            cout << "Invalid choice\n";
        }
    }
    return 0;
}
