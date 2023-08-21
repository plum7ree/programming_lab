// mutex 

// 우선 뮤텍스의 경우, 자원에 이미 락이 걸려 있을 경우 락이 풀릴 때까지 기다리며 컨텍스트 스위칭을 실행한다. 

// 즉, 다른 병렬적인 태스크를 처리하기 위해 CPU를 양보할 수 있다는 것이며 이는 
// 자원을 얻기 위해 오랜 시간을 기다려야 할 것이 예상될 때 다른 작업을 동시에 진행할 수 있다는 것이다. 
// 하지만 이는 자원이 단시간 내로 얻을 수 있게 될 경우 컨텍스트 스위칭에 더 큰 자원을 낭비하게 될 수 있다는 문제가 있다.



// spin_lock

// 스핀 락의 경우에는 이름에서부터 알 수 있듯이, 자원에 락이 걸려 있을 경우 이를 얻을 때까지
//  무한 루프를 돌면서 다른 태스크에 CPU를 양보하지 않는 것이다. 자원이 단시간 내로 얻을 수 있게 된다면
//  컨텍스트 스위칭 비용이 들지 않으므로 효율을 높일 수 있지만, 그 반대의 경우 다른 태스크에 
//  CPU를 양보하지 않으므로 오히려 CPU 효율을 떨어뜨릴 수 있는 문제가 있다.