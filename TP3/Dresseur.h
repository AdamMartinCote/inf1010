/*
Fichier: Dresseur.h
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification:  6 septembre 2016 par Maude Carrier
Description: les dresseurs sont les etres capables d'attraper des creatures
*/
#ifndef DRESSEUR_H
#define DRESSEUR_H

#include <string>
#include "Creature.h"
#include <iostream>
#include <vector>

class Dresseur
{
public:
	/**
	 * Constructeur par defaut
	 **/
	Dresseur();
	/**
	 * Constructeur par parametre
	 **/
	Dresseur(const std::string& nom, const std::string& equipe);
	/**
	 * Constructeur de copie
	 **/
	Dresseur(const Dresseur& dresseur);
	/**
	 * Destructeur
	 **/
	~Dresseur();
	/**
	 * accesseur de l'attribut nom
	 *
	 **/
	std::string obtenirNom() const;
	/**
	 * modificateur de l'attribut nom
	 * @param nom nouveau nom a attribuer
	 **/
	void modifierNom(const std::string& nom);
	/**
	 * obtenirNombreCreatures
	 * @return la taille du vecteur de creatures
	 **/
	unsigned int obtenirNombreCreatures() const;
	/**
	 * obtenir creatures
	 * @return le vecteur de creature en entier
	 **/
	std::vector<Creature*> obtenirCreatures() const;
	/**
	 * Methode d'acces d'une creature du vecteur
	 * @param nom de la creature a rechercher
	 * @return pointeur vers la creature
	 **/
	Creature* obtenirUneCreature(const std::string& nom) const;
	/**
	 * modificateur de creatures
	 * @param creature un nouveau vector
	 **/
	void modifierCreature(std::vector<Creature*> creatures);
	/**
	 * ajout d'une creature
	 * @param creature un pointeur
	 **/
	bool ajouterCreature(Creature* creature);
	/**
	 * enleve une creature par nom
	 * @param nom
	 **/
	bool enleverCreature(const std::string& nom);
	/**
	 * Accesseur de l'objet magique
	 **/
	ObjetMagique obtenirObjetMagique() const;
	/**
	 * modificateur de l'objetMagique
	 * @param objetMagique a copier
	 **/
	void modifierObjetMagique(const ObjetMagique& objetMagique);
	/**
	 * utilise l'objetMagique sur une creature et DESALLOUE la mémoire associé
	 * @param creature la cible
	 **/
	void utiliserObjetMagique(Creature* creature);
	/**
	 * accesseur du nom d'équipe
	 **/
	std::string obtenirEquipe() const;
	/**
	 * modificateur du nom d'équipe
	 **/
	void modifierEquipe(const std::string& equipe);
	/**
	 * méthode externe pour l'affichage des Dresseurs
	 **/
	friend std::ostream& operator<<(std::ostream& os, const Dresseur& dresseur);
	/**
	 * opérateur de comparaison avec un autre dresseur
	 **/
	bool operator==(const Dresseur& dresseur) const;
	/**
	 * opérateur de comparaison par nom
	 **/
	bool operator==(const std::string& nom) const;
	/**
	 * opérateur de comparaison (commutativité)
	 **/
	friend bool operator==(const std::string& nom, const Dresseur& dresseur);
	/**
	 * opérateur d'assignation
	 **/
	Dresseur& operator=(const Dresseur& dresseur);

private:
	std::string nom_;
	std::vector<Creature*> creatures_;
	std::string equipe_;
	ObjetMagique* objetMagique_;
};

#endif
