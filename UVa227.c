#include<stdio.h>
#include<string.h>
const char msg[] = "This puzzle has no final configuration.";
char temp[100];
char line[10];
char data[10][10];
char inst[100];

int main()
{
	int n = 0;
	int m = 1;
	int ind = 0;
	int x, y;
	while (m) {
		ind = 0;
		inst[0] = '\0';
		
		while (ind < 5) {
			gets(line);
			if (n && (ind == 0)) {
				gets(line);
			}
			if (line[0] == 'Z') {
				m = 0;
				break;
			}
			
			for (int i = 0; i < 6; i++) {
				data[ind][i] = line[i];
				if (line[i] == ' ') {
					x = i;
					y = ind;
				}
			}
			
			ind++;
		}
		
		if (m == 0) break;
		
		while(scanf("%s", temp) == 1) {
			strcat(inst, temp);
			if (temp[strlen(temp)-1] == '0') break;
		}
				
		int instlen = strlen(inst);
		int flag = 0; // flag == 1 means error
		for (int i = 0; i < instlen - 1; i++) {
			char tempchar;
			switch (inst[i]) {
				case 65: //'A'
					if(y-1 < 0) {
						flag = 1;
						break;
					}
					tempchar = data[y-1][x];
					data[y-1][x] = data[y][x];
					data[y][x] = tempchar;
					y--;
					break;
				case 66: //'B'
					if(y+1 > 4) {
						flag = 1;
						break;
					}
					tempchar = data[y+1][x];
					data[y+1][x] = data[y][x];
					data[y][x] = tempchar;
					y++;
					break;
				case 76: //'L'
					if(x-1 < 0) {
						flag = 1;
						break;
					}
					tempchar = data[y][x-1];
					data[y][x-1] = data[y][x];
					data[y][x] = tempchar;
					x--;
					break;
				case 82: //'R'
					if(x+1 > 4) {
						flag = 1;
						break;
					}
					tempchar = data[y][x+1];
					data[y][x+1] = data[y][x];
					data[y][x] = tempchar;
					x++;
					break;
			}
			if (flag) {
				break;
			}
		}
		if(n) printf("\n");
		printf("Puzzle #%d:\n", ++n);
		if (flag) {
			printf("%s\n", msg);
		} else {
			for (int i = 0; i < 5; i++) {
				printf("%c %c %c %c %c\n", data[i][0],data[i][1],data[i][2],data[i][3],data[i][4]);
			}
		}
	}
	return 0;
}
