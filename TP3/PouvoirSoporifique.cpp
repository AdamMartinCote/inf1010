
#include "PouvoirSoporifique.h"
#include "EtatEndormi.h"

PouvoirSoporifique::PouvoirSoporifique(const std::string& nom, unsigned int nombreDeDegat, unsigned int energieNecessaire)
	: Pouvoir(nom, nombreDeDegat, energieNecessaire)
	, duree_(0)
{
	Pouvoir::type_ = TypeEtat_endormi;
}

PouvoirSoporifique::PouvoirSoporifique(const std::string& nom, unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree)
	: Pouvoir(nom, nombreDeDegat, energieNecessaire)
	, duree_(duree)
{
	Pouvoir::type_ = TypeEtat_endormi;
}

std::ostream& operator<<(std::ostream& out, const PouvoirSoporifique& pouvoirSoporifique)
{
	return out << static_cast<const Pouvoir&>(pouvoirSoporifique)<< "il peut endormir la cible" << std::endl;
}

void PouvoirSoporifique::appliquerEffetOffensif(Creature& creature)
{
	creature.modifierEtat(new EtatEndormi("endormi as fuck", static_cast<unsigned int>(duree_)));
}
