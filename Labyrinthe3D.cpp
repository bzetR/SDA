#include <iostream>
#include <cassert>
using namespace std;

#include "Labyrinthe3D.h"
#include "Tableau3D.cpp"

/**
 * @file Labyrinthe3D.cpp
 * @author Robin BIZET
 * @version 1 20/12/2016
 * @brief Projet - Spécialisation des fonctions correspondant au Labyrinthe3D
 */

void initialiser(Labyrinthe3D& l, unsigned int dimX,
                 unsigned int dimY, unsigned int dimZ){
    initialiser(l.t3d, dimX, dimY, dimZ);
}



void detruire(Labyrinthe3D& l);

