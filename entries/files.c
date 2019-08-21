#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

void criaArqBin(void){
  char arquivo [30] = "";
  char teste [30] = "Este arquivo tem alguma coisa\n";
  FILE* arq = fopen(arquivo,"wb");
  if (arq == NULL){
    printf("Erro na abertura do arquivo.\n");
    return;
  }
  fwrite(teste,sizeof(teste),30,arq);
  fclose(arq);
  
  /*Leitura  |
  /          V
  */
  arq = fopen(arquivo,"rb");
  if (arq == NULL){
    printf("Erro na abertura do arquivo.\n");
    return;
  }
  fread(teste,sizeof(teste),30,arq);
  fclose(arq);

}