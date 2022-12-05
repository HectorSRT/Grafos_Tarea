#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct{
    char elemento[MAX];
    int matriz[MAX][MAX];
    int noElement;
}TGrafo;

void inicia_grafo(TGrafo *g);
int add_relation(TGrafo *g, char vertice1, char vertice2);
int find_vertice(TGrafo *g, char value);
int add_vertice(TGrafo *g, char vertice);
void imprime_grafo(TGrafo *g);
int delete_relation(TGrafo *g, char vertice1, char vertice2);

int main()
{
    int main() {
    TGrafo *g;
    inicia_grafo(&g);
    add_vertice(&g,'A');
    add_vertice(&g,'B');
    add_vertice(&g,'C');
    add_vertice(&g,'X');
    add_vertice(&g,'Y');
    add_vertice(&g,'Z');
    add_relation(&g,'A','Z');
    add_relation(&g,'A','C');
    add_relation(&g,'X','C');
    add_relation(&g,'B','Y');
    add_relation(&g,'C','Z');
    printGraph(g);
    printf("\n");
    delete_relation(&g,'A','Z');
    imprime_grafo(&g);
    return 0;
}
    return 0;
}

void inicia_grafo(TGrafo *g){
    g->noElement=0;
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            g->matriz[i][j]=0;
        }
    }
}

int add_relation(TGrafo *g, char vertice1, char vertice2){
    int posVertice1=find_vertice(g,vertice1);
    int posVertice2=find_vertice(g,vertice2);

    if(posVertice1!=-1&&posVertice2!=-1){
        g->matriz[posVertice1][posVertice2];
        return 1;
    }

    return 0;
}

int add_vertice(TGrafo *g, char vertice){

    if(g->noElement<MAX){
        g->elemento[g->noElement]=vertice;
        g->noElement++;
        return 1;
    }

    return 0;
}

int find_vertice(TGrafo *g, char value){
    int pos=-1;

    for(int i=0;i<g->noElement && pos==-1;i++){
        if(g->elemento[i]==value){
            pos=i;
        }
    }

    return pos;
}

void imprime_grafo(TGrafo *g){

    for(int i=0;i<g->noElement;i++){
        printf("%c ", g->elemento[i]);
    }

    for(int i=0;i<g->noElement;i++){
        printf("%c ", g->elemento[i]);

        for(int j=0;j<g->noElement;j++){
            printf("%d ", g->matriz[i][j]);
        }

        printf("\n");
    }
}

int delete_relation(TGrafo *g, char vertice1, char vertice2){

    int posVertice1=find_vertice(g,vertice1);
    int posVertice2=find_vertice(g,vertice2);

    if(posVertice1!=-1 && posVertice2!=-1){

        g->matriz[posVertice1][posVertice2]=0;
        g->matriz[posVertice2][posVertice1]=0;
        return 1;

    }

    return 0;
}
