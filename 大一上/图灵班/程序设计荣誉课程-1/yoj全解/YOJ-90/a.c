// Determine top-k students (dense ranking) based on required problems solved
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	long long sno;
	int solved;
} Student;

// qsort comparator: solved desc, sno asc
static int cmp(const void *a, const void *b) {
	const Student *sa = (const Student *)a;
	const Student *sb = (const Student *)b;
	if (sa->solved != sb->solved) return sb->solved - sa->solved;
	if (sa->sno < sb->sno) return -1;
	if (sa->sno > sb->sno) return 1;
	return 0;
}

int main(void) {
	int n;
	if (scanf("%d", &n) != 1) return 0;

	int required[100];
	for (int i = 0; i < n; i++) {
		scanf("%d", &required[i]);
	}

	int m, k;
	scanf("%d %d", &m, &k);

	Student students[105];
	for (int idx = 0; idx < m; idx++) {
		long long sno;
		int p;
		scanf("%lld %d", &sno, &p);

		int solved = 0;
		int counted[100] = {0}; // track duplicates for this student
		for (int j = 0; j < p; j++) {
			int pid;
			scanf("%d", &pid);
			for (int r = 0; r < n; r++) {
				if (pid == required[r] && !counted[r]) {
					counted[r] = 1;
					solved++;
					break;
				}
			}
		}
		students[idx].sno = sno;
		students[idx].solved = solved;
	}

	qsort(students, m, sizeof(Student), cmp);

	// Dense ranking: rank increments only when solved count decreases
	int rank = 1;
	int prev = students[0].solved;

	for (int i = 0; i < m; i++) {
		if (i > 0 && students[i].solved != prev) {
			rank++;
			prev = students[i].solved;
		}
		if (rank > k) break;
		if (i > 0) printf(" ");
		printf("%lld", students[i].sno);
	}
	// If all students rank <= k (e.g., many ties), loop already printed all relevant ones
	printf("\n");
	return 0;
}
