// map //
#include "main.h"

// typemap passé en argument permet d'identifier les différents environnements/bâtiments

// affiche le nom de la Map actuelle en couleur
void mapname(int typemap) {
    const string default_colour_bash_code="\033[0m";
    string bash_code;
    if (typemap==1) { // Route 1
        bash_code = "\033[33m";
        cout << bash_code << " ——————————————— " << default_colour_bash_code << endl;
        cout << bash_code << "| *:･ﾟ✧ ROUTE 1 |" << default_colour_bash_code << endl;
        cout << bash_code << " ——————————————— " << default_colour_bash_code << endl;
    }
    if (typemap==2) { // Plage
        bash_code = "\033[94m";
        cout << bash_code << " —————————————————————— " << default_colour_bash_code << endl;
        cout << bash_code << "| *:･ﾟ✧ CARMIN SUR MER |"<< default_colour_bash_code << endl;
        cout << bash_code << " —————————————————————— " << default_colour_bash_code << endl;
    }

    if (typemap==3) { // Ville
        bash_code = "\033[37m";
        cout << bash_code << " —————————————————— " << default_colour_bash_code << endl;
        cout << bash_code << "| *:･ﾟ✧ CÉLADOPOLE |"<< default_colour_bash_code << endl;
        cout << bash_code << " —————————————————— " << default_colour_bash_code << endl;
    }

    if (typemap==4) { // Centre Pkmn
        bash_code = "\033[95m";
        cout << bash_code << " —————————————————————— " << default_colour_bash_code << endl;
        cout << bash_code << "| *:･ﾟ✧ CENTRE POKEMON |" << default_colour_bash_code << endl;
        cout << bash_code << " —————————————————————— " << default_colour_bash_code << endl;
    }

    if (typemap==5) { // Shop
        bash_code = "\033[94m";
        cout << bash_code << " ———————————————————————— " << default_colour_bash_code << endl;
        cout << bash_code << "| *:･ﾟ✧ BOUTIQUE POKEMON |" << default_colour_bash_code << endl;
        cout << bash_code << " ———————————————————————— " << default_colour_bash_code << endl;
    }

    if (typemap==6) { // Casino
        bash_code = "\033[94m";
        cout << bash_code << " —————————————— " << default_colour_bash_code << endl;
        cout << bash_code << "| *:･ﾟ✧ CASINO |" << default_colour_bash_code << endl;
        cout << bash_code << " —————————————— " << default_colour_bash_code << endl;
    }
}

// affichage en couleur des éléments de la Map
void displaycolor(const char* c, int typemap) {
    const string default_colour_bash_code="\033[0m";
    string bash_code;

    if (typemap==1) { // route 1
        bash_code = "\033[43m"; //fond orange
        if (c=="w") { //haute herbe
            bash_code = "\033[92m\033[43m"; //vert clair + fond orange
        }
        if (c=="Y") { // arbres
            bash_code = "\033[32m\033[43m"; //vert + fond orange
        }
        if (c=="|" or c=="_" or c=="." or c=="P" or c=="K" or c=="M" or c=="N") { // centre PKMN
            bash_code = "\033[105m"; // fond magenta
        }
    }

    if (typemap==2) { // plage
        bash_code = "\033[103m"; //fond jaune clair
        if (c=="~") { //eau.
            bash_code = "\033[104m"; //fond bleu clair
        }
        if (c=="ߐ") { //joueur
            bash_code = "\033[30m\033[103m"; //noir + fond jaune
        }
        if (c=="↑") { //joueur
            bash_code = "\033[30m\033[103m"; //noir + fond jaune
        }
        if (c=="w") { //joueur
            bash_code = "\033[92m\033[103m"; //noir + fond jaune
        }
    }

    if (typemap==3) { // ville
        bash_code = "\033[104m"; //fond bleu (shop/casino)
        if (c==" " or c=="ߐ" or c=="←") { 
            bash_code = "\033[37m\033[100m"; // gris/fond gris
        }
        if (c=="w") { //haute herbe.
            bash_code = "\033[92m\033[100m"; //vert + fond gris
        }
    }

    if (typemap==4) { // centre pkmn
        bash_code = "\033[105m"; //fond magenta
    }

    if (typemap==5) { // shop
        bash_code = "\033[104m"; //fond bleu
    }

    if (typemap==6) { // centre pkmn
        bash_code = "\033[104m"; //fond bleu
    }

    cout << bash_code << c << default_colour_bash_code;
}

// détecte si le joueur est dans hautes herbes + renvoie 1 s'il l'est, 0 sinon.
int dansHT(int posX, int posY, int typemap) {
    if (typemap==1) { // route 1
        if ((posX <=10 && posX>=1) && (posY <=12 && posY>=10)) { //si joueur dans haute herbe
            return 1; 
        }
        if ((posX <=15 && posX>=11) && (posY <=3 && posY>=2)) { //si joueur dans haute herbe
            return 1;
        }
    }

    if (typemap==2) { // plage
        if ((posX <=22 && posX>=18) && (posY <=5 && posY>=3)) { //si joueur dans haute herbe
            return 1; 
        }
    }

    if (typemap==3) { // ville
        if ((posX <=22 && posX>=9) && (posY <=13 && posY>=11)) { //si joueur dans haute herbe
            return 1; 
        }
    }
    return 0;

}

// dessine la map de type typamp, de taille TX, TY + le joueur.
void drawMap(char* map[TX][TY], int posX, int posY, int typemap){
    int x; //colonnes
    int y; //lignes

    if (typemap==1) { // ROUTE 1
        for (y=0;y<TY;y++){
            for (x=0;x<TX;x++){ 
                
                //dessin sol
                map[y][x]=" "; 

                //dessin hautes herbes
                if (x <=10 && x>=1) { 
                    map[10][x]="w";
                    map[11][x]="w";
                    map[12][x]="w";
                }

                if (x <=15 && x>=11) { 
                    
                    map[2][x]="w";
                    map[3][x]="w";
                    
                }

                // dessin arbres
                if (y==0) { 
                    for (int i=0; i<=TX-1; i++) {
                        map[y][i]="Y";
                    }
                }
                if (x==0) { 
                    for (int i=0; i<=TY-1; i++) {
                        map[i][x]="Y";
                    }
                }

                // dessin flèches
                if (y==14) {
                    map[y][1] = "↓" ;
                    map[y][23] = "↓" ;
                }
                if (x==24) {
                    map[1][x] = "→" ;
                    map[13][x] = "→" ;
                }

                //dessin joueur
                if (y==posY && x==posX){ 
                    map[y][x]="ߐ"; 
                }


                //dessin c pkmn
                if (y==1) {
                    map[y][2] = "_";
                    map[y][3] = "_";
                    map[y][4] = "_";
                    map[y][5] = "_";
                    map[y][6] = "_";

                }
                if (y==2) {
                    map[y][1] = "|";
                    map[y][2] = ".";
                    map[y][3] = "P";
                    map[y][4] = "K";
                    map[y][5] = "M";
                    map[y][6] = "N";
                    map[y][7] = "|";

                }
                if (y==3) {
                    map[y][1] = "|";
                    map[y][2] = ".";
                    map[y][3] = ".";
                    map[y][4] = "_";
                    map[y][5] = ".";
                    map[y][6] = ".";
                    map[y][7] = "|";

                }
                if (y==4) {
                    map[y][1] = "|";
                    map[y][2] = "_";
                    map[y][3] = "|";
                    map[y][5] = "|";
                    map[y][6] = "_";
                    map[y][7] = "|";

                }
                
                //dessin final y-ième ligne
                displaycolor(map[y][x], typemap);
            }
            cout << endl;
        }
    }

    if (typemap==2) { // PLAGE
        for (y=0;y<TY;y++){
            for (x=0;x<TX;x++){ 
                map[y][x]=" "; //dessin sable.

                if (x<=TX && x>=0) { //dessin mer.
                    map[10][x]="~";
                    map[11][x]="~";
                    map[12][x]="~";
                    map[13][x]="~";
                    map[14][x]="~";
                }
                if (y==0) {
                    map[y][1] = "↑" ;
                    map[y][23] = "↑" ;
                }

                if (x <=22 && x>=18) { 
                    map[3][x]="w";
                    map[4][x]="w";
                    map[5][x]="w";
                }

                if (y==posY && x==posX){ //si position=joueur
                    map[y][x]="ߐ"; //dessin joueur
                }
                displaycolor(map[y][x], typemap);
            }
        cout << endl;
        }
    }

    if (typemap==3) { // VILLE
        for (y=0;y<TY;y++){
            for (x=0;x<TX;x++){ 
                
                map[y][x]=" "; //dessin sol

                if (x==0) {
                    map[1][x] = "←" ;
                    map[13][x] = "←" ;
                }

                if (x <=22 && x>=9) { 
                    map[11][x]="w";
                    map[12][x]="w";
                    map[13][x]="w";
                }
                

                if (y==posY && x==posX){ //si position=joueur
                    map[y][x]="ߐ"; //dessin joueur
                }

                //dessin casino !! arjan
                if (y==1) {
                    map[y][16] = "_";
                    map[y][17] = "_";
                    map[y][18] = "_";
                    map[y][19] = "_";
                    map[y][20] = "_";
                    map[y][21] = "_";

                }

                if (y==2) {
                    map[y][15] = "|";
                    map[y][16] = "_";
                    map[y][17] = "_";
                    map[y][18] = "_";
                    map[y][19] = "_";
                    map[y][20] = "_";
                    map[y][21] = "_";
                    map[y][22] = "|";
                }


                if (y==3) {
                    map[y][15] = "|";
                    map[y][16] = "C";
                    map[y][17] = "A";
                    map[y][18] = "$";
                    map[y][19] = "I";
                    map[y][20] = "N";
                    map[y][21] = "O";
                    map[y][22] = "|";

                }
                if (y==4) {
                    map[y][15] = "|";
                    map[y][16] = ".";
                    map[y][17] = ".";
                    map[y][18] = "_";
                    map[y][19] = ".";
                    map[y][20] = ".";
                    map[y][21] = ".";
                    map[y][22] = "|";

                }
                if (y==5) {
                    map[y][15] = "|";
                    map[y][16] = "_";
                    map[y][17] = "|";
                    map[y][19] = "|";
                    map[y][20] = "_";
                    map[y][21] = ".";
                    map[y][22] = "|";

                }


                //dessin shop
                if (y==2) {
                    map[y][5] = "_";
                    map[y][6] = "_";
                    map[y][7] = "_";
                    map[y][8] = "_";
                    map[y][9] = "_";

                }
                if (y==3) {
                    map[y][4] = "|";
                    map[y][5] = ".";
                    map[y][6] = "S";
                    map[y][7] = "H";
                    map[y][8] = "O";
                    map[y][9] = "P";
                    map[y][10] = "|";

                }
                if (y==4) {
                    map[y][4] = "|";
                    map[y][5] = ".";
                    map[y][6] = ".";
                    map[y][7] = "_";
                    map[y][8] = ".";
                    map[y][9] = ".";
                    map[y][10] = "|";

                }
                if (y==5) {
                    map[y][4] = "|";
                    map[y][5] = "_";
                    map[y][6] = "|";
                    map[y][8] = "|";
                    map[y][9] = "_";
                    map[y][10] = "|";

                }

                
                
                displaycolor(map[y][x], typemap);
            }
            cout << endl;
        }
    }

    if (typemap==4) { // CENTRE PKMN
         for (y=0;y<5;y++){
            for (x=0;x<7;x++){ 
                map[y][x]=" "; 

                if (y==0) {
                    map[y][3]="ꗑ";
                }

                if (y==4) {
                    map[y][2]="↓";
                    map[y][4]="↓";

                }

                if (y==posY && x==posX){ //si position=joueur
                    map[y][x]="ߐ"; //dessin joueur
                }

                displaycolor(map[y][x], typemap);
            }
        cout << endl;
        }
    }

    if (typemap==5) { // SHOP
         for (y=0;y<3;y++){
            for (x=0;x<7;x++){ 
                map[y][x]=" "; 

                if (y==0) {
                    map[y][0]="ꔍ";
                }

                if (y==2) {
                    map[y][2]="↓";
                    map[y][4]="↓";

                }

                if (y==posY && x==posX){ //si position=joueur
                    map[y][x]="ߐ"; //dessin joueur
                }

                displaycolor(map[y][x], typemap);
            }
        cout << endl;
        }
    } 

    if (typemap==6) { // CASINO
         for (y=0;y<5;y++){
            for (x=0;x<7;x++){ 
                map[y][x]=" "; 

                if (y==4) {
                    map[y][2]="↓";
                    map[y][4]="↓";
                }

                if (y==0) {
                    map[y][0]="ꕡ";
                    map[y][3]="₽";

                }

                

                if (y==posY && x==posX){ //si position=joueur
                    map[y][x]="ߐ"; //dessin joueur
                }

                displaycolor(map[y][x], typemap);
            }
        cout << endl;
        }
    }
}  

// Affichage et déplacements dans Map
void MAP(char* map[TX][TY], int posX, int posY, int typemap, Dresseur joueur) {
    string suite;

    for(int i=0;;i++) {
       
        // efface console
        system("clear"); 
        
        // dessin Map
        drawMap(map, posX, posY, typemap);

        // nom Map
        cout << endl << endl;
        mapname(typemap);
        cout << endl << endl;

        // Rappel commandes
        cout << "Déplacement : Z/S/Q/D puis ENTREE " << endl;
        cout << "Equipe : E puis ENTREE " << endl;
        cout << "Inventaire : I puis ENTREE " << endl;

        // // Vérif : affichage position actuelle A EFFACER
        // cout << endl;
        // cout << "x = " << posX << endl;
        // cout << "y = " << posY << endl;
        

        // Gestion des interactions

        // soin dans centre pokémon
        if (typemap==4 && posX==3 && posY==1) {
            interactionsoin(&joueur);
            posY=2;
        }

        // achats dans boutique
        if (typemap==5 && posX==1 && posY==0) {
            interactionboutique(&joueur);
            posX=2;
        }

        // jeu dans casino
        if (typemap==6 && posX==0 && posY==1) {
            interactioncasino(&joueur, 1);
            posY=2;
        }
        if (typemap==6 && posX==3 && posY==1) {
            interactioncasino(&joueur, 2);
            posY=2;
        }

        // fin Gestion des interactiohs

        string entry;
        entry = getchar(); //récupération touche pressée 
        

        // Gestion des changements de Map

        // route1 -> plage
        if(typemap==1 && posY==TY-1) {
            posY = 1;
            typemap = 2;
        } 
        
        // route1 -> centre pkmn
        if(typemap==1 && posX==4 && posY==4) {
            posX = 3;
            posY = 3;
            typemap = 4;
        } 

        // route1 -> ville
        if(typemap==1 && posX==TX-1) {
            posX = 2;
            typemap = 3;
        } 

        // ville -> route1
        if(typemap==3 && posX==1) {
            posX = TX-2;
            typemap = 1;
        } 

        // plage -> route1
        if(typemap==2 && posY==0) {
            posY = TY-2;
            typemap = 1;
        } 

        // centre pkmn -> route1
        if(typemap==4 && posY==4 && posX==3) {
            posX = 4;
            posY = 5;
            typemap = 1;
        } 

        // ville -> shop
        if(typemap==3 && posX==7 && posY==5) {
            posX = 3;
            posY = 1;
            typemap = 5;
        } 

        // shop -> ville
        if(typemap==5 && posY==2 && posX==3) {
            posX = 7;
            posY = 6;
            typemap = 3;
        } 

        // ville -> casino
        if(typemap==3 && posX==18 && posY==5) {
            posX = 3;
            posY = 3;
            typemap = 6;
        } 

        // casino -> ville
        if(typemap==6 && posY==4 && posX==3) {
            posX = 18;
            posY = 6;
            typemap = 3;
        } 

        // fin Gestion des changements de Map
       

        
        // Gestion déplacement 

        if (typemap==4 or typemap==6) {
            if ((entry=="z" || entry=="Z") && posY>0){
                posY--;
            } 
            else if ((entry=="s" || entry=="S") && posY<4){
                posY++;
            } 
            else if ((entry=="q" || entry=="Q") && posX>0){
                posX--;
            } 
            else if ((entry=="d" || entry=="D") && posX<6){
                posX++;
            }
        }

        else if (typemap==2) {
            if ((entry=="z" || entry=="Z") && posY>0){
                posY--;
            } 
            else if ((entry=="s" || entry=="S") && posY<9){
                posY++;
            } 
            else if ((entry=="q" || entry=="Q") && posX>0){
                posX--;
            } 
            else if ((entry=="d" || entry=="D") && posX<TX-1){
                posX++;
            }
        }

        else if (typemap==1) {
            if ((entry=="z" || entry=="Z") && posY>1){
                posY--;
            } 
            else if ((entry=="s" || entry=="S") && posY<TY){
                posY++;
            } 
            else if ((entry=="q" || entry=="Q") && posX>1){
                posX--;
            } 
            else if ((entry=="d" || entry=="D") && posX<TX-1){
                posX++;
            }
        }

        else if (typemap==5) {
            if ((entry=="z" || entry=="Z") && posY>0){
                posY--;
            } 
            else if ((entry=="s" || entry=="S") && posY<2){
                posY++;
            } 
            else if ((entry=="q" || entry=="Q") && posX>1){
                posX--;
            } 
            else if ((entry=="d" || entry=="D") && posX<6){
                posX++;
            }
        }

        else {
            if ((entry=="z" || entry=="Z") && posY>0){
                posY--;
            } 
            else if ((entry=="s" || entry=="S") && posY<TY-1){
                posY++;
            } 
            else if ((entry=="q" || entry=="Q") && posX>0){
                posX--;
            } 
            else if ((entry=="d" || entry=="D") && posX<TX-1){
                posX++;
            }
        }

        // fin Gestion déplacement

        // Menus
        // Equipe (E)
        if (entry=="e" || entry=="E") {
            string suite;
            system("clear");
            afficheEquipe(&joueur);
            suite=getchar();
        }
        // Inventaire (I)
        if (entry=="i" || entry=="I") {
            string suite;
            system("clear");
            afficheInventaire(&joueur);
            suite=getchar();
        }


        // Lancement combat si dans hautes herbes
        if (dansHT(posX, posY, typemap)==1) {
            int spawn = rand() % 6;
            if (spawn==0) {
                int n = pokemonsauvage(typemap);
                ecrancombat(pokedex(n), &joueur);
            }
            
        }

        if (entry=="L" || entry=="l") {
            if (typemap==1){ ecrancombat(pokedex(146), &joueur); } //Sulfura, route1
            if (typemap==2){ ecrancombat(pokedex(144), &joueur); } //Artikodin, plage
            if (typemap==3){ ecrancombat(pokedex(145), &joueur); } //Electhor, ville
        }


        // Gestion du hors-jeu (si tous les Pokémon de l'équipe sont K.O : téléportation au centre PKMN + soin)
        int nbko=0;
        for (int i=0; i<(joueur.nbPok); i++) {
            if (joueur.equipe[i]->PV==0) {
                nbko++;
            }
        }
        if(nbko==joueur.nbPok) {
            cout << "Vous n'avez plus de Pokémon en forme !" << endl;
            suite = getchar();
            cout << joueur.nom << " est hors-jeu !" << endl;
            nbko=0;
            suite = getchar();
            typemap=4;
            posX=3;
            posY=2;
            for (int i=0; i<(&joueur)->nbPok; i++) {
                ((&joueur)->equipe[i])->PV = ((&joueur)->equipe[i])->PVmax; // remet les PV de toute l'équipe au max
            }
        }

        // fin Gestion du hors-jeu



    }

} 