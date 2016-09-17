typedef struct{
    char reg;
    
    //verdadeiro caso a letra seja a ultima letra de uma das palavras
    unsigned int fimDeString: 1;
    
    struct Node *esq;
    struct Node *mid;
    struct Node *dir;
}Node;

Node *novoNo(char reg);
void inserir(Node **raiz,char *palavra);
void percorreTSTUtil(Node *raiz,char *buffer,int profundidade);
void percorreTST(Node *raiz);
int buscaTST(Node *raiz,char *palavra);
    
    

