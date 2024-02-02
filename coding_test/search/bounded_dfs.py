

# constraint 가 주어지고, depth K 일때.
# input adj : n x n

class DFS:
    def __init__(self, Adj):
        self.Adj = Adj
        self.N = len(self.Adj)
        self.visited = (lambda: {k: False for k in range(self.N)})()
        print(self.visited)

    def search(self, source, target, ret_path_list, depth, type="recursive"):
        if type=="recursive":
            self.visited[source] = True
            self._recursive_search(source, target, 0, [source], ret_path_list, depth)
        elif type=="iterative":
            self.visited[source] = True
            self._iterative_search(source, target, 0, [source], ret_path_list, depth)

    def _recursive_search(self, current, target, acc_cost, path: list[int], ret_path_list: list[tuple[int, list]], depth: int):
        print("curr: {} target: {} path:{}".format(current, target, path))
        if current==target:
            ret_path_list.append((acc_cost, path.copy())) # copy() important
            print("current == target! return path: {}, ret_path_list: {}".format(path, ret_path_list))
            return
        if depth==0:
            return
        elif depth<0:
            pass
        for i, w in enumerate(self.Adj[current]):
            if self.visited[i]:
                continue
            if w == 0:
                continue
            self.visited[i] = True
            acc_cost += w
            path.append(i)
            self._recursive_search(i, target, acc_cost, path, ret_path_list, depth-1)
            self.visited[i] = False
            acc_cost -= w
            path.pop(-1)


    def _iterative_search(self, source, target, acc_cost, ret_path, ret_path_list, depth):
        pass

# array ref: https://static.javatpoint.com/tutorial/daa/images/dijkstras-algorithm6.png
# node: A,B,C,D,E,F
# edges and weights: A-B: 4, A-C:5, B-C:11, B-D:9 B-E:7, ...
adj = [[0,4,5,0,0,0],\
       [4,0,11,9,7,0],\
       [5,11,0,0,3,0],\
       [0,9,0,13,0,2],\
       [0,7,3,13,0,6],\
       [0,0,0,2,6,0]]

dfs = DFS(adj)
ret_path_list = list()
dfs.search(0,5, ret_path_list, -1)
# print(ret_path_list)
# [(33, [0, 1, 2, 4, 3, 5]), (24, [0, 1, 2, 4, 5]), (15, [0, 1, 3, 5]), (26, [0, 1, 4, 3, 5]),
# (17, [0, 1, 4, 5]), (27, [0, 2, 1, 3, 5]), (38, [0, 2, 1, 4, 3, 5]), (29, [0, 2, 1, 4, 5]),
# (26, [0, 2, 4, 1, 3, 5]), (23, [0, 2, 4, 3, 5]), (14, [0, 2, 4, 5])]

dfs = DFS(adj)
ret_path_list = list()
dfs.search(0,5, ret_path_list,3)
# print(ret_path_list)
# [(15, [0, 1, 3, 5]), (17, [0, 1, 4, 5]), (14, [0, 2, 4, 5])]