#include <iostream>
#include <cassert>
using namespace std;

#include "Tableau3D.h"


// bandeau





// descirption fonction

void initialisatier(Tableau3D& t3d, unsigned int dimx, unsigned int dimy, unsigned int dimz) {
	assert((dimx > 0) && (dimy > 0) && (dimz > 0));
	t3d.dimX = dimx;
	t3d.dimY = dimy;
	t3d.dimZ = dimz;

	t3d.tab = new Item3D**[dimx];
	for (unsigned i = 0; i < dimx; ++i) {
		t3d.tab[i] = new Item3D*[dimy];
		for (unsigned j = 0; j < dimy; ++j) {
			t3d.tab[i][j] = new Item3D[dimz];
		}
	}
}

// descrip fonc

void detruire(Tableau3D& t3d) {
	for (unsigned int i = 0; i < t3d.dimY; ++i) {
		for (unsigned int j = 0; j < t3d.dimZ; ++j) {
			delete t3d.tab[i][j];
		}
		delete t3d.tab[i];
	}
	delete t3d.tab;
	t3d.tab = NULL;
}