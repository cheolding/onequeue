#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct { // 큐 타입
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
} QueueType;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1); // [juht] 프로그램 종료는 과도한 에러 처리
}

void init_queue(QueueType* q)
{
	q->rear = MAX_QUEUE_SIZE - 1;
	q->front = MAX_QUEUE_SIZE - 1;
}

void queue_print(QueueType* q)
{
	printf("Queue(front=%d rear=%d) : ", q->front, q->rear);
	int i = q->front;
	do {
		i = (i + 1) % MAX_QUEUE_SIZE;
		if (i == (q->rear + 1) % MAX_QUEUE_SIZE) {
			printf("\n");
			break;
		}
		printf("%d ", q->data[i]);
	} while (i != q->rear);
	printf("\n");
}
int is_full(QueueType* q)
{
	if ((q->rear + 1) % MAX_QUEUE_SIZE == q->front)
		return 1;
	else
		return 0;
}

int is_empty(QueueType* q)
{
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}

void enqueue(QueueType* q, int item)
{
	if (is_full(q)) {
		fprintf(stderr, "큐가 포화상태입니다\n");
		return;
	}
	else {
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->data[q->rear] = item;
	}
}

int dequeue(QueueType* q)
{
	if (is_empty(q)) {
		fprintf(stderr, "큐가 공백상태입니다\n");
		return 0;
	}
	else {
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return q->data[q->front];
	}
}

int main(void)
{
	QueueType q;
	init_queue(&q);
	int item = 0;
	int input;

	while (1)
	{
		printf("\n\n1.Input data and Enqueue\n2.Dequeue and print data\n3.Print Queue\n4.Exit\nSelect number :");
		scanf("%d", &input);

		if (input == 1)
		{
			int num;
			printf("Input the Data : ");
			scanf("%d", &num);

			enqueue(&q, num);
			printf("Enqueue : %d", num);
		}
		else if (input == 2)
		{
			item = dequeue(&q);
			if (item != 0)
			{
				printf("Dequeue : %d", item);
			}
		}
		else if (input == 3)
		{
			queue_print(&q);
		}
		else if (input == 4)
		{
			printf("Exit the Program");
			break;
		}
	}

	return 0;
}