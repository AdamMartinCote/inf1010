/*
Fichier: ObjetMagique.h
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification:  6 septembre 2016 par Maude Carrier
Description: La classe ObjetMagique correspond aux differents objets utilisables
			par le dresseur sur ses creatures
*/
#ifndef OBJETMAGIQUE_H
#define OBJETMAGIQUE_H

#include <string>
#include <iostream>

#include "Creature.h"

class Creature;

class ObjetMagique
{
public:

	ObjetMagique();

	ObjetMagique(const std::string &nom, int bonus);

	ObjetMagique(const ObjetMagique& objetMagique);

	~ObjetMagique();

	std::string obtenirNom() const;
	int obtenirBonus() const;

	void modifierNom(const std::string& nom);
	void modifierBonus(int bonus);

	void utiliserSur(Creature& creature) const;

	friend std::ostream& operator<<(std::ostream& os, const ObjetMagique& objet);

protected:
	std::string nom_;
	int bonus_;
};

#endif
