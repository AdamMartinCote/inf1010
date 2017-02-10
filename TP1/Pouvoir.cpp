#include <iostream>
#include "Pouvoir.h"

using namespace std;

Pouvoir::Pouvoir()
	: nom_(""), nombreDegat_(0), valeurEnergieNecessaire_(0)
{}

Pouvoir::Pouvoir(std::string nom, int nombreDegat, int valeurEnergieNecessaire)
	: nom_(nom), nombreDegat_(nombreDegat), valeurEnergieNecessaire_(valeurEnergieNecessaire)
{}

Pouvoir::Pouvoir(const Pouvoir& autrePouvoir):
	nom_(autrePouvoir.nom_), 
	nombreDegat_(autrePouvoir.nombreDegat_), 
	valeurEnergieNecessaire_(autrePouvoir.valeurEnergieNecessaire_)
{}

Pouvoir::~Pouvoir(){}

string Pouvoir::obtenirNom() const
{
	return nom_;
}

int Pouvoir::obtenirNombreDeDegat() const
{
	return nombreDegat_;
}

int Pouvoir::obtenirValeurEnergieNecessaire() const
{
	return valeurEnergieNecessaire_;
}

void Pouvoir::modifierNom(std::string nom)
{
	nom_ = nom;
}

void Pouvoir::modifierNombreDegat(int nombreDegat)
{
	nombreDegat_ = nombreDegat;
}

void Pouvoir::modifierValeurEnergieNecessaire(int valeurEnergieNecessaire)
{
	valeurEnergieNecessaire_ = valeurEnergieNecessaire;
}

void Pouvoir::description() const
{
	cout << "Nom: " << nom_ << " necessite " << valeurEnergieNecessaire_ 
		<< " mana et inflige " << nombreDegat_ << " degats"<< endl;
}
