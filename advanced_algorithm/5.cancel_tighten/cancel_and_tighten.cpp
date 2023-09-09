// 1. Initialization: Begin by sending as much flow as possible (ignoring costs).

// 2. Cancel Negative Cycles: If there is a negative cycle in the residual graph, 
// send flow along this cycle. Repeat until there are no negative cycles.

// 3. Tighten (using potentials): Modify the costs of the edges 
// using the potentials of nodes so that the modified costs are non-negative.

// 4. Augment Flow: Find the shortest path from source to sink in the residual graph (using modified costs). 
// Send as much flow as possible along this path.

// 5. Repeat steps 2-4 until no augmenting paths exist.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

const int INF = 1e9;

struct Edge {
    int from, to, capacity, cost, flow;
};

std::vector<std::vector<int>> adj; // adjacency list
std::vector<Edge> edges;
std::vector<int> distance, parent;

bool bellmanFord(int source, int sink) {
    distance.assign(adj.size(), INF);
    parent.assign(adj.size(), -1);
    distance[source] = 0;
    for (int i = 0; i < adj.size() - 1; ++i) {
        for (int u = 0; u < adj.size(); ++u) {
            for (int v : adj[u]) {
                if (edges[v].capacity - edges[v].flow > 0 &&
                // edges[v] what does this mean? Look at addEdge carefully.
                    distance[u] + edges[v].cost < distance[edges[v].to]) {
                    distance[edges[v].to] = distance[u] + edges[v].cost;
                    parent[edges[v].to] = v;
                }
            }
        }
    }
    return distance[sink] != INF;
}

std::pair<int, int> minCostMaxFlow(int source, int sink) {
    int flow = 0, cost = 0;
    while (bellmanFord(source, sink)) {
        int path_flow = INF, path_cost = 0;
        for (int v = sink; v != source; v = edges[parent[v]].from) {
            path_flow = std::min(path_flow, edges[parent[v]].capacity - edges[parent[v]].flow);
        }
        flow += path_flow;
        for (int v = sink; v != source; v = edges[parent[v]].from) {
            edges[parent[v]].flow += path_flow;
            edges[parent[v] ^ 1].flow -= path_flow; // reverse edge
            path_cost += edges[parent[v]].cost * path_flow;
        }
        cost += path_cost;
    }
    return {flow, cost};
}

void addEdge(int u, int v, int capacity, int cost) {
    adj[u].push_back(edges.size());
    edges.push_back({u, v, capacity, cost, 0});
    adj[v].push_back(edges.size());
    edges.push_back({v, u, 0, -cost, 0}); // reverse edge
}

int main() {
    int n, m; 
    std::cin >> n >> m; // n = number of nodes, m = number of edges

    adj.resize(n);
    for (int i = 0; i < m; ++i) {
        int u, v, capacity, cost;
        std::cin >> u >> v >> capacity >> cost;
        addEdge(u, v, capacity, cost);
    }

    int source, sink;
    std::cin >> source >> sink;
    auto [maxFlow, minCost] = minCostMaxFlow(source, sink);
    std::cout << "Max Flow: " << maxFlow << ", Min Cost: " << minCost << std::endl;

    return 0;
}
