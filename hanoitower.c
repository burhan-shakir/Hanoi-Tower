#include <stdio.h>
#include <string.h>
#include <unistd.h>
int peg1[9], peg2[9], peg3[9];

void display_pegs(){
    int disks1,spaces1,disks2,spaces2,disks3,spaces3,i,j,k;
    for(i = 8; i >= 0; i--){
        disks1 = peg1[i];
        disks2 = peg2[i];
        disks3 = peg3[i];
        spaces1 = 10 - disks1;
        spaces2 = 10 - disks2;
        spaces3 = 10 - disks3;
        for(j = 0; j < spaces1; j++){
            printf(" ");
        }
        for(k = 0; k < disks1; k++){
            printf("+");
        }
        printf("|");
        for(k = 0; k < disks1; k++){
            printf("+");
        }
        for(j = 0; j < spaces1; j++){
            printf(" ");
        }
        printf("  ");
        for(j = 0; j < spaces2; j++){
            printf(" ");
        }
        for(k = 0; k < disks2; k++){
            printf("+");
        }
        printf("|");
        for(k = 0; k < disks2; k++){
            printf("+");
        }
        for(j = 0; j < spaces2; j++){
            printf(" ");
        }
        printf("  ");
        for(j = 0; j < spaces3; j++){
            printf(" ");
        }
        for(k = 0; k < disks3; k++){
            printf("+");
        }
        printf("|");
        for(k = 0; k < disks3; k++){
            printf("+");
        }
        for(j = 0; j < spaces3; j++){
            printf(" ");
        }

        printf("\n");
    }
    printf("XXXXXXXXXXXXXXXXXXXXX  XXXXXXXXXXXXXXXXXXXXX  XXXXXXXXXXXXXXXXXXXXX\n");
    printf("\n");
}

void move(int pegA[9], int pegB[9]){
        int store,i,j;
        for(i = 8; i >= 0; i--){
            if(pegA[i] != 0){
                store = pegA[i];
                pegA[i] = 0;
                break;
            }
        }
        for(j = 0; j < 9; j++){
            if(pegB[j] == 0){
                pegB[j] = store;
                break;
            }
        }
        display_pegs();
        sleep(1);
}

void hantow(int nod, int pego[9], int pegd[9], int pegh[9]){
        if(nod > 1)
                hantow(nod-1, pego, pegh, pegd);
        move(pego,pegd);
        if(nod > 1)
                hantow(nod-1, pegh, pegd, pego);
}

int main(int argc, char* argv[]){
        if(argc != 2){
                printf("Too many command line arguments\n");
                return 0;
        }
        if(strlen(argv[1]) != 1){
                printf("Incorrect argument\n");
                return 0;
        }
        if(!('1' <= argv[1][0] && argv[1][0] <= '9')){
                printf("Incorrect argument\n");
                return 0;
        }
        int num_of_disks = argv[1][0]-'0';
        int temp = argv[1][0]-'0';
        int i,j;
        for(i = 0; i < num_of_disks; i++, temp--)
                peg1[i] = temp;
        for(j = 0; j < 9; j++){
                peg2[j] = 0;
                peg3[j] = 0;
        }
        display_pegs();
        sleep(1);
        hantow(num_of_disks, peg1, peg2, peg3);
        printf("done\n");
        return 0;
}

