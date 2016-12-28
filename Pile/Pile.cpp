/**
 * @file Pile.cpp
 * Projet sem04-tp-Cpp3
 * @author l'�quipe p�dagogique 
 * @version 1 - 23/12/05
 * @brief Composant de pile � capacit� extensible
 * Structures de donn�es et algorithmes - DUT1 Paris 5
 */

#include <iostream>
#include <cassert>

#include "Pile.h"

/**
 * @brief Initialiser une pile vide
 * la pile est allou�e en m�moire dynamique
 * @see detruire, pour une d�sallocation en fin d�utilisation
 * @param[out] p : la pile � initialiser
 * @param[in] c : capacit� initiale de la pile
 * @param[in] pas : pas d'extension de la pile
 * @pre c>0 et pas >0
 */
void initialiser(Pile& p, unsigned int c, unsigned int pas) {
	assert((c>0) && (pas >0));
	initialiser(p.tab, c, pas);
	p.sommet = -1; 
}

/**
 * @brief D�sallouer une pile
 * @see initialiser, la pile a d�j� �t� initialis�e
 * @param[in,out] p : la pile � d�sallouer
 */
void detruire(Pile& p) {
	detruire(p.tab);
}

/**
 * @brief Test de pile vide
 * @param[in] p : la pile test�e
 * @return true si p est vide, false sinon
 */
bool estVide(const Pile& p) {
	return (p.sommet == -1);
}

/**
 * @brief Lire l'item au sommet de pile
 * @param[in] p : la pile
 * @return la valeur de l'item au sommet de pile
 * @pre la pile n�est pas vide
 */
Item sommet(const Pile& p) {
	assert(!estVide(p));
	return (lire(p.tab, p.sommet));
}

/**
 * @brief Empiler un item sur une pile
 * @param[in,out] p : la pile
 * @param[in] it : l'item � empiler
 * La pr�condition (@pre la pile n�est pas pleine) n'est pas utile 
 * en raison de l'extension automatique en m�moire dynamique 
 */
void empiler(Pile& p, const Item& it) {
	p.sommet++;
	ecrire(p.tab, p.sommet, it);
}

/**
 * @brief D�piler l�item au sommet de pile
 * @param[in,out] p : la pile
 * @pre la pile n�est pas vide
 */
void depiler(Pile& p) {
	assert(!estVide(p));
	p.sommet--;
}
