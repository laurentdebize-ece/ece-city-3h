#ifndef ECE_CITY_3H_STRUCTURE_H
#define ECE_CITY_3H_STRUCTURE_H
#include "raylib.h"
#include "macros.h"
typedef struct case_element {
    int numero;//numero negatif si l'element n'est pas afficher ici mais touche comme meme cette case exemple maison: -5
    double temps;
}c_element;
typedef struct element{
    Texture2D texture;///remplacer par image plus tard

    Model model;
    float decalage_x;
    float decalage_y;
    float decalage_z;
    float scale;

    int nb_habitants;// 0 si pas habitant
    int prix;// -1 si pas achetable
    int espacement_x;
    int espacement_y;
}element;

typedef struct joueur {
    int element_choisie;
}joueur;

typedef struct voiture {
    int x;
    int y;
    Model model;
}voiture;
typedef struct ece_city{///ajouter compteur temps
    c_element plateau[colones][ligne];//45 colonnes sur 35 lignes
    element tableau_element[nombreElement];
    Texture2D tableau_texture[nombreTexture];
    Model model_route[3];
    voiture v[10];
    joueur joueur1;
    int etage;//tool boxe =1
    int ece_flouz;
    int nb_habitant;
    int nb_electricite;
    int nb_eau;
    bool mode;
}city;
#endif //ECE_CITY_3H_STRUCTURE_H
