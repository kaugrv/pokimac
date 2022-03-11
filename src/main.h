// Librairies et namespace
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h> // pour le module rand
#include <time.h>   // pour le temps
#include <unistd.h> // pour le sleep
#include <cmath> // pour les calculs en combat

using namespace std;

// Définition des structures utiles

struct PokImac {
    int numero; // numéro correspondant à l'espèce dans le pokédex. Ex : Bulbizarre = 1, Pikachu = 25
    string espece;
    string nom; // surnom du pokémon. Par défaut : nom = espèce
    string rep; // caractère représentant le pokémon dans l'interface
    string type; // un seul type par pokémon
    string rarete; // Starter, Commun, Peu commun, Rare, ...
    int PVmax;
    int PV;
    int att;
    int def;
    int map; // type de map dans lequel le pokémon peut être rencontré
} ;

struct Dresseur {
    string nom;
    PokImac* equipe[256];
    int nbPok;
    int argent;
    int nbPokeballs;
    int nbPotions;
};

// Taille de la Map

const int TX = 25;
const int TY = 15;


// Prototypage des fonctions

// dialogs //
void clignotant(const string c);
void logo();
int dialoguedebut(Dresseur* joueur);
void choixstarter(Dresseur* joueur);

// interactions //
void interactionsoin(Dresseur *joueur);
void interactionboutique(Dresseur *joueur);

void machineAsous(Dresseur *joueur);
void lejusteprix(Dresseur *joueur);
void interactioncasino(Dresseur *joueur, int n);


// map //
void mapname(int typemap);

void displaycolor(const char*c, int typemap);
int dansHT(int posX, int posY, int typemap);

void drawMap(char* map[TX][TY], int posX, int posY, int typemap);

void MAP(char* map[TX][TY], int posX, int posY, int typemap, Dresseur joueur);


// menus //
void affichePokemon(PokImac P);
void afficheEquipe(Dresseur *joueur);
void afficheInventaire(Dresseur* joueur);

// pokedex //
PokImac pokedex(int n);

// fight //
int pokemonsauvage(int typemap);

int calculDegats(PokImac* attaquant, PokImac* defenseur, int modAttaquant, int modDefenseur);
void changerPokemon(Dresseur* joueur);

void displayPV(PokImac P);
void ecrancombat(PokImac P, Dresseur* joueur);

string nomAttaque(PokImac* poke);
bool tryCatch(PokImac* cible);