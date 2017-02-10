/**
 * EtatEndormi.h
 *
 * auteurs: Adam Martin-Cote
 * 			Jad Sebti
 *
 * date: 25 octobre 2016
 **/
#ifndef ETAT_ENDORMI_H
#define ETAT_ENDORMI_H

#include "EtatCreature.h"

class EtatEndormi : public EtatCreature
{
public:
	EtatEndormi(const std::string& nom);

	EtatEndormi(const std::string&, unsigned int duree);

	friend std::ostream& operator<<(std::ostream&, const EtatCreature&);

	bool peutAttaquer() const;

	void appliquerEtat();

	bool estFini() const;
};


#endif // ETAT_ENDORMI_H
