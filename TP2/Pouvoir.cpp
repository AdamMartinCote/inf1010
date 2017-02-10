#include "Pouvoir.h"
using namespace std;

Pouvoir::Pouvoir()
	: nom_(""), nombreDeDegat_(0)
{
}

Pouvoir::Pouvoir(const std::string& nom, 
	unsigned int nombreDeDegat,	unsigned int energieNecessaire):
	nom_(nom), nombreDeDegat_(nombreDeDegat), energieNecessaire_(energieNecessaire)
{
}


Pouvoir::Pouvoir(const Pouvoir& autrePouvoir):
	nom_(autrePouvoir.obtenirNom()),
	nombreDeDegat_(autrePouvoir.obtenirNombreDeDegat()),
	energieNecessaire_(autrePouvoir.obtenirEnergieNecessaire())
{}

Pouvoir::~Pouvoir()
{
}

unsigned int Pouvoir::obtenirEnergieNecessaire() const
{
	return energieNecessaire_;
}

std::string Pouvoir::obtenirNom() const
{
	return nom_;
}

unsigned int Pouvoir::obtenirNombreDeDegat() const
{
	return nombreDeDegat_;
}

void Pouvoir::modifierNombreDeDegat(unsigned int nombreDegat)
{
	nombreDeDegat_ = nombreDegat;
}

void Pouvoir::modifierEnergieNecessarie(unsigned int energieNecessaire)
{
	energieNecessaire_ = energieNecessaire;
}

void Pouvoir::modifierNom(const std::string& nom)
{
	nom_ = nom;
}


void Pouvoir::operator=(const Pouvoir& autrePouvoir)
{
	nom_ = autrePouvoir.obtenirNom();
	nombreDeDegat_ = autrePouvoir.obtenirNombreDeDegat();
	energieNecessaire_ = autrePouvoir.obtenirEnergieNecessaire();
}

bool Pouvoir::operator==(const std::string& nomPouvoir) const
{
	if (nom_ == nomPouvoir) return true;
	else return false;
}

ostream& operator<<(ostream& out, const Pouvoir& pouvoir) {
	return out << pouvoir.obtenirNom() << " possede un nombre de dégats de " << pouvoir.nombreDeDegat_
		<< " et une energie necessaire de " << pouvoir.obtenirEnergieNecessaire() << endl;
}