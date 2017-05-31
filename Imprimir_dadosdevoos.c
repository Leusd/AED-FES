#include <stdio.h>
#include <locale.h>
struct voo
{
    int numeroVoo;
    int a;
};
struct voo conj[5][10];
int imprimir_dadosdevoos()
{
    setlocale(LC_ALL, "Portuguese");
    int numvoo,i,j,achei=0;
    char opcao;
    printf("1- Imprimir dados de um voo \n");
    printf("2- Imprimir ocupação de todos os voos \n");
    printf("3- Imprimir todos os dados de voos \n");
    printf("Digite sua opção: ");
    scanf("%c", &opcao);
    while (opcao!='1' && opcao!='2' && opcao!='3')
    {
        printf("Função inválida. \nDigite novamente: ");
        scanf("%c", &opcao);
    }

    switch(opcao)
    {
    case '1':// imprimir dados de um voo
        printf("Digite o numero do voo: ");
        scanf("%d",&numvoo);
        for(i=0; i<5; i++)
        {
            for(j=0; j<10; j++)
            {

                if(conj[i][j].numeroVoo==numvoo)
                {
                    achei++;
                    if (conj[i][j].a==1)
                    {
                        printf("Número de reservas:  \n");
                        printf("Passageiro:  Assento: ");
                    }
                    if (conj[i][j].a==0)
                    {
                        printf("Voo Inexistente.");
                    }

                }


            }
        }
        if(achei==0)
        {
            printf("Voo Inexistente.");
        }
        break;

    case '2':// imprimir a ocupação de todos os voos
        for(i=0; i<5; i++)
        {
            for(j=0; j<10; j++)
            {
                if (conj[i][j].a==1)
                {
                    printf("Voo número: %d  ", conj[i][j].numeroVoo);
                    printf("Número de reservas:  \n");
                }
            }
        }
        break;

    case '3':// imprimir todos os dados dos voos
        printf("chupagalo");
        for(i=0; i<5; i++)
        {
            for(j=0; j<10; j++)
            {
                if (conj[i][j].a==1)
                {
                    printf("Voo número: %d  ", conj[i][j].numeroVoo);
                    printf("Número de reservas:  \n");
                    // Para o resto do programa é necessário o cpf
                }
            }
        }

        break;

    }
}


int main()
{


    int i,j,num=1000,aux=1;
    for(i=0; i<5; i++)
    {
        for(j=0; j<10; j++)
        {
            conj[i][j].numeroVoo = aux + num;
            conj[i][j].a = 1;
            aux++;

        }
        num=num+1000;
        aux=1;
    }
    imprimir_dadosdevoos();
}
