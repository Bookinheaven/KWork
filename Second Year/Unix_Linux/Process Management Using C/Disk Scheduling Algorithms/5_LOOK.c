#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, i, j, temp, size, dir, seek = 0;
    int req[100];
    printf("Enter number of requests: ");
    scanf("%d", &n);
    printf("Enter request sequence:\n");
    for (i = 0; i < n; i++) 
        scanf("%d", &req[i]);
    printf("Enter initial head position: ");
    scanf("%d", &head);
    printf("Enter disk size: ");
    scanf("%d", &size);
    printf("Enter direction (0 = left, 1 = right): ");
    scanf("%d", &dir);
    req[n++] = head;
    req[n++] = dir ? size - 1 : 0;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (req[i] > req[j]) {
                temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }
        }
    }
    for (i = 0; i < n; i++) {
        if (req[i] == head) 
            break;
    }
    if (dir) { // right
        for (j = i; j < n - 1; j++) seek += abs(req[j + 1] - req[j]);
        for (j = i - 1; j >= 0; j--) seek += abs(req[j + 1] - req[j]);
        } else { // left
        for (j = i; j > 0; j--) seek += abs(req[j] - req[j - 1]);
        for (j = i + 1; j < n; j++) seek += abs(req[j] - req[j - 1]);
        }
       
    printf("Total seek time = %d\n", seek);
    return 0;
}
