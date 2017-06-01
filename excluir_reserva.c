#include <stdio.h>
#include <locale.h>
struct voo
{
    int numeroVoo;
    int a;
};
struct voo conj[5][10];
void excluir_reserva(int voo1,char cpf1[11])
{
    int i,j;
    for(i=0;i<5;i++){
        for(j=0;j<10;j++){
            if(voo1==conj[i][j].numeroVoo){
                if(conj[i][j].a==1){
                    if(cpf existir){
                    }
                    else
                    {
                    printf("Passageiro inexistente");
                    }

                //Indicação passageiro inexistente no voo
                //Precisa de outra função chamando cpf
                }
                else{
                    printf("Voo inexistente");
                }
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char cpf[11];
    int voo;
    int i,j,num=1000,aux=1;
    for(i=0; i<5; i++)
    {
        for(j=0; j<10; j++)
        {
            conj[i][j].numeroVoo = aux + num;
            conj[i][j].a = 0;
            aux++;

        }
        num=num+1000;
        aux=1;
    }
    printf("Digite o número do voo:\n");
    scanf("%d",&voo);
    printf("Digite seu cpf:\n");
    scanf("%s",&cpf);
    excluir_reserva(voo,cpf);
}
