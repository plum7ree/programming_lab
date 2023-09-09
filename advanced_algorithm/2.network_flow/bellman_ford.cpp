

// 1. Initialize distances to all vertices as infinite and distance to source vertex as 0.
// 2. For every edge, update the distance of the destination vertex if the distance of the source vertex plus weight of edge is less than the current distance of the destination vertex.
// 3. This step is repeated for all vertices V-1 times where V is the number of vertices.
// 4. If we get a shorter path for any vertex even after V-1 iterations, then there is a negative weight cycle in the graph.

// negative weight meaning
// Cost Reduction or Profit: If the weight represents a cost, a negative weight might represent a cost reduction or a profit. For instance, in financial networks, a negative weight could denote a situation where instead of incurring a cost by moving through an edge (like buying a product), you receive a benefit or earn a profit (like receiving a cashback or discount).

// Time Travel or Backward Movement: In time-based networks, a negative weight could hypothetically denote backward time travel or any situation where you gain time.

// Error or Anomaly: Negative weights can sometimes be introduced erroneously, either due to data errors or modeling errors. In such cases, the interpretation of the negative weight might not make physical sense.

// Mathematical or Algorithmic Utility: In some algorithms or mathematical proofs, introducing negative weights can serve a specific purpose, even if they don't have a clear real-world interpretation.


// function BellmanFord(graph, V, E, src):
//     // Initialize distances from src to all other vertices as INFINITE
//     for each vertex v in graph:
//         distance[v] = INFINITE
//     distance[src] = 0

//     // Relax all edges V-1 times. A simple shortest path from src to any
//     // vertex can have at most V-1 edges
//     for i from 1 to V-1:
//         for j from 0 to E-1:
//             u = graph.edge[j].src
//             v = graph.edge[j].dest
//             weight = graph.edge[j].weight
//             if distance[u] + weight < distance[v]:
//                 distance[v] = distance[u] + weight

//     // Check for negative-weight cycles. The above step guarantees the
//     // shortest distances if the graph doesn't contain a negative weight cycle.
//     // If we get a shorter path, then there is a cycle.
//     for j from 0 to E-1:
//         u = graph.edge[j].src
//         v = graph.edge[j].dest
//         weight = graph.edge[j].weight
//         if distance[u] + weight < distance[v]:
//             print("Graph contains negative weight cycle")
//             return
    
//     // Print the shortest distances
//     printDistances(distance, V)