#include <stdio.h>
#include <stdlib.h>

int isExit(int i, int j, int n, int m);

void printSolution(int n, int m, int **solution);

int isSafe(int i, int j, int n, int m, int **labyrinth, int **solution);

void findPath(int i, int j, int n, int m, int trace, int **labyrinth, int **solution);

int isValidStartPoint(int i, int j, int n, int m, int **labyrinth);

int main() {
    int iStart, jStart, n, m;
    printf("Please introduce the size of the labirinth:\n");
    scanf("%d %d", &n, &m);
    printf("Please introduce the labirinth:\n");
    int **labyrinth = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        labyrinth[i] = (int *) malloc(m * sizeof(int));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &labyrinth[i][j]);
    int **solution = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        solution[i] = (int *) malloc(m * sizeof(int));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            solution[i][j] = 0;
    printf("Please introduce the starting point:\n");
    scanf("%d %d", &iStart, &jStart);
    while (isValidStartPoint(iStart, jStart, n, m, labyrinth) == 0) {
        printf("Please introduce a valid starting point:\n");
        scanf("%d %d", &iStart, &jStart);
    }
    findPath(iStart, jStart, n, m, 1, labyrinth, solution);
    return 0;
}

void findPath(int i, int j, int n, int m, int trace, int **labyrinth, int **solution) {
    int iMove[4] = {1, 0, -1, 0};
    int jMove[4] = {0, 1, 0, -1};
    solution[i][j] = trace;
    if (isExit(i, j, n, m)) {
        printSolution(n, m, solution);
    } else
        for (int k = 0; k < 4; k++) {
            if (isSafe(i + iMove[k], j + jMove[k], n, m, labyrinth, solution) > 0)
                findPath(i + iMove[k], j + jMove[k], n, m, trace + 1, labyrinth, solution);
        }
    solution[i][j] = 0;
}

int isExit(int i, int j, int n, int m) {
    return (i == n - 1 && j == m - 1);
}

void printSolution(int n, int m, int **solution) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%d ", solution[i][j]);
        printf("\n");
    }
    printf("\n");
}

int isSafe(int i, int j, int n, int m, int **labyrinth, int **solution) {
    return (i < n && j < m && i >= 0 && j >= 0 && labyrinth[i][j] == 1 && solution[i][j] == 0);
}

int isValidStartPoint(int i, int j, int n, int m, int **labyrinth) {
    return (i >= 0 && i < n && j >= 0 & j < m && labyrinth[i][j] == 1);
}