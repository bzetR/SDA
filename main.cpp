nclude <iostream>
#include <cassert>
using namespace std;

#include "Labyrinthe3D.h"

int main(int argc, const char * argv[]) {
    Labyrinthe3D lab;
    cin >> lab.t3D.dimX >> lab.t3D.dimY >> lab.t3D.dimZ;
    initialiser(lab.t3d, lab.t3D.dimX, lab.t3D.dimY, lab.t3D.dimZ);
    for (unsigned int i = 0; i < lab.t3D.dimZ; ++i){
        for (unsigned int j = 0; j <lab.t3D.dimY; ++j){
            for (unsigned int u = 0; u < lab.t3D.dimX; ++u){
                cin >> lab.t3d.tab[u][j][i];
            }
        }
    }
    cout << lab.t3D.dimX << lab.t3D.dimY << lab.t3D.dimZ;
    for (unsigned int i = 0; i < lab.t3D.dimZ; ++i){
        for (unsigned int j = 0; j <lab.t3D.dimY; ++j){
            for (unsigned int u = 0; u < lab.t3D.dimX; ++u){
                cout << lab.t3d.tab[u][j][i];
            }
        }
        cout << endl;
    }
    return 0;
}

