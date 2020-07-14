// 정점의 갯수, 간선의 갯수, 탐색을 시작할 정점의 수 받은 뒤, dfs수행 후 bfs 수행하여 값 출력

#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 1000
//dfs 구간
typedef struct GraphType {
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int visited[MAX_VERTICES];

void init(GraphType* g) {
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0;
}

void insert_vertex(GraphType* g, int v) {
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "그래프 : 정점의 개수 초과");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int start, int end) {
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "그래프 : 정점 번호 오류");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}

void dfs_mat(GraphType* g, int v) {
	int w;
	visited[v] = TRUE;
	printf("%d ", v);
	for (w = 0; w < g->n; w++)
		if (g->adj_mat[v][w] && !visited[w])
			dfs_mat(g, w);
}
//dfs 구간 끝
//bfs 구간 시작
typedef struct GraphType2 {
	int n2;
	int adj_mat2[MAX_VERTICES][MAX_VERTICES];
}GraphType2;

int visited2[MAX_VERTICES];

void init2(GraphType2* g2) {
	int r2, c2;
	g2->n2 = 0;
	for (r2 = 0; r2 < MAX_VERTICES; r2++)
		for (c2 = 0; c2 < MAX_VERTICES; c2++)
			g2->adj_mat2[r2][c2] = 0;
}

void insert_vertex2(GraphType2* g2, int v2) {
	if (((g2->n2) + 1) > MAX_VERTICES) {
		fprintf(stderr, "그래프 : 정점의 개수 초과");
		return;
	}
	g2->n2++;
}

void insert_edge2(GraphType2* g2, int start2, int end2) {
	if (start2 >= g2->n2 || end2 >= g2->n2) {
		fprintf(stderr, "그래프 : 정점 번호 오류");
		return;
	}
	g2->adj_mat2[start2][end2] = 1;
	g2->adj_mat2[end2][start2] = 1;
}


#define MAX_QUEUE_SIZE 10
typedef int element;
typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
void graph_init(GraphType2* g) {
	int r, c;
	g->n2 = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_QUEUE_SIZE; c++)
			g->adj_mat2[r][c] = 0;
}

void queue_init(QueueType* q) {
	q->front = q->rear = 0;
}

int is_empty(QueueType* q) {
	return (q->front == q->rear);
}
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
void enqueue(QueueType* q, element item) {
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

element dequeue(QueueType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}

void bfs_mat(GraphType2* g, int v) {
	int w;
	QueueType q;

	queue_init(&q);
	visited2[v] = TRUE;
	printf("%d ", v);
	enqueue(&q, v);
	while (!is_empty(&q)) {
		v = dequeue(&q);
		for (w = 0; w < g->n2; w++)
			if (g->adj_mat2[v][w] && !visited2[w]) {
				visited2[w] = TRUE;
				printf("%d ", w);
				enqueue(&q, w);
			}
	}

}

int main() {
	printf("201858009 유종환\n");
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);

	GraphType2* g2;
	g2 = (GraphType2*)malloc(sizeof(GraphType2));
	graph_init(g2);


	int a, b, c;
	scanf_s("%d %d %d", &a, &b, &c);


	while (a < 1 || a > 100 || b < 1 || b > 1000) {
		if (a < 1 || a > 100) {
			printf("정점의 갯수가 잘못 입력되었습니다. 정점의 범위는 0<정점 수<101 입니다.\n");
		}
		if (b < 1 || b > 1000) {
			printf("간선의 수가 잘못 입력되었습니다. 간선의 수 범위는 0<정점 수<1001 입니다.\n");
		}
		scanf_s("%d %d %d", &a, &b, &c);
	}

	for (int i = 0; i <= a; i++) {
		insert_vertex(g, i);
		insert_vertex2(g2, i);
	}

	int data1, data2;
	for (int i = 0; i < b; i++) {
		scanf_s("%d %d", &data1, &data2);
		insert_edge(g, data1, data2);
		insert_edge2(g2, data1, data2);
	}

	dfs_mat(g, c);
	printf("\n");
	bfs_mat(g2, c);
	free(g);
	free(g2);
	printf("\n");
	return 0;
}
