#include <stdio.h>
int main()
{
     struct voo {
           int numeroVoo;
           int a;
     };

    struct voo conj[5][10];
    int i,j,num=1000,aux=1;
    for(i=0; i<5; i++)
    {
        for(j=0; j<10; j++)
        {
            conj[i][j].numeroVoo = aux + num;
            conj[i][j].a = 1;
            aux++;
            printf("numero:%d , existencia:%d",conj[i][j].numeroVoo,conj[i][j].a);
            printf("\n");

        }
        num=num+1000;
        aux=1;
        printf("\n");
    }
}
