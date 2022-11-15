//
// Created by leque on 04/11/2022.
//

#ifndef ECE_CITY_3H_AFFICHAGE_H
#define ECE_CITY_3H_AFFICHAGE_H
#include "../structure et macros/STRUCTURE.h"
void affichage(city c);

void afficherToolBoxe(Color Toolboxes);

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


void afficherNiveau1( Color Toolboxes);

void afficherNiveau2(Color Toolboxes);

void afficherNiveau0(Color Toolboxes);
#endif //ECE_CITY_3H_AFFICHAGE_H
