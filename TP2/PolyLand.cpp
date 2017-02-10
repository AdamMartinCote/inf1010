#include "PolyLand.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

PolyLand::PolyLand() 
{}

PolyLand::~PolyLand()
{
	for (auto i : creatures_) delete i;
}

bool PolyLand::ajouterDresseur(Dresseur* dresseur)
{
	if (dresseurs_.size() >= MAX_DRESSEURS) return false;

	for (auto i : dresseurs_) if (*i == dresseur->obtenirNom()) return false;

	dresseurs_.push_back(dresseur);
	cout << dresseur->obtenirNom() << " a bien été ajouté !" << endl;
	return true;
}

bool PolyLand::ajouterCreature(const Creature& creature)
{
	if(creatures_.size() >= MAX_CREATURES) return false;

	for (auto i : creatures_) if (*i == creature.obtenirNom()) return false;

	creatures_.push_back(new Creature(creature));
	cout << creature.obtenirNom() << " a bien été ajouté !" << std::endl;
	return true;
}

bool PolyLand::retirerDresseur(const string& nom)
{
	for (auto i : dresseurs_) {
		if (*i == nom)
		{
			i = nullptr;
			return true;
		}
	}
	return false;
}

bool PolyLand::retirerCreature(const string& nom) 
{
	for(auto i : creatures_)
	{
		if (*i == nom)
		{
			delete i;
			i = nullptr;
			return true;
		}
	}
	return false;
}

Dresseur* PolyLand::choisirDresseurAleatoire() 
{
	if (dresseurs_.size() > 0) 
    {
		unsigned int indice = rand() % dresseurs_.size();
		return dresseurs_[indice];
	}
	else 
    {
		return nullptr;
	}
}

Creature* PolyLand::choisirCreatureAleatoire()
{
	if (creatures_.size() > 0) 
    {
		unsigned int indice = rand() % creatures_.size();
		return creatures_[indice];
	}
	else {
		return nullptr;
	}
}

bool PolyLand::attraperCreature(Dresseur* dresseur, Creature* creature)
{
	return dresseur->ajouterCreature(creature);
}

bool PolyLand::relacherCreature(Dresseur* dresseur, const std::string& nomCreature)
{
	return dresseur->enleverCreature(nomCreature);
}

void PolyLand::infoDresseur(const string& nom) const
{
	Dresseur* dresseur = nullptr;
	for (unsigned int i = 0; i < dresseurs_.size(); i++)
	{
		if (dresseurs_[i]->obtenirNom() == nom)
		{
			dresseur = dresseurs_[i];
			break;
		}
	}
	if (dresseur != nullptr)
	{
		std::cout << "Informations sur le dresseur: " << std::endl;
		cout << dresseur;
		for (unsigned int i = 0; i < dresseur->obtenirNombreCreatures(); i++)
		{
			std::cout << "- " << i + 1 << " - ";
			cout << dresseur->obtenirCreature(i);
		}
	}
	else
	{
		std::cout << "Dresseur introuvable!" << std::endl;
	}
}

PolyLand& PolyLand::operator+=(Dresseur* dresseur)
{
	PolyLand::ajouterDresseur(dresseur);
	return *this;
}

PolyLand& PolyLand::operator-=(Dresseur* dresseur)
{
	PolyLand::retirerDresseur(dresseur->obtenirNom());
	return *this;
}

PolyLand& PolyLand::operator+=(const Creature& creature)
{
	PolyLand::ajouterCreature(creature);
	return *this;
}

PolyLand& PolyLand::operator-=(Creature& creature)
{
	PolyLand::retirerCreature(creature.obtenirNom());
	return *this;
}

std::ostream& operator<<(std::ostream& out, const PolyLand& polyland)
{
	for (auto i : polyland.dresseurs_)
	{
		out << *i;
	}
	return out;
}