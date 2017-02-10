#include <algorithm>
#include "AttaqueMagique.h"

AttaqueMagique::AttaqueMagique(int duree)
	: duree_(duree)
{
}

AttaqueMagique::~AttaqueMagique()
{
}

int AttaqueMagique::obtenirDuree() const
{
	return duree_;
}

void AttaqueMagique::modifierDuree(int nouvelleDuree)
{
	duree_ = nouvelleDuree;
}

//	http://en.cppreference.com/w/cpp/language/typeid
std::string AttaqueMagique::obtenirTypeAttaque() const
{
	return typeid(*this).name();
}

std::ostream& operator<<(std::ostream& out, const AttaqueMagique& attaqueMagique)
{
	std::string nomAttaque = attaqueMagique.obtenirTypeAttaque();
	// effacer les caractères numérique de la string
	// sinon on a "23AttaqueMagiquePoison"
	nomAttaque.erase(std::remove_if(nomAttaque.begin(), nomAttaque.end(), &isdigit), nomAttaque.end());

	return out << " " << nomAttaque << " qui a une duree de " << attaqueMagique.obtenirDuree() << std::endl;
}
