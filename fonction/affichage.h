#ifndef ECE_CITY_3H_AFFICHAGE_H
#define ECE_CITY_3H_AFFICHAGE_H
#include "../structure et macros/STRUCTURE.h"

void affichage3d(city c, Camera3D camera, city *c_adresse,Color couleur,Color couleur1,Color capacite);
void poser_element(city* c,Camera3D camera,city* c_adresse);
void affichage_route(city c, int i, int j, int i2, int j2,Color couleur1);
void afficherToolBoxe3d(city c,Camera3D camera, city *c_adresse);
void affichageNiveauMoinsUn(city c,int i,int j,int i2,int j2,Color couleur);
void achat(city* c);
void NiveauZeroUnDeux();
void afficherCapaciteCE(chateauEau** listeChateauEau,Color capacite);
static void DrawTextCodepoint3D(Font font, int codepoint, Vector3 position, float fontSize, bool backface, Color tint);
static Vector3 MeasureText3D(Font font, const char* text, float fontSize, float fontSpacing, float lineSpacing);
static void DrawText3D(Font font, const char *text, Vector3 position, float fontSize, float fontSpacing, float lineSpacing, bool backface, Color tint);


#endif //ECE_CITY_3H_AFFICHAGE_H
