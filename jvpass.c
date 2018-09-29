#include <stdio.h>
#include <stdlib.h>
#define max(X, Y) (((X) > (Y)) ? (X) : (Y))

int CurrentTreeAVLState = 1;

typedef struct node{
    struct node * esquerda;
    struct node * direita;
    int info;
}Node;

int height(Node* node) 
{ 
   
   if(node == NULL) 
       return 0; 
  
   
   return 1 + max(height(node->esquerda), height(node->direita)); 
}  

Node * insereEmArvore(Node * arvore, int info){
    
    if(arvore == NULL){
        Node * new =(Node *) malloc(sizeof(Node));
        new->info = info;
        arvore = new;
        
        
    }else{
        int prof;
        if(info < arvore->info){
            arvore ->esquerda = insereEmArvore(arvore->esquerda,info);
           
            
        }else{
            arvore->direita = insereEmArvore(arvore->direita,info);
            
            
        }
        int taxa = height(arvore->esquerda)-height(arvore->direita);
        if(taxa>1 || taxa< -1) {
            CurrentTreeAVLState = 0;
        }
    }
    
        
    return arvore;
    
}

int main(){
    int c;
    scanf("%d",&c);
    

    

    int i;
    for(i=1;i<=c;i++){
        
        Node * arvore = NULL;
        
        int n;
        scanf("%d",&n);
        int j;
        for(j=1;j<=n;j++){
            int info;
            scanf("%d",&info);
            if(info == -1)continue;
            arvore = insereEmArvore(arvore,info);
            
            
            
        }
        if(!CurrentTreeAVLState){
                printf("F\n");
                CurrentTreeAVLState = 1;
            }else{
                printf("T\n");
        }
        
        
        
        
    }
    return 0;
}