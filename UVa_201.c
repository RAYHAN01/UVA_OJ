#include<stdio.h>
#include<string.h>
#include<memory.h>

#define SN 13
char H[SN][SN]; //main refe
char V[SN][SN];
char P[81][2];
char F[SN];

int main() {
	int n, m, x, y, i, count, result, kase = 0;
	char c[2];
	while(scanf("%d", &n) != EOF) {
		scanf("%d", &m);
		i = 0;
		memset(H, 0, sizeof(H));
		memset(V, 0, sizeof(V));
		while(m--) {
			scanf("%s", c);
			scanf("%d%d", &x, &y);
			if (c[0] == 'H') {
				H[x][y] = 1;
				if (V[y][x]) {
					P[i][0] = x;
					P[i++][1] = y;
				}
			}
			if (c[0] == 'V') {
				V[x][y] = 1;
				if (H[y][x]) {
					P[i][0] = y;
					P[i++][1] = x;
				}
			}
		}
		memset(F, 0, sizeof(F));
		for (int ind = 0; ind < i; ind++) {
			int cx = P[ind][0];
			int cy = P[ind][1];
			for (int exp = 1; (exp + cx <= n) && (exp + cy <= n); exp++) {
				result = 1;
				for (int d = 0; d < exp; d++) {
					result = result * H[cx][cy+d] * H[cx+exp][cy+d] * V[cy][cx+d] * V[cy+exp][cx+d];
					if (!result) break;
				}
				if (result) {
					F[exp]++;
				}
			}
		}
		if (kase++) printf("\n**********************************\n\n");
		printf("Problem #%d\n\n", kase);
		count = 0;
		for (int i = 1; i <= n; i++) {
			if (F[i]) printf("%d square (s) of size %d\n", F[i], i);
			else count++;
		}
		if (count == n) {
			printf("No completed squares can be found.\n");
		}
	}
	return 0;
}
