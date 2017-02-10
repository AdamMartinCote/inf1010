#include "Elixir.h"

Elixir::Elixir()
    : PotionMagique("", 0)
{
}

Elixir::Elixir(const std::string& nom, int bonus)
    : PotionMagique(nom, bonus)
{
}

std::ostream& operator<<(std::ostream& out, const Elixir& elixir)
{
    return out << "l'objet " << elixir.obtenirNom() << " fournit  " << 2*elixir.obtenirBonus()
               << " point(s) " << std::endl;
}

// dépassement du maximum restreint pas la méthode modifierEnergie()
void Elixir::utiliserSur(Creature& creature)
{
	ObjetMagique::utiliserSur(creature);
	PotionMagique::utiliserSur(creature);
}
