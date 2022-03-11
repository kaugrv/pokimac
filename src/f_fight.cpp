// fight //
#include "main.h"


// Génère un numéro de Pokémon sauvage
int pokemonsauvage(int typemap) {
    // Détermine aléatoirement la rareté du Pokémon
    int valeurRarete = rand() % 100 + 1;
    string nomRarete;
    if (valeurRarete <= 60){ // 60% Commun
        nomRarete = "Commun";
    } 
    else if (valeurRarete > 60 && valeurRarete <= 93){ // 33% Peu commun
        nomRarete = "Peu commun";
    } 
    else if (valeurRarete > 93){ // 7% Rare
        nomRarete = "Rare";
    }

    // Établit un tableau des Pokémon éligibles
    int nbEligibles = 0; // nombre de Pokémon éligibles
    int eligibles[152]; // tableau qui va contenir les numéros dans le Pokédex des Pokémon éligibles

    for (int i=0; i<=152; i++){
        if (pokedex(i).rarete == nomRarete && pokedex(i).map==typemap){ // PUIS si la rareté correspond à la rareté voulue + le type de map
            eligibles[nbEligibles] = i; // ALORS on ajoute le numéro du Pokémon au tableau des numéros des Pokémon éligibles
            nbEligibles++;
        }
    }

    // Sélectionne le numéro d'un pokémon au hasard parmi ceux éligibles
    int n = rand() % (nbEligibles) ;

    // Retourne le numéro dans le Pokédex du Pokémon finalement élu
    return eligibles[n];
}

// Affichage nom + la barre de PV
void displayPV(PokImac P) {
    const string default_colour_bash_code="\033[0m";
    string bash_code = "\033[102m";

    cout << P.nom << " : " << P.PV << "/" << P.PVmax << "  ";

    if (P.PV>=7) {
        for(int i=1; i<=P.PV; i++) { // entre 7 et 10
            bash_code = "\033[102m"; //vert clair
            cout << bash_code << " " << default_colour_bash_code;
        }
    }

    if ((P.PV <= 6) && (P.PV>=3)) { // entre 3 et 6
        for(int i=1; i<=P.PV; i++) { 
            bash_code = "\033[103m"; //jaune clair
            cout << bash_code << " " << default_colour_bash_code;
        }
    }

    else if (P.PV < 3){
        for(int i=1; i<=P.PV; i++) { // entre 1 et 2
            bash_code = "\033[101m"; //rouge
            cout << bash_code << " " << default_colour_bash_code;
        }
    }
    cout << endl;
}

// Calcul des dégâts infligés
int calculDegats(PokImac* attaquant, PokImac* defenseur, int modAttaquant, int modDefenseur){
    float attbase = 20;
    float modTotalAttaque = ((attaquant->att)+modAttaquant)/10;
    float modTotalDefense = ((defenseur->def)+modDefenseur)/10;
    if (modTotalDefense <= 1){
        modTotalDefense = 1;
    }
    int attmodifiee = floor(attbase * modTotalAttaque / modTotalDefense /10);
    if (attmodifiee < 1){
        attmodifiee = 1;
    }
    return attmodifiee;
}

// Changement du Pokémon du joueur
void changerPokemon(Dresseur* joueur){
    int n;
    PokImac* copie = (joueur->equipe)[0];

    cout << "Avec quel pokémon voulez-vous échanger " << (joueur->equipe)[0]->nom << " ?" << endl;
    for (int i=1; i<(joueur->nbPok); i++) {
        cout << "◓ " << i+1 << " : " << (joueur->equipe)[i]->nom << endl;
    }

    cin >> n;
    cout << endl;
    (joueur->equipe)[0] = (joueur->equipe)[n-1];
    (joueur->equipe)[n-1] = copie;
}

// Essai pour attraper un Pokémon selon ses PV
bool tryCatch(PokImac* cible){
    int catchValue = rand() % 11; // Nb aléatoire entre 0 et 10
    if (catchValue >= cible->PV){ // SI ce nb est supérieur aux PV du Pokémon
        return true; // alors on peut l'attraper
    } else {
        return false;
    }
}

// Nom de l'attaque n° 1 selon le type
string nomAttaque(PokImac* poke){
    if ((poke->type) == "Eau"){
        return "Pistolet à O";
    } else if ((poke->type) == "Feu"){
        return "Flammèche";
    } else if ((poke->type) == "Plante"){
        return "Fouet Lianes";
    } else if ((poke->type) == "Electrik"){
        return "Éclair";
    } else if ((poke->type) == "Poison"){
        return "Dard-Venin";
    } else if ((poke->type) == "Insecte"){
        return "Taillade";
    } else if ((poke->type) == "Acier"){
        return "Griffe Acier";
    } else if ((poke->type) == "Combat"){
        return "Mawashi Geri";
    } else if ((poke->type) == "Dragon"){
        return "Draco-Griffe";
    } else if ((poke->type) == "Fée"){
        return "Éclat Magique";
    } else if ((poke->type) == "Glace"){
        return "Crocs Givre";
    } else if ((poke->type) == "Psy"){
        return "Choc Mental";
    } else if ((poke->type) == "Roche"){
        return "Jet-Pierres";
    } else if ((poke->type) == "Sol"){
        return "Tunnel";
    } else if ((poke->type) == "Spectre"){
        return "Léchouille";
    } else if ((poke->type) == "Ténèbres"){
        return "Morsure";
    } else if ((poke->type) == "Vol"){
        return "Tornade";
    } else {
        return "Charge";
    }
}
    
// Phase de combat
void ecrancombat(PokImac P, Dresseur* joueur) {
    string suite;

    int modAttaqueJoueur = 0;
    int modDefenseJoueur = 0;
    int modAttaqueSauvage = 0;
    int modDefenseSauvage = 0;

    int choix;
    system("clear");

    // Apparition du Pokémon
    cout << endl << endl; 
    cout << "                    " << P.rep << endl << endl;
    cout << "Un " << P.espece << " sauvage apparaît !" << endl;
    suite = getchar();
    cout << (joueur->equipe)[0]->nom << " ! GO !" << endl;
    suite = getchar();

    bool fighton = true; // true tant que le combat doit continuer
    int tour = 1; // nombres de tours, impair = tour du joueur, pair = tour de l'adversaire
    int attaqueSauvage; // choix d'attaque de l'adversaire


    while (fighton == true){

        if (tour % 2 == 0){ //tour de l'adversaire
            system("clear");

            cout << endl << endl;
            cout << (joueur->equipe)[0]->rep << "                   " << P.rep << endl;

            cout << endl << endl ;

            displayPV(*(joueur->equipe)[0]);
            displayPV(P);

            cout << endl << endl ;

            if (P.espece == "MAGICARPE"){ // SI c'est Magicarpe il n'a que Trempette...

                cout << "Le " << P.espece << " sauvage lance Trempette !" << endl;
                cout << "..." << endl;
                cout << "Rien ne se passe !" << endl;

            } else {

                attaqueSauvage = rand() % 4 + 1;

                if (attaqueSauvage == 1) {

                    cout << "Le " << P.espece << " sauvage lance " << nomAttaque(&P) << " !" << endl;
                    (joueur->equipe)[0]->PV = (joueur->equipe)[0]->PV - calculDegats(&P, (joueur->equipe)[0], modAttaqueSauvage, modDefenseJoueur);
                    cout << (joueur->equipe)[0]->nom << " perd " << calculDegats(&P, (joueur->equipe)[0], modAttaqueSauvage, modDefenseJoueur) << " PV !";

                } else if (attaqueSauvage == 2) {

                    cout << "Le " << P.espece << " sauvage lance Rugissement !" << endl;
                    if (modAttaqueJoueur <= -10){
                        cout << "L'attaque de " << (joueur->equipe)[0]->nom << " n'ira pas plus bas !" << endl;
                    } else {
                        modAttaqueJoueur -= 2;
                        cout << "Oh non ! L'attaque de " << (joueur->equipe)[0]->nom << " diminue ! " << endl;
                    }

                } else if (attaqueSauvage == 3) {

                    cout << "Le " << P.espece << " sauvage lance Mimi-Queue !" << endl;
                    if (modDefenseJoueur <= -10){
                        cout << "La défense de " << (joueur->equipe)[0]->nom << " n'ira pas plus bas !" << endl;
                    } else {
                        modDefenseJoueur -= 2;
                        cout << "Oh non ! La défense de " << (joueur->equipe)[0]->nom << " diminue ! " << endl;
                    }

                } else if (attaqueSauvage == 4) {

                    cout << "Le " << P.espece << " sauvage lance Trempette !" << endl;
                    cout << "..." << endl;
                    cout << "Rien ne se passe !" << endl;

                }

            }

            suite = getchar();

        } else { //tour du joueur

            system("clear");

            cout << endl << endl;
            cout << (joueur->equipe)[0]->rep << "                   " << P.rep << endl;

            cout << endl << endl ;

            displayPV(*(joueur->equipe)[0]);
            displayPV(P);

            cout << endl << endl ;

            cout << "Que voulez-vous faire ?" << endl;
            cout << "1 : ATTAQUER" << endl;
            cout << "2 : LANCER POKEBALL" << endl;
            cout << "3 : CHANGER DE POKEMON" << endl;
            cout << "4 : FUIR" << endl;

            cout << endl << endl ;

            cout << "Votre choix : " ;
            cin >> choix;

            if (choix==1) { // 1 : ATTAQUER

                system("clear");

                cout << endl << endl;
                cout << (joueur->equipe)[0]->rep << "                   " << P.rep << endl;

                cout << endl << endl ;

                displayPV(*(joueur->equipe)[0]);
                displayPV(P);

                cout << endl << endl ;

                if ((joueur->equipe)[0]->espece == "MAGICARPE"){

                    cout << "1 : Trempette " << endl;
                    cout << "2 : Trempette " << endl;
                    cout << "3 : Trempette " << endl;
                    cout << "4 : Trempette " << endl << endl;

                    int choixatt;
                    cout << "Votre choix : " ;
                    cin >> choixatt;
                    cout << endl;

                    suite = getchar();

                    if (choixatt >= 1 && choixatt <= 4) {

                        cout << (joueur->equipe)[0]->nom << " lance Trempette !" << endl;
                        cout << "..." << endl;
                        cout << "Rien ne se passe !" << endl;
                        
                    }

                } else {

                    cout << "1 : " << nomAttaque((joueur->equipe)[0]) << endl;
                    cout << "2 : Rugissement " << endl;
                    cout << "3 : Mimi-Queue" << endl;
                    cout << "4 : Trempette " << endl << endl;

                    int choixatt;
                    cout << "Votre choix : " ;
                    cin >> choixatt;
                    cout << endl;

                    suite = getchar();

                    if (choixatt == 1) {

                        P.PV = P.PV - calculDegats((joueur->equipe)[0], &P, modAttaqueJoueur, modDefenseSauvage);
                        cout << (joueur->equipe)[0]->nom << " lance " << nomAttaque((joueur->equipe)[0]) << " !" << endl;
                        cout << "Le " << P.nom << " sauvage perd " << calculDegats((joueur->equipe)[0], &P, modAttaqueJoueur, modDefenseSauvage) <<" PV !" << endl;

                    } else if (choixatt == 2) {

                        cout << (joueur->equipe)[0]->nom << " lance Rugissement !" << endl;
                        if (modAttaqueSauvage <= -10){
                            cout << "L'attaque du " << P.nom << " sauvage n'ira pas plus bas ! " << endl;
                        } else {
                            modAttaqueSauvage -= 2;
                            cout << "L'attaque du " << P.nom << " sauvage diminue ! " << endl;
                        }

                    } else if (choixatt == 3) {

                        cout << (joueur->equipe)[0]->nom << " lance Mimi-Queue !" << endl;
                        if (modDefenseSauvage <= -10){
                            cout << "La défense du " << P.nom << " sauvage n'ira pas plus bas ! " << endl;
                        } else {
                            modDefenseSauvage -= 2;
                            cout << "La défense du " << P.nom << " sauvage diminue ! " << endl;
                        }

                    } else if (choixatt == 4) {

                        cout << (joueur->equipe)[0]->nom << " lance Trempette !" << endl;
                        cout << "..." << endl;
                        cout << "Rien ne se passe !" << endl;

                    }

                }

                suite = getchar();

            }

            if (choix==2) { // 2 : LANCER UNE POKEBALL

                system("clear");

                cout << endl << endl;
                cout << (joueur->equipe)[0]->rep << "                   " ;
                clignotant("◓");
                cout << endl;
                cout << endl << endl ;
                displayPV(*(joueur->equipe)[0]);
                displayPV(P);
                cout << endl << endl ;

                suite = getchar();

                if ((joueur->nbPokeballs) >= 1){
                    cout << joueur->nom << " lance une POKEBALL !" << endl;
                    (joueur->nbPokeballs) -= 1;

                    suite = getchar();

                    bool essaiBall = tryCatch(&P);

                    if (essaiBall == true){

                        cout << P.nom << " est attrapé !" << endl;
                        string conf="O";
                        cout << "Voulez-vous lui donner un surnom ? O/N " << endl;
                        cin >> conf;
                        string surnom;
                        if (conf == "O" || conf == "o") {
                            cout <<"Surnom de " << P.nom << " : ";
                            cin >> surnom;
                            P.nom=surnom;
                            cout << endl;
                        }
                        PokImac* Pattrap = new PokImac;
                        *Pattrap = P;
                        (joueur->equipe[joueur->nbPok]) = Pattrap;
                        joueur->nbPok = joueur->nbPok +1;

                        fighton = false;

                    } else if (essaiBall == false){

                        cout << "Mince ! Le " << P.nom << " sauvage s'est échappé !" << endl;

                    }



                } else {

                    cout << "Oh non ! Le sac ne contient aucune POKEBALL !" << endl;
                    tour--;

                }

                suite = getchar();

            }

            if (choix==3){ // 3 : CHANGER DE POKEMON

                system("clear");
                cout << endl << endl;
                cout << (joueur->equipe)[0]->rep << "                   " << P.rep << endl;
                cout << endl << endl ;
                displayPV(*(joueur->equipe)[0]);
                displayPV(P);
                cout << endl << endl ;

                suite = getchar();

                if (joueur->nbPok <= 1){
                    cout << "Aucun autre pokémon disponible !" << endl;
                    tour--;
                } else {
                    changerPokemon(joueur);
                    cout << (joueur->equipe)[0]->nom << " ! GO !" << endl;
                    modAttaqueJoueur = 0;
                    modDefenseJoueur = 0;
                    suite=getchar();
                }

                suite = getchar();

            }

            if (choix==4){ // 4 : FUIR
                system("clear");
                cout << endl << endl;
                cout << (joueur->equipe)[0]->rep << "                   " << P.rep << endl;
                cout << endl << endl ;
                displayPV(*(joueur->equipe)[0]);
                displayPV(P);
                cout << endl << endl ;

                suite = getchar();

                cout << "Vous prenez la fuite !" << endl;
                fighton = false;
                suite = getchar();
            }

        }

        if (P.PV <= 0){ // Si le Pokémon sauvage est K.O
            P.PV = 0;
            cout << "Le " << P.nom << " sauvage est K.O !" << endl;
            suite = getchar();
            fighton = false;
        }

        if ((joueur->equipe)[0]->PV <= 0){ // Si le Pokémon du joueur est K.O

            modAttaqueJoueur = 0;
            modDefenseJoueur = 0;

            (joueur->equipe)[0]->PV = 0;

            system("clear");
            cout << endl << endl;
            cout << (joueur->equipe)[0]->rep << "                   " << P.rep << endl;
            cout << endl << endl ;
            displayPV(*(joueur->equipe)[0]);
            displayPV(P);
            cout << endl << endl ;

            if ((joueur->nbPok) < 2){
                system("clear");
                cout << endl << endl;
                cout << (joueur->equipe)[0]->rep << "                   " << P.rep << endl;
                cout << endl << endl ;
                displayPV(*(joueur->equipe)[0]);
                displayPV(P);
                cout << endl << endl ;

                suite = getchar();

                cout << "Vous prenez la fuite !" << endl;
                fighton = false;
                suite = getchar();
                
            } else {

                cout << (joueur->equipe)[0]->nom << " est K.O !" << endl;
                cout << "Que voulez-vous faire ?" << endl;
                cout << "1 : CHANGER DE POKEMON" << endl;
                cout << "2 : FUIR" << endl;
                cout << endl << endl ;

                cout << "Votre choix : " ;
                cin >> choix;

                if (choix==1){

                    system("clear");
                    cout << endl << endl;
                    cout << (joueur->equipe)[0]->rep << "                   " << P.rep << endl;
                    cout << endl << endl ;
                    displayPV(*(joueur->equipe)[0]);
                    displayPV(P);
                    cout << endl << endl;

                    suite = getchar();

                    changerPokemon(joueur);
                    cout << (joueur->equipe)[0]->nom << " ! GO !" << endl;

                    suite = getchar();
                    suite = getchar();
                }

                if (choix==2){

                    system("clear");
                    cout << endl << endl;
                    cout << (joueur->equipe)[0]->rep << "                   " << P.rep << endl;
                    cout << endl << endl ;
                    displayPV(*(joueur->equipe)[0]);
                    displayPV(P);
                    cout << endl << endl ;

                    suite = getchar();

                    cout << "Vous prenez la fuite !" << endl;
                    fighton = false;
                    suite = getchar();

                }
            }


        }

        tour++;

    };

}

