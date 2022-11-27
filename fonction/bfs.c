//
// Created by leque on 23/11/2022.
//

#include "../structure et macros/include.h"

void afficher_successeurs(pSommet *sommet, int num) {

    printf(" sommet %d :\n", num);

    pArc arc = sommet[num]->arc;

    while (arc != NULL) {
        printf("%d ", arc->sommet);
        arc = arc->arc_suivant;
    }

}

void graphe_afficher(Graphe *graphe) {
    printf("graphe\n");

    if (graphe->orientation)
        printf("oriente\n");
    else
        printf("non oriente\n");

    printf("ordre = %d\n", graphe->ordre);

    printf("listes d'adjacence :\n");

    for (int i = 0; i < graphe->ordre; i++) {
        afficher_successeurs(graphe->pSommet, i);
        printf("\n");
    }

}

pSommet *CreerArete(pSommet *sommet, int s1, int s2) {
    if (sommet[s1]->arc == NULL) {
        pArc Newarc = (pArc) malloc(sizeof(struct Arc));
        Newarc->sommet = s2;
        Newarc->arc_suivant = NULL;
        sommet[s1]->arc = Newarc;
        return sommet;
    } else {
        pArc temp = sommet[s1]->arc;
        while (!(temp->arc_suivant == NULL)) {
            temp = temp->arc_suivant;
        }
        pArc Newarc = (pArc) malloc(sizeof(struct Arc));
        Newarc->sommet = s2;
        Newarc->arc_suivant = NULL;

        if (temp->sommet > s2) {
            Newarc->arc_suivant = temp->arc_suivant;
            Newarc->sommet = temp->sommet;
            temp->sommet = s2;
            temp->arc_suivant = Newarc;
            return sommet;
        }

        temp->arc_suivant = Newarc;
        return sommet;
    }
}

void calcul_nombre_chateau(chateauEau *ce, city c) {
    ce->capacite = -1;
    for (int i = 0; i < colones; i++) {
        for (int j = 0; j < ligne; j++) {
            if (c.plateau[i][j].numero == 9) {
                if (ce->capacite == -1) {
                    ce->capacite = EAUMAX;
                    ce->position_x = i;
                    ce->position_y = j;
                    ce->chateauEau = NULL;
                } else {
                    struct ChateauEau *ch = ce;
                    while (ch->chateauEau != NULL) {
                        ch = ch->chateauEau;
                    }
                    ch->chateauEau = (chateauEau *) malloc(sizeof(chateauEau));
                    ch = ch->chateauEau;
                    ch->capacite = EAUMAX;
                    ch->position_x = i;
                    ch->position_y = j;
                    ch->chateauEau = NULL;
                }
            }
        }
    }

}

void creer_graphe(city c, city *c_adresse) {
    Graphe *g = (Graphe *) malloc(sizeof(Graphe));
    g->ordre = 0;
    for (int i = 0; i < colones; i++) {
        for (int j = 0; j < ligne; j++) {
            if (c.plateau[i][j].numero == 1) {
                g->ordre++;
            }
        }
    }
    g->pSommet = (pSommet *) malloc(g->ordre * sizeof(pSommet));
    int nb = 0;
    for (int i = 0; i < colones; i++) {
        for (int j = 0; j < ligne; j++) {
            if (c.plateau[i][j].numero == 1) {
                g->pSommet[nb] = (pSommet) malloc(sizeof(struct Sommet));
                g->pSommet[nb]->arc = NULL;
                g->pSommet[nb]->x = i;
                g->pSommet[nb]->y = j;
                g->pSommet[nb]->valeur = nb;
                nb++;
            }
        }
    }
    for (int i = 0; i < g->ordre; i++) {
        if (c.plateau[g->pSommet[i]->x + 1][g->pSommet[i]->y].numero == 1) {
            for (int j = 0; j < g->ordre; j++) {
                if (g->pSommet[i]->x + 1 == g->pSommet[j]->x && g->pSommet[i]->y == g->pSommet[j]->y) {
                    g->pSommet = CreerArete(g->pSommet, i, j);
                }
            }
        }
        if (c.plateau[g->pSommet[i]->x - 1][g->pSommet[i]->y].numero == 1) {
            for (int j = 0; j < g->ordre; j++) {
                if (g->pSommet[i]->x - 1 == g->pSommet[j]->x && g->pSommet[i]->y == g->pSommet[j]->y) {
                    g->pSommet = CreerArete(g->pSommet, i, j);
                }
            }
        }
        if (c.plateau[g->pSommet[i]->x][g->pSommet[i]->y + 1].numero == 1) {
            for (int j = 0; j < g->ordre; j++) {
                if (g->pSommet[i]->x == g->pSommet[j]->x && g->pSommet[i]->y + 1 == g->pSommet[j]->y) {
                    g->pSommet = CreerArete(g->pSommet, i, j);
                }
            }
        }
        if (c.plateau[g->pSommet[i]->x][g->pSommet[i]->y - 1].numero == 1) {
            for (int j = 0; j < g->ordre; j++) {
                if (g->pSommet[i]->x == g->pSommet[j]->x && g->pSommet[i]->y - 1 == g->pSommet[j]->y) {
                    g->pSommet = CreerArete(g->pSommet, i, j);
                }
            }
        }
    }
    graphe_afficher(g);
    chateauEau *ch = (chateauEau *) malloc(sizeof(chateauEau));
    calcul_nombre_chateau(ch, c);
    if (ch->capacite == -1) {
        ch = NULL;
    }
    struct ChateauEau *ch2 = ch;
    int s0_x, s0_y = -1;
    int s0;
    int nb_ch = 0;
    while (ch2 != NULL) {
        nb_ch++;
        ch2->numero = nb_ch;
        for (int i = 0; i <= c.tableau_element[8].espacement_x - 1; i++) {
            for (int j = 0; j <= c.tableau_element[8].espacement_y - 1; j++) {
                if (c.plateau[ch2->position_x + i][ch2->position_y - 1].numero == 1) {
                    s0_x = ch2->position_x + i;
                    s0_y = ch2->position_y - 1;
                } else if (c.plateau[ch2->position_x + i][ch2->position_y + c.tableau_element[8].espacement_y].numero ==
                           1) {
                    s0_x = ch2->position_x + i;
                    s0_y = ch2->position_y + c.tableau_element[8].espacement_y;
                } else if (c.plateau[ch2->position_x - 1][ch2->position_y + j].numero == 1) {
                    s0_x = ch2->position_x - 1;
                    s0_y = ch2->position_y + j;
                } else if (c.plateau[ch2->position_x + c.tableau_element[8].espacement_x][ch2->position_y + j].numero ==
                           1) {
                    s0_x = ch2->position_x + c.tableau_element[8].espacement_x;
                    s0_y = ch2->position_y + j;
                }
            }
        }
        for (int j = 0; j < g->ordre; j++) {
            if (s0_x == g->pSommet[j]->x && s0_y == g->pSommet[j]->y) {
                s0 = j;
            }
        }
        ch2->habitation = NULL;
        parcoursBFS(g, s0, c, ch2);
        ch2 = ch2->chateauEau;
    }

    c_adresse->chateauEau = ch;
}

File fileVide() {
    File F;
    F = (File) malloc(sizeof(struct _file));
    if (F == NULL) printf("erreur allocation fileVide");
    F->longueur = 0;
    F->tete = F->queue = NULL;
    return (F);
}

int longueur(File F) {
    if (F == NULL)printf("file existe pas - longueur");
    return (F->longueur);
}

void enfiler(File F, typage element) {
    Cellule cellule;
    if (F == NULL) printf("file existe pas - enfiler");

    cellule = (Cellule) malloc(sizeof(struct _cellule));
    if (cellule == NULL) printf("erreur allocation memoire - enfiler");
    cellule->element = element;
    cellule->suivant = NULL;
    if (longueur(F) == 0) {
        F->tete = F->queue = cellule;
    } else {
        F->queue->suivant = cellule;
        F->queue = cellule;
    }
    ++(F->longueur);
}

typage defiler(File F) {
    Cellule cellule;
    typage element;
    if (F == NULL || longueur(F) == 0) printf("File existe pas - defilement");
    cellule = F->tete;
    element = cellule->element;
    if (longueur(F) == 1) {
        F->tete = F->queue = NULL;
    } else {
        F->tete = F->tete->suivant;
    }
    free(cellule);
    --(F->longueur);
    return (element);
}


void parcoursBFS(Graphe *graphe, int s0, city c, chateauEau *ch) {
    int taille = graphe->taille;
    int preds[graphe->ordre];
    int distance[graphe->ordre];
    for (int i = 0; i < graphe->ordre; i++) {
        graphe->pSommet[i]->couleur = 0;
    }
    for (int i = 0; i < graphe->ordre; ++i) {
        preds[i] = -1;
        distance[i] = 0;
    }
    File file = fileVide();
    enfiler(file, s0);
    graphe->pSommet[s0]->couleur = 1;
    distance[s0] = 0;
    for (int i = 0; i < colones; i++) {
        for (int j = 0; j < ligne; j++) {
            if (c.plateau[i][j].numero > 2 && c.plateau[i][j].numero < 8) {
                c.plateau[i][j].marquage = 0;
            }
        }
    }
    while (file->tete != NULL) {
        int num = defiler(file);
        struct Arc *pArc = graphe->pSommet[num]->arc;
        while (pArc != NULL) {
            int num2 = pArc->sommet;
            if (graphe->pSommet[num2]->couleur == 0) {
                enfiler(file, num2);
                graphe->pSommet[num2]->couleur = 1;
                preds[num2] = num;
                distance[num2] = distance[num] + 1;
                if (abs(c.plateau[graphe->pSommet[num2]->x + 1][graphe->pSommet[num2]->y].numero) > 3 &&
                    abs(c.plateau[graphe->pSommet[num2]->x + 1][graphe->pSommet[num2]->y].numero) < 8
                    &&
                    c.plateau[c.plateau[graphe->pSommet[num2]->x + 1][graphe->pSommet[num2]->y].reference_x][c.plateau[
                            graphe->pSommet[num2]->x + 1][graphe->pSommet[num2]->y].reference_y].marquage == 0) {
                    if (ch->habitation == NULL) {
                        ch->habitation = (maison *) malloc(sizeof(maison));
                        ch->habitation->habitation = NULL;
                        ch->habitation->distance = distance[num2];
                        ch->habitation->position_x = c.plateau[graphe->pSommet[num2]->x +
                                                               1][graphe->pSommet[num2]->y].reference_x;
                        ch->habitation->position_y = c.plateau[graphe->pSommet[num2]->x +
                                                               1][graphe->pSommet[num2]->y].reference_y;
                        int nb = abs(c.plateau[graphe->pSommet[num2]->x + 1][graphe->pSommet[num2]->y].numero);
                        ch->habitation->nb_habitants = c.tableau_element[nb].nb_habitants;
                    } else {
                        maison *m = ch->habitation;
                        while (m->habitation != NULL) {
                            m = m->habitation;
                        }
                        m->habitation = (maison *) malloc(sizeof(maison));
                        m = m->habitation;
                        m->habitation = NULL;
                        m->distance = distance[num2];
                        m->position_x = c.plateau[graphe->pSommet[num2]->x + 1][graphe->pSommet[num2]->y].reference_x;
                        m->position_y = c.plateau[graphe->pSommet[num2]->x + 1][graphe->pSommet[num2]->y].reference_y;
                        m->nb_habitants = c.tableau_element[abs(
                                c.plateau[graphe->pSommet[num2]->x + 1][graphe->pSommet[num2]->y].numero)].nb_habitants;
                    }
                    c.plateau[c.plateau[graphe->pSommet[num2]->x + 1][graphe->pSommet[num2]->y].reference_x][
                            c.plateau[graphe->pSommet[num2]->x + 1][graphe->pSommet[num2]->y].reference_y].marquage = 1;

                }
                if (abs(c.plateau[graphe->pSommet[num2]->x - 1][graphe->pSommet[num2]->y].numero) > 2 &&
                    abs(c.plateau[graphe->pSommet[num2]->x - 1][graphe->pSommet[num2]->y].numero) < 8 &&
                    c.plateau[c.plateau[graphe->pSommet[num2]->x - 1][graphe->pSommet[num2]->y].reference_x][c.plateau[
                            graphe->pSommet[num2]->x - 1][graphe->pSommet[num2]->y].reference_y].marquage == 0) {
                    if (ch->habitation == NULL) {
                        ch->habitation = (maison *) malloc(sizeof(maison));
                        ch->habitation->habitation = NULL;
                        ch->habitation->distance = distance[num2];
                        ch->habitation->position_x = c.plateau[graphe->pSommet[num2]->x -
                                                               1][graphe->pSommet[num2]->y].reference_x;
                        ch->habitation->position_y = c.plateau[graphe->pSommet[num2]->x -
                                                               1][graphe->pSommet[num2]->y].reference_y;
                        ch->habitation->nb_habitants = c.tableau_element[abs(
                                c.plateau[graphe->pSommet[num2]->x - 1][graphe->pSommet[num2]->y].numero)].nb_habitants;
                    } else {
                        maison *m = ch->habitation;
                        while (m->habitation != NULL) {
                            m = m->habitation;
                        }
                        m->habitation = (maison *) malloc(sizeof(maison));
                        m = m->habitation;
                        m->habitation = NULL;
                        m->distance = distance[num2];
                        m->position_x = c.plateau[graphe->pSommet[num2]->x - 1][graphe->pSommet[num2]->y].reference_x;
                        m->position_y = c.plateau[graphe->pSommet[num2]->x - 1][graphe->pSommet[num2]->y].reference_y;
                        m->nb_habitants = c.tableau_element[abs(
                                c.plateau[graphe->pSommet[num2]->x - 1][graphe->pSommet[num2]->y].numero)].nb_habitants;
                    }
                    c.plateau[c.plateau[graphe->pSommet[num2]->x - 1][graphe->pSommet[num2]->y].reference_x][
                            c.plateau[graphe->pSommet[num2]->x - 1][graphe->pSommet[num2]->y].reference_y].marquage = 1;
                }
                if (abs(c.plateau[graphe->pSommet[num2]->x][graphe->pSommet[num2]->y + 1].numero) > 2 &&
                    abs(c.plateau[graphe->pSommet[num2]->x][graphe->pSommet[num2]->y + 1].numero) < 8 &&
                    c.plateau[c.plateau[graphe->pSommet[num2]->x][graphe->pSommet[num2]->y + 1].reference_x][c.plateau[
                            graphe->pSommet[num2]->x][graphe->pSommet[num2]->y + 1].reference_y].marquage == 0) {
                    if (ch->habitation == NULL) {
                        ch->habitation = (maison *) malloc(sizeof(maison));
                        ch->habitation->habitation = NULL;
                        ch->habitation->distance = distance[num2];
                        ch->habitation->position_x = c.plateau[graphe->pSommet[num2]->x][graphe->pSommet[num2]->y +
                                                                                         1].reference_x;
                        ch->habitation->position_y = c.plateau[graphe->pSommet[num2]->x][graphe->pSommet[num2]->y +
                                                                                         1].reference_y;
                        ch->habitation->nb_habitants = c.tableau_element[abs(
                                c.plateau[graphe->pSommet[num2]->x][graphe->pSommet[num2]->y + 1].numero)].nb_habitants;
                    } else {
                        maison *m = ch->habitation;
                        while (m->habitation != NULL) {
                            m = m->habitation;
                        }
                        m->habitation = (maison *) malloc(sizeof(maison));
                        m = m->habitation;
                        m->habitation = NULL;
                        m->distance = distance[num2];
                        m->position_x = c.plateau[graphe->pSommet[num2]->x][graphe->pSommet[num2]->y + 1].reference_x;
                        m->position_y = c.plateau[graphe->pSommet[num2]->x][graphe->pSommet[num2]->y + 1].reference_y;
                        m->nb_habitants = c.tableau_element[abs(
                                c.plateau[graphe->pSommet[num2]->x][graphe->pSommet[num2]->y + 1].numero)].nb_habitants;
                    }
                    c.plateau[c.plateau[graphe->pSommet[num2]->x][graphe->pSommet[num2]->y + 1].reference_x][
                            c.plateau[graphe->pSommet[num2]->x][graphe->pSommet[num2]->y + 1].reference_y].marquage = 1;

                }
                if (abs(c.plateau[graphe->pSommet[num2]->x][graphe->pSommet[num2]->y - 1].numero) > 2 &&
                    abs(c.plateau[graphe->pSommet[num2]->x][graphe->pSommet[num2]->y - 1].numero) < 8 &&
                    c.plateau[c.plateau[graphe->pSommet[num2]->x][graphe->pSommet[num2]->y - 1].reference_x][
                            c.plateau[graphe->pSommet[num2]->x][graphe->pSommet[num2]->y - 1].reference_y].marquage ==
                    0) {
                    if (ch->habitation == NULL) {
                        ch->habitation = (maison *) malloc(sizeof(maison));
                        ch->habitation->habitation = NULL;
                        ch->habitation->distance = distance[num2];
                        ch->habitation->position_x = c.plateau[graphe->pSommet[num2]->x][graphe->pSommet[num2]->y -
                                                                                         1].reference_x;
                        ch->habitation->position_y = c.plateau[graphe->pSommet[num2]->x][graphe->pSommet[num2]->y -
                                                                                         1].reference_y;
                        ch->habitation->nb_habitants = c.tableau_element[abs(
                                c.plateau[graphe->pSommet[num2]->x][graphe->pSommet[num2]->y - 1].numero)].nb_habitants;
                    } else {
                        maison *m = ch->habitation;
                        while (m->habitation != NULL) {
                            m = m->habitation;
                        }
                        m->habitation = (maison *) malloc(sizeof(maison));
                        m = m->habitation;
                        m->habitation = NULL;
                        m->distance = distance[num2];
                        m->position_x = c.plateau[graphe->pSommet[num2]->x][graphe->pSommet[num2]->y - 1].reference_x;
                        m->position_y = c.plateau[graphe->pSommet[num2]->x][graphe->pSommet[num2]->y - 1].reference_y;
                        m->nb_habitants = c.tableau_element[abs(
                                c.plateau[graphe->pSommet[num2]->x][graphe->pSommet[num2]->y - 1].numero)].nb_habitants;
                    }
                    c.plateau[c.plateau[graphe->pSommet[num2]->x][graphe->pSommet[num2]->y - 1].reference_x][
                            c.plateau[graphe->pSommet[num2]->x][graphe->pSommet[num2]->y - 1].reference_y].marquage = 1;

                }
            }
            pArc = pArc->arc_suivant;
        }

    }

}

void distributionEau(chateauEau *listeCheateauEau, city *c) {
    for (int i = 0; i < colones; i++) {
        for (int j = 0; j < ligne; j++) {
            c->plateau[i][j].marquage = 0;
        }
    }

    if (listeCheateauEau != NULL) {

        for (chateauEau *pChateau = listeCheateauEau; pChateau != NULL; pChateau = pChateau->chateauEau) {
            struct maison *pMaison = pChateau->habitation;
            for (; pMaison != NULL; pMaison = pMaison->habitation) { // parcours du 1er ChateauEau
                if (pChateau->capacite != 0) {
                    if (c->plateau[pMaison->position_x][pMaison->position_y].marquage == 0) {
                        if (pMaison->nb_habitants <= pChateau->capacite) {
                            /// faut relier la maison au chateau
                            pChateau->capacite -= pMaison->nb_habitants;
                            pMaison->numero_ch = pChateau->numero;
                            c->plateau[pMaison->position_x][pMaison->position_y].marquage = 1;
                            c->plateau[pMaison->position_x][pMaison->position_y].distance_eau = pMaison->distance;
                            pMaison->chateauEau_principal = pChateau;
                        } else if (pMaison->nb_habitants > pChateau->capacite) {
                            /// faut relier la maison au chateau (peut etre relie a plusieurs chateau)
                            pMaison->nb_habitants -= pChateau->capacite;
                            pChateau->capacite = 0;
                        }
                    } else if (c->plateau[pMaison->position_x][pMaison->position_y].marquage == 1 &&
                               pMaison->distance < c->plateau[pMaison->position_x][pMaison->position_y].distance_eau) {
                        if (pMaison->nb_habitants <= pChateau->capacite) {
                            /// faut relier la maison au chateau
                            pChateau->capacite -= pMaison->nb_habitants;
                            pMaison->numero_ch = pChateau->numero;
                            c->plateau[pMaison->position_x][pMaison->position_y].distance_eau = pMaison->distance;
                            chateauEau *chateauEau1 = listeCheateauEau;
                            maison *pMaison2 = (maison *) malloc(sizeof(maison));
                            pMaison2->habitation = chateauEau1->habitation;
                            while ((pMaison->position_x != pMaison2->habitation->position_x ||
                                    pMaison->position_y != pMaison2->habitation->position_y)) {
                                pMaison2 = pMaison2->habitation;
                                if (pMaison2 == NULL) {
                                    chateauEau1 = chateauEau1->chateauEau;
                                    pMaison2->habitation = chateauEau1->habitation;
                                }
                            }
                            if (pMaison2->habitation->habitation == NULL) {
                                pMaison2->habitation = NULL;
                            } else {
                                pMaison2->habitation = pMaison2->habitation->habitation;

                            }

                            chateauEau1->capacite += pMaison->nb_habitants;
                            pMaison->chateauEau_principal = pChateau;
                            pChateau = listeCheateauEau;
                            pMaison = listeCheateauEau->habitation;

                        } else if (pMaison->nb_habitants > pChateau->capacite) {
                            /// faut relier la maison au chateau (peut etre relie a plusieurs chateau)
                            pMaison->nb_habitants -= pChateau->capacite;
                            pChateau->capacite = 0;

                        }

                    } else {
                        chateauEau *chateauEau1 = listeCheateauEau;
                        maison *pMaison2 = (maison *) malloc(sizeof(maison));
                        pMaison2->habitation = chateauEau1->habitation;
                        while ((pMaison->position_x != pMaison2->habitation->position_x ||
                                pMaison->position_y != pMaison2->habitation->position_y)) {
                            pMaison2 = pMaison2->habitation;
                            if (pMaison2->habitation == NULL) {
                                chateauEau1 = chateauEau1->chateauEau;
                                pMaison2->habitation = chateauEau1->habitation;
                            }
                        }
                        if (pMaison2->habitation->habitation == NULL) {
                            pMaison2->habitation = NULL;
                        } else {
                            pMaison2->habitation = pMaison2->habitation->habitation;

                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < colones; i++) {
        for (int j = 0; j < ligne; j++) {
            if (c->plateau[i][j].marquage == 0) {
                if (c->plateau[i][j].numero == 4) {
                    c->plateau[i][j].numero = 2;
                } else if (c->plateau[i][j].numero == 3) {
                    c->plateau[i][j].temps = 0;
                } else if (c->plateau[i][j].numero > 4 && c->plateau[i][j].numero < 8) {
                    c->plateau[i][j].numero--;
                }

            }
            if (c->plateau[i][j].marquage == 1) {
                if (c->plateau[i][j].numero == 3 && c->plateau[i][j].temps == 0) {
                    if (c->nb_electricite > c->nb_habitant ) {
                        c->plateau[i][j].temps = (GetTime() - c->temps) + 15;
                    }
                }

            }
        }
    }
}



void distributionElectricite(city *c) {
    int i2 = 4;
    while (c->nb_electricite < c->nb_habitant) {
        int nb_element = 0;
        for (int i = 0; i < colones; i++) {
            for (int j = 0; j < ligne; j++) {
                if (c->plateau[i][j].numero == i2) {
                    if (i2 != 3) {
                        nb_element++;
                    }
                    if (i2 == 4) {
                        c->plateau[i][j].numero = 2;
                    } else if (i2 == 3) {
                        c->plateau[i][j].temps = 0;
                    } else {

                        c->plateau[i][j].numero--;

                    }
                    c->nb_habitant -= c->tableau_element[i2].nb_habitants;
                }
            }
        }
        if (nb_element == 0) {
            i2++;
        }
    }

}
