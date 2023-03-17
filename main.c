#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Uso: %s <arquivo de entrada> <nova extensão>\n", argv[0]);
        return 1;
    }
    
    char *entrada = argv[1];
    char *nova_extensao = argv[2];
    
    // Verifica se a extensão de entrada é suportada
    char *extensao = strrchr(entrada, '.');
    if(extensao == NULL) {
        printf("Erro: extensão de arquivo inválida.\n");
        return 1;
    }
    
    // Cria uma cópia da string do nome do arquivo
    char *nome_arquivo = (char*) malloc(sizeof(char) * (strlen(entrada) + 1));
    strcpy(nome_arquivo, entrada);
    
    // Troca a extensão
    strcpy(strrchr(nome_arquivo, '.'), nova_extensao);
    
    // Renomeia o arquivo
    if(rename(entrada, nome_arquivo) != 0) {
        printf("Erro: não foi possível renomear o arquivo.\n");
        return 1;
    }
    
    printf("Arquivo renomeado com sucesso.\n");
    
    free(nome_arquivo);
    
    return 0;
}
