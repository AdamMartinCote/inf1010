
#include "EtatEmpoisonne.h"

EtatEmpoisonne::EtatEmpoisonne(const std::string& nom)
	: EtatCreature(nom)
{
	type_ = TypeEtat_empoisonne;
}

EtatEmpoisonne::EtatEmpoisonne(const std::string& nom, unsigned int duree)
	: EtatCreature(nom, duree)
{
	type_ = TypeEtat_empoisonne;
}

std::ostream& operator<<(std::ostream& out, const EtatEmpoisonne& etatEmpoisonne)
{
	return out << static_cast<EtatCreature>(etatEmpoisonne) << " :Empoisonne durera " << etatEmpoisonne.obtenirDuree() << std::endl;
}

void EtatEmpoisonne::appliquerEtat(Creature& creature)
{
	duree_--;
	creature.modifierPointDeVie(creature.obtenirPointDeVie() - 5);
}

bool EtatEmpoisonne::peutAttaquer() const
{
	return true;
}

bool EtatEmpoisonne::estFini() const
{
	if (duree_ <= 0) return true;
	else return false;
}