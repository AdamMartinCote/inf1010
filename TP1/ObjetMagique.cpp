#include <iostream>
#include <string>
#include "ObjetMagique.h"
using namespace std;

ObjetMagique::ObjetMagique()
	: nom_(""), bonus_(0)
{}

ObjetMagique::ObjetMagique(string nom, int bonus)
	:nom_(nom), bonus_(bonus)
{}

ObjetMagique::~ObjetMagique()
{}

std::string ObjetMagique::obtenirNom() const
{
	return nom_;
}

int ObjetMagique::obtenirBonus() const
{
	return bonus_;
}

void ObjetMagique::modifierNom(string nom)
{
	nom_ = nom;
}

void ObjetMagique::modifierBonus(int bonus)
{
	bonus_ = bonus;
}

void ObjetMagique::affichage() const
{
	cout << "l'objet " << nom_ << " fourni un bonus de " << bonus_ << endl;
}