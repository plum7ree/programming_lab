# AdvancedAlgorithm

https://ocw.mit.edu/courses/6-854j-advanced-algorithms-fall-2008/pages/lecture-notes/

## Ch1. Fibonacci Heap
- Efficient implementation of priority queue

Example of Problem:
1. Single-source Shortest Path Problem : for each Vertex v, compute shortest path from s to v. The classical solution is Dijkstra's Algorithm
2. Minimum Spanning Tree: classical solution is Prim's Algorithm

Both of them uses priority queue.
1. Binary Heap
2. d-ary Heap : reduce depth of tree ->  inserts and bottlenecking decrease-key operations excute in O(log_d|S|) time.
3. Fibonacci Heap : laziness. work when we do must. simplify the structure. 
<br>  <br>  <br>  

## Ch2. Network Flow
### 1. Shortest Path Problem
Shortest Path -> Minimum Cost Flow -> Multi-commodity Flow  

Transformation of an undirected edge into two directed edge for Dijkstra's algorithm.  

Negative length after transformation

Bellman-Ford Algorithm:  
1. Negative Edge Weights: It can handle graphs with negative edge weights.  
2. Negative Cycles: If the graph contains a negative cycle that is reachable from the source vertex, the Bellman-Ford algorithm can detect it. This is because if the shortest path is updated in the Vth iteration (where V is the number of vertices), it indicates the presence of a negative cycle. However, if there's a negative cycle that's not reachable from the source, Bellman-Ford will correctly compute shortest paths to all reachable vertices.  
3. Time Complexity: The algorithm is generally slower than Dijkstra's, with a worst-case time complexity of O(V×E), where V is the number of vertices and E is the number of edges.  

Dijkstra's Algorithm:  
1. Negative Edge Weights: Dijkstra's algorithm does not work correctly with negative edge weights. This is because Dijkstra's algorithm makes a greedy choice by selecting the next closest vertex based on the current shortest path estimations. If negative edges are introduced, a vertex that was previously processed might need its shortest path updated, but Dijkstra's algorithm doesn't reconsider such vertices.  
2. Negative Cycles: If the graph has negative cycles, Dijkstra's will definitely not work, as the concept of "shortest path" in the presence of negative cycles is not well-defined.  
3. Time Complexity: With a good priority queue (like a Fibonacci heap), its time complexity can be O(E+VlogV).  

<br>

### 2. Maximum Flow Problem  
row flow, net flow  
capacity constraint  
conservation constraint  
skw symmetry  
capacity constraint  
flow conservation  
maximum flow problem.  
s-t cut  

cut capacity  
<br>  

### 3. Max flow and Min cut
duality : maxflow = min cut.  

residual capacity 
residual arc  
residual network  
augmenting path  

max flow min-cut theorem  

<br>  

### 4. Ford-Fulkerson Algorithm
Augmenting Path still exists in residual network? -> push more flow!    


FORD-FULKERSON(G)  
1 start with a zero flow f  
2 while G has an augmenting path P  
3 do push $\epsilon(P)$ more units of flow through $P$, so that $\ |f| $ <- $\ |f| + \epsilon(P)$ 


does this algorithm ever halt?  
if more than one augmenting path in residual network, which one to choose?  
running time of the algorithm?  

case 1. capacity u is integer.  
case 2. capacity u is rational value : always halts.  
case 3. capacity u is real value : Ford-Fulkerson never halts  
<br>  

### 5. Fixing Ford-Fulkerson Algorithm
how to choose good augmenting path at every iteration?  
<br>  <br>  <br>  

## Ch3. Maximum Flow, minimum cost circulation


### 1. Bipartite Matching
<b> Cardinality Bipartite Matching </b>  
bipartite graph  
1. two disjoint sets  
2. every edge connects a vertex in A to one in B.  
3. cardinality matching problem = max-flow problem: Given an undirected bipartite graph G, find a matching M of maximum cardinality


<b> Weighted Bipartite Matching </b>
<br>  

### 2. Flow Decomposition

<br>  

### 3. Fastest Augmenting Path Algorithm
Ford-Fulkerson for finding a mximum flow -> exponential time or event no termination.  
<b> Edmonds and Karp </b> -> specific choice of augmenting path: polynomial running time.  
minimum residual capacity, the bottleneck, $\epsilon(P)$ -> push this along the path P.  
fastest augmenting path P such that the bottleneck $\epsilon(P)$ is maximized
<br>

### 4. Minimum Cost Circulation Problem (PMCCP)
circulation: a flow where the net flow into every vertex is zero. There are no sources or sinks.  
cost function c satisfies skew symmetry: $c(v,w) = -c(v,w)$  
find a circulation f of minimum cost c(f).  
MCCP is a special case of a Linear Programming problem.  
<br>  

### 5. Vertex Potentials
vertex potential : assign each vertes a potential.
$ c_p(v,w) = c(v,w) + p(v) - p(w)$
<br>  

### 6. Klein's Cycle-Cancelling Algorithm
removing negative-cost cycles.

### Optimality Conditions
conditions for minimum cost circulation.
The followings are equivalent:
1. f is of minimum cost
2. There exists no negative-cost cycle in the residual graph G_f
3. There exists a potential function p such that for all (v,w) of E, c(v,w) >= 0

### Others
Network Simplex Algorithm  
Out-of-Killer Algorithm  
LEMON C++ Library  
Maximum Flow and Minimum-Cost Flow in Almost-Linear Time  
- https://www.youtube.com/watch?v=KsMtVthpkzI  

Application of Max flow: https://www.cs.princeton.edu/~wayne/cs423/lectures/max-flow-applications  

<br>  <br>  <br>  

## Ch4. Goldberg-Tarjan min-cost circulation algorithm
How to choose negative-cost cycle to remove by pushing a flow?
### Klein's cycle cancelling algorithm.
Ford-Fulkerson algorithm is a special case of Klein's cycle cancelling algorithm. (zero costs for all edges, extra one edge added from the sink to the source with cost -1.)

choice of negative cost cycle
1. (Weintraub 1972) maximum improvement cycle.
2. (Goldberg-Tarjan 1986) cycle of minimum mean cost

### Bounding the number of iterations
How to bound it in a polynomial time?
closeness to the optimal circulation.
why pushing flow along negative cost cycle bring us to closer optimality?
<br> 

### Strongly Polynomial Analysis
<br>  <br>  <br>  

## Ch5. Cancel and Tighten algorithm

<br>  <br>  <br>  

## Ch6. Splay Trees

 v

<br>  <br>  <br>  

## Ch 10. Duality, Geometry, Simplex


Physical Justification of the Dual
<br>  <br>  <br>  
