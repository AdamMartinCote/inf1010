/**
* Classe Dresseur
*
* @author      Adam Martin-Cote
* @author      Jad Sebti
* version finale: 3 octobre 2016
*/
#ifndef DRESSEUR_H
#define DRESSEUR_H

#include <iostream>
#include <string>
#include <vector>
#include "Creature.h"

#define MAX_NOMBRE_CREATURES 2

class Dresseur
{
public:
	/**
	* @brief Constructeur par defaut
	*/
	Dresseur();
	/**
	* @brief Constructeur par parametre
	* @param initialisent les attributs correspondants
	*/
	Dresseur(const std::string& nom, const std::string equipe);
	/**
	* @brief Constructeur de copie
	*/
	Dresseur(const Dresseur& dresseur);
	/**
	* @brief Destructeur
	*/
	~Dresseur();
	/**
	* @return nom_
	*/
	std::string obtenirNom() const;
	/**
	* @param nom nouveau nom
	*/
	void modifierNom(const std::string& nom);
	/**
	* @return la taille du vecteur
	*/
	unsigned int obtenirNombreCreatures() const;
	/**
	* @brief retourne un creature par indice
	* @return pointeur sur la creature
	*/
	Creature* obtenirCreature(int) const;
	/**
	* @brief retourne une creature par nom, si presente
	* @return pointeur sur la creature
	*/
	Creature* obtenirUneCreature(const std::string&) const; 
	/**
	* @brief retourne l'objet magique
	*/
	ObjetMagique obtenirObjetMagique() const;
	/**
	* @brief mutateur objet magique
	*/
	void modifierObjetMagique(const ObjetMagique& objetMagique);
	/**
	* @brief utiliser l'objet sur une creature
	* @param creature cible
	*/
	void utiliserObjetMagique(Creature* creature);
	/**
	* @brief ajout d'une creature
	* @param creature
	* @return true si reussi
	*/
	bool ajouterCreature(Creature* creature);
	/**
	* @brief retirer une creature
	* @param nom le nom de la creature a enlever
	* @return true si reussi
	*/
	bool enleverCreature(const std::string& nom);
	/**
	* @brief affichage
	*/
	friend std::ostream& operator<<(std::ostream&, Dresseur);
	/**
	* @brief comparaison par objet
	*/
	bool operator==(const Dresseur&) const;
	/**
	* @brief comparaison par nom
	*/
	bool operator==(const std::string&) const;
	/**
	* @brief difference
	*/
	bool operator!=(const std::string&) const;
	/**
	* @brief comparaison commutative
	*/
	friend bool operator==(const std::string&, const Dresseur&);
	/**
	* @return equipe_
	*/
	std::string obtenirEquipe() const;
private:
	std::string nom_;
	ObjetMagique objetMagique_;

	std::vector<Creature*> creatures_;
	std::string equipe_;

};

#endif