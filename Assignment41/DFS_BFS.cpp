#include <iostream>
#include <queue>
using namespace std;

void bfs_rrl(int vertices_rrl, int adjMatrix_rrl[][10], int start_rrl) {
    bool visited_rrl[vertices_rrl];
    for (int i_rrl = 0; i_rrl < vertices_rrl; i_rrl++)
        visited_rrl[i_rrl] = false;

    queue<int> q_rrl;
    q_rrl.push(start_rrl);
    visited_rrl[start_rrl] = true;

    cout << "BFS Traversal: ";
    while (!q_rrl.empty()) {
        int current_rrl = q_rrl.front();
        q_rrl.pop();
        cout << current_rrl << " ";
        for (int i_rrl = 0; i_rrl < vertices_rrl; i_rrl++) {
            if (adjMatrix_rrl[current_rrl][i_rrl] && !visited_rrl[i_rrl]) {
                q_rrl.push(i_rrl);
                visited_rrl[i_rrl] = true;
            }
        }
    }
    cout << endl;
}

void dfs_rrl(int vertices_rrl, int adjMatrix_rrl[][10], int start_rrl) {
    bool visited_rrl[vertices_rrl];
    for (int i_rrl = 0; i_rrl < vertices_rrl; i_rrl++)
        visited_rrl[i_rrl] = false;

    int stack_rrl[vertices_rrl];
    int top_rrl = -1;
    stack_rrl[++top_rrl] = start_rrl;

    cout << "DFS Traversal: ";
    while (top_rrl >= 0) {
        int current_rrl = stack_rrl[top_rrl--];
        if (!visited_rrl[current_rrl]) {
            cout << current_rrl << " ";
            visited_rrl[current_rrl] = true;
            for (int i_rrl = vertices_rrl - 1; i_rrl >= 0; i_rrl--) {
                if (adjMatrix_rrl[current_rrl][i_rrl] && !visited_rrl[i_rrl]) {
                    stack_rrl[++top_rrl] = i_rrl;
                }
            }
        }
    }
    cout << endl;
}

int main() {
    int vertices_rrl, choice_rrl, start_rrl;
    int adjMatrix_rrl[10][10];

    cout << "Enter number of vertices: ";
    cin >> vertices_rrl;

    cout << "Enter adjacency matrix:\n";
    for (int i_rrl = 0; i_rrl < vertices_rrl; i_rrl++) {
        for (int j_rrl = 0; j_rrl < vertices_rrl; j_rrl++) {
            cin >> adjMatrix_rrl[i_rrl][j_rrl];
        }
    }

    while (true) {
        cout << "\n1. BFS Traversal\n2. DFS Traversal\n3. Exit\nEnter choice: ";
        cin >> choice_rrl;

        if (choice_rrl == 1) {
            cout << "Enter starting vertex (0-" << vertices_rrl - 1 << "): ";
            cin >> start_rrl;
            bfs_rrl(vertices_rrl, adjMatrix_rrl, start_rrl);
        }
        else if (choice_rrl == 2) {
            cout << "Enter starting vertex (0-" << vertices_rrl - 1 << "): ";
            cin >> start_rrl;
            dfs_rrl(vertices_rrl, adjMatrix_rrl, start_rrl);
        }
        else if (choice_rrl == 3) {
            break;
        }
        else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
