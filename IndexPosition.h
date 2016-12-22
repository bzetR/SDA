#ifndef _IndexPostion_
#define _IndexPostion_

/**
* @file IndexPosition.h
* @author Robin BIZET
* @version 1 14/12/2016
* @brief Projet - Spécialisation du type IndexPosition
*/

struct IndexPosition3D {
	unsigned int x;
	unsigned int y;
	unsigned int z;
};

/* Initialisation des coordonnées de index */
void initialisation(IndexPosition3D& index,
	unsigned int i = 0, unsigned int j = 0,
		unsigned int k = 0);
/* Fonction indicatrice qui renvoie true
si i1 et i2 sont connexes, false sinon */
bool estConnexe(const IndexPosition3D& i1,
	const IndexPosition3D& i2);



#endif