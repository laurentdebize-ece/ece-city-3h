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
    int nb_habitants;// 0 si pas habitant
    int prix;// -1 si pas achetable
    int espacement_x;
    int espacement_y;
}element;

typedef struct joueur {
    int element_choisie;
}joueur;


typedef struct ece_city{///ajouter compteur temps
    c_element plateau[colones][ligne];//45 colonnes sur 35 lignes
    element tableau_element[nombreElement];
    Texture2D tableau_texture[nombreTexture];
    joueur joueur1;
    int etage;
    int ece_flouz;
    int nb_habitant;
    int nb_electricite;
    int nb_eau;
}city;
#endif //ECE_CITY_3H_STRUCTURE_H
