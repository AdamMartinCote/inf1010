/**
 * PouvoirPoison.h
 *
 * auteurs: Adam Martin-Cote
 * 			Jad Sebti
 *
 * date: 25 octobre 2016
 **/
#ifndef POUVOIR_POISON_H
#define POUVOIR_POISON_H

#include <iostream>
#include <string>
#include "Pouvoir.h"

class PouvoirPoison : public Pouvoir
{
public:
	PouvoirPoison(const std::string& nom, unsigned int nombreDeDegat, unsigned int energieNecessaire);
	PouvoirPoison(const std::string& nom, unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree);
	friend std::ostream& operator<<(std::ostream& out, const PouvoirPoison&);
	void appliquerEffetOffensif(Creature& creature);

private:
	int duree_;
};

#endif // POUVOIR_POISON_H
