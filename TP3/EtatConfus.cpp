
#include "EtatConfus.h"

EtatConfus::EtatConfus(const std::string& nom)
	: EtatCreature(nom)
{
	type_ = TypeEtat_confus;
}

EtatConfus::EtatConfus(const std::string& nom, unsigned int duree)
	: EtatCreature(nom, duree)
{
	type_ = TypeEtat_confus;
}

std::ostream& operator<<(std::ostream& out, const EtatConfus& etatConfus)
{
	return out << static_cast<EtatCreature>(etatConfus) << " :folie durera " << etatConfus.obtenirDuree() << std::endl;
}

bool EtatConfus::peutAttaquer() const
{
	return (rand() % 2 == 0); 
}

void EtatConfus::appliquerEtat(Creature& creature)
{
	if (rand() % 3 == 0)
	{
		if (creature.obtenirPointDeVieTotal() > 100)
			creature.modifierPointDeVie(creature.obtenirPointDeVie() * 0.95);
		else creature.modifierPointDeVie(creature.obtenirPointDeVie() - 5);
	}
	duree_--;
}

bool EtatConfus::estFini()
{
	if (duree_ == 0) return true;
	if (rand() % 3 == 0)return true;
	return false;
}
