#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <signal.h>

#define UNUSED(X) ((void) (X))

static unsigned int beats = 0;
static time_t start = 0;

double get_bpm(void) {
	return 60 * ((double) beats / (time(NULL) - start));
}

void sigint_handler(int s) {
	UNUSED(s);
	double bpm = get_bpm();
	printf("\n%.1lf bpm\n", bpm);
	exit(EXIT_SUCCESS);
}

int main(void) {
	signal(SIGINT, sigint_handler);

	fprintf(stderr, "Press [Enter] on the beat.\n");

	start = time(NULL);
	while (true) {
		int c = getchar();
		if (c == -1) {
			break;
		}
		beats += 1;
	}

	double bpm = get_bpm();
	printf("%.1lf bpm\n", bpm);

	return EXIT_SUCCESS;
}
