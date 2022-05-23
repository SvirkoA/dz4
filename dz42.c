#include <stdio.h>

int main(){
    int n, i, j;
    int y =0;
    int z =0;
    int A[101][101], B[101][101], C[101][101];
    FILE* graph1, *viz1;
    FILE* graph2, *viz2;
    FILE* graph3, *viz3;

    graph1 = fopen("graph1.txt", "r");
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            fscanf(graph1, "%d", &A[i][j]);
        }
    }
    fclose(graph1);

    viz1 = fopen("viz1.txt", "w");
    fprintf(viz1, "graph {");
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if (A[i][j] != 0){
                fprintf(viz1, "%d -- %d\n", i + 1, j + 1);
                    if (A[i][j] > 1){
                        fprintf(viz1, " [label = %d]\n", A[i][j]);
                    }
            }
        }
    }
    fprintf(viz1, "}");

    graph2 = fopen("graph2.txt", "r");
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            fscanf(graph2, "%d", &B[i][j]);
        }
    }
    fclose(graph2);

    viz2 = fopen("viz2.txt", "w");
    fprintf(viz2, "graph {");
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if (B[i][j] != 0){
                fprintf(viz2, "%d -- %d\n", i + 1, j + 1);
                    if (B[i][j] > 1){
                        fprintf(viz2, " [label = %d]\n", B[i][j]);
                    }
            }
        }
    }
    fprintf(viz2, "}");

    graph3 = fopen("graph3.txt", "w");
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            C[i][j] = 0;
            if(A[i][j] = B[i][j]){
                C[i][j] = A[i][j];
            }else{
                C[i][j] = 0;
            }
            fprintf(graph3, "%d ", C[i][j]);
        }
        fprintf(graph3, "\n");
    }
    fclose(graph3);

    viz3 = fopen("viz3.txt", "w");
    fprintf(viz3, "graph {");
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if (C[i][j] != 0){
                fprintf(viz3, "%d -- %d\n", i + 1, j + 1);
                if (C[i][j] > 1){
                    fprintf(viz3, " [label = %d]\n", C[i][j]);
                }
            }
        }
    }
    fprintf(viz3, "}");
    return 0;
}
