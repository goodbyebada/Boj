#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#define X first
#define Y second
#define MAX 52
using namespace std;

/**
 * 0은 방문할 수 없다.
 * 1이 모여있는곳이라면 배추흰지렁이가 한 마리 필요하다.
 *
 * 입출력
 *  M N K
 * 가로(y), 세로(x), 배추가 있는 위치의 개수
 *
 * * ?
 * 배추가 모여있는것을 어케 알것인가.
 *
 * 1. 이중 for문을 돌면서 1을 찾는다.
 * 2. 1이 있는 좌표를 시작점으로 인식한다.
 * 3. BFS를 돌린다.
 * 4. BFS가 끝난다면 cnt++을 한다. 다시 위와 같은 과정을 반복한다.
 * 끝이 난다면 다시 위와 같은 과정을 반복한다.
 * 마지막으로 cnt++을 출력한다.
 */

int T, M, N, K;
int x, y;
int box[MAX][MAX];
int vis[MAX][MAX];
pair<int, int> p;
queue<pair<int, int>> Q;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS() {
  pair<int, int> curr;
  while (!Q.empty()) {
    curr = Q.front();
    Q.pop();

    for (int i = 0; i < 4; i++) {
      int x = curr.X + dx[i];
      int y = curr.Y + dy[i];

      if (x < 0 || y < 0 || x >= M || y >= N) continue;
      if (box[x][y] == 0 || vis[x][y] == 1) continue;

      vis[x][y] = 1;
      Q.push({x, y});
    }
  }
};

void boj() {
  cin >> T;

  while (T--) {
    int cnt = 0;
    cin >> M >> N >> K;

    for (int i = 0; i < K; i++) {
      cin >> y >> x;
      box[x][y] = 1;
    }

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (box[i][j] == 1 && vis[i][j] == 0) {
          Q.push({i, j});
          //   큐에 넣을때 방문했음을 표시해야한다
          vis[i][j] = 1;
          BFS();
          cnt++;
        }
      }
    }
    cout << cnt;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  boj();
  return 0;
}