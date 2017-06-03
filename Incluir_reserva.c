#include <stdio.h>
#include <locale.h>
struct voo
{
    int numeroVoo;
    int a;
    int cpf;
};
struct voo conj[5][10];
int incluir_reserva()
{
    setlocale(LC_ALL, "Portuguese");
    int numvoo,cpfn,achei=0;
    int i,j,num=1000,aux=1;
    printf("Número do voo: ");
    scanf("%d",&numvoo);
    printf("CPF: ");
    scanf("%d",&cpfn);
    printf("Assentos vagos no voo\n");
    for(i=0; i<5; i++)
    {
        for(j=0; j<10; j++)
        {
            conj[i][j].numeroVoo = aux + num;
            conj[i][j].a = 1;
            aux++;
            if(conj[i][j].numeroVoo==numvoo)
            {
                if (cpfn==conj[i][j].cpf)
                {
                    return 2;
                }
                if (conj[i][j].a==0)
                {
                    printf("número:%d",conj[i][j].numeroVoo);
                    printf("\n");
                    achei++;
                }
                if (achei==0)
                {
                    return 1;
                }
            }
            printf("Escolha um assento/n");
            scanf("%d",&numvoo);
            for(i=0; i<5; i++)
            {
                for(j=0; j<10; j++)
                {
                    if(conj[i][j].numeroVoo==numvoo)
                    {
                        if (conj[i][j].a==1)
                        {
                            return 3;
                        }
                        if (conj[i][j].a==0)
                        {
                            conj[i][j].cpf=cpfn;
                            printf("Número voo: %d\n",conj[i][j].numeroVoo);
                            printf("CPF: %d\n",conj[i][j].cpf);
                            conj[i][j].a=1;
                            return 4;
                        }
                    }
                }

            }
        }
    }
}
