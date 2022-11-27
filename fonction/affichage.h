//
// Created by leque on 04/11/2022.
//

#ifndef ECE_CITY_3H_AFFICHAGE_H
#define ECE_CITY_3H_AFFICHAGE_H
#include "../structure et macros/STRUCTURE.h"
void affichage(city c, int x, int y, Color couleurMaison);
void affichage3d(city c,Camera3D camera,city* c_adresse,Color couleur,Color couleur1,Color capacite);
void poser_element(city* c,Camera3D camera,city* c_adresse);
void affichage_route(city c, int i, int j, int i2, int j2,Color couleur1);
void afficherToolBoxe3d(city c,Camera3D camera, city *c_adresse);
void affichageNiveauMoinsUn(city c,int i,int j,int i2,int j2,Color couleur);
void affichageNiveauMoinsUn1(city c,int i,int j,int i2,int j2,Color couleur);

void afficherToolBoxe(city c,Color Toolboxes,Color couleurMaison1);

void aggrandirRectangle( int x, int y,Color Toolboxes);

void achat(city* c);

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
void cliqueMenuGeneral(city* c,int x,int y,int a, Color *Toolboxes, Color *couleurMaison1, Color *couleurMaison, Color* rond,Color* rond1,Color* rond2,Color* rond3,Color noir, Color blanc);





void NiveauZeroUnDeux();


void afficherCapaciteCE(chateauEau** listeChateauEau,Color capacite);


static void DrawTextCodepoint3D(Font font, int codepoint, Vector3 position, float fontSize, bool backface, Color tint);
static Vector3 MeasureText3D(Font font, const char* text, float fontSize, float fontSpacing, float lineSpacing);
static void DrawText3D(Font font, const char *text, Vector3 position, float fontSize, float fontSpacing, float lineSpacing, bool backface, Color tint);


#endif //ECE_CITY_3H_AFFICHAGE_H
