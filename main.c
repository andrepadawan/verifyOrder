#include <stdio.h>
#include <string.h>

const int MAXC=50;
int verifyOrder(FILE *fp);

int main(void) {
    char namein[MAXC+1];
    FILE *fin;
    printf("name of input file: ");
    scanf("%s", namein);
    fin=fopen(namein,"r");
    if (verifyOrder(fin)==1)
        printf("File %s is ordered\n", namein);
    else
    printf("File %s is not ordered\n",
    namein);
    fclose(fin);
    return 0; }
int verifyOrder(FILE *fp) {
    char row0[MAXC+1], row1[MAXC+1];
    fgets(row0,MAXC,fp);
    while (fgets(row1,MAXC,fp)!=NULL) {
        if (strcmp(row1,row0)<0)
            return 0;
        strcpy(row0,row1);
    }
    return 1; }
