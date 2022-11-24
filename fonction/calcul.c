#include "../structure et macros/STRUCTURE.h"
#include "../structure et macros/include.h"


void calcul(city * c){
    c->nb_habitant=0;
    c->nb_electricite=0;
    c->nb_eau=0;

    for (int i = 0; i < colones; i++) {
        for (int j = 0; j < ligne; j++) {
            c->nb_habitant += c->tableau_element[c->plateau[i][j].numero].nb_habitants;
            if(c->plateau[i][j].numero == 8){
                c->nb_electricite += 5000;
            }
            if(c->plateau[i][j].numero == 9){
                c->nb_eau += 5000;
            }

        }
    }
}

File fileVide() {
    File F;
    F = (File)malloc(sizeof(struct _file));
    if (F == NULL) printf("erreur allocation fileVide");
    F->longueur = 0;
    F->tete = F->queue = NULL;
    return(F);
}

int longueur(File F) {
    if (F == NULL)printf("file existe pas - longueur");
    return(F->longueur);
}

void enfiler(File F, typage element) {
    Cellule cellule;
    if (F == NULL) printf ("file existe pas - enfiler");

    cellule = (Cellule)malloc(sizeof(struct _cellule));
    if (cellule == NULL) printf("erreur allocation memoire - enfiler");
    cellule->element = element;
    cellule->suivant = NULL;
    if (longueur(F) == 0){
        F->tete = F->queue = cellule;
    }
    else {
        F->queue->suivant = cellule;
        F->queue = cellule;
    }
    ++(F->longueur);
}

typage defiler(File F) {
    Cellule cellule;
    typage element;
    if (F == NULL || longueur(F) == 0) printf("File existe pas - defilement");
    cellule = F->tete;
    element = cellule->element;
    if (longueur(F) == 1){
        F->tete = F->queue = NULL;
    }
    else{
        F->tete = F->tete->suivant;
    }
    free(cellule);
    --(F->longueur);
    return(element);
}


void parcoursBFS(Graphe* graphe, int s0){
    int taille = graphe->taille;
    int preds[taille];
    for(int i=0;i<graphe->ordre;i++){
        graphe->pSommet[i]->couleur=0;
    }
    for (int i = 0;i <graphe->ordre ;++i) {
        preds[i] = -1;
    }
    File file = fileVide();
    enfiler(file,s0);
    graphe->pSommet[s0]->couleur=1;

    while(file->tete!=NULL){
        int num=defiler(file);
        struct Arc* pArc=graphe->pSommet[num]->arc;
        while(pArc!=NULL){
            int num2=pArc->sommet;
            if(graphe->pSommet[num2]->couleur==0){
                enfiler(file,num2);
                graphe->pSommet[num2]->couleur=1;
                preds[num2]=num;
            }
            pArc=pArc->arc_suivant;
        }
    }
}

Graphe* creerGraphe(int ordre){

}