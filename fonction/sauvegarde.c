//
// Created by leque on 22/11/2022.
//

#include "../structure et macros/include.h"
void sauvegarde(city c){
    FILE* sauvegarde = NULL;

    sauvegarde = fopen("sauvegarde.txt", "w");
    for (int i = 0 ; i < colones; i++){
        for (int j = 0 ; j < ligne; j++){
            fprintf(sauvegarde, "%d\n", c.plateau[i][j].numero);
            fprintf(sauvegarde, "%f\n", c.plateau[i][j].temps);
        }
    }
    fprintf(sauvegarde, "%d\n", c.joueur1.element_choisie);
    fprintf(sauvegarde, "%d\n", c.etage);
    fprintf(sauvegarde, "%d\n", c.mode);
    fprintf(sauvegarde, "%d\n", c.nb_eau);
    fprintf(sauvegarde, "%d\n", c.nb_electricite);
    fprintf(sauvegarde, "%d\n", c.ece_flouz);
    double temps = c.temps - GetTime();
    fprintf(sauvegarde, "%f\n", temps);
    fclose(sauvegarde);
}
void lire_sauvegarde(city* c){
    FILE* sauvegarde = NULL;
    sauvegarde = fopen("sauvegarde.txt", "r");
    for (int i = 0 ; i < colones; i++){
        for (int j = 0 ; j < ligne; j++){
            fscanf(sauvegarde, "%d", &(c->plateau[i][j].numero));
            fscanf(sauvegarde, "%lf", &(c->plateau[i][j].temps));
        }
    }
    fscanf(sauvegarde, "%d", &(c->joueur1.element_choisie));
    fscanf(sauvegarde, "%d", &(c->etage));
    fscanf(sauvegarde, "%d", &(c->mode));
    fscanf(sauvegarde, "%d", &(c->nb_eau));
    fscanf(sauvegarde, "%d", &(c->nb_electricite));
    fscanf(sauvegarde, "%d", &(c->ece_flouz));
    fscanf(sauvegarde, "%lf", &(c->temps));
    fclose(sauvegarde);
}