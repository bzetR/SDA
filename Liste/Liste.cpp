/**
 * @file Liste.cpp
 * Projet sem06-tp-Cpp3
 * @author l'équipe pédagogique 
 * @version 2 - 26/11/16
 * @brief Composant de file d'items
 * Structures de données et algorithmes - DUT1 Paris 5
 */
 
#include "Liste.h"

#include <iostream>
#include <cassert>
using namespace std;

/**
 * @brief initialiser une liste vide
 * la liste est allouée en mémoire dynamique
 * elle est à désallouer (cf. detruire) en fin d’utilisation
 * @param[in,out] l : la liste à créer (vide)
 * @pre aucune (la liste peut déjà être créée ou non)
 * @post l est vide  
 */
void initialiser(Liste& l) {
	initialiser(l.ch);
	l.nb = 0;
	l.index = 0;
}

/**
 * @brief Désallouer une liste
 * la liste a été créée (cf. initialiser)
 * @param[in,out] l : la liste
 */
void detruire(Liste& l) {
	detruire(l.ch);
}
	
/**
 * @brief Longueur de liste
 * @param[in] l : la liste
 * @return la longueur
 */
unsigned int longueur(const Liste& l) {
	return l.nb;
}

/**
 * @brief Déplacer la position courante à une position donnée dans la liste
 * @param[in,out] l : la liste
 * @param[in] i : la position de déplacement
 * @pre 0<=i<=longueur(l)
 */
void deplacer(Liste& l, unsigned int i) {
	assert((i >= 0) && (i <= longueur(l)));
	while (l.index != i) {
		if (l.index < i) {
			suivant(l.ch);
			l.index++;
		}
		else {
			precedent(l.ch);
			l.index--;
		}
	}
}

/**
 * @brief Lire un élément de liste
 * @param[in] l : la liste
 * @return l'item lu
 * @pre 0<=i<longueur(l)
 * @pos la liste est inchnangée
 */
Item lire(Liste& l, unsigned int i) {
	assert((i >= 0) && (i < longueur(l)));
	deplacer(l, i);
	return (lire(l.ch));
}

/**
 * @brief Ecrire un item dans la liste
 * @param[in,out] l : la liste
 * @param[in] i : position de l'élément à écrire
 * @param[in] it : l'item
 * @pre 0<=i<longueur(l)
 * @pos it est en position i,
 *  la longueur de liste est inchangée
 */
void ecrire(Liste& l, unsigned int i, const Item& it) {
	assert((i >= 0) && (i < longueur(l)));
	deplacer(l, i);
	ecrire(l.ch, it);
}

/**
 * @brief Insérer un élément dans une liste
 * @param[in,out] l : la liste
 * @param[in] i : la position avant laquelle l'élément est inséré
 * @param[in] it : l'élément inséré
 * @pre 0<=i<=longueur(l)
 * @pos l'élément it inséré est en position i, 
 *  la longueur de liste est incrémentée de 1 
 */
void inserer(Liste& l, unsigned int i, const Item& it) {
	assert((i >= 0) && (i <= longueur(l)));
	deplacer(l, i);
	inserer(l.ch, it);
	l.nb++;
}
	
/**
 * @brief Supprimer un élément dans une liste
 * @param[in,out] l : la liste
 * @param[in] i : la position de l'élément à supprimer
 * @pre 0<=i<longueur(l)
 * @pos la longueur de liste est diminuée de 1 
 */
void supprimer(Liste& l, unsigned int i) {
	assert((i >= 0) && (i < longueur(l)));
	deplacer(l, i);
	supprimer(l.ch);
	l.nb--;
}
