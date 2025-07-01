#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, i, head, seek = 0;
    int request[100];
    printf("Enter number of disk requests: ");
    scanf("%d", &n);
    printf("Enter request sequence:\n");
    for (i = 0; i < n; i++) scanf("%d", &request[i]);
    printf("Enter initial head position: ");
    scanf("%d", &head);
    for (i = 0; i < n; i++) {
        seek += abs(request[i] - head);
        head = request[i];
    }
    printf("Total seek time = %d\n", seek);
    return 0;
}
