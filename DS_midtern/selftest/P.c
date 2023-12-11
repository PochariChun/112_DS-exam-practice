#include <stdio.h>
int main(){

    int M;
    scanf("%d",&M);
    while (M > 0){
        int triup = 1;
        int trido = 1;
        for (int i= 0; i<5, i++) {
            for (int j= 0; j<5, j++) {
                int x;
                scanf("%d", &x);
                if (x && i<j){
                    trido = 0;
                }
                if (x && i>j){
                    triup = 0;
                }
            }
        }
        if (triup){
            printf("0\n");
        }
        else if (trido)
        {
            printf("1\n");
        }else
        {
            printf("-1\n");
        }
        M--;
    }
    return 0;    
}