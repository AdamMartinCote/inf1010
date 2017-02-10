/**
 * EtatConfus.h
 *
 * auteurs: Adam Martin-Cote
 * 			Jad Sebti
 *
 * date: 25 octobre 2016
 **/
#ifndef ETAT_CONFUS_H
#define ETAT_CONFUS_H

#include "EtatCreature.h"
#include "TypeEtat.h"

class EtatConfus : public EtatCreature
{
public:

	EtatConfus(const std::string& nom);

	EtatConfus(const std::string&, unsigned int duree);

	friend std::ostream& operator<<(std::ostream&, const EtatConfus&);

	bool peutAttaquer() const;

	void appliquerEtat(Creature& creature);

	bool estFini();
};


#endif // ETAT_CONFUS_H
