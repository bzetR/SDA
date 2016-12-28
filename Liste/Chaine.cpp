/**
 * @file Chaine.cpp
 * Projet sem06-tp-Cpp1
 * @author l'�quipe p�dagogique 
 * @version 2 26/11/15
 * @brief Composant de chaine
 * Structures de donn�es et algorithmes - DUT1 Paris 5
 */

#include <iostream>
#include <cassert>
using namespace std;

#include "Chaine.h"

/** 
 * brief Initialisation d'une cha�ne
 * la cha�ne est allou�e en m�moire dynamique
 * la d�sallouer en fin d'utilisation (cf. detruire)
 * @param[in,out] c : la cha�ne
 * @pos la cha�ne est vide
 */
void initialiser(Chaine& c) {
	c.tete = c.queue = c.courant = NULL;
}

/** 
 * brief Destruction d'une cha�ne
 * la cha�ne a �t� cr��e (cf. initialiserC)
 * @param[in,out] c : la cha�ne
 * @pos la m�moire de cha�ne est d�sallou�e
 */
void detruire(Chaine& c) {
	debut(c);
	while (!estVide(c)) 
	supprimer(c);
}

/**
 * @brief Test de cha�ne vide
 * @param[in] c : la cha�ne test�e
 * @return true si c est vide, false sinon
 */
bool estVide(const Chaine& c) {
	return (c.tete == NULL);
}

/**
 * @brief Insertion d'un �l�ment � l'emplacement courant de la cha�ne 
 * @param[in,out] c : la cha�ne
 * @param[in] elem : l'�l�ment ins�r�
 */
void inserer(Chaine& c, const Item& elem) {
	Maillon* m = new Maillon;
	m->elem = elem;
	m->suiv = c.courant;
	
	// ajout en t�te de cha�ne
	if (c.courant == c.tete) {
		m->prec = NULL;
		if (c.tete != NULL) 
			c.tete->prec = m;
		else c.queue = m;
		c.courant = c.tete = m;
	}
	
	// ajout en queue de chaine
	if (c.courant == NULL) {
		m->prec = c.queue;
		c.queue->suiv = m; 
		c.courant = c.queue = m;
	}

	// ajout ni en t�te ni en queue de chaine
    if ((c.courant != c.tete) && (c.courant != c.queue)) {
		m->prec = c.courant->prec;
		c.courant->prec->suiv = m;
		c.courant->prec = m;
		c.courant = m;
	}
}

/**
 * @brief Suppression de l'�l�ment � l'emplacement courant de la cha�ne 
 * @param[in,out] c : la cha�ne
 * @pre le maillon courant est dans la cha�ne
 */
void supprimer(Chaine& c) {
	assert(c.courant != NULL);
	
	Maillon* m = c.courant;
	
	// suppression d'un maillon en d�but de chaine
	if (c.courant == c.tete) {
		c.courant = c.tete = c.tete->suiv;
		if (estVide(c)) c.queue = NULL;
		else c.tete->prec = NULL;
		delete m;
		return;
	}
		
	// suppression d'un maillon en queue de chaine
	if (c.courant == c.queue) {
		c.queue = c.queue->prec;
		c.courant = c.queue->suiv = NULL;
		delete m;
		return;
	}
		
	// suppression d'un maillon ni en t�te ni en queue de chaine
  	if ((c.courant != c.tete) && (c.courant != c.queue)) {
  		c.courant->prec->suiv = c.courant->suiv;
		c.courant->suiv->prec = c.courant->prec;
		c.courant = c.courant->suiv;
		delete m;
	}
	
}

/**
 * @brief Ecriture d'un �l�ment � l'emplacement courant de la cha�ne 
 * @param[in,out] c : la cha�ne
 * @param[in] elem : l'�l�ment � �crire
 * @pre le maillon courant est dans la cha�ne
 */
void ecrire(Chaine& c, const Item& elem) {
	assert(c.courant != NULL);
	c.courant->elem = elem;
}

/**
 * @brief Lecture d'un �l�ment � l'emplacement courant de la cha�ne 
 * @param[in] c : la cha�ne
 * @return l'�l�ment lu
 * @pre le maillon courant est dans la cha�ne
 */
Item lire(const Chaine& c) {
	assert(c.courant != NULL);
	return c.courant->elem;
}

/**
 * @brief Positionnement du maillon courant en d�but de cha�ne 
 * @param[in,out] c : la cha�ne
 */
void debut(Chaine& c) {
	c.courant = c.tete;
}

/**
 * @brief Test de debut de chaine
 * @param[in] c : la cha�ne test�e
 * @return true si le maillon courant est le d�but de cha�ne, false sinon
 */
bool estDebut(const Chaine& c) {
	return (c.courant == c.tete);
}

/**
 * @brief Positionnement du maillon courant en fin de cha�ne
 * @param[in,out] c : la cha�ne
 */
void fin(Chaine& c) {
	c.courant = NULL;
}

/**
 * @brief Test de fin de cha�ne
 * @param[in] c : la cha�ne test�e
 * @return true si le maillon courant est la fin de cha�ne, false sinon
 */
bool estFin(const Chaine& c) {
	return (c.courant == NULL);
}

/**
 * @brief Positionnement du maillon courant au maillon suivant
 * @param[in,out] c : la cha�ne
 * @pre le maillon courant est dans la cha�ne
 */
void suivant(Chaine& c) {
	assert(c.courant != NULL);
	c.courant = c.courant->suiv;
}

/**
 * @brief Positionnement du maillon courant au maillon pr�c�dent
 * @param[in,out] c : la cha�ne
 * @pre le maillon courant n'est pas le d�but de cha�ne
 */
void precedent(Chaine& c) {
	assert(c.courant != c.tete);
	if (c.courant == NULL)
		c.courant = c.queue;
	else c.courant = c.courant->prec;
}
