#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF					1000000
#define MAX_VERTEX_COUNT	501
#define MAX_EDGE_COUNT		(2500 * 2 + 200)

typedef struct
{
	int src;
	int dest;
	int weight;
} edge_t;

edge_t edges[MAX_EDGE_COUNT];
int dist[MAX_VERTEX_COUNT];

bool BellmanFord(int edgeCount, int vertexCount)
{
	for (int i = 1; i <= vertexCount; ++i) {
		dist[i] = INF;
	}

	dist[1] = 0;
	for (int i = 1; i <= vertexCount; ++i) {
		for (int j = 0; j < edgeCount; ++j) {
			const edge_t edge = edges[j];

			const int src    = edge.src;
			const int dest   = edge.dest;
			const int weight = edge.weight;

			if (dist[dest] > dist[src] + weight) {
				dist[dest] = dist[src] + weight;

				if (i == vertexCount) {
					return true;
				}
			}
		}
	}

	return false;
}

int main(void) {
	int TestCase;
	scanf("%d", &TestCase);

	while (TestCase--) {
		int n, m, w;
		scanf("%d %d %d", &n, &m, &w);

		int top = -1;
		for (int i = 0; i < m; ++i) {
			int s, e, t;
			scanf("%d %d %d", &s, &e, &t);

			edges[++top] = (edge_t){ s, e, t };
			edges[++top] = (edge_t){ e, s, t };
		}

		for (int i = 0; i < w; ++i) {
			int s, e, t;
			scanf("%d %d %d", &s, &e, &t);

			edges[++top] = (edge_t){ s, e, -t };
		}

		printf(BellmanFord(m * 2 + w, n) ? "YES\n" : "NO\n");
	}

	return 0;
}