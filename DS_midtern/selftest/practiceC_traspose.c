#include<stdio.h>

int main(){
    int M;int N;
    int matrix[10][10];
    scanf("%d %d", &M, &N);
    for (int i =0; i< M; i++){
        for (int j =0; j< M; j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    for (int i =0; i< N; i++){
        for (int j =0; j< M; j++){
            printf("%d",matrix[j][i]);
            if (j<M-1){
                printf(" ");
            }
        }
        print("\n");
        

    }
    return 0;
}