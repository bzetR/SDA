#ifndef _TABLEAU3D_
#define _TABLEAU3D_

/**
* @file Tableau3D.h
* @brief Projet
* @author Robin BIZET
* @version 1 14/12/2016
* Structures de données et algorithmes
*/

#include "Item3D.h"

struct Tableau3D {
	Item3D*** tab;
	unsigned int dimX;
	unsigned int dimY;
	unsigned int dimZ;
};



void initialiser(Tableau3D& t, unsigned int dimX,
	unsigned int dimY, unsigned int dimZ);




void detruire(Tableau3D& t);

#endif
