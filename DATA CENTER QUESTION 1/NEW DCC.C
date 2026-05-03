#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SALAS 10
#define RACKS 5
#define SENSORES 3
#define TEMP_MAX 80

typedef struct{
    int Temperatura[SENSORES];
    int RackMedia;
}Rack;

typedef struct{
    Rack RacksDasSalas[RACKS];
    int SalaMedia;
}Sala;

void PegarDados(Sala Datacenter[SALAS]);
void ProcessarDados(Sala Datacenter[SALAS]);
void Exibir(Sala Datacenter[SALAS]);

int main(){
    srand(time(NULL));

    Sala Datacenter[SALAS];

    PegarDados(Datacenter);
    ProcessarDados(Datacenter);
    Exibir(Datacenter);

    return 0;

}

void PegarDados(Sala Datacenter[SALAS]){
    for(int s = 0; s < SALAS; s++){
        for(int r = 0; r < RACKS; r++){
            for(int se = 0; se < SENSORES; se++){
                Datacenter[s].RacksDasSalas[r].Temperatura[se] = rand() % 100;
            }
        }
    }
}

void ProcessarDados(Sala Datacenter[SALAS]){
    for(int s = 0; s < SALAS; s++){
        int TotalSala = 0;

        for(int r = 0; r < RACKS; r++){
            int TotalRack = 0;

            for(int se = 0; se < SENSORES; se++){

                int Valor = Datacenter[s].RacksDasSalas[r].Temperatura[se];
                TotalRack += Valor;
                TotalSala += Valor;

                if(Valor > TEMP_MAX){
                    printf("ALERTA: SALA %02d RACK %02d SENSOR %02d : %d°C\n", s+1, r+1, se+1, Valor);
                }
            }
            Datacenter[s].RacksDasSalas[r].RackMedia = TotalRack/SENSORES;
        }
        Datacenter[s].SalaMedia = TotalSala/(RACKS*SENSORES);
    } 
}

void Exibir(Sala Datacenter[SALAS]){
    printf("MEDIAS SALAS & RACKS:        \n");
    for(int s = 0; s < SALAS; s++){

        printf("SALA %02d : %d°C |",s+1, Datacenter[s].SalaMedia);

        for(int r = 0; r < RACKS; r++){
            int Visual = (s * RACKS)+r+1;
                printf(" RACK %02d : %d°C | ", Visual, Datacenter[s].RacksDasSalas[r].RackMedia);
            }
        printf("\n");
    }
}

