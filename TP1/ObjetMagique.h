/**
* Classe Objet magique
* les dresseurs peuvent posseder un objet magique.
* chaque objet a une valeur 'bonus'
* l'utilisation de l'objet incremente a la fois les points de vie et
* l'energie d'une creature cible selon la valeur du bonus de l'objet
* jusqu'a la valeur maximale de depart
*
* @author      Adam Martin-Cote
* @author      Jad Sebti
* version finale: 25 septembre 2016
*/
#ifndef OBJETMAGIQUE_H
#define OBJETMAGIQUE_H

#include <iostream>

class ObjetMagique
{
public:
	/**
	* @brief Constructeur par defaut
	*/
	ObjetMagique();
	/**
	* @brief Constructeur par parametres
	* @param nom
	* @param bonus valeur restorative de l'objet
	*/
	ObjetMagique(std::string nom, int bonus);
	/**
	* @brief Destructeur par defaut
	*/
	~ObjetMagique();
	/**
	* @brief Accesseurs
	*/
	std::string obtenirNom() const;
	int obtenirBonus() const;
	/**
	* @brief Mutateurs
	*/
	void modifierNom(std::string nom);
	void modifierBonus(int bonus);
	/**
	* @brief Affichage
	*/
	void affichage() const;

private:
	std::string nom_;
	int bonus_;
};


#endif


