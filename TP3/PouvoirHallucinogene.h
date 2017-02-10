/**
 * PouvoirHallucinogene.h
 *
 * auteurs: Adam Martin-Cote
 * 			Jad Sebti
 *
 * date: 25 octobre 2016
 **/
#ifndef POUVOIR_HALLUCINOGENE_H
#define POUVOIR_HALLUCINOGENE_H

#include <iostream>
#include <string>
#include "Pouvoir.h"

class PouvoirHallucinogene : public Pouvoir
{
public:
	PouvoirHallucinogene(const std::string& nom, unsigned int nombreDeDegat, unsigned int energieNecessaire);
	PouvoirHallucinogene(const std::string& nom, unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree);
	friend std::ostream& operator<<(std::ostream& out, const PouvoirHallucinogene& pouvoirHallucinogene);
	void appliquerEffetOffensif(Creature& creature);

private:
	int duree_;
};

#endif // POUVOIR_HALLUCINOGENE_H
