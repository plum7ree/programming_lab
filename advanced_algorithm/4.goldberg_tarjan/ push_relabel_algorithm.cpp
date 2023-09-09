

// The Goldberg-Tarjan algorithm is an approach to find the minimum-cost circulation in a flow network. A circulation is simply a flow that satisfies all capacity and demand constraints and has no net inflow or outflow at any vertex. The minimum-cost circulation problem seeks to find the least expensive circulation in terms of edge costs.

// Goldberg and Tarjan developed a "successive approximation" method to solve the min-cost circulation problem, which is essentially a refined version of the capacity scaling method.

// Here's a brief summary of the Goldberg-Tarjan algorithm for min-cost circulation:

// Initialize all flows to zero.
// Scale the capacities.
// Use a shortest-path algorithm (like Dijkstra's or Bellman-Ford) to find augmenting paths.
// Augment the flow along the found path.
// Repeat until no augmenting paths can be found for the current scale.
// Reduce the scale and go back to step 3 until the scale is less than a predetermined value.
// Finalize the result using a non-scaled augmenting path search.
// Implementing the Goldberg-Tarjan algorithm requires a deep understanding of flow network algorithms 
// and is relatively complex. The actual code can be extensive and might not be feasible to write out in a single response.

// If you're planning to implement the algorithm, I'd recommend starting with a well-tested max-flow library 
// and then adapting it for the min-cost circulation problem. 
// You'd also benefit from having the original paper by Goldberg and Tarjan on hand, 
// titled "Finding minimum-cost circulations by canceling negative cycles." 
// This paper provides a detailed description of the algorithm and its intricacies.

// For those looking to solve real-world problems without delving into the intricacies of algorithm implementation, 
// it might be more practical to use existing software packages or libraries that provide routines for solving min-cost circulation problems,
// such as the Lemon C++ library or the NetworkX Python library.

// Augmenting Path
// In the context of network flow problems, an augmenting path is a simple path from the source 
// to the sink in the residual graph that has positive capacity on all its edges. 
// The residual graph is derived from the original flow network and represents how much you can change the flow on each edge.
// To understand augmenting paths, consider the Max-Flow problem, 
// where the objective is to send as much flow as possible from a source node to a sink node in a network without violating any edge capacities.
// Here's the concept of augmenting paths step by step:
// Initialization: Start with an initial feasible flow (which can be zero flow everywhere).
// Residual Graph: From the current flow, compute the residual graph. The residual graph contains all edges that can still admit more flow. Specifically, if an edge 
// (u,v) in the original graph has a capacity of c and currently carries a flow 
// f, then in the residual graph, there is a forward edge (u,v) with capacity 
// c−f (the remaining capacity) and a backward edge (v,u) with capacity f (the current flow that can be "undone" or "pushed back").
// Find Augmenting Path: Search for a path from the source to the sink in the residual graph. This path is called an "augmenting path".
// Augment the Flow: Increase the flow on the network along the augmenting path. The amount by which you can increase the flow is determined 
// by the edge with the smallest remaining capacity on the path (often called the "bottleneck" capacity).
// Iterate: Repeat the above steps until no augmenting paths can be found in the residual graph.
// The reason for the name "augmenting path" is that each time you find such a path and adjust the flow along it, 
// you "augment" the total flow from the source to the sink. The famous Ford-Fulkerson algorithm uses the concept of augmenting paths to solve the Max-Flow problem.

// It's worth noting that the efficiency of the Ford-Fulkerson algorithm depends on how you select the augmenting paths. 
// If chosen poorly, the algorithm might not terminate for certain graphs with rational capacities. 
// Using shortest augmenting paths (as in the Edmonds-Karp algorithm) guarantees polynomial time.





// The Goldberg-Tarjan algorithm, often known as the push-relabel algorithm, 
// is used to solve the maximum flow problem in a flow network. 
// The fundamental idea is to maintain a pre-flow, 
// which is like a flow but allows vertices other than the source and sink to temporarily accumulate more flow than they dispatch, 
// and then iteratively push and relabel to adjust the flow until a feasible max flow is reached.
#include <vector>
#include <queue>
#include <limits>
#include <iostream>

class Graph {
public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    int maxflow(int s, int t);

private:
    struct Edge {
        int v;
        int flow;
        int cap;
        int rev; // index for reverse edge
    };

    int V;
    std::vector<std::vector<Edge>> adj;
    std::vector<int> excess, height;
    void push(int u, Edge& e);
    void relabel(int u);
    void initialize_preflow(int s);
};

Graph::Graph(int V) : V(V), adj(V), excess(V, 0), height(V, 0) {}

void Graph::addEdge(int u, int v, int w) {
    Edge a{v, 0, w, (int)adj[v].size()};
    Edge b{u, 0, 0, (int)adj[u].size()}; // reverse edge with no capacity
    adj[u].push_back(a);
    adj[v].push_back(b);
}

void Graph::initialize_preflow(int s) {
    height[s] = V;
    for (auto& e : adj[s]) {
        e.flow = e.cap;
        adj[e.v][e.rev].flow = -e.flow;
        excess[e.v] += e.flow;
    }
}

void Graph::push(int u, Edge& e) {
    int flow = std::min(excess[u], e.cap - e.flow);
    e.flow += flow;
    adj[e.v][e.rev].flow -= flow;
    excess[u] -= flow;
    excess[e.v] += flow;
}

void Graph::relabel(int u) {
    int minHeight = std::numeric_limits<int>::max();
    for (const auto& e : adj[u]) {
        if (e.cap > e.flow) {
            minHeight = std::min(minHeight, height[e.v]);
            height[u] = minHeight + 1;
        }
    }
}

int Graph::maxflow(int s, int t) {
    initialize_preflow(s);

    std::queue<int> activeVertices;
    for (int i = 0; i < V; i++) {
        if (i != s && i != t && excess[i] > 0) {
            activeVertices.push(i);
        }
    }

    while (!activeVertices.empty()) {
        int u = activeVertices.front();
        activeVertices.pop();

        for (auto& e : adj[u]) {
            if (e.cap > e.flow && height[u] == height[e.v] + 1) {
                push(u, e);
                if (e.v != s && e.v != t && excess[e.v] > 0) {
                    activeVertices.push(e.v);
                }
            }
        }

        if (excess[u] > 0) {
            relabel(u);
            activeVertices.push(u);
        }
    }

    int max_flow = 0;
    for (const auto& e : adj[s]) {
        max_flow += e.flow;
    }

    return max_flow;
}

int main() {
    Graph g(4);
    g.addEdge(0, 1, 16);
    g.addEdge(0, 2, 13);
    g.addEdge(1, 2, 10);
    g.addEdge(1, 3, 12);
    g.addEdge(2, 1, 4);
    g.addEdge(2, 3, 14);
    g.addEdge(3, 2, 3);
    g.addEdge(3, 0, 11);

    std::cout << "The maximum flow is " << g.maxflow(0, 3) << std::endl;

    return 0;
}
