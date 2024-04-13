#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct Santa {
	int r, c;  // 좌표
	int dir;   // 이동방향
	int sleep; // 기절한 시간 -> 기절했을 때 1, 2일 때 턴 종료 후 0으로 정상상태
	int dist;  // 루돌프와의 거리
	bool out;  // 나갔는지 확인

	bool operator<(Santa right) const {
		// 거리가 같을 때
		if (dist == right.dist) {
			// r이 같을 때
			if (r == right.r) return c < right.c;  // c가 큰 산타한테
			return r < right.r; // r이 큰 산타한테
		}
		// 거리가 가까운 산타한테
		return dist > right.dist;
	}
};

struct Rudol {
	int r, c; // 좌표
	int dir;  // 이동방향
};

struct Move {
	int dir, dist;

	bool operator<(Move right) const {
		if (dist == right.dist) {
			return dir > right.dir;
		}
		return dist > right.dist;
	}
};

int	N, M, P, C, D;
int ans[31] = { 0, };  // 산타 점수 배열 (최종 목표)
Rudol rudol;  

Santa santas[31];

// 산타 이동방향 - 상우하좌
int sdy[4] = { -1, 0, 1, 0 };
int sdx[4] = { 0, 1, 0, -1 };

// 루돌프 이동방향
// 산타가 같은 열, 행이 작다 -> 상 (0) / 행이 크다 -> 하 (1)
//		 같은 행, 열이 작다 -> 좌 (2) / 열이 크다 -> 우 (3)
//       우상 -> 상, 우상, 우 (0, 4, 3)
//       우하 -> 하, 우하, 우 (1, 5, 3)
//       좌상 -> 상, 좌상, 좌 (0, 6, 2)
//       좌하 -> 하, 좌하, 좌 (1, 7, 2)

// 상하좌우/우상우하좌상좌하
int rudy[8] = { -1, 1, 0, 0, -1, 1, -1, 1 };
int rudx[8] = { 0, 0, -1, 1, 1, 1, -1, -1 };

// 시뮬레이션용 배열
int santaMap[52][52];

void init() {
	memset(ans, 0, sizeof(ans));
}

void input() {
	cin >> N >> M >> P >> C >> D;
	cin >> rudol.r >> rudol.c;

	for (int i = 0; i < P; i++) {
		int num, r, c;
		cin >> num >> r >> c;
		santas[num] = { r, c, -1, 0, 0, false };
		santaMap[r][c] = num;
	}
}

int calDist(int r1, int c1, int r2, int c2) {
	return (r1 - r2) * (r1 - r2) + (c1 - c2) * (c1 - c2);
}

int findNextRu(Santa santa, Rudol rudol, int d1, int d2, int d3) {
	int ret = -1;
	int minDist = 1e9;

	int nextrr = rudol.r + rudy[d1], nextrc = rudol.c + rudx[d1];
	int nowDist = calDist(nextrr, nextrc, santa.r, santa.c);
	if (minDist > nowDist) {
		minDist = nowDist;
		ret = d1;
	}

	nextrr = rudol.r + rudy[d2], nextrc = rudol.c + rudx[d2];
	nowDist = calDist(nextrr, nextrc, santa.r, santa.c);
	if (minDist > nowDist) {
		minDist = nowDist;
		ret = d2;
	}

	nextrr = rudol.r + rudy[d3], nextrc = rudol.c + rudx[d3];
	nowDist = calDist(nextrr, nextrc, santa.r, santa.c);
	if (minDist > nowDist) {
		minDist = nowDist;
		ret = d3;
	}

	return ret;
}
		 
void moveRu() {
	priority_queue<Santa> pq;
	// 1. 루돌프와 살아있는 산타들의 거리 구하기
	for (int i = 1; i <= P; i++) {
		if (santas[i].out) continue;
		Santa nowSanta = santas[i];
		int nowDist = calDist(rudol.r, rudol.c, nowSanta.r, nowSanta.c);
		// 2. pq에 넣어서 가장 가까운 산타 찾기
		santas[i].dist = nowDist;
		pq.push(santas[i]);
	}

	Santa minDistSanta = pq.top();

	// 1. minDistSanta가 상하좌우에 있다면 루돌프는 상하좌우로 이동
	//	  같은 행일 때 루돌프 열 > 산타 열 -> 루돌프 열 -= 1
	//				 루돌프 열 < 산타 열 -> 루돌프 열 += 1
	if (rudol.r == minDistSanta.r) {
		if (rudol.c > minDistSanta.c) {
			rudol.c -= 1;
			rudol.dir = 2;
		}
		else if (rudol.c < minDistSanta.c) {
			rudol.c += 1;
			rudol.dir = 3;
		}
	}
	//    같은 열 루 > 산 -> 루 행 -= 1, 루 < 산 -> 루 행 += 1
	else if (rudol.c == minDistSanta.c) {
		if (rudol.r > minDistSanta.r) {
			rudol.r -= 1;
			rudol.dir = 0;
		}
		else if (rudol.r < minDistSanta.r) {
			rudol.r += 1;
			rudol.dir = 1;
		}
	}

	// 우상 -> 상, 우상, 우 (0, 4, 3)
	// 우하 -> 하, 우하, 우 (1, 5, 3)
	// 좌상 -> 상, 좌상, 좌 (0, 6, 2)
	// 좌하 -> 하, 좌하, 좌 (1, 7, 2)
	
	// 2. minDistSanta가 우상에 있다면
	else if (minDistSanta.r < rudol.r && minDistSanta.c > rudol.c) {
		int nextRuDir = findNextRu(minDistSanta, rudol, 0, 3, 4);
		rudol.r = rudol.r + rudy[nextRuDir];
		rudol.c = rudol.c + rudx[nextRuDir];
		rudol.dir = nextRuDir;
	}

	// 우하
	else if (minDistSanta.r > rudol.r && minDistSanta.c > rudol.c) {
		int nextRuDir = findNextRu(minDistSanta, rudol, 1, 3, 5);
		rudol.r = rudol.r + rudy[nextRuDir];
		rudol.c = rudol.c + rudx[nextRuDir];
		rudol.dir = nextRuDir;
	}

	// 좌상
	else if (minDistSanta.r < rudol.r && minDistSanta.c < rudol.c) {
		int nextRuDir = findNextRu(minDistSanta, rudol, 0, 2, 6);
		rudol.r = rudol.r + rudy[nextRuDir];
		rudol.c = rudol.c + rudx[nextRuDir];
		rudol.dir = nextRuDir;
	}

	// 좌하
	else if (minDistSanta.r > rudol.r && minDistSanta.c < rudol.c) {
		int nextRuDir = findNextRu(minDistSanta, rudol, 1, 2, 7);
		rudol.r = rudol.r + rudy[nextRuDir];
		rudol.c = rudol.c + rudx[nextRuDir];
		rudol.dir = nextRuDir;
	}
}

void moveSan() {
	// 이미 탈락했거나 자고 있는 산타는 넘어가기
	for (int i = 1; i <= P; i++) {
		if (santas[i].out || santas[i].sleep != 0) continue;

		Santa now = santas[i];
		santaMap[now.r][now.c] = 0;

		priority_queue<Move> pq;

		for (int d = 0; d < 4; d++) {
			int ny = now.r + sdy[d];
			int nx = now.c + sdx[d];
			if (ny < 1 || ny > N || nx < 1 || nx > N) continue;
			if (santaMap[ny][nx] != 0) continue;

			pq.push({ d, calDist(rudol.r, rudol.c, ny, nx) });
		}

		Move next = pq.top();
		if (calDist(santas[i].r, santas[i].c, rudol.r, rudol.c) <= next.dist) {
			santaMap[santas[i].r][santas[i].c] = i;
			continue;
		}

		santas[i].r = santas[i].r + sdy[next.dir];
		santas[i].c = santas[i].c + sdx[next.dir];
		santas[i].dir = next.dir;
		santaMap[santas[i].r][santas[i].c] = i;

		// 루돌프와 충돌하는지 확인 
		if (santas[i].r == rudol.r && santas[i].c == rudol.c) {
			santaMap[santas[i].r][santas[i].c] = 0;
			ans[i] += D;

			santas[i].r = santas[i].r + sdy[santas[i].dir ^ 2] * D;
			santas[i].c = santas[i].c + sdx[santas[i].dir ^ 2] * D;
			santas[i].sleep = 1;
			if (santas[i].r < 1 || santas[i].r > N || santas[i].c < 1 || santas[i].c > N) {
				santas[i].out = true;
			}
			else if (santaMap[santas[i].r][santas[i].c] == 0) {
				santaMap[santas[i].r][santas[i].c] = i;
			}
			// 산타가 밀려난 곳에서 다른 산타를 만난 경우
			else if (santaMap[santas[i].r][santas[i].c] != 0) {
				int nowR = santas[i].r;
				int nowC = santas[i].c;
				int nowNum = i;
				while (1) {
					int temp = santaMap[nowR][nowC];
					santaMap[nowR][nowC] = nowNum;

					int nextR = nowR + sdy[next.dir ^ 2];
					int nextC = nowC + sdx[next.dir ^ 2];
					if (nextR < 1 || nextR > N || nextC < 1 || nextR > N) {
						santas[temp].out = true;
						break;
					}

					if (santaMap[nextR][nextC] == 0) {
						santaMap[nextR][nextC] = temp;
						santas[temp].r = nextR;
						santas[temp].c = nextC;
						break;
					}

					// 밀린 곳에도 산타 있다면
					else {
						nowR = nextR;
						nowC = nextC;
						nowNum = temp;
					}
				}

			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	input();

	while (M--) {
		bool flag = false;
		for (int i = 1; i <= P; i++) {
			// 산타 한명이라도 남아있으면 진행
			if (!santas[i].out) {
				flag = true;
				break;
			}
		}
		if (!flag) break;

		// 기절한 산타 확인
		for (int i = 1; i <= P; i++) {
			if (santas[i].out || santas[i].sleep == 0) continue;
			santas[i].sleep++;
			if (santas[i].sleep > 2) santas[i].sleep = 0;
		}

		// 루돌프 움직이기
		moveRu();

		// 루돌프 움직인 후에 산타 만난 경우
		if (santaMap[rudol.r][rudol.c] != 0) {
			int num = santaMap[rudol.r][rudol.c];
			ans[num] += C;
			// 산타맵 초기화
			santaMap[santas[num].r][santas[num].c] = 0;

			santas[num].r = santas[num].r + rudy[rudol.dir] * C;
			santas[num].c = santas[num].c + rudx[rudol.dir] * C;
			if (santas[num].sleep == 0) santas[num].sleep = 1;
			if (santas[num].r < 1 || santas[num].r > N || santas[num].c < 1 || santas[num].c > N) {
				santas[num].out = true;
			}
			else if (santaMap[santas[num].r][santas[num].c] == 0) {
				santaMap[santas[num].r][santas[num].c] = num;
			}
			// 산타가 밀려난 곳에서 다른 산타를 만난 경우
			else if (santaMap[santas[num].r][santas[num].c] != 0) {
				int nowR = santas[num].r;
				int nowC = santas[num].c;
				int nowNum = num;
				while (1) {
					int temp = santaMap[nowR][nowC];
					santaMap[nowR][nowC] = nowNum;

					int nextR = nowR + rudy[rudol.r];
					int nextC = nowC + rudx[rudol.c];
					if (nextR < 1 || nextR > N || nextC < 1 || nextR > N) {
						santas[temp].out = true;
						break;
					}

					if (santaMap[nextR][nextC] == 0) {
						santaMap[nextR][nextC] = temp;
						santas[temp].r = nextR;
						santas[temp].c = nextC;
						break;
					}

					// 밀린 곳에도 산타 있다면
					else {
						nowR = nextR;
						nowC = nextC;
						nowNum = temp;
					}
				}
			}
		}

		// 산타 움직이기 
		moveSan();

		// 남아있으면 +1
		for (int i = 1; i <= P; i++) {
			if (santas[i].out) continue;
			ans[i]++;
		} 
	}

	for (int i = 1; i <= P; i++) {
		cout << ans[i] << " ";
	}
}