#include<stdio.h>
void copyFiles (char* destino, char* archivos[], int tamaño);

int main(int argc, char *argv[]){
    
    copyFiles(argv[1], argv+2, argc-2);

return 0;}

void copyFiles (char* destino, char* archivos[], int tamaño){

    FILE *dest = fopen(destino, "a");
    for(int i=0; i<tamaño; i++){
        FILE *ent=fopen(archivos[i], "r");
        int j=0;
        char c;
        char entS[100];
        while((c=fgetc(ent))!=EOF){
            entS[j] = c;
            j++;
        }
        entS[j]='\0';
        printf("%s\n", entS);
        fprintf(dest,"%s", entS);
    }
}