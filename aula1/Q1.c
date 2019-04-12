#include <stdio.h>

int main(){

    int n = 1;
    printf("informe n(finalize com n<=0): ");
    scanf("%d", &n);
    for(;n > 0;){
        int compMax = 1;
        int compMaxTemp = 0;
        int itemSeq = 0;
        int itemSeqTemp = 0;
        for(;n > 0;n--){
            scanf("%d", &itemSeqTemp);
            //printf("itemSeqTemp/itemSeq %d/%d\n", itemSeqTemp, itemSeq);
            if (itemSeqTemp > itemSeq){
                compMaxTemp++;
            }
            else{
                if (compMaxTemp > compMax){
                    compMax = compMaxTemp;
                }
                compMaxTemp = 1;
            }
            itemSeq = itemSeqTemp;
        }
        if (compMaxTemp > compMax){
            compMax = compMaxTemp;
        }
        printf("Comprimento Maximo: %d \n", compMax);
        printf("informe novo n (finalize com n<=0): ");
        scanf("%d", &n);
    }
    printf("bye !!!\n");
}