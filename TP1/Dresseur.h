/*
Fichier: Dresseur.h
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification: 4 septembre 2016
Description: les dresseurs sont les etres capables d'attraper des creatures

Modifications par: Adam Martin-Cote et Jad Sebti
pour: INF1010 tp1
version finale: 25 septembre 2016
*/
#ifndef DRESSEUR_H
#define DRESSEUR_H

#include <string>
#include "Creature.h"
#include "ObjetMagique.h"

#define MAX_NOMBRE_CREATURES 2

class Dresseur
{
public:
	/**
	* @brief Constructeur par defaut
	*/
    Dresseur();
	/**
	* @brief Constructeur par parametres
	* @param nom du dresseur
	*/
    Dresseur(const std::string& nom);
	/**
	* @brief Destructeur par defaut
	*/
    ~Dresseur();
	/**
	* @brief Accesseurs
	*/
    std::string obtenirNom() const;
    ObjetMagique obtenirObjetMagique() const;
	unsigned int obtenirNombreCreatures() const;
	/**
	* @brief Accesseurs/Mutateur
	* @return le tableau complet
	* ! ATTENTION bris de l'encapsulation
	*/
	Creature** obtenirCreatures();
	/**
	* @brief Mutateurs
	*/
	void modifierNom(const std::string& nom);
    void modifierObjetMagique(const ObjetMagique& objetMagique);
	void modifierCreature(Creature** creatures);
	/**
	* @brief utlise un objet pour guerrir une creature
	* @param creature cible 
	* ! incremente les points de vie et energie de la cible selon le bonus de l'objet
	*/
    void utiliserObjetMagique(Creature* creature);
	/**
	* @brief Ajoute une copie d'une creature existante au dresseur
	* ! ATTENTION cette methode utilise le constructeur par copie, qui cree la nouvelle creature avec
	* ! points de vie et energie a la valeur maximale (ex: energie = energie totale)
	*/
    bool ajouterCreature(const Creature& creature);
	/**
	* @brief retire une creature au dresseur
	* @param nom un nom de creature
	* @return true si le nom appartenait a une des creatures du dresseur et la suppression a donc ete completee
	* ! cette methode delete l'objet
	*/
    bool retirerCreature(const std::string& nom);
	/**
	* @brief affichage
	*/
    void affichage() const;

private:
    std::string nom_;
    Creature** creatures_;
    unsigned int nombreCreatures_;
    unsigned int nombreCreaturesMax_;
    ObjetMagique objetMagique_;

};


#endif