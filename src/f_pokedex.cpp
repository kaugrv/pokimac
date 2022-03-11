// pokedex //
#include "main.h"

PokImac pokedex(int n) { // génère et renvoie le n-ième PokImac du Pokédex

    PokImac P;
    if (n==1) {
        P.espece="BULBIZARRE";
        P.rep="꘠";
        P.type="Plante";
        P.rarete="Starter";
    }

    if (n==4) {
        P.espece="SALAMÈCHE";
        P.rep="꘢🔥";
        P.type="Feu";
        P.rarete="Starter";
    }

    if (n==7) {
        P.espece="CARAPUCE";
        P.rep="ꕫ";
        P.type="Eau";
        P.rarete="Starter";
    }

    if (n==9) {
        P.espece="CHENIPAN";
        P.rep="ꘫ";
        P.type="Insecte";
        P.rarete="Commun";
        P.map = 1;
    }

    if (n==13) {
        P.espece="ASPICOT";
        P.rep="ꘫ";
        P.type="Insecte";
        P.rarete="Commun";
        P.map=1;
    }

    if (n==16) {
        P.espece="ROUCOOL";
        P.rep="^ꕒ";
        P.type="Vol";
        P.rarete="Commun";
        P.map=1;
    }

    if (n==19) {
        P.espece="RATTATA";
        P.rep="ꕮ";
        P.type="Normal";
        P.rarete="Commun";
        P.map=1;
    }
    
    if (n==21) {
        P.espece="PIAFABEC";
        P.rep="ꗩ";
        P.type="Vol";
        P.rarete="Commun";
        P.map=1;
    }

    if (n==23) {
        P.espece="ABO";
        P.rep="꘩";
        P.type="Poison";
        P.rarete="Commun";
        P.map=3;
    }

    if (n==25) {
        P.espece="PIKACHU";
        P.rep="ꘪ⚡";
        P.type="Electrik";
        P.rarete="Rare";
        P.map=3;
    }


    if (n==27) {
        P.espece="SABELETTE";
        P.rep="ꕮ";
        P.type="Sol";
        P.rarete="Commun";
        P.map=2;
    }

    if (n==29) {
        P.espece="NIDORAN♀";
        P.rep="ꕮ";
        P.type="Poison";
        P.rarete="Commun";
        P.map=1;
    }

    if (n==32) {
        P.espece="NIDORAN♂";
        P.rep="ꕮ";
        P.type="Poison";
        P.rarete="Commun";
        P.map=1;
    }

    
    if (n==35) {
        P.espece="MELOFEE";
        P.rep="ꘪ";
        P.type="Fée";
        P.rarete="Peu commun";
        P.map=1;
    }

    if (n==37) {
        P.espece="GOUPIX";
        P.rep="ꖐ";
        P.type="Feu";
        P.rarete="Peu commun";
        P.map=1;
    }

    if (n==39) {
        P.espece="RONDOUDOU";
        P.rep="ꖏ";
        P.type="Fée";
        P.rarete="Peu commun";
        P.map=3;
    }

    if (n==41) {
        P.espece="NOSFERAPTI";
        P.rep="ꔺ";
        P.type="Poison";
        P.rarete="Peu commun";
        P.map=3;
    }

    if (n==43) {
        P.espece="MYSTHERBE";
        P.rep="ꕥ";
        P.type="Plante";
        P.rarete="Commun";
        P.map=1;
    }

    if (n==46) {
        P.espece="PARAS";
        P.rep="^ꗭ^";
        P.type="Insecte";
        P.rarete="Peu commun";
        P.map=1;
    }

    if (n==48) {
        P.espece="MIMITOSS";
        P.rep="꘠";
        P.type="Poison";
        P.rarete="Peu commun";
        P.map=1;
    }

    if (n==50) {
        P.espece="TAUPIQUEUR";
        P.rep="|ꖴ|";
        P.type="Sol";
        P.rarete="Commun";
        P.map=2;
    }

    if (n==52) {
        P.espece="MIAOUSS";
        P.rep="ꖐ";
        P.type="Normal";
        P.rarete="Peu commun";
        P.map=3;
    }

    if (n==54) {
        P.espece="PSYKOKWAK";
        P.rep="ꔾ";
        P.type="Eau";
        P.rarete="Commun";
        P.map=2;
    }

    if (n==56) {
        P.espece="FÉROSINGE";
        P.rep="ꖡ";
        P.type="Combat";
        P.rarete="Commun";
        P.map=1;
    }

    if (n==58) {
        P.espece="CANINOS";
        P.rep="ꖐ";
        P.type="Feu";
        P.rarete="Peu commun";
        P.map=3;
    }

    if (n==60) {
        P.espece="PTITARD";
        P.rep="@/";
        P.type="Eau";
        P.rarete="Peu commun";
        P.map=2;
    }


    if (n==63) {
        P.espece="ABRA";
        P.rep="ꖙ";
        P.type="Psy";
        P.rarete="Commun";
        P.map=1;
    }


    if (n==66) {
        P.espece="MACHOC";
        P.rep="ꖡ";
        P.type="Combat";
        P.rarete="Commun";
        P.map=3;
    }

    if (n==69) {
        P.espece="CHETIFLOR";
        P.rep="꘣";
        P.type="Plante";
        P.rarete="Commun";
        P.map=1;
    }

    if (n==72) {
        P.espece="TENTACOOL";
        P.rep="ꘐ";
        P.type="Eau";
        P.rarete="Commun";
        P.map=2;
    }

    if (n==74) {
        P.espece="RACAILLOU";
        P.rep="งoง";
        P.type="Combat";
        P.rarete="Commun";
        P.map=1;
    }

    if (n==77) {
        P.espece="PONYTA";
        P.rep="ꖥ🔥";
        P.type="Feu";
        P.rarete="Peu commun";
        P.map=1;
    }

    if (n==79) {
        P.espece="RAMOLOSS";
        P.rep="ꖐ Zzz";
        P.type="Psy";
        P.rarete="Peu commun";
        P.map=2;
    }

    if (n==81) {
        P.espece="MAGNETI";
        P.rep="cꖴc";
        P.type="Electrik";
        P.rarete="Commun";
        P.map=3;
    }

    if (n==83) {
        P.espece="CANARTICHO";
        P.rep="ꕒ Y";
        P.type="Vol";
        P.rarete="Peu commun";
        P.map=1;
    }

    if (n==84) {
        P.espece="DODUO";
        P.rep="ꖶꖶ";
        P.type="Vol";
        P.rarete="Peu commun";
        P.map=1;
    }

    if (n==86) {
        P.espece="OTARIA";
        P.rep="ꔫꕁ";
        P.type="Glace";
        P.rarete="Peu commun";
        P.map=2;
    }

    if (n==88) {
        P.espece="TADMORV";
        P.rep="ꘓꖬ";
        P.type="Poison";
        P.rarete="Commun";
        P.map=3;
    }

    if (n==90) {
        P.espece="KOKIYAS";
        P.rep="ꖘ";
        P.type="Eau";
        P.rarete="Peu commun";
        P.map=2;
    }

    if (n==92) {
        P.espece="FANTOMINUS";
        P.rep="ꖴꖴ";
        P.type="Spectre";
        P.rarete="Commun";
        P.map=3;
    }

    if (n==95) {
        P.espece="ONYX";
        P.rep="ꘫ";
        P.type="Roche";
        P.rarete="Peu commun";
        P.map=1;
    }

    if (n==96) {
        P.espece="SOPORIFIK";
        P.rep="ꘪ Zzz";
        P.type="Psy";
        P.rarete="Peu commun";
        P.map=3;
    }

    if (n==98) {
        P.espece="KRABBY";
        P.rep="cꗬc";
        P.type="Eau";
        P.rarete="Commun";
        P.map=2;
    }

    if (n==100) {
        P.espece="VOLTORBE";
        P.rep="◓";
        P.type="Electrik";
        P.rarete="Commun";
        P.map=3;
    }

    if (n==102) {
        P.espece="NOEUNOEUF";
        P.rep="ꕢ";
        P.type="Plante";
        P.rarete="Peu commun";
        P.map=1;
    }

    if (n==104) {
        P.espece="OSSELAIT";
        P.rep="ꕸ";
        P.type="Sol";
        P.rarete="Peu commun";
        P.map=3;
    }

    if (n==106) {
        P.espece="KICKLEE";
        P.rep="ꗒ";
        P.type="Combat";
        P.rarete="Rare";
        P.map=3;
    }

    if (n==107) {
        P.espece="TYGNON";
        P.rep="ꗑ";
        P.type="Combat";
        P.rarete="Rare";
        P.map=3;
    }

    if (n==108) {
        P.espece="EXCELANGUE";
        P.rep="ꘪ :p";
        P.type="Normal";
        P.rarete="Rare";
        P.map=1;
    }

    if (n==109) {
        P.espece="SMOGO";
        P.rep="O☁";
        P.type="Poison";
        P.rarete="Peu commun";
        P.map=3;
    }

    if (n==111) {
        P.espece="RHINOCORNE";
        P.rep="^ꕸ";
        P.type="Sol";
        P.rarete="Rare";
        P.map=1;
    }

    if (n==113) {
        P.espece="LEVEINARD";
        P.rep="ꘪO";
        P.type="Normal";
        P.rarete="Rare";
        P.map=3;
    }

    if (n==114) {
        P.espece="SAQUEDENEU";
        P.rep="ꗥ";
        P.type="Plante";
        P.rarete="Peu commun";
        P.map=1;
    }

    if (n==115) {
        P.espece="KANGOUREX";
        P.rep="ꕸꖐ";
        P.type="Normal";
        P.rarete="Rare";
        P.map=1;
    }

    if (n==116) {
        P.espece="HYPOTREMPE";
        P.rep="ꕎ";
        P.type="Eau";
        P.rarete="Peu commun";
        P.map=2;
    }

    if (n==118) {
        P.espece="POISSIRÈNE";
        P.rep="-3-";
        P.type="Eau";
        P.rarete="Commun";
        P.map=2;
    }

    if (n==120) {
        P.espece="STARI";
        P.rep="☆";
        P.type="Psy";
        P.rarete="Commun";
        P.map=2;
    }

    if (n==122) {
        P.espece="M. MIME";
        P.rep="ꖂ";
        P.type="Psy";
        P.rarete="Rare";
        P.map=3;
    }

    if (n==123) {
        P.espece="INSÉCATEUR";
        P.rep="ꘘ";
        P.type="Insecte";
        P.rarete="Rare";
        P.map=1;
    }

    if (n==124) {
        P.espece="LIPPOUTOU";
        P.rep="💋";
        P.type="Glace";
        P.rarete="Rare";
        P.map=1;
    }

    if (n==125) {
        P.espece="ÉLEKTEK";
        P.rep="⚡⚡";
        P.type="Electrik";
        P.rarete="Rare";
        P.map=3;
    }

    if (n==126) {
        P.espece="MAGMAR";
        P.rep="🔥🔥";
        P.type="Feu";
        P.rarete="Rare";
        P.map=1;
    }

    if (n==127) {
        P.espece="SCARABRUTE";
        P.rep="ꘘ";
        P.type="Insecte";
        P.rarete="Peu commun";
        P.map=1;
    }

    if (n==128) {
        P.espece="TAUROS";
        P.rep="ꕸ-^";
        P.type="Normal";
        P.rarete="Rare";
        P.map=1;
    }

    if (n==129) {
        P.espece="MAGICARPE";
        P.rep="ꖴ3ꖴ";
        P.type="Eau";
        P.rarete="Commun";
        P.map=2;
    }

    if (n==131) {
        P.espece="LOKHLASS";
        P.rep="ꕃ";
        P.type="Glace";
        P.rarete="Rare";
        P.map=2;
    }

    if (n==132) {
        P.espece="MÉTAMORPH";
        P.rep="ꘓ°c°3";
        P.type="Normal";
        P.rarete="Rare";
        P.map=3;
    }

    if (n==133) {
        P.espece="EVOLI";
        P.rep="ꖐ" ;
        P.type="Normal";
        P.rarete="Peu commun";
        P.map=1;
    }

    if (n==137) {
        P.espece="PORYGON";
        P.rep="ꗇ" ;
        P.type="Normal";
        P.rarete="Rare";
        P.map=3;
    }

    if (n==138) {
        P.espece="AMONITA";
        P.rep="w@" ;
        P.type="Eau";
        P.rarete="Fossile";
    }

    if (n==140) {
        P.espece="KABUTO";
        P.rep="ꖷ" ;
        P.type="Eau";
        P.rarete="Fossile";
    }

    if (n==142) {
        P.espece="PTERA";
        P.rep="ꖚ" ;
        P.type="Vol";
        P.rarete="Fossile";
    }

    if (n==143) {
        P.espece="RONFLEX";
        P.rep="ꗢ Zzz" ;
        P.type="Normal";
        P.rarete="Rare";
        P.map=3;
    }

    if (n==144) {
        P.espece="ARTIKODIN";
        P.rep="ꕒ ❄" ;
        P.type="Glace";
        P.rarete="Légendaire";
    }

    if (n==145) {
        P.espece="ÉLECTHOR";
        P.rep="ꕒ ⚡" ;
        P.type="Electrik";
        P.rarete="Légendaire";
    }

    if (n==146) {
        P.espece="SULFURA";
        P.rep="ꕒ 🔥" ;
        P.type="Feu";
        P.rarete="Légendaire";
    }

    if (n==147) {
        P.espece="MINIDRACO";
        P.rep="꘩" ;
        P.type="Dragon";
        P.rarete="Rare";
        P.map=1;
    }

    if (n==150) {
        P.espece="MEWTWO";
        P.rep="ꔓ" ;
        P.type="Psy";
        P.rarete="Légendaire";
    }


    if (n==151) {
        P.espece="MEW";
        P.rep="ꖆ";
        P.type="Normal";
        P.rarete="Légendaire";
    }

    if (n==152) {
        P.espece="MISSINGNO.";
        P.rep="⠾";
        P.type="Bird";
        P.rarete="Bug";
    }


    P.numero=n;
    P.nom=P.espece;
    P.PV = 10;
    P.PVmax = 10; 
    P.att=rand() % 20 + 11;
    P.def=rand() % 20 + 11;

    return P;
}
