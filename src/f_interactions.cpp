// interactions //
#include "main.h"

// Centre Pkmn
void interactionsoin(Dresseur *joueur) {
    string bash_code = "\033[95m";
    const string default_colour_bash_code="\033[0m";

    // Dialogue avec l'infirmière Joëlle (<3)
    cout << bash_code << "ꗑ : Bienvenue au centre POKEMON ! ~ ♪ " << default_colour_bash_code << endl;

    string suite;
    suite = getchar();
    
    cout << bash_code << "Voulez-vous que l'on soigne votre équipe ?" << default_colour_bash_code << endl;
    cout << "O/N : ";
    
    string choix="O";
    cin >> choix;

    if (choix=="O" || choix =="o") {

        for (int i=0; i<joueur->nbPok; i++) {
            (joueur->equipe[i])->PV = (joueur->equipe[i])->PVmax; // remet les PV de toute l'équipe au max
        }

        cout << bash_code << "... Votre équipe est maintenant en pleine forme ! " << default_colour_bash_code << endl;
        suite = getchar();
        cout << bash_code << "À très bientôt ! ~ ♪ " << default_colour_bash_code << endl;
        
    }    

    else {
        cout << bash_code << "À très bientôt ! ~ ♪ " << default_colour_bash_code << endl;
        suite = getchar();

    }
    
}

// Shop
void interactionboutique(Dresseur *joueur) {
    string bash_code = "\033[94m";
    const string default_colour_bash_code="\033[0m";

    // Dialogue avec le vendeur
    cout << bash_code << "ꔍ : Bienvenue à la boutique POKEMON ! " << endl;
    cout << "Vous avez " << joueur->argent << "₽." << default_colour_bash_code << endl;

    string suite;
    suite = getchar();
    suite = getchar();

    cout << bash_code << "Que désirez-vous ?" << default_colour_bash_code << endl;
    cout << bash_code << "1 : POKEBALLS (100₽)" << default_colour_bash_code << endl;
    cout << bash_code << "2 : POTIONS (50₽)" << default_colour_bash_code << endl;
    cout << bash_code << "3 : FOSSILE (1000₽)" << default_colour_bash_code << endl;
    cout << bash_code << "4 : Annuler" << default_colour_bash_code << endl;
    cout << "Votre choix (1,2, 3 ou 4) : " ;

    int choix;
    int nb;
    string choixON;

    cin >> choix;
    cout << endl;

    if (choix==1) { // POKEBALLS
        cout << bash_code << "Combien de POKEBALLS ?" << default_colour_bash_code << endl;

        cout << "Votre choix : ";
        cin >> nb;
        cout << endl;

        cout << bash_code << "Cela fera " << 100*nb << "₽." << default_colour_bash_code << endl;
        suite = getchar();

        cout << bash_code << "Cela vous convient ?" << default_colour_bash_code << endl;
        cout << "O/N : ";
        cin >> choixON;
        cout << endl;

        if ((choixON=="O" || choixON=="o") && (nb>0)) {
            if (100*nb <= joueur->argent) { 
                string p=" POKEBALLS ! " ;
                if (nb==1) { // singulier si 1
                    p = " POKEBALL ! ";
                }
                cout << bash_code << joueur->nom << " obtient " << nb << p << default_colour_bash_code << endl;
                joueur->nbPokeballs+=nb;
                joueur->argent-=100*nb;
            }
            else {
                cout << bash_code << "Je suis désolé, vous n'avez pas assez d'argent." << default_colour_bash_code << endl;
            }
        }
        cout << bash_code << "À bientôt !" << default_colour_bash_code << endl;
        suite = getchar();
    }

    if (choix==2) { // POTIONS
        cout << bash_code << "Combien de POTIONS ?" << default_colour_bash_code << endl;

        cout << "Votre choix : ";
        cin >> nb;
        cout << endl;

        cout << bash_code << "Cela fera " << 50*nb << "₽." << default_colour_bash_code << endl;
        suite = getchar();

        cout << bash_code << "Cela vous convient ?" << default_colour_bash_code << endl;
        cout << "O/N : ";
        cin >> choixON;
        cout << endl;

        if ((choixON=="O" || choixON=="o") && (nb>0)) {
            if (50*nb <= joueur->argent) { 
                string p=" POTIONS ! " ;
                if (nb==1) { // singulier si 1
                    p = " POTION ! ";
                }
                cout << bash_code << joueur->nom << " obtient " << nb << p << default_colour_bash_code << endl;
                joueur->nbPokeballs+=nb;
                joueur->argent-=50*nb;
            }
            else {
                cout << bash_code << "Je suis désolé, vous n'avez pas assez d'argent." << default_colour_bash_code << endl;
            }
        }

        cout << bash_code << "À bientôt !" << default_colour_bash_code << endl;
        suite = getchar();
    }
    
    if (choix==3) { //FOSSILE
        cout << bash_code << "Un FOSSILE de POKÉMON ? Cela fera 1000₽." << default_colour_bash_code << endl;
        suite = getchar();

        cout << bash_code << "Êtes-vous sûr ?" << default_colour_bash_code << endl;
        cout << "O/N : ";
        cin >> choixON;
        cout << endl;

        if ((choixON=="O" || choixON=="o")) {
            if (1000 <= joueur->argent) { 
                cout << bash_code << "Oh ... Il prend vie !" << endl;

                int f = rand() % 3;
                PokImac Fossile;
                if (f==0) { Fossile = pokedex(138); } // AMONITA
                if (f==1) { Fossile = pokedex(140); } // KABUTO
                if (f==2) { Fossile = pokedex(142); } // AMONITA

                cout << bash_code << joueur->nom << " obtient un " << Fossile.nom << " ! " <<  default_colour_bash_code << endl;
                joueur->argent-=1000;

                string conf="O";
                cout << "Voulez-vous lui donner un surnom ? O/N " << endl;
                cin >> conf;
                string surnom;
                if (conf == "O" || conf == "o") {
                    cout <<"Surnom de " << Fossile.nom << " : ";
                    cin >> surnom;
                    Fossile.nom=surnom;
                    cout << endl;
                }

                PokImac* Pattrap = new PokImac;
                *Pattrap = Fossile;
                (joueur->equipe[joueur->nbPok]) = Pattrap;
                joueur->nbPok = joueur->nbPok +1;

            }

            else {
                cout << bash_code << "Je suis désolé, vous n'avez pas assez d'argent." << default_colour_bash_code << endl;
            }
        }
        cout << bash_code << "À bientôt !" << default_colour_bash_code << endl;
        suite = getchar();
    }
}


// Mini-jeu Machine à sous 
void machineAsous(Dresseur *joueur) {
    system("clear");

    string suite;
    suite = getchar(); 

    string bash_code = "\033[94m";
    const string default_colour_bash_code="\033[0m";
    
    cout << bash_code << "Appuyez sur M pour tirer la molette " << default_colour_bash_code << endl;
    string entry;
    cin >> entry;
    
    if (entry=="M" || entry=="m") {
       
        int val = rand() %8; // Tirage d'un nombre entre 0 et 7

        if (val==0) {
            cout << "◓ ◓ ◓ " << endl;
            suite = getchar();
            cout << "Bravo ! Vous gagnez 200₽ ! " << endl << endl;
            joueur->argent+=200;  // +200 dans l'inventaire
        }

        if (val!=0 && val !=7) {
            if (val==1) { cout << "7 7 ◓ " << endl;}
            if (val==2) { cout << "◓ 7 ◓ " << endl;}
            if (val==3) { cout << "◓ ◓ 7 " << endl;}
            if (val==4) { cout << "7 ◓ ◓ " << endl;}
            if (val==5) { cout << "◓ 7 7 " << endl;}
            if (val==6) { cout << "7 ◓ 7 " << endl;}
            suite = getchar();
            cout << "Dommage... " << endl << endl;
        }

        if (val==7) {
            cout << "7 7 7 " << endl;
            suite = getchar();
            cout << "!!! JACKPOT !!! Vous gagnez 1000₽ ! " << endl << endl;
            joueur->argent+=1000; // +1000 dans l'inventaire
        }
        
    }

    if (entry=="Motherlode" || entry=="motherlode") { //code de triche
        suite = getchar();
        cout << "......... Vous gagnez 100 000₽ !!" << endl << endl;
        joueur->argent+=100000; // +100 000 dans l'inventaire

    }
}

// Mini-jeu Le Juste Prix
void lejusteprix(Dresseur *joueur) {
    system("clear");
    string suite;
    suite = getchar();

    string choix;

    cout << "Bienvenue dans le Juste ₽rix ! " << endl;
    suite = getchar();
    cout << "Je vais penser à une somme entre 500 et 1000₽. ";
    suite = getchar();
    cout << "Si tu la devines en moins de 10 essais, tu la remportes ! " << endl;
    cout << "Si tu la devines en moins de 5 essais, tu remportes le double !" << endl;
    suite = getchar();
    cout << "Tu es prêt ? " << endl;
    cout << "O/N : " ;
    cin >> choix;

    if (choix=="O" || choix=="o") {
        int res = (rand() %501) + 500;
        int guess;
        int i=0;

        do {
            cout << "Votre proposition : ";
            cin >> guess;

            if (guess>res) {
                cout << "C'est moins." << endl;
                i++;
            }

            if (guess<res) {
                cout << "C'est plus." << endl;
                i++;
            }

        } while (guess != res && i<=12);

        if (i==11) {
            cout << "Dommage ! Cela fait plus de 10 essais..." << endl;
            cout << "Je pensais à " << res << "." << endl << endl;
            suite = getchar();
        }

        else if (guess==res) {
                if (i>5 && i<=12) {
                    cout << "Bravo ! Vous gagnez " << res << "₽ !" << endl;
                    joueur->argent+=res; // + la somme dans l'inventaire
                    suite=getchar();
                }

                if (i<=5) {
                    cout << "Bravo ! Vous gagnez " << res*2 << "₽ !"<< endl;
                    joueur->argent+=res*2; // + le double de la somme dans l'inventaire (trop fort !)
                    suite=getchar();
                }

        }
    }
}

// Casino
void interactioncasino(Dresseur *joueur, int n) {
    string bash_code = "\033[94m";
    const string default_colour_bash_code="\033[0m";
    string choix;


    if (n==1) {
        cout << bash_code << "Voulez-vous jouer à la MACHINE À SOUS ?" << default_colour_bash_code << endl;
        cout << "O/N : ";
        cin >> choix;
        if (choix=="O" || choix=="o") {
            machineAsous(joueur);
        }
    }

    if (n==2) {
        cout << bash_code << "Voulez-vous jouer au JUSTE ₽RIX ?" << default_colour_bash_code << endl;
        cout << "O/N : ";
        cin >> choix;
        if (choix=="O" || choix=="o") {
            lejusteprix(joueur);
        }
    }
}
 