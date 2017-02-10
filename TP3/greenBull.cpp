#include "GreenBull.h"

GreenBull::GreenBull()
	: ObjetMagique("", 0)
{
}

GreenBull::GreenBull(const std::string& nom, int bonus)
	: ObjetMagique(nom, bonus)
{
}

std::ostream& operator<<(std::ostream& out, const GreenBull& greenBull)
{
	return out << "l'objet " << greenBull.obtenirNom() << " fournit  " << greenBull.obtenirBonus()
	       << " point(s) d'énergie" << std::endl;
}

void GreenBull::utiliserSur(Creature& creature)
{
	if((creature.obtenirEnergieTotale() - creature.obtenirEnergie()) > obtenirBonus())
	{
		creature.modifierEnergie(creature.obtenirEnergie() + obtenirBonus());
	}
	else
	{
		creature.modifierEnergie(creature.obtenirEnergieTotale());
	}
}
