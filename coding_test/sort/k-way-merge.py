# input: k sorted List = [[1->4->5], [1->3->4], [2->6]]

# brute force approch :
# 포인터가 각각의 list 맨 처음 리스트에 있고, 그중에 가장 작은 걸 찾음 -> k 타임 걸림
# 가장 작은 걸 찾은 리스트의 포인터를 다음 걸 가리 킨 다음 다시 수행 -> 또 k 타임 걸림
# 최종 time complexity: k^avg_length 인가?

# 쉽게 해결 하는 방법 1.
# 그냥 min-heap 만들어서 그곳에 넣으면 됨.
# 리스트 heap 에 merge
# time complexity: N*log(k)

import heapq
input = [[1,4,5], [1,3,4], [2,6]]
merged = input[0]
for i, l in enumerate(input):
    if (i < len(input) - 1):
        merged = heapq.merge(merged, input[i+1])

for v in merged:
    print(v)

print("\n")
# 쉽게 해결 하는 방법 2.
# flatten 한다음 element 를 하나하나 넣기

flattened = []
for l in input:
    flattened.extend(l)
heap = []
for v in flattened:
    heapq.heappush(heap, v)

for v in heap:
    print(v)


# 쉽게 해결 하는 방법 3.
# 같은 방법임. 다만 더 복잡한 자료 구조를 만듬. def __lt__ 활용.
# ref : https://www.youtube.com/watch?v=cUiUCR-XTO0&t=224s

