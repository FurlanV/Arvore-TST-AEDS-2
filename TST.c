#include <stdlib.h>
#include <stdio.h>
#include "TST.h"

#define MAX 50

Node *novoNo(char reg)
{
    Node *novoNo = (Node*)malloc(sizeof(Node));
    novoNo->reg = reg; 
    novoNo->fimDeString = 0;
    novoNo->dir = NULL;
    novoNo->mid = NULL;
    novoNo->esq = NULL;
    
    return novoNo;
}

void inserir(Node **raiz,char *palavra)
{
    //Caso Base
    if(!(*raiz))
        *raiz = novoNo(*palavra);
    
    //Se o caracter atual da palavra for menor do que o caracter da raiz
    //entao inserimos essa palavra na subarvore a esquerda da raiz
    if((*palavra) < (*raiz)->reg){
        inserir(&(*raiz)->esq,palavra);
    }
    
    //Se o caracter atual da palavra for maior do que o caracter da raiz
    //entao inserimos essa palavra na subarvore a direita da raiz
    else if((*palavra) > (*raiz)->reg){
        inserir(&(*raiz)->dir,palavra);
    }
    
    //Se o caracter atual da palavra é o mesmo caracter da raiz
    else{
        
        if(*(palavra+1))
            inserir(&(*raiz)->mid,palavra+1);
        else
            (*raiz)->fimDeString = 1;
        
    }
    
}

//Funçao auxiliar que percorre a arvore de forma recursiva
void percorreTSTUtil(Node *raiz,char *buffer,int profundidade)
{
    if(raiz){
        //primeiro percorre a subarvore a esquerda
        percorreTSTUtil(raiz->esq,buffer,profundidade);
        
        //Guarda o caracter deste nó
        buffer[profundidade] = raiz->reg;
        
        if(raiz->fimDeString){
            buffer[profundidade+1] = '\0';
            printf("%s\n",buffer);
        }
        
        //percorre a subarvore do meio
        percorreTSTUtil(raiz->mid,buffer,profundidade+1);
        
        //Finalmente percorre a subarvore da direta
        percorreTSTUtil(raiz->dir,buffer,profundidade);
    }
}

void percorreTST(Node *raiz)
{
    char buffer[MAX];
    percorreTSTUtil(raiz,buffer,0);
}

int buscaTST(Node *raiz,char *palavra)
{
    if(!raiz)
        return  0;
    
    if(*palavra < (raiz)->reg)
        return buscaTST(raiz->esq,palavra);
    else if (*palavra > (raiz)->reg)
        return buscaTST(raiz->dir,palavra);
    else{
        if(*(palavra+1) == 0)
            return raiz->fimDeString;
        
        return buscaTST(raiz->mid,palavra+1);
            
    }
}

void menu()
{
    Node *raiz = NULL;
    int opc = 1,j;
    char palavra[20],palavra2[20];
    
    while(opc != 0 ){
        printf("1 - Inserir | 2 - Percorrer Arvore | 3 - Buscar Palavra | 0 - Sair\n");
        scanf("%d",&opc);
        
        switch(opc){
            case 1:
                printf("Digite a palavra que deseja inserir\n");
                scanf("%s",&palavra);
                
                inserir(&raiz,palavra);
                break;
            case 2:
                printf("Percorrendo a arvore..\n");
                percorreTST(raiz);
                break;
            case 3:
                printf("Digite a palavra que voce deseja buscar\n");
                scanf("%s,&palavra2");
                
                if(buscaTST(raiz,palavra2))
                    printf("A palavra '%s' foi encontrada !\n",palavra2);
                else
                    printf("A palavra '%s' nao foi encontrada !\n",palavra2);
                break;
        }
     }
    
}