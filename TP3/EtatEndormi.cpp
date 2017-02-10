#include "EtatEndormi.h"

EtatEndormi::EtatEndormi(const std::string& nom)
	: EtatCreature(nom)
{
	type_ = TypeEtat_endormi;
}

EtatEndormi::EtatEndormi(const std::string& nom, unsigned int duree)
	: EtatCreature(nom, duree)
{
	type_ = TypeEtat_endormi;
}

std::ostream& operator<<(std::ostream& out, const EtatEndormi& etatEndormi)
{
	return out << static_cast<EtatCreature>(etatEndormi) << " :Endormi durera " << etatEndormi.obtenirDuree() << std::endl;
}

bool EtatEndormi::peutAttaquer() const
{
	return false;
}

void EtatEndormi::appliquerEtat()
{
	if (duree_ > 0) duree_--;
}

bool EtatEndormi::estFini() const
{
	if (duree_ <= 0) return true;
	else return false;
}