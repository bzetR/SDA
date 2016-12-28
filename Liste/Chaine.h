#ifndef CHAINE_H_
#define CHAINE_H_

/**
 * @file Chaine.h
 * Projet sem06-tp-Cpp1
 * @author l'�quipe p�dagogique 
 * @version 2 26/11/15
 * @brief Composant de chaine
 * Structures de donn�es et algorithmes - DUT1 Paris 5
 */

#include "Item.h"

/** Type Maillon avec le principe du double cha�nage
 *  (maillon suivant et maillon pr�cedent)
 */
struct Maillon {
    Item elem;			// El�ment (du maillon) de la liste cha�n�e
    Maillon* suiv;		// Pointeur sur le maillon suivant
    Maillon* prec;		// Pointeur sur le maillon pr�c�dent
};

/** Type Chaine 
 *  Rep�res de d�but et de fin de cha�ne
 *  Rep�re de l'�l�ment courant
 */
 struct Chaine {
    Maillon* tete;		//Pointeur sur le maillon de t�te
    Maillon* queue;		//Pointeur sur le maillon de queue
    Maillon* courant; 	//Pointeur sur le maillon courant		   		   
};

/** 
 * brief Initialisation d'une cha�ne
 * la cha�ne est allou�e en m�moire dynamique
 * la d�sallouer en fin d'utilisation (cf. detruire)
 * @param[in,out] c : la cha�ne
 * @pos la cha�ne est vide
 */
void initialiser(Chaine& c);

/** 
 * brief Destruction d'une cha�ne
 * la cha�ne a �t� initialis�e (cf. initialiserC)
 * @param[in,out] c : la cha�ne
 * @pos la m�moire de cha�ne est d�sallou�e
 */
 void detruire(Chaine& c);

/**
 * @brief Test de cha�ne vide
 * @param[in] c : la cha�ne test�e
 * @return true si c est vide, false sinon
 */
bool estVide(const Chaine& c);

/**
 * @brief Insertion d'un �l�ment � l'emplacement courant de la cha�ne 
 * @param[in,out] c : la cha�ne
 * @param[in] elem : l'�l�ment ins�r�
 */
 void inserer(Chaine& c, const Item& elem);

/**
 * @brief Suppression de l'�l�ment � l'emplacement courant de la cha�ne 
 * @param[in,out] c : la cha�ne
 */
void supprimer(Chaine& c);

/**
 * @brief Ecriture d'un �l�ment � l'emplacement courant de la cha�ne 
 * @param[in,out] c : la cha�ne
 * @param[in] elem : l'�l�ment � �crire
 * @pre le maillon courant est dans la cha�ne
 */
 void ecrire(Chaine& c, const Item& elem);

/**
 * @brief Lecture d'un �l�ment � l'emplacement courant de la cha�ne 
 * @param[in] c : la cha�ne
 * @return l'�l�ment lu
 * @pre le maillon courant est dans la cha�ne
 */
Item lire(const Chaine& c);

/**
 * @brief Positionnement du maillon courant en d�but de cha�ne 
 * @param[in,out] c : la cha�ne
 * @pre le maillon courant est dans la cha�ne
 */
void debut(Chaine& c);

/**
 * @brief Test de debut de chaine
 * @param[in] c : la cha�ne test�e
 * @return true si le maillon courant est le d�but de cha�ne, false sinon
 */
bool estDebut(const Chaine& c);

/**
 * @brief Positionnement du maillon courant en fin de cha�ne
 * @param[in,out] c : la cha�ne
 */
void fin(Chaine& c);

/**
 * @brief Test de fin de cha�ne
 * @param[in] c : la cha�ne test�e
 * @return true si le maillon courant est la fin de cha�ne, false sinon
 */
 bool estFin(const Chaine& c);

/**
 * @brief Positionnement du maillon courant au maillon suivant
 * @param[in,out] c : la cha�ne
 * @pre le maillon courant est dans la cha�ne
 */
void suivant(Chaine& c);

/**
 * @brief Positionnement du maillon courant au maillon pr�c�dent
 * @param[in,out] c : la cha�ne
 * @pre le maillon courant n'est pas le d�but de cha�ne
 */
 void precedent(Chaine& c);

#endif /*CHAINE_H_*/
