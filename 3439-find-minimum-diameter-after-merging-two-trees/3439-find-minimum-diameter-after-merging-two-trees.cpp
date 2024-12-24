class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        vector<vector<int>> g = packU(n, edges1);
        int m = edges2.size() + 1;
        vector<vector<int>> h = packU(m, edges2);
        vector<int> d1 = diameter(g);
        vector<int> d2 = diameter(h);
        int ans = max(d1[0], d2[0]);
        ans = max((d1[0] + 1) / 2 + (d2[0] + 1) / 2 + 1, ans);
        return ans;
    }

private:
    vector<int> diameter(const vector<vector<int>>& g) {
        int n = g.size();
        int f0, f1, d01;
        vector<int> q(n);
        vector<bool> visited(n, false);
        int qp = 0;
        q[qp++] = 0;
        visited[0] = true;

        // First BFS to find one endpoint of the diameter
        for (int i = 0; i < qp; ++i) {
            int cur = q[i];
            for (int neighbor : g[cur]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q[qp++] = neighbor;
                }
            }
        }
        f0 = q[qp - 1];

        // Second BFS from f0 to find the other endpoint and calculate distances
        vector<int> d(n, 0);
        qp = 0;
        fill(visited.begin(), visited.end(), false);
        q[qp++] = f0;
        visited[f0] = true;
        for (int i = 0; i < qp; ++i) {
            int cur = q[i];
            for (int neighbor : g[cur]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q[qp++] = neighbor;
                    d[neighbor] = d[cur] + 1;
                }
            }
        }
        f1 = q[qp - 1];
        d01 = d[f1];
        return {d01, f0, f1};
    }

    vector<vector<int>> packU(int n, const vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (const auto& edge : edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        return g;
    }
};
