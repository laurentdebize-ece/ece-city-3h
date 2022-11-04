//
// Created by leque on 03/11/2022.
//

#include "chargement.h"
element chargement_element(char *nomFichier){
    FILE *ifs = fopen(nomFichier, "r");
    if (!ifs) {
        printf("Erreur de lecture fichier\n");
        exit(-1);
    }
  /*  char chemin[255]={NULL};
    char caractere;
    int i =0;
    while(caractere!= '\n'){
        fscanf(ifs, "%c", &caractere);
        chemin[i] = caractere;
        i++;
    }*/
    element e;
   // e.texture = LoadTexture(chemin);
    int nb_hab,x,y,prix;
    fscanf(ifs, "%d", &prix);
    fscanf(ifs, "%d", &nb_hab);
    fscanf(ifs, "%d", &x);
    fscanf(ifs, "%d", &y);

    e.nb_habitants = nb_hab;
    e.espacement_x = x;
    e.espacement_y = y;
    e.prix = prix;
    return e;
}
city chargement_total_element(){
    city c;

    ///////////////////////pas element/////////////////////////////
    c.tableau_element[0]=chargement_element("../FILE/element/rien");


    ///////////////////////route/////////////////////////////
    c.tableau_element[1]=chargement_element("../FILE/element/route");
    c.tableau_element[1].texture = LoadTexture("../image/route.png");

    ///////////////////////terrain vague/////////////////////////////
    c.tableau_element[2]=chargement_element("../FILE/element/terrain vague");
    c.tableau_element[2].texture = LoadTexture("../image/terrain_vague.png");

    ///////////////////////ruine/////////////////////////////
    c.tableau_element[3]=chargement_element("../FILE/element/ruine");
    c.tableau_element[3].texture = LoadTexture("../image/ruin.png");

    ///////////////////////cabane-en-bois/////////////////////////////
    c.tableau_element[4]=chargement_element("../FILE/element/cabane");
    c.tableau_element[4].texture = LoadTexture("../image/cabane-en-bois.png");

    ///////////////////////maison/////////////////////////////
    c.tableau_element[5]=chargement_element("../FILE/element/maison");
    c.tableau_element[5].texture = LoadTexture("../image/maison.png");

    ///////////////////////immeuble/////////////////////////////
    c.tableau_element[6]=chargement_element("../FILE/element/immeuble");
    c.tableau_element[6].texture = LoadTexture("../image/immeuble-de-bureaux.png");

    ///////////////////////gratte-ciel/////////////////////////////
    c.tableau_element[7]=chargement_element("../FILE/element/gratte-ciel");
    c.tableau_element[7].texture = LoadTexture("../image/gratte-ciel.png");

    ///////////////////////centrale-electrique/////////////////////////////
    c.tableau_element[8]=chargement_element("../FILE/element/centrale");
    c.tableau_element[8].texture = LoadTexture("../image/centrale-electrique.png");

     ///////////////////////chateau d'eau/////////////////////////////
    c.tableau_element[9]=chargement_element("../FILE/element/chateau d'eau");
    c.tableau_element[9].texture = LoadTexture("../image/chateau-deau.png");

    return  c;
}
city chargement_base(city c){
    FILE *ifs = fopen("../FILE/element principaux", "r");
    if (!ifs) {
        printf("Erreur de lecture fichier\n");
        exit(-1);
    }
    int flouz , etage ,hab, elect, eau;
    fscanf(ifs, "%d", &flouz);
    fscanf(ifs, "%d", &etage);
    fscanf(ifs, "%d", &hab);
    fscanf(ifs, "%d", &elect);
    fscanf(ifs, "%d", &eau);
    c.ece_flouz = flouz;
    c.etage = etage;
    c.nb_habitant = hab;
    c.nb_electricite = elect;
    c.nb_eau = eau;
    return c;
}
city initialisation(){
    city c;
    c = chargement_total_element();
    for (int i = 0; i < colones; i++) {
        for (int j = 0; j < ligne; j++) {
            c.plateau[i][j] = 0;
        }
    }
    c.joueur1.element_choisie = NULL;
    c = chargement_base(c);
    return c;
}
