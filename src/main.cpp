// PROJET POKIMAC 
// by "Game Freak 3" (Axel DONA & Wendy GERVAIS) IMAC 1
// Janvier 2022

// main //
#include "main.h"
#include <time.h>


// Map
char* map[TX][TY]; 

int main(){
    // Efface la console
    system("clear");

    // Pour avoir des entiers (vraiment) aléatoires ("seed")
    srand(time(NULL));

    // Initialisation joueur
    Dresseur joueur;
    joueur.nbPok=0;
    joueur.argent=1000;
    joueur.nbPokeballs=15;
    joueur.nbPotions=10;
    
    // Position initiale du joueur
    int posX=TX/2;
    int posY=TY/2;

    // Logo et dialogue du début
    dialoguedebut(&joueur);
 
    // Création du starter + ajout à l'équipe
    choixstarter(&joueur);

    system("clear");

    // Map de départ : route 1
    int typemap=1;
    
    // Déplacement sur la Map : JEU !
    MAP(map, posX, posY, typemap, joueur);
}
