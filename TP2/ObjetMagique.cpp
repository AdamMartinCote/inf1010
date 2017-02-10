#include "ObjetMagique.h"
#include <iostream>

using namespace std;

ObjetMagique::ObjetMagique()
{
}

ObjetMagique::ObjetMagique(const std::string & nom, int bonus):
	nom_(nom), bonus_(bonus)
{
}

ObjetMagique::~ObjetMagique()
{
}

std::string ObjetMagique::obtenirNom() const
{
	return nom_;
}

int ObjetMagique::obtenirBonus() const
{
	return bonus_;
}

void ObjetMagique::modifierNom(const std::string& nom)
{
	nom_ = nom;
}

void ObjetMagique::modifierBonus(int bonus)
{
	bonus_ = bonus;
}

ostream& operator<<(ostream& out, const ObjetMagique& objetMagique)
{
	return out << "l'objet " << objetMagique.obtenirNom() << " fournit un bonus de " << objetMagique.obtenirBonus() << std::endl;
}