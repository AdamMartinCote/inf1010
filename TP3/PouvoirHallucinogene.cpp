#include "PouvoirHallucinogene.h"
#include "EtatConfus.h"

PouvoirHallucinogene::PouvoirHallucinogene(const std::string& nom, unsigned int nombreDeDegat, unsigned int energieNecessaire)
    : Pouvoir(nom, nombreDeDegat, energieNecessaire)
    , duree_(0)
{
	Pouvoir::type_ = TypeEtat_endormi;
}

PouvoirHallucinogene::PouvoirHallucinogene(const std::string& nom, unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree)
    : Pouvoir(nom, nombreDeDegat, energieNecessaire)
    , duree_(duree)
{
	Pouvoir::type_ = TypeEtat_endormi;
}

std::ostream& operator<<(std::ostream& out, const PouvoirHallucinogene& pouvoirHallucinogene)
{
    return out << static_cast<const Pouvoir&>(pouvoirHallucinogene) << "il peut rendre confus la cible" << std::endl;
}

void PouvoirHallucinogene::appliquerEffetOffensif(Creature& creature)
{
    creature.modifierEtat(new EtatConfus("confus", static_cast<unsigned int>(duree_)));
}
