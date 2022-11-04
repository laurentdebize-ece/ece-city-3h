//
// Created by zelie on 25/10/2022.
//

#include "chargement.h"

element chargement_element(char *nomFichier){
    FILE *ifs = fopen(nomFichier, "r");
    if (!ifs) {
        printf("Erreur de lecture fichier\n");
        exit(-1);
    }
    char chemin[250]={0};
    char caractere = 0 ;
    int i =0;
    while(caractere != '\n'){
        fscanf(ifs, "%c", &caractere);
        chemin[i] = caractere;
        i++;
    }
    int nb_hab,x,y;
    fscanf(ifs, "%d", &nb_hab);
    fscanf(ifs, "%d", &x);
    fscanf(ifs, "%d", &y);
    element teste;
    return teste;
}