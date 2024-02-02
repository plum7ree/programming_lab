

1. Greedy Algorithm
간단한 접근 방법은 물품을 가치 대비 무게 비율, v_i/w_i 에 따라 선택하는 것입니다. 이 방법은 빠르지만 항상 최선의 해결책을 제공하지는 않습니다.

2. Linear Programming Relaxation and Rounding:
이 접근 방법은 물품을 부분적으로 포함할 수 있는 문제의 완화된 버전을 해결합니다. 
선형 프로그래밍 완화의 해결책은 정수 해결책을 얻기 위해 반올림됩니다. 
이 방법은 반올림에 대한 휴리스틱과 결합될 때 좋은 근사치를 제공할 수 있습니다.


3. Fully Polynomial-Time Approximation Scheme (FPTAS)
 배낭 문제에는 (1-e) 의 최적해에 대해 어떤 ϵ>0에 대해서도 다항 시간 내에 해결책을 제공하는 FPTAS 알고리즘이 있습니다. 
 이를 물품 개수 제한에 적용하는 것은 추가적인 복잡성을 포함하지만 가능합니다.


4. Local Search Heuristics
 simulated annealing, genetic algorithms, or tabu search
이러한 방법은 지역적인 변경을 통해 해결책을 반복적으로 개선하며, 특히 큰 인스턴스에 대해 효과적일 수 있습니다.

5. Dynamic Programming with Approximation
동적 프로그래밍은 근사 기술과 결합하여 더 큰 인스턴스를 효율적으로 처리할 수 있도록 조정될 수 있습니다. 
예를 들어, 가치 또는 무게 척도를 이산화함으로써 상태 공간을 줄일 수 있습니다.


