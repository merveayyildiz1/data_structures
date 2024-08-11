#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int grid[MAX][MAX];
int tekrar[MAX][MAX];
int k, m;

int ax[]={-1, 1, 0, 0, -1, -1, 1, 1};
int ay[]={0, 0, -1, 1, -1, 1, -1, 1};

int valid(int x,int y) {
    return (x>=0 && y>= 0 && x<k && grid[x][y]==1 && y<m && !tekrar[x][y]);
}

int search(int x, int y) {
    tekrar[x][y]=1;
    int count=1;

    for (int i=0; i<8;i++) {
        int yeniX =x+ax[i];
        int yeniY =y+ay[i];
        if(valid(yeniX,yeniY)) {
            count+=search(yeniX,yeniY);
        }
    }

    return count;
}

int main() {
    int countBlobs = 0;
    int blobSizes[MAX];

    scanf("%d %d", &k, &m);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            grid[i][j] = 0;
            tekrar[i][j] = 0;
        }
    }

    int x, y;
    while (1) {
        scanf("%d", &x);
        if (x == -1) break;
        scanf("%d", &y);
        if (y == -1) break;
        grid[x][y] = 1;
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1 && !tekrar[i][j]) {
                int size = search(i, j);
                blobSizes[countBlobs++] = size;
            }
        }
    }

    for (int i = 0; i < countBlobs - 1; i++) {
        for (int j = i + 1; j < countBlobs; j++) {
            if (blobSizes[i] > blobSizes[j]) {
                int temp = blobSizes[i];
                blobSizes[i] = blobSizes[j];
                blobSizes[j] = temp;
            }
        }
    }

    printf("%d ", countBlobs);
    for (int i = 0; i < countBlobs; i++) {
        printf("%d ", blobSizes[i]);
    }
    printf("\n");

    return 0;
}
