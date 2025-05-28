// #include <stdio.h>
// #include <time.h>

// int main() {
// 	clock_t start, end;
// 	double cpu_time;
	
// 	start = clock();
	
// 	for(int i =0; i<100000000; i++);
	
// 	end = clock();
	
// 	cpu_time= ((double) (end - start)) / CLOCKS_PER_SEC;
// 	printf("%.6f", cpu_time);
// 	return 0;
// }

#include <stdio.h>
#include <sys/time.h>   // for gettimeofday()
#include <unistd.h>     // for sleep()

int main() {
    struct timeval start, end;
    double elapsed;

    gettimeofday(&start, NULL);

    printf("Process started...\n");

    sleep(10);  // Sleep for 10 seconds

    printf("Process ended...\n");

    gettimeofday(&end, NULL);

    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) * 1e-6;

    printf("Total real execution time: %.6f seconds\n", elapsed);

    return 0;
}
