#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

class Graph {
    vector<bool> visited;
    vector<bool> visitedBfs;
    queue<int> queueBfs;

    public:
    vector<vector<int>> adjList;

    Graph() {
        adjList = vector<vector<int>>();
    }

    bool findNode(int data) {
        // Node* curr = head;
        // while (curr != nullptr)
        // {
        //     if (curr->data == data) {
        //         return true;
        //     }
        //     curr = curr->next;
        // }
        return false;
    }

    void dfs() {
        visited = vector<bool>(adjList.size());

        // for (int i = 0; i < visited.size(); ++i) {
        //     cout << visited[i] << " ";
        // }
        // cout << endl;

        dfs(0);
        cout << endl;

    }

    void bfs() {
        queueBfs = queue<int>();
        visitedBfs = vector<bool>(adjList.size());

        // for (int i = 0; i < visitedBfs.size(); ++i) {
        //     cout << visitedBfs[i] << " ";
        // }
        // cout << endl;

        visitedBfs[0] = true;
        bfs(0);
        cout << endl;

    }

    private:

    void dfs(int curr) {
        visited[curr] = true;
        cout << curr << " ";
        for (int neighbour: adjList[curr]) {
            if (!visited[neighbour]) {
                dfs(neighbour);
            }
        }
    }

    void bfs(int curr) {
        cout << curr << " ";
        for (int neighbour: adjList[curr]) {
            if (!visitedBfs[neighbour]) {
                queueBfs.push(neighbour);
                visitedBfs[neighbour] = true;
            }
        }
        
        // cout << "stack: ";
        // stack<int> temp = stack<int>(queueBfs);
        // while (!temp.empty()) {
        //     cout << temp.top() << " ";
        //     temp.pop();
        // }
        // cout << endl;

        if (queueBfs.empty()) {
            return;
        }
        else {
            int front = queueBfs.front();
            queueBfs.pop();

            // cout << "stack: ";
            // temp = stack<int>(queue);
            // while (!temp.empty()) {
            //     cout << temp.top() << " ";
            //     temp.pop();
            // }
            // cout << endl;

            bfs(front);
        }
    }

};

void t2() {
    Graph graph = Graph();
    
    vector<int> l1 = vector<int>();
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    graph.adjList.push_back(l1);
    
    l1 = vector<int>();    
    l1.push_back(0);
    l1.push_back(2);
    graph.adjList.push_back(l1);

    l1 = vector<int>();    
    l1.push_back(0);
    l1.push_back(1);
    l1.push_back(4);
    graph.adjList.push_back(l1);

    l1 = vector<int>();    
    l1.push_back(0);
    graph.adjList.push_back(l1);

    l1 = vector<int>();    
    l1.push_back(2);
    graph.adjList.push_back(l1);

    graph.dfs();
    graph.bfs();
}

void t1() {
    Graph graph = Graph();
    
    vector<int> l1 = vector<int>();
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    graph.adjList.push_back(l1);
    
    l1 = vector<int>();    
    l1.push_back(0);
    l1.push_back(2);
    graph.adjList.push_back(l1);

    l1 = vector<int>();    
    l1.push_back(0);
    l1.push_back(1);
    graph.adjList.push_back(l1);

    l1 = vector<int>();    
    l1.push_back(0);
    graph.adjList.push_back(l1);

    graph.dfs();
    graph.bfs();
}

int main(int argc, char* argv[]) {
    t1();
    t2();
}