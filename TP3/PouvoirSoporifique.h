/**
 * PouvoirSoporifique.h
 *
 * auteurs: Adam Martin-Cote
 * 			Jad Sebti
 *
 * date: 25 octobre 2016
 **/
#ifndef POUVOIR_SOPORIFIQUE_H
#define POUVOIR_SOPORIFIQUE_H

#include <iostream>
#include <string>
#include "Pouvoir.h"

class PouvoirSoporifique : public Pouvoir
{
public:
	PouvoirSoporifique(const std::string& nom, unsigned int nombreDeDegat, unsigned int energieNecessaire);
	PouvoirSoporifique(const std::string& nom, unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree);
	friend std::ostream& operator<<(std::ostream& out, const PouvoirSoporifique& pouvoirSoporifique);
	void appliquerEffetOffensif(Creature& creature);

private:
	int duree_;
};

#endif // POUVOIR_SOPORIFIQUE_H
