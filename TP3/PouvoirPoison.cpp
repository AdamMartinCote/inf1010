

#include "PouvoirPoison.h"
#include "EtatEmpoisonne.h"

PouvoirPoison::PouvoirPoison(const std::string& nom, unsigned int nombreDeDegat, unsigned int energieNecessaire)
	: Pouvoir(nom, nombreDeDegat, energieNecessaire)
	, duree_(0)
{
	Pouvoir::type_ = TypeEtat_empoisonne;
}

PouvoirPoison::PouvoirPoison(const std::string& nom, unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree)
	: Pouvoir(nom, nombreDeDegat, energieNecessaire)
	, duree_(duree)
{
	Pouvoir::type_ = TypeEtat_empoisonne;
}

std::ostream& operator<<(std::ostream& out, const PouvoirPoison& pouvoirPoison)
{
	return out << static_cast<const Pouvoir&>(pouvoirPoison)<< "il peut empoisonner la cible" << std::endl;
}

void PouvoirPoison::appliquerEffetOffensif(Creature& creature)
{
	creature.modifierEtat(new EtatEmpoisonne("Empoisonne", static_cast<unsigned int>(duree_)));
}
