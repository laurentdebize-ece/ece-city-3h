//
// Created by leque on 23/11/2022.
//

#ifndef ECE_CITY_3H_BFS_H
#define ECE_CITY_3H_BFS_H


void bfs(Graphe *g, File f, int c, int num_depart);
Graphe *creer_graphe(city c);
pSommet *CreerArete(pSommet *sommet, int s1, int s2);
File fileVide();
int longueur(File F);
void enfiler(File F, typage element);
typage defiler(File F);
void parcoursBFS(Graphe* graphe, int s0);
#endif //ECE_CITY_3H_BFS_H
