//
// Created by leque on 03/11/2022.
//

#include "char.h"
element chargement_element(char *nomFichier){
    FILE *ifs = fopen(nomFichier, "r");
    if (!ifs) {
        printf("Erreur de lecture fichier\n");
        exit(-1);
    }
    int nb_hab,x,y,prix;
    fscanf(ifs, "%d", &prix);
    fscanf(ifs, "%d", &nb_hab);
    fscanf(ifs, "%d", &x);
    fscanf(ifs, "%d", &y);
    element e;
    e.nb_habitants = nb_hab;
    e.espacement_x = x;
    e.espacement_y = y;
    e.prix = prix;
    return e;
}
city chargement(){
    city c;
    c.tableau_element[0]=chargement_element("../FILE/element/rien");


    c.tableau_element[1]=chargement_element("../FILE/element/route");
    c.tableau_element[1].texture = LoadTexture("../image/route.png");

    c.tableau_element[2]=chargement_element("../FILE/element/terrain vague");
    c.tableau_element[2].texture = LoadTexture("../image/terrain_vague.png");

    c.tableau_element[3]=chargement_element("../FILE/element/ruine");
    c.tableau_element[3].texture = LoadTexture("../image/ruin.png");

    c.tableau_element[4]=chargement_element("../FILE/element/cabane");
    c.tableau_element[4].texture = LoadTexture("../image/cabane.png");

    c.tableau_element[5]=chargement_element("../FILE/element/maison");
    c.tableau_element[5].texture = LoadTexture("../image/maison.png");

    c.tableau_element[6]=chargement_element("../FILE/element/immeuble");
    c.tableau_element[6].texture = LoadTexture("../image/immeuble.png");

    c.tableau_element[7]=chargement_element("../FILE/element/gratte-ciel");
    c.tableau_element[7].texture = LoadTexture("../image/gratte-ciel.png");

    c.tableau_element[8]=chargement_element("../FILE/element/centrale");
    c.tableau_element[8].texture = LoadTexture("../image/centrale-electrique.png");

    c.tableau_element[9]=chargement_element("../FILE/element/chateau d'eau");
    c.tableau_element[9].texture = LoadTexture("../image/chateau-deau.png");

    for (int i = 0; i < colones; i++) {
        for (int j = 0; j < ligne; j++) {
            c.plateau[i][j] = 0;
        }
    }

    return c;

}