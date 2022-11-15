//
// Created by leque on 01/11/2022.
//

#ifndef ECE_CITY_3H_STRUCTURE_H
#define ECE_CITY_3H_STRUCTURE_H
#include "raylib.h"
struct element{
    Color color;///remplacer par image plus tard
    int nb_habitants;// 0 si pas habitant
    int prix;// -1 si pas achetable
    int espacement_x;
    int espacement_y;
}element;

struct joueur {
    int element_choisie;
}joueur;
struct ece_city{///ajouter compteur temps
    int plateau[colones][ligne];//45 colonnes sur 35 lignes
    struct element tableau_element[10];
    struct joueur joueur1;
    int etage;
    int ece_flouz;
    int nb_habitant;
    int nb_electricite;
    int nb_eau;
    bool mode;
}city;
#endif //ECE_CITY_3H_STRUCTURE_H
