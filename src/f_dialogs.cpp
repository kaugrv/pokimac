// dialogs //
#include "main.h"

// Prend un string et l'affiche clignotant
void clignotant(const string c) {
    const string default_colour_bash_code="\033[0m";
    string bash_code = "\033[05m";
    cout << bash_code << c << default_colour_bash_code;
}

// Animation du début : Pokémon By Game Freak 3
void logo() { 
    string suite;
    suite = getchar();
    cout << "                                  ..| " << endl <<
    "    _.----.        ____         ..  _|   ___    ___     ____ " << endl <<
    ".-.       -.      |    |  /-.   |.-.    |   |  /   |   |    |  |-. " << endl <<
    "|      __    |    .-.  | /   -.  ___    |    |/    |    -.   | |  | " << endl <<
    " |.    | |   |  __  |  |/    ...._  -.  |          | __  |    ||  | " << endl <<
    "   |    |/   /.. _-.|      .. / / / /   |          .. _-.|     |  | " << endl<< 
    "    |     .-./  /   |    ..   | |/ / .-.|         /  /   |  |     | " << endl <<
    "     |    | |   |_/  |   --.  |    -.  /|  |    ||   |_/  | ||    | " << endl <<
    "      |    | |      /       --.-.___.-. |  ||  /| |      /  | |   | " << endl <<
    "       |    | -.__..|  |--._    -|      |__| |/ |  -.__..|  | |   | " << endl <<
    "        |_.-.       |__|    --._ |              .-.|     .-.| |   | " << endl <<
    "                                -.                            .-._  "<< endl << endl;
    
    sleep(1); // attend 1 seconde
    cout <<  
 " _                ___                          ___                      _       ____" << endl <<
 "| |__   _  _     / __|  __ _   _ __    ___    | __|  _ _   ___   __ _  | |__   |__ / " << endl <<
 "| '_ | | || |   | (_ | / _` | | '  |  / -_)   | _|  | '_| / -_) / _` | | / /    |_ | " << endl <<
 "|_.__/  |_, |    |___| |__,_| |_|_|_| |___|   |_|   |_|   |___| |__,_| |_|_|   |___/ " << endl <<
 "        |__/                                                                         " << endl << endl;
    sleep(1);
    cout << "Appuyez sur ENTREE pour continuer " ;
    suite = getchar();
    system("clear");
}

// Dialogue du début avec le professeur. Demande le nom du joueur
int dialoguedebut(Dresseur* joueur) { 
    logo();
    string suite;
    clignotant("ߐ ") ;
    cout << "Bienvenue dans le monde des POKEMON ! " ; 
    cout << endl;
    suite = getchar(); // entree pour continuer

    cout << "Je suis le professeur CHEN. ";
    suite = getchar();
    cout << "Mais tout le monde m'appelle le professeur Pokémon.";
    cout << endl;
    suite = getchar();

    cout << "Dis-moi, quel est ton nom ?";
    cout << endl;
    cout << "Votre nom : ";
    cin >> joueur->nom; 
    cout << endl;
    suite = getchar();

    cout << "Enchanté, " << joueur->nom << ". " ;
    suite = getchar();
    cout << "Ton aventure est sur le point de commencer ! " << endl;
    suite = getchar();

    system("clear");
    return 0;
}

// Choix du premier Pokémon
void choixstarter(Dresseur* joueur) {
    string suite;
    
    int choix;
    clignotant("ߐ ") ;
    cout << "Choisis d'abord un POKEMON !" << endl;
    cout << endl;
    cout << "◓ 1 : BULBIZARRE, le Pokémon Plante ?" << endl;
    cout << "◓ 2 : SALAMECHE, le Pokémon Feu ?" << endl;
    cout << "◓ 3 : CARAPUCE, le Pokémon Eau ?" << endl << endl;
    
    cout << "Votre choix (1,2 ou 3): " ;
    cin >> choix ;
    cout << endl;
  
    string phrase;

    PokImac S ;

    if (choix==1) {
        S = pokedex(1);
        phrase = "BULBIZARRE ? Excellent choix !";
    }
    else if (choix==2) {
        S = pokedex(4);
        phrase = "SALAMÈCHE ! C'est un très bon choix.";
    }
    else if (choix==3) {
        S = pokedex(7);
        phrase = "CARAPUCE, très bon choix !";
    }
    else if (choix==151) {
        S = pokedex(151); //Mew
        phrase = " ... Meeeewwww ! ~ ♪";

    }
    else { 
        S = pokedex(152); //Missingno.
        phrase = "................";
    }

    S.PV=10;
    S.PVmax=10;
    S.att=rand() % 22 + 12;
    S.def=rand() % 22 + 12;

    cout << phrase << endl << endl;
    suite=getchar();
    cout << joueur->nom << " obtient un " << S.nom << " !" << endl;
    suite=getchar();
    
    // Choix du surnom
    string conf="O";
    cout << "Voulez-vous lui donner un surnom ?" << endl;
    cout << "O/N : ";
    cin >> conf;
    string surnom;
    if (conf == "O" || conf == "o") {
        cout <<"Surnom de " << S.nom << " : ";
        cin >> surnom;
        S.nom=surnom;
    } 

    // Ajout à l'équipe
    PokImac* P = new PokImac;
    *P = S;
    (joueur->equipe[0])=P;
    joueur->nbPok=1;

    cout << endl;

    suite=getchar();

    cout << "C'est parti ! Bon voyage ! " << endl ;
    
    suite=getchar();
}