#include <iostream>
#include <string>
#include "Polyland.h"
using namespace std;

const unsigned int N_DRESSEURS_MAX = 100;
const unsigned int N_CREATURES_MAX = 1000;


Polyland::Polyland()
	: nDresseurs_(0), nCreatures_(0)
{
	tableauDeDresseurs_ = new Dresseur*[N_DRESSEURS_MAX];
	for (int i = 0; i < N_DRESSEURS_MAX; i++)
	{
		tableauDeDresseurs_[i] = nullptr;
	}

	tableauDeCreatures_ = new Creature*[N_CREATURES_MAX];
	for (int i = 0; i < N_CREATURES_MAX; i++)
	{
		tableauDeCreatures_[i] = nullptr;
	}
}

Polyland::~Polyland()
{
	for(int i = 0; i < nDresseurs_; i++)
	{
		delete tableauDeDresseurs_[i];
		tableauDeDresseurs_[i] = nullptr;
	}
	delete[] tableauDeDresseurs_;

	for (int i = 0; i < nCreatures_; i++)
	{
		delete tableauDeCreatures_[i];
		tableauDeCreatures_[i] = nullptr;
	}
	delete []tableauDeCreatures_;
}

void Polyland::ajouterDresseur(Dresseur* dresseur)
{
	// check if name already present
	for(int i = 0; i < nDresseurs_; i++)
	{
		if (tableauDeDresseurs_[i]->obtenirNom() == dresseur->obtenirNom()) return;
	}
	// check if capacity >
	if (nDresseurs_ >= 100) return;
	tableauDeDresseurs_[nDresseurs_] = dresseur;
	nDresseurs_++;
	cout << dresseur->obtenirNom() << " a bien été ajouté !" << endl;
}

bool Polyland::retirerDresseur(const string& nom)
{
	for (int i = 0; i < nDresseurs_; i++)
	{
		if (tableauDeDresseurs_[i]->obtenirNom() == nom)
		{
			tableauDeDresseurs_[i] = nullptr;
			return true;
		}
	}
	return false;
}

void Polyland::ajouterCreature(const Creature& creature)
{	
	for(int i = 0; i < nCreatures_; i++)
	{
		if (tableauDeCreatures_[i]->obtenirNom() == creature.obtenirNom()) return;
	}

	if (nCreatures_ >= 1000) return;
	tableauDeCreatures_[nCreatures_] = new Creature(creature);
	nCreatures_++;
	cout << creature.obtenirNom() << " a bien été ajouté !" << endl;
}

bool Polyland::retirerCreature(const string& nom)
{
	for(int i = 0; i < nCreatures_; i++)
	{
		if (tableauDeCreatures_[i]->obtenirNom() == nom)
		{
			delete tableauDeCreatures_[i];
			tableauDeCreatures_[i] = nullptr;
			return true;
		}
	}
	return false;
}

Dresseur* Polyland::choisirDresseurAleatoire() const
{
	return tableauDeDresseurs_[rand() % nDresseurs_];
}

Creature* Polyland::choisirCreatureAleatoire() const
{
	return tableauDeCreatures_[rand() % nCreatures_];
}

bool Polyland::attraperCreature(Dresseur* dresseur, const Creature& creature)
{
	if (dresseur->obtenirNombreCreatures() == 2) return false;
	for (int i = 0; i < dresseur->obtenirNombreCreatures(); i++)
	{
		if (dresseur->obtenirCreatures()[i]->obtenirNom() == creature.obtenirNom()) return false;
	}
	return dresseur->ajouterCreature(creature);
}

bool Polyland::relacherCreature(Dresseur* dresseur, const string& nomCreature)
{
	for (int i = 0; i < dresseur->obtenirNombreCreatures(); i++)
	{
		if (dresseur->obtenirCreatures()[i]->obtenirNom() == nomCreature)
		{
			dresseur->retirerCreature(nomCreature);
			return true;
		}
	}
	return false;
}

void Polyland::infoDresseur(std::string nom) const
{
	for (int i = 0; i < nDresseurs_; i++)
	{
		if (tableauDeDresseurs_[i] == nullptr) continue;
		else if (tableauDeDresseurs_[i]->obtenirNom() == nom)
		{
			tableauDeDresseurs_[i]->affichage();
			return;
		}
	}
	cout << "Dresseur introuvable!" << endl;
}