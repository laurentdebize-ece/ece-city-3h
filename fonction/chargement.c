#include "../structure et macros/include.h"
#include "raymath.h"

element chargement_element(char *nomFichier){
    FILE *ifs = fopen(nomFichier, "r");
    if (!ifs) {
        printf("Erreur de lecture fichier\n");
        exit(-1);
    }
    /*  char chemin[255]={NULL};
      char caractere;
      int i =0;
      while(caractere!= '\n'){
          fscanf(ifs, "%c", &caractere);
          chemin[i] = caractere;
          i++;
      }*/
    element e;
    // e.texture = LoadTexture(chemin);
    int nb_hab,x,y,prix;float d_x,d_y,d_z,scale;
    fscanf(ifs, "%d", &prix);
    fscanf(ifs, "%d", &nb_hab);
    fscanf(ifs, "%d", &x);
    fscanf(ifs, "%d", &y);
    fscanf(ifs, "%f", &d_x);
    fscanf(ifs, "%f", &d_y);
    fscanf(ifs, "%f", &d_z);
    fscanf(ifs, "%f", &scale);
    e.nb_habitants = nb_hab;
    e.espacement_x = x;
    e.espacement_y = y;
    e.prix = prix;
    e.decalage_x = d_x;
    e.decalage_y = d_y;
    e.decalage_z = d_z;
    e.scale = scale;
    return e;
}

city chargement_total_element(){
    city c;
    int x=0;
    int y=0;
    x=GetMouseX();
    y=GetMouseY();

    ///////////////////////pas element/////////////////////////////
    c.tableau_element[0]=chargement_element("../FILE/element/rien");
    c.tableau_element[0].texture = LoadTexture("../image/herbe.png");
    c.tableau_element[0].model = LoadModel("../model3d/herbe.glb");


    ///////////////////////route/////////////////////////////
    c.tableau_element[1]=chargement_element("../FILE/element/route");
    c.tableau_element[1].texture = LoadTexture("../image/route.png");
    c.tableau_element[1].model = LoadModel("../model3d/route.glb");
    c.model_route[0] = LoadModel("../model3d/route4.glb");
    c.model_route[1] = LoadModel("../model3d/route2.glb");



    ///////////////////////ruine/////////////////////////////
    c.tableau_element[2] = chargement_element("../FILE/element/ruine");
    c.tableau_element[2].texture = LoadTexture("../image/ruin.png");
    c.tableau_element[2].model = LoadModel("../model3d/ruined.glb");
    c.tableau_element[2].model.transform = MatrixRotateX(PI/2);

    ///////////////////////terrain vague/////////////////////////////
    c.tableau_element[3]=chargement_element("../FILE/element/terrain vague");
    c.tableau_element[3].texture = LoadTexture("../image/terrain_vague.png");
    c.tableau_element[3].model = LoadModel("../model3d/construction_site.glb");
    c.tableau_element[3].model.transform = MatrixMultiply(MatrixScale(1, 1, 2), MatrixRotateX(PI/2));



    ///////////////////////cabane-en-bois/////////////////////////////
    c.tableau_element[4]=chargement_element("../FILE/element/cabane");
    c.tableau_element[4].texture = LoadTexture("../image/cabane-en-bois.png");
    c.tableau_element[4].model = LoadModel("../model3d/WoodHouse.glb");
    c.tableau_element[4].model.transform = MatrixScale(2, 1, 3);

    ///////////////////////maison/////////////////////////////
    c.tableau_element[5]=chargement_element("../FILE/element/maison");
    c.tableau_element[5].texture = LoadTexture("../image/maison.png");
    c.tableau_element[5].model = LoadModel("../model3d/maison.glb");

    ///////////////////////immeuble/////////////////////////////
    c.tableau_element[6] = chargement_element("../FILE/element/immeuble");
    c.tableau_element[6].texture = LoadTexture("../image/immeuble-de-bureaux.png");
    c.tableau_element[6].model = LoadModel("../model3d/immeuble.glb");

    ///////////////////////gratte-ciel/////////////////////////////
    c.tableau_element[7] = chargement_element("../FILE/element/gratte-ciel");
    c.tableau_element[7].texture = LoadTexture("../image/gratte-ciel.png");
    c.tableau_element[7].model = LoadModel("../model3d/gratte_ciel.glb");

    ///////////////////////centrale-electrique/////////////////////////////
    c.tableau_element[8]=chargement_element("../FILE/element/centrale");
    c.tableau_element[8].texture = LoadTexture("../image/centrale-electrique.png");
    c.tableau_element[8].model = LoadModel("../model3d/centrale.glb");

    ///////////////////////chateau d'eau/////////////////////////////
    c.tableau_element[9]=chargement_element("../FILE/element/chateau d'eau");
    c.tableau_element[9].texture = LoadTexture("../image/chateau-deau.png");
    c.tableau_element[9].model = LoadModel("../model3d/chateau-deau.glb");
    c.tableau_element[9].model.transform = MatrixRotateX(PI/2);

    //////////////////////eau///////////////////////////////
    //c.tableau_element[10]=
    //c.tableau_element[10].texture= DrawRectangleLines(x,y,15,15,BLUE);

    ////////////////////elec////////////////////////////////
    //c.tableau_element[10]=
    //c.tableau_element[11].texture= DrawRectangleLines(x,y,15,15,YELLOW);

    return  c;
}

city chargement_base(city c){
    FILE *ifs = fopen("../FILE/element principaux", "r");
    if (!ifs) {
        printf("Erreur de lecture fichier\n");
        exit(-1);
    }
    int flouz , etage ,hab, elect, eau;
    fscanf(ifs, "%d", &flouz);
    fscanf(ifs, "%d", &etage);
    fscanf(ifs, "%d", &hab);
    fscanf(ifs, "%d", &elect);
    fscanf(ifs, "%d", &eau);
    c.ece_flouz = flouz;
    c.etage = etage;
    c.nb_habitant = hab;
    c.nb_electricite = elect;
    c.nb_eau = eau;
    return c;
}

city initialisation(){
    city c;
    c = chargement_total_element();
    for (int i = 0; i <colones; i++) {
        for (int j = 0; j < ligne; j++) {
            c.plateau[i][j].numero = 0;
            c.plateau[i][j].temps = 0;
            c.plateau[i][j].passage_eau = 0;
        }
    }
    c.joueur1.element_choisie = 0;
    c = chargement_base(c);

    c.tableau_texture[0] = LoadTexture("../image/horloge.png");
    c.tableau_texture[1] = LoadTexture("../image/monnaie.png");
    c.tableau_texture[2] = LoadTexture("../image/habitant.png");
    c.tableau_texture[3] = LoadTexture("../image/electriciter.png");
    c.tableau_texture[4] = LoadTexture("../image/eau.png");
    c.tableau_texture[5] = LoadTexture("../image/+.png");
    c.tableau_texture[6] = LoadTexture("../image/poubelle fermer.png");
    c.tableau_texture[7] = LoadTexture("../image/poubelle ouvert.png");
    for (int i =0;i< 10 ;i++){
        c.v[i].model = LoadModel("../model3d/voiture.glb");
    }
    c.temps = GetTime();


    return c;
}