#include <stdio.h>
#define MAX 10000

typedef struct {
    int n, source, destination, buffer;
} Track;
Track stack[MAX];
int top = -1;

void hanoi(int n, int source, int destination, int buffer) {
    stack[++top] = (Track) {n, source, destination, buffer};
    while (top != -1) {
        Track record = stack[top--];
        if (record.n == 1 || record.buffer == -1) {
            printf("Move peg %d source %d destination %d\n", record.n, record.source, record.destination);
            continue;
        }
        stack[++top] = (Track) {record.n - 1, record.buffer, record.destination, record.source};
        stack[++top] = (Track) {record.n, record.source, record.destination, -1};
        stack[++top] = (Track) {record.n - 1, record.source, record.buffer, record.destination};
    }
}

int main(void) 
{
    hanoi(3, 1, 3, 2);
    return 0;
}