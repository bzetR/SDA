/**
 * @file Liste.cpp
 * Projet sem06-tp-Cpp3
 * @author l'�quipe p�dagogique 
 * @version 2 - 26/11/16
 * @brief Composant de file d'items
 * Structures de donn�es et algorithmes - DUT1 Paris 5
 */
 
#include "Liste.h"

#include <iostream>
#include <cassert>
using namespace std;

/**
 * @brief initialiser une liste vide
 * la liste est allou�e en m�moire dynamique
 * elle est � d�sallouer (cf. detruire) en fin d�utilisation
 * @param[in,out] l : la liste � cr�er (vide)
 * @pre aucune (la liste peut d�j� �tre cr��e ou non)
 * @post l est vide  
 */
void initialiser(Liste& l) {
	initialiser(l.ch);
	l.nb = 0;
	l.index = 0;
}

/**
 * @brief D�sallouer une liste
 * la liste a �t� cr��e (cf. initialiser)
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
 * @brief D�placer la position courante � une position donn�e dans la liste
 * @param[in,out] l : la liste
 * @param[in] i : la position de d�placement
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
 * @brief Lire un �l�ment de liste
 * @param[in] l : la liste
 * @return l'item lu
 * @pre 0<=i<longueur(l)
 * @pos la liste est inchnang�e
 */
Item lire(Liste& l, unsigned int i) {
	assert((i >= 0) && (i < longueur(l)));
	deplacer(l, i);
	return (lire(l.ch));
}

/**
 * @brief Ecrire un item dans la liste
 * @param[in,out] l : la liste
 * @param[in] i : position de l'�l�ment � �crire
 * @param[in] it : l'item
 * @pre 0<=i<longueur(l)
 * @pos it est en position i,
 *  la longueur de liste est inchang�e
 */
void ecrire(Liste& l, unsigned int i, const Item& it) {
	assert((i >= 0) && (i < longueur(l)));
	deplacer(l, i);
	ecrire(l.ch, it);
}

/**
 * @brief Ins�rer un �l�ment dans une liste
 * @param[in,out] l : la liste
 * @param[in] i : la position avant laquelle l'�l�ment est ins�r�
 * @param[in] it : l'�l�ment ins�r�
 * @pre 0<=i<=longueur(l)
 * @pos l'�l�ment it ins�r� est en position i, 
 *  la longueur de liste est incr�ment�e de 1 
 */
void inserer(Liste& l, unsigned int i, const Item& it) {
	assert((i >= 0) && (i <= longueur(l)));
	deplacer(l, i);
	inserer(l.ch, it);
	l.nb++;
}
	
/**
 * @brief Supprimer un �l�ment dans une liste
 * @param[in,out] l : la liste
 * @param[in] i : la position de l'�l�ment � supprimer
 * @pre 0<=i<longueur(l)
 * @pos la longueur de liste est diminu�e de 1 
 */
void supprimer(Liste& l, unsigned int i) {
	assert((i >= 0) && (i < longueur(l)));
	deplacer(l, i);
	supprimer(l.ch);
	l.nb--;
}
