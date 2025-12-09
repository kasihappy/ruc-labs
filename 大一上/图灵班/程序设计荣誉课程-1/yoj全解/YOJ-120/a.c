// Recursive selection sort that logs swaps and prints them in reverse order
#include <stdio.h>

#define MAXN 100

typedef struct {
	int i, j;              // 1-based swap indices
	int arr[MAXN];         // array snapshot after the swap
} Step;

static Step steps[MAXN];
static int step_count = 0;

static void record_step(int idx1, int idx2, int a[], int n) {
	Step *s = &steps[step_count++];
	s->i = idx1 + 1; // convert to 1-based
	s->j = idx2 + 1;
	for (int k = 0; k < n; k++) s->arr[k] = a[k];
}

static void recursive_selection(int a[], int n, int start) {
	if (start >= n - 1) return;

	// find min element in [start, n)
	int min_pos = start;
	for (int i = start + 1; i < n; i++) {
		if (a[i] < a[min_pos]) min_pos = i;
	}

	// swap if needed, then record the step
	if (min_pos != start) {
		int tmp = a[start];
		a[start] = a[min_pos];
		a[min_pos] = tmp;
		record_step(start, min_pos, a, n);
	}

	recursive_selection(a, n, start + 1);
}

int main(void) {
	int n;
	if (scanf("%d", &n) != 1 || n <= 0 || n > MAXN) return 0;
	int a[MAXN];
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);

	recursive_selection(a, n, 0);

	// print steps in reverse order (last swap to first)
	for (int s = step_count - 1; s >= 0; s--) {
		printf("%d<->%d:", steps[s].i, steps[s].j);
		for (int k = 0; k < n; k++) {
			printf("%s%d", k == 0 ? "" : " ", steps[s].arr[k]);
		}
		printf("\n");
	}

	printf("Total steps:%d\n", step_count);

	// array a is already sorted; print right order
	printf("Right order:");
	for (int i = 0; i < n; i++) {
		printf("%s%d", i == 0 ? "" : " ", a[i]);
	}
	printf("\n");
	return 0;
}
