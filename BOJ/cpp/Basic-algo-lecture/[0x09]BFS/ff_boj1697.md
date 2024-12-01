# BOJ1697 숨바꼭질

**틀린이유**  
이게 왜 BFS인지 이해가 전혀 이해가 안 갔다.  
이차원 배열 좌표로 만들어야하나? 전부 더해서 구해야하나? 라는 고민을 했었으나 전혀 할 필요 없던 문제였다.

**풀이 방법**

1.  방문할 수 있는 곳을 모두 방문한다.

    - `X-1`, `X+1`, `X*2` 방문 가능하다.

2.  모든 좌표를 -1로 초기화한다.
3.  거리 배열을 만든다.
4.  처음 방문할 좌표의 값을 0으로 초기화한 후 큐에 넣는다.
5.  큐의 front 원소를 변수에 저장후 pop한다.
6.  방문 가능한 좌표를 큐에 넣는다.

    - 좌표를 벗어나거나 , dist[x]이 -1이 아니라면 방문할 수 없다.

7.  방문이 가능하다면, dist[현재 좌표]의 값을 dist[x]+1의 값으로 초기화한다.
8.  `dist[동생위치] == -1`조건을 만족할때 위의 과정을 반복 한다.

_조심해야할 것_  
100001과 같은 MAX 값은 #define으로 이용하는게 좋다.  
 0을 하나 빼먹어서 틀렸습니다를 보는 불상사는 방지하도록 하자.