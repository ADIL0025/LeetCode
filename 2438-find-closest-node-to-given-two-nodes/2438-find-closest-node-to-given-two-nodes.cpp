class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {

        int numNodes = edges.size();
        vector<vector<int>> graph(numNodes);
        for (int i = 0; i < numNodes; ++i) {
            if (edges[i] != -1) {
                graph[i].push_back(edges[i]);
            }
        }
        const int infinity = 1 << 30;
        using DistNodePair = pair<int, int>;

        auto dijkstra = [&](int startNode) {
            vector<int> distances(numNodes, infinity);
            distances[startNode] = 0;
            priority_queue<DistNodePair, vector<DistNodePair>, greater<DistNodePair>> pq;
            pq.emplace(0, startNode);
            while (!pq.empty()) {
                auto pair = pq.top();
                pq.pop();
                int currentNode = pair.second;
                for (int neighbor : graph[currentNode]) {
                    if (distances[neighbor] > distances[currentNode] + 1) {
                        distances[neighbor] = distances[currentNode] + 1;
                        pq.emplace(distances[neighbor], neighbor);
                    }
                }
            }
            return distances;
        };
        vector<int> distancesFromNode1 = dijkstra(node1);
        vector<int> distancesFromNode2 = dijkstra(node2);

        int closestNode = -1;
        int minDistance = infinity;

        for (int i = 0; i < numNodes; ++i) {
            int maxDist = max(distancesFromNode1[i], distancesFromNode2[i]);
            if (maxDist < minDistance) {
                minDistance = maxDist;
                closestNode = i;
            }
        }
        return closestNode;
    }
};