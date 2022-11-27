//
// Created by leque on 23/11/2022.
//

#ifndef ECE_CITY_3H_BFS_H
#define ECE_CITY_3H_BFS_H


void bfs(Graphe *g, File f, int c, int num_depart);
void creer_graphe(city c, city* c_adresse);
pSommet *CreerArete(pSommet *sommet, int s1, int s2);
File fileVide();
int longueur(File F);
void enfiler(File F, typage element);
typage defiler(File F);
void parcoursBFS(Graphe* graphe, int s0,city c , chateauEau* ch,city *c_adresse );
void calcul_nombre_chateau(chateauEau* ce , city c);
void distributionEau(chateauEau* listeCheateauEau,city* c );
void distributionElectricite(city *c);
void chemin_eau(city* c ,int preds[1000],int s0, Graphe * g );
#endif //ECE_CITY_3H_BFS_H
