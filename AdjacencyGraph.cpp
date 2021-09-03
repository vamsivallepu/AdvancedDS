#include<bits/stdc++.h>
using namespace std;

class Graph {
    int numVertices;
    vector<int> *adj;
    bool *visited;

   public:
    Graph() {
        cout << "Enter no. of vertices : ";
        cin >> numVertices;
        adj = new vector<int>[numVertices];
        cout << "Enter vertices :\n";
        for (int i = 0; i < numVertices; i++) {
            int t;
            cin >> t;
            adj[i].push_back(t);
        }
        visited=new bool[numVertices];
        for(int i=0; i<numVertices; i++){
            visited[numVertices]=false;
        }
    }
    void addEdge(int from, int to) {
        // cout<<"in add edge\n";
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    void printGraph() {
        for (int v = 0; v < numVertices; v++) {
            vector<int>::iterator it;
            it = adj[v].begin();
            cout << *it;
            it++;
            while (it != adj[v].end()) {
                cout << " -> " << *it;
                it++;
            }
            printf("\n");
        }
    }
    void BFS(){
        queue<int> q;
        bool visited[numVertices];
        for(int i=0; i<numVertices; i++) visited[i]=false;
        q.push(adj[0][0]);
        visited[0]=true;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            cout<<u<<" ";
            for(int v: adj[u]){
                if(!visited[v]){
                    q.push(v);
                    visited[v]=true;
                }
            }
        }
    }
    void dfs(int s=0){
        visited[s]=true;
        cout<<s<<" ";
        for(int i: adj[s]){
            if(!visited[i]) dfs(i);
        }
    }
    void findDegree() {
        for (int i = 0; i < numVertices; i++) {
            cout << "Degree of " << adj[i].front() << " is "
                 << adj[i].size() - 1;
            cout << "\n";
        }
    }
};
int main() {
    Graph g;
    g.addEdge(0, 2);
    g.addEdge(0, 4);
    g.addEdge(1, 3);
    g.addEdge(1, 2);
    g.addEdge(5, 4);
    g.addEdge(4, 3);
    g.printGraph();
    // g.findDegree();
    g.dfs();
    return 0;
}