#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

char cpf[11];
int i;
FILE *arquivo;

int main(){
    int matrizVoos();
    int validar_cpf();

    printf("[GERAR CPFs]\n");
    gets(cpf);

    system("cls");

    gerar_cpf();
}

int gerar_cpf(){
    srand(time(NULL));
    int numero,digito,soma=0,qntdCpfs=0,valida;

    do{
        valida = 0;
        do{
            digito = 0;

            for(i=0;i<9;i++)
                cpf[i] = (rand()%10)+48;

            for(i=0,numero=10;i <9;i++,numero--)
                digito += (cpf[i]-48)*numero;

            digito %= 11;

            if(digito<2)
                cpf[9] = 48;
            else
                cpf[9] = (11-digito)+48;

            for(i=0,numero=11;i<10;i++,numero--)
                digito += (cpf[i]-48)*numero;

            digito %= 11;

            if(digito<2)
                cpf[10] = 48;
            else
                cpf[10] = (11-digito)+48;

            valida = validar_cpf(cpf);

        }while((valida != 1) && (cpf!='00000000000') && (cpf!='11111111111') && (cpf!='22222222222') && (cpf!='33333333333') && (cpf!='44444444444') && (cpf!='55555555555') && (cpf!='66666666666') && (cpf!='77777777777') && (cpf!='88888888888') && (cpf!='99999999999'));
        printf("    %s\n",cpf);
        qntdCpfs++;
    }while(qntdCpfs<7);
    printf("\nForam gerados 7 cpfs para ocuparem 70%% das vagas de cada voo.\n\n\nALERTA: CPFs salvos com sucesso!\n\n     Os dados foram salvos no arquivo 'dados.txt'\n\n");
}

int validar_cpf(char cpf[11]){
    int soma=0, resultado, numero, i,validador=0;
    char digito10,digito11;

    for(i=0;i<9;i++){
        numero = cpf[i]-48;
        soma += (numero*(10-i));
    }

    resultado=11-(soma%11);

    if(resultado>9)
        digito10=0;
    else
        digito10=resultado;


    soma = 0;

    for(i=0;i<9;i++){
        numero = cpf[i]-48;
        soma += (numero*(11-i));
    }
    soma += digito10*2;
    resultado = 11-(soma%11);

    if(resultado>9)
        digito11=0;
    else
        digito11=resultado;

    arquivo = fopen("dados.txt","a");

    if(arquivo == NULL){
        printf("ERROR: Nao foi possivel abrir o arquivo.");
        exit(1);
    }
    if((digito10 == (cpf[9]-48)) && (digito11 == (cpf[10]-48))){
        fwrite("\n\n    ",1,1,arquivo);
        fwrite(cpf,sizeof(cpf),3,arquivo);

        validador = 1;
    }else
        validador = 0;

    fclose(arquivo);
    return validador;
}
