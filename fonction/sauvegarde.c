#include "../structure et macros/include.h"

void sauvegarde(city c){

    FILE* sauvegarde = NULL;

    // on crée une sauvegarde en mode ecriture
    sauvegarde = fopen("sauvegarde.txt", "w");

    // on enregistre le numero de la case et son temps d'évolution
    for (int i = 0 ; i < colones; i++){
        for (int j = 0 ; j < ligne; j++){
            fprintf(sauvegarde, "%d\n", c.plateau[i][j].numero);
            fprintf(sauvegarde, "%f\n", c.plateau[i][j].temps);
        }
    }

    // on sauvegarde tous les elements du jeu
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

void lire_sauvegarde(city* c,int * t){

    FILE* sauvegarde = NULL;

    // on accede à la sauvegarde en mode lecture
    sauvegarde = fopen("sauvegarde.txt", "r");
    for (int i = 0 ; i < colones; i++){
        for (int j = 0 ; j < ligne; j++){
            // on lie le numéro de la case et son temps d'évolution
            fscanf(sauvegarde, "%d", &(c->plateau[i][j].numero));
            fscanf(sauvegarde, "%lf", &(c->plateau[i][j].temps));
        }
    }
    // on lie tous les éléments du jeu
    fscanf(sauvegarde, "%d", &(c->joueur1.element_choisie));
    fscanf(sauvegarde, "%d", &(c->etage));
    fscanf(sauvegarde, "%d", &(c->mode));
    fscanf(sauvegarde, "%d", &(c->nb_eau));
    fscanf(sauvegarde, "%d", &(c->nb_electricite));
    fscanf(sauvegarde, "%d", &(c->ece_flouz));
    fscanf(sauvegarde, "%lf", &(c->temps));
    fclose(sauvegarde);
}