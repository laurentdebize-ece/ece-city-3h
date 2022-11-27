#ifndef ECE_CITY_3H_STRUCTURE_H
#define ECE_CITY_3H_STRUCTURE_H
#include "raylib.h"
#include "macros.h"

/////////////////////    BFS    /////////////////////////////////

typedef int typage;
typedef struct _cellule* Cellule;
typedef struct _file* File;



struct _cellule {
    typage element;
    struct _cellule *suivant;
};

struct _file {
    int longueur;
    Cellule tete;
    Cellule queue;
};

/* Structure d'un arc*/
struct Arc
{
    int sommet; // numero de sommet d'un arc adjacent au sommet initial
    int valeur;
    struct Arc* arc_suivant;
};

/* Alias de pointeur sur un Arc */
typedef struct Arc* pArc;

/* Structure d'un sommet*/
struct Sommet
{
    struct Arc* arc;
    int valeur;
    int x;
    int y;

    char couleur;
    int pred;
};

/* Alias de pointeur sur un Sommet */
typedef struct Sommet* pSommet;

/* Alias d'un Graphe */
typedef struct Graphe
{
    int taille;
    int orientation;
    int ordre;
    pSommet* pSommet;
} Graphe;


typedef struct maison{
    int distance;
    int numero_ch;
    int nb_habitants;
    int besoin_eau;
    int  position_x;
    int  position_y;
    struct  ChateauEau * chateauEau_principal;
    struct maison * habitation;
}maison;

typedef struct ChateauEau{
    int capacite;
    int  position_x;
    int  position_y;
    int numero;
    struct maison * habitation;
    struct  ChateauEau * chateauEau;
    struct ChateauEau* next;
}chateauEau;

///////////////////////////////////////////////
typedef struct case_element {
    int numero;//numero negatif si l'element n'est pas afficher ici mais touche comme meme cette case exemple maison: -5
    int reference_x;
    int reference_y;
    int marquage;
    int distance_eau;
    int passage_eau;
    int passage_elect;
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
    chateauEau * chateauEau;
    double temps;
    int etage;//tool boxe =1
    int ece_flouz;
    int nb_habitant;
    int nb_electricite;
    int nb_eau;
    bool mode;
}city;







#endif //ECE_CITY_3H_STRUCTURE_H
