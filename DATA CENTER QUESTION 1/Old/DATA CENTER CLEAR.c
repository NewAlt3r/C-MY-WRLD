#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

#define SALAS 10
#define RACKS 5
#define SENSORES 3
#define TEMPALERTA 80

int main(){
    srand(time(NULL));
    int sala[SALAS][RACKS][SENSORES];
    int mediasala[SALAS];
    int mediarack[SALAS][RACKS];
    int mediasensor = 0;

    int v = 0;
    for(int s = 0; s < SALAS; s++){
        for(int r = 0; r < RACKS; r++){
            for(int se = 0; se < SENSORES; se++){
                sala[s][r][se] = rand() % 100;

            }
        }
    }

    for(int s = 0; s < SALAS; s++){
        int zerasala = 0;
        for(int r = 0; r <RACKS; r++){
            int zerarack = 0;
            for(int se = 0; se < SENSORES; se++){
                int tempsensor = sala[s][r][se];
                mediasensor += tempsensor;
                zerarack += tempsensor;
                zerasala += tempsensor;

                if(tempsensor > TEMPALERTA){
                    printf("ALERTA: Sala %d Rack %d Sensor %d PASSOU DOS 80°C\n", s+1, r+1, se+1);
                }

            }
            mediarack[s][r] = zerarack/SENSORES;
        }
        mediasala[s] = zerasala/SALAS * RACKS;
    }
    printf("=====================================================");

    int valo = 1;
    for(int s= 0; s < SALAS; s++){
        printf("Media da Sala %d: %d\n", s+1, mediasala[s]);
    }

    printf("=====================================================\n");
    for(int s = 0; s < SALAS; s++){
        for(int r = 0; r < RACKS; r++){
            printf("Media do Rack %d: %d\n", valo++, mediarack[s][r]);
        }
    }

    printf("=====================================================\n");
    

    system("pause");
    return 0;
}