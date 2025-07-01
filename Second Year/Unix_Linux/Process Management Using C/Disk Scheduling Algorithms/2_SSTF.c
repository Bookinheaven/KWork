#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, head, min, seek = 0, index;
    int request[100], visited[100] = {0};
    printf("Enter number of disk requests: ");
    scanf("%d", &n);
    printf("Enter request sequence:\n");
    for (i = 0; i < n; i++) scanf("%d", &request[i]);
    printf("Enter initial head position: ");
    scanf("%d", &head);
    for (i = 0; i < n; i++) {
        min = 9999;
        for (j = 0; j < n; j++) {
            if (!visited[j] && abs(request[j] - head) < min) {
                min = abs(request[j] - head);
                index = j;
            }
        }
        seek += abs(request[index] - head);
        head = request[index];
        visited[index] = 1;
    }
    printf("Total seek time = %d\n", seek);
    return 0;
}