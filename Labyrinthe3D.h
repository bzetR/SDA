#ifndef _Labyrinthe3D_
#define _Labyrinthe3D_

/**
* @file Item.h
* @author Robin BIZET
* @version 1 14/12/2016
* @brief Projet - SpŽcialisation du type Labyrinthe3D
*/

#include "Tableau3D.h"
#include "IndexPosition.h"

struct Labyrinthe3D {
	Tableau3D t3D; // le labyrinthe
	IndexPosition3D entree; // position de l’entrée
	IndexPosition3D plans; // position des plans
};



void initialiser(Labyrinthe3D& l, unsigned int dimX,
	unsigned int dimY, unsigned int dimZ);



void detruire(Labyrinthe3D& l);


#endif
