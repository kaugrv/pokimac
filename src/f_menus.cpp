// menus //
#include "main.h"

// affiche un Pokémon de l'équipe
void affichePokemon(PokImac P) {
    string suite;
    cout << P.rep << " " << P.nom << endl;
    cout << "Espèce : " << P.espece << endl;
    cout << "Type : " << P.type << endl;
    cout << "PV : " << P.PV << "/" << P.PVmax << endl;
    cout << "Attaque : " << P.att << endl;
    cout << "Défense : " << P.def << endl;
    suite=getchar();
}

// Menu Equipe (E)
void afficheEquipe(Dresseur* joueur) {
    string suite;
    int n;
    cout << "*:･ﾟ✧ Pokémon de " << joueur->nom << " (" << joueur->nbPok << " Pokémon) :"  << endl << endl;
    for (int i=0; i<(joueur->nbPok); i++) {
        cout << "◓ " << i+1 << " - " << (joueur->equipe)[i]->nom << " : " << (joueur->equipe)[i]->PV << "/"<< (joueur->equipe)[i]->PVmax << endl;
    }
    cout << endl << "Num. du Pokémon à consulter (0 pour annuler) : " ;

    cin >> n;
    cout << endl;
    if (n==0) {
    }
    else { 
        affichePokemon(*(joueur->equipe)[n-1]);
    }
    
}

// Menu Inventaire (I)
void afficheInventaire(Dresseur* joueur) {
    string suite;
    cout << "*:･ﾟ✧ Inventaire de " << joueur->nom << endl << endl;

    cout << "Argent : " << joueur->argent << "₽" << endl;
    cout << "◓ POKEBALLS : " << joueur->nbPokeballs << endl;
    cout << "ꕺ POTIONS : " << joueur->nbPotions << endl << endl;
    suite = getchar();

    if (joueur->nbPotions>0) { 
        cout << "Utiliser une POTION ? " << endl;
        cout << "O/N : "; 
        string choix;
        cin >> choix;
        if (choix=="O" || choix=="o") {
            cout << "Sur quel Pokémon ? " << endl;

            for (int i=0; i<(joueur->nbPok); i++) {
                cout << "◓ " << i+1 << " - " << (joueur->equipe)[i]->nom << " : " << (joueur->equipe)[i]->PV << "/"<< (joueur->equipe)[i]->PVmax << endl;
            }

            cout << endl << "Num. du Pokémon (0 pour annuler) : ";
            int n;
            cin >> n;

            if (n==0) {}
            else {
                (joueur->equipe[n-1])->PV = (joueur->equipe[n-1])->PVmax;
                cout << (joueur->equipe[n-1])->nom << " a récupéré tous ses PV !" << endl;
                joueur->nbPotions--;
            }
            suite = getchar();
        }

    }

     

}