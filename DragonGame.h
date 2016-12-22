#ifndef _DragonGame_
#define _DragonGame_

/**
* @file DragonGame.h
* @author Robin BIZET
* @version 1 14/12/2016
* @brief Projet - Spécialisation du type DragonGame
*/

#include "Labyrinthe3D.h"

struct DragonGame {
	Labyrinthe3D lab; // le labyrinthe
	Pile plan; // planification de la recherche
	Liste chemin; // chemin du Dragon à l’entrée
};

// initialisation de lab, plan et chemin
//void initialiser(DragonGame& d, ifstream& f);
void initialiser(DragonGame& d);


void detruire(DragonGame& d);



/* d le jeu du Dragon, e l'entrée du labyrinthe
où se trouve le dragon. Retourne vrai si le trésor
est trouvé, false sinon. Cf. algorithme de recherche*/
bool missionDragon(DragonGame& d,
	const IndexPosition3D& e);


// affiche les différentes traces de la solution
// void afficher(ostream& f, const DragonGame&
void afficher(const DragonGame& d);


#endif