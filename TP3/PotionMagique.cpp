#include "PotionMagique.h"

PotionMagique::PotionMagique()
	: ObjetMagique("", 0)
{
}

PotionMagique::PotionMagique(const std::string& nom, int bonus)
	: ObjetMagique(nom, bonus)
{
}

std::ostream& operator<<(std::ostream& out, const PotionMagique& potionMagique)
{
	return out << "l'objet " << potionMagique.obtenirNom() << "soigne de " << potionMagique.obtenirBonus()
	       << " points de vie" << std::endl;
}

// dépassement du maximum restreint pas la méthode modifierPointDeVie()
void PotionMagique::utiliserSur(Creature& creature) const
{
	if((creature.obtenirPointDeVieTotal() - creature.obtenirPointDeVie()) >= obtenirBonus())
	{
		creature.modifierPointDeVie(creature.obtenirPointDeVie() + obtenirBonus());
	}
	else
	{
		creature.modifierPointDeVie(creature.obtenirPointDeVieTotal());
	}
}
