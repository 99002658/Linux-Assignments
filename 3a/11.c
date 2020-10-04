#include <stdio.h>
#include <time.h>
#include <unistd.h>

void delay(int number_of_seconds)
{

    int milli_seconds = 1000 * number_of_seconds;

    clock_t start_time = clock();

    while (clock() < start_time + milli_seconds);
}

int main()
{

	double time_spent = 0.0;

	clock_t begin = clock();

    for (int i = 0; i < 10; i++) {
         delay(1);
    printf("Delay to see time elapsed\n");
    }

	clock_t end = clock();

	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

	printf("Time elapsed is %f seconds", time_spent);

	return 0;
}
