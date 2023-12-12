#include <stdio.h>
#include <stdlib.h>
int main()
{
    float* piF=(float*)malloc(sizeof(float));

    printf("input piF value=");
    scanf("%f",piF);
    printf("\n");
    printf("piF to the data is %f\n",*piF);
    printf("piF to adress is %p\n",piF);

    free(piF);

    system("pause") ;
    return 0;
}