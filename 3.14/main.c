#include <stdio.h>
#include <stdlib.h>

void printSolution(int n, int **solution);

int isValidMove(int i, int j, int n, int **solution);

void findTour(int i, int j, int n, int trace, int **solution);

int noOfSolutions = 0;

int main() {
    printf("Introduce the size of the chess board:\n");
    int n;
    scanf("%d", &n);
    int **board = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        board[i] = (int *) malloc(n * sizeof(int));
    int **solution = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        solution[i] = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            solution[i][j] = 0;
    solution[0][0] = 1;
    findTour(0, 0, n, 1, solution);
    printf("%d", noOfSolutions);
    return 0;
}

void findTour(int i, int j, int n, int trace, int **solution) {
    int iMove[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int jMove[] = {1, 2, 2, 1, -1, -2, -2, -1};
    solution[i][j] = trace;
    if (trace == n * n)
        printSolution(n, solution);
    else
        for (int k = 0; k < 8; k++)
            if (isValidMove(i + iMove[k], j + jMove[k], n, solution))
                findTour(i + iMove[k], j + jMove[k], n, trace + 1, solution);
    solution[i][j] = 0;
}

void printSolution(int n, int **solution) {
    noOfSolutions++;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", solution[i][j]);
        printf("\n");
    }
    printf("\n");
}

int isValidMove(int i, int j, int n, int **solution) {
    return (i >= 0 && i < n && j >= 0 && j < n && solution[i][j] == 0);
}