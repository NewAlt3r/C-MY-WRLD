#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CASAS 20

//Conta de Luz
typedef struct{
    int NumeroCasa;
    int Consumo;
    int Fatura;

}Ficha;

typedef struct{
    int MediaConsumo;
    int MediaFatura;
    int MaiorConsumo;
    int MenorConsumo;
}Caixa;

void Dados_Conta(Ficha Dados[CASAS]);
void Processar_Dados(Ficha Dados[CASAS], Caixa *Dashboard);
void Exibir(Ficha Dados[CASAS], Caixa Dashboard);


int main(){
    srand(time(NULL));

    Ficha Dados[CASAS];
    Caixa Dashboard;

    Dados_Conta(Dados);
    Processar_Dados(Dados, &Dashboard);
    Exibir(Dados, Dashboard);
    
    return 0;
}

void Dados_Conta(Ficha Dados[CASAS]){
    for(int c = 0; c < CASAS; c++){
        Dados[c].NumeroCasa = c+1;
        Dados[c].Consumo = rand() %100;
        Dados[c].Fatura = rand() %100;
    }
}

void Processar_Dados(Ficha Dados[CASAS], Caixa *Dashboard){
    int ConsumoTotal = 0; 
    int FaturaTotal = 0;
    int MenorConsumo = 9999; int MaiorConsumo = -1;

    for(int c = 0; c < CASAS; c++){

        ConsumoTotal += Dados[c].Consumo;
        FaturaTotal += Dados[c].Fatura;

        if(Dados[c].Consumo > MaiorConsumo){
            MaiorConsumo = Dados[c].Consumo;
        }
        if(Dados[c].Consumo < MenorConsumo){
            MenorConsumo = Dados[c].Consumo; 
        }
    }
    Dashboard->MediaConsumo = ConsumoTotal / CASAS;
    Dashboard->MediaFatura = FaturaTotal / CASAS;
    Dashboard->MaiorConsumo = MaiorConsumo;
    Dashboard->MenorConsumo = MenorConsumo;

}


void Exibir(Ficha Dados[CASAS], Caixa Dashboard){
    printf("\n=====================================================\n");
    printf("                  DADOS DAS CASAS                    \n");
    printf("=====================================================\n");
    for(int c = 0; c < CASAS; c++){
        printf("              CASA NUMERO %d                     \n",Dados[c].NumeroCasa);
        printf("              CONSUMO: %d kWh                    \n",Dados[c].Consumo);
        printf("              FATURA: %d REAIS                   \n",Dados[c].Fatura);
        printf("=================================================\n");
    }
    printf("                  FUNFACTS                             \n");
    printf("=================================================\n");
    printf("                  CONSUMO MEDIO: %d                  \n", Dashboard.MediaConsumo);
    printf("                  FATURA MEDIA: %d                  \n", Dashboard.MediaFatura);
    printf("                  MAIOR CONSUMO: %d                  \n", Dashboard.MaiorConsumo);
    printf("                  MENOR CONSUMO: %d                  \n", Dashboard.MenorConsumo);
    printf("\n=====================================================\n");
}