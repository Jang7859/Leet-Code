#include <stdio.h>
#include <stdbool.h>
#define INF 10000
int number = 6;


// spf tree 이차배열 선언
int a[6][6] = {								

   {0, 2, 5, 1, INF, INF},
   {2, 0, 3, 2, INF, INF},
   {5, 3, 0, 3, 1, 5},
   {1, 2, 3, 0, 1, INF},
   {INF, INF, 1, 1, 0, 2},
   {INF, INF, 5, INF, 2, 0},
};

// 방문한 정점 표시 변수
bool v[6];
// 비용을 표시할 거리수									
int d[6];									

 // 가장 최소 거리를 가지는 정점 가져오기
int getSmallIndex() {						       
	int min = INF;							// 최소값 무한대로 초기화 
	int index = 0;							// 최소값을 반환할 변수
	for (int i = 0; i < number; i++) {		                // 선형 탐색(시간복잡도)
		if (d[i] < min && !v[i]) {	        // 방문하지 않은 정점에 최소값보다 작다면 i를 저장 
			min = d[i];						// 새로운 최소 비용 저장
			index = i;
		}
	}
	return index;
}

void dijkstra(int start) {					        // 다익스트라 함수
	for (int i = 0; i < number; i++) {		                // 최초 시작할 정점을 정보를 입력
		d[i] = a[start][i];
	}
	v[start] = true;
	for (int i = 0; i < number - 2; i++) {	                // 자기자신을 제외한 근처 정점 탐색 
		int current = getSmallIndex();
		v[current] = true;					// 방문 정점임을 표시
		for (int j = 0; j < 6; j++) {                           // (시간복잡도)
			if (!v[j]) {
				if (d[current] + a[current][j] < d[j]) { // 기존의 거리값보다 현재정점을 거쳐가는 
					d[j] = d[current] + a[current][j];	 // 최단거리를 찾았다면 갱신
				}
			}
		}
	}
}

int main(void) {

	dijkstra(0);
	for (int i = 0; i < number; i++) {
		printf("%d ", d[i]);
	}
}