#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Graph {
    vector<pair<int, int> > *l;
    int V;

   public:
    Graph(int n) {
        V = n;
        l = new vector<pair<int, int> >[n];
    }

    void addEdge(int x, int y, int w) {
        l[x].push_back({y, w});
        l[y].push_back({x, w});
    }

    int prim_mst() {
        priority_queue<pair<int, int>, vector<pair<int, int> >,
                       greater<pair<int, int> > >
            Q;

        bool *vis = new bool[V]{0};
        int ans = 0;

        Q.push({0, 0});  // weight, node

        while (!Q.empty()) {
            auto best = Q.top();
            Q.pop();

            int to = best.second;
            int weight = best.first;

            if (vis[to]) {
                continue;
            }
            ans += weight;
            vis[to] = 1;
            for (auto x : l[to]) {
                if (vis[x.first] == 0) {
                    Q.push({x.second, x.first});
                }
            }
        }
        return ans;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    Graph g(n);
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        g.addEdge(x - 1, y - 1, w);
    }

    cout << g.prim_mst() << endl;
}