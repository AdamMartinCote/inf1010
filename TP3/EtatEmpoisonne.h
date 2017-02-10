/**
 * EtatEmpoisonne.h
 *
 * auteurs: Adam Martin-Cote
 * 			Jad Sebti
 *
 * date: 25 octobre 2016
 **/
#ifndef ETAT_EMPOISONNE_H
#define ETAT_EMPOISONNE_H

#include "EtatCreature.h"

class EtatEmpoisonne : public EtatCreature
{
public:
	EtatEmpoisonne(const std::string& nom);

	EtatEmpoisonne(const std::string&, unsigned int duree);

	friend std::ostream& operator<<(std::ostream&, const EtatEmpoisonne&);

	void appliquerEtat(Creature&);

	bool peutAttaquer() const;

	bool estFini() const;

};


#endif // ETAT_EMPOISONNE_H
