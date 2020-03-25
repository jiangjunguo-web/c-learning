#include <stdio.h>
#include <stdlib.h>

int surfaceArea(int** grid, int gridSize, int gridColSize){
	int i, j, ans = 0, temp;
	for (i = 0; i<gridSize; i++){
		for (j = 0; j<gridColSize; j++){
			if (grid[i][j] != 0){
				ans = ans + grid[i][j] * 6 - (grid[i][j] - 1) * 2;
				if (i - 1 >= 0)
					ans -= grid[i][j]>grid[i - 1][j] ? grid[i - 1][j] : grid[i][j];
				if (i + 1<gridSize)
					ans -= grid[i][j]>grid[i + 1][j] ? grid[i + 1][j] : grid[i][j];
				if (j - 1 >= 0)
					ans -= grid[i][j]>grid[i][j - 1] ? grid[i][j - 1] : grid[i][j];
				if (j + 1<gridColSize)
					ans -= grid[i][j]>grid[i][j + 1] ? grid[i][j + 1] : grid[i][j];
			}
		}
	}
	return ans;
}

int main() {
	int str[2][2] = { { 1, 2 }, { 3, 4 } };
	int *p[2];
	for (int i = 0; i < 2; i++) {
		p[i] = str[i];
	}
	printf("%d", surfaceArea(p,2,2)); 
	system("pause");
	return 0;
}