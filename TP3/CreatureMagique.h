/**
 * CreatureMagique.h
 *
 * auteurs: Adam Martin-Cote
 * 			Jad Sebti
 *
 * date: 25 octobre 2016
 **/
#ifndef CREATURE_MAGIQUE_H
#define CREATURE_MAGIQUE_H

#include <iostream>
#include "Creature.h"

class CreatureMagique : public Creature
{
public:
	CreatureMagique(const std::string& nom,
	                unsigned int attaque,
	                unsigned int defense,
	                unsigned int pointDeVie,
	                unsigned int energie,
	                int bonus);
	~CreatureMagique();

	CreatureMagique(const CreatureMagique& creatureMagique);

	void operator=(const CreatureMagique& creatureMagique);

	friend std::ostream& operator<<(std::ostream& out, const CreatureMagique& creatureMagique);

	void attaquer(const Pouvoir& pouvoir, Creature& creature);

private:
	int bonus_;
};

#endif // CREATURE_MAGIQUE_H
