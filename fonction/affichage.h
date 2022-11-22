//
// Created by leque on 04/11/2022.
//

#ifndef ECE_CITY_3H_AFFICHAGE_H
#define ECE_CITY_3H_AFFICHAGE_H
#include "../structure et macros/STRUCTURE.h"
void affichage(city c, int x, int y, Color couleurMaison);
void affichage3d(city c,Camera3D camera,city* c_adresse);
void poser_element(city* c,Camera3D camera,city* c_adresse);
void affichage_route(city c, int i, int j, int i2, int j2);
void afficherToolBoxe3d(city c,Camera3D camera, city *c_adresse);

void afficherToolBoxe(city c,Color Toolboxes,Color couleurMaison1);

void aggrandirRectangle( int x, int y,Color Toolboxes);

void achat(city* c,Color noir, Color blanc);

int clickNiveauDeux(int x, int y);
int clickNiveauUn(int x, int y);
int clickNiveauZero(int x, int y);
int clickNiveauBack(int x,int y);
int clickCaseMaison(int x,int y);
int clickCaseRoute(int x,int y);
int clickCaseElec(int x,int y);
int clickCaseEau(int x,int y);

int clickPlateau(int x,int y);
void afficherSurLaSouris(city c,Color couleurMaison,int x,int y);


void afficherEmplacementMaison(Color rond,Color rond1,Color rond2,Color rond3, int x,int y);
void cliqueMenuGeneral(city* c,int x,int y,int a, Color *Toolboxes, Color *couleurMaison1, Color *couleurMaison, Color* rond,Color* rond1,Color* rond2,Color* rond3);


#endif //ECE_CITY_3H_AFFICHAGE_H
