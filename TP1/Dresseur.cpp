/*
Fichier: Dresseur.h
Auteur(s): 
Date de creation: 14 septembre 2016
Date de modification: 
Description: 
*/
#include <iostream>
#include "Dresseur.h"

const int NOMBRE_MAX_CREATURES = 2;

using namespace std;

Dresseur::Dresseur()
	: nom_(""), nombreCreatures_(0), nombreCreaturesMax_(NOMBRE_MAX_CREATURES), objetMagique_()
{
	creatures_ = new Creature*[NOMBRE_MAX_CREATURES];
	for (int i = 0; i < NOMBRE_MAX_CREATURES; i++)
	{
		creatures_[i] = nullptr;
	}
}

Dresseur::Dresseur(const std::string& nom)
	: nom_(nom), nombreCreatures_(0), nombreCreaturesMax_(NOMBRE_MAX_CREATURES), objetMagique_()
{
	creatures_ = new Creature*[NOMBRE_MAX_CREATURES];
	for (int i = 0; i < NOMBRE_MAX_CREATURES; i++)
	{
		creatures_[i] = nullptr;
	}
}

Dresseur::~Dresseur()
{
	for(auto i = 0; i < nombreCreatures_; i++)
	{
		delete creatures_[i];
	}
	delete creatures_;
}

string Dresseur::obtenirNom() const
{
	return nom_;
}

void Dresseur::modifierNom(const std::string& nom)
{
	nom_ = nom;
}

ObjetMagique Dresseur::obtenirObjetMagique() const
{
	return objetMagique_;
}

void Dresseur::modifierObjetMagique(const ObjetMagique& objetMagique)
{
	objetMagique_ = objetMagique;
}
	 
void Dresseur::utiliserObjetMagique(Creature* creature)
{
	// augmente PV
	if ((creature->obtenirPointDeVie() + objetMagique_.obtenirBonus()) > creature->obtenirPointDeVieTotal())
		creature->modifierPointDeVie(creature->obtenirPointDeVieTotal());
	else if ((creature->obtenirPointDeVie() + objetMagique_.obtenirBonus()) < creature->obtenirPointDeVieTotal())
		creature->modifierPointDeVie(creature->obtenirPointDeVie() + objetMagique_.obtenirBonus());

	// augmente E
	if ((creature->obtenirEnergie() + objetMagique_.obtenirBonus()) > creature->obtenirEnergieTotale())
		creature->modifierEnergie(creature->obtenirEnergieTotale());
	else if ((creature->obtenirEnergie() + objetMagique_.obtenirBonus()) > creature->obtenirEnergieTotale())
		creature->modifierEnergie(objetMagique_.obtenirBonus());
}



unsigned int Dresseur::obtenirNombreCreatures() const
{
	return nombreCreatures_;
}

Creature** Dresseur::obtenirCreatures()
{
	return creatures_;
}

void Dresseur::modifierCreature(Creature** creatures)
{
	creatures_ = creatures;
}

bool Dresseur::ajouterCreature(const Creature& creature)
{
	for (int i = 0; i < nombreCreatures_; i++)
	{
		if (creatures_[i]->obtenirNom() == creature.obtenirNom())
			return false;
	}

	if(nombreCreatures_ == nombreCreaturesMax_)
	{
		nombreCreaturesMax_ *= 2;
		Creature** tmp = creatures_;
		creatures_ = new Creature*[nombreCreaturesMax_];
		for(int i = 0; i < nombreCreatures_; i++)
		{
			creatures_[i] = new Creature(*tmp[i]);
		}
	}
	creatures_[nombreCreatures_] = new Creature(creature);	
	nombreCreatures_++;
	return true;
}

bool Dresseur::retirerCreature(const std::string& nom)
{
	for (int i = 0; i < nombreCreatures_; i++)
	{
		if (creatures_[i]->obtenirNom() == nom) {
			delete creatures_[i];
			creatures_[i] = nullptr;
			nombreCreatures_--;
			return true;
		}	
	}
	return false;
}

void Dresseur::affichage() const
{
	cout << "Informations sur le dresseur:" << endl;
	cout << nom_ << " possede " << nombreCreatures_ << " creature(s)" << endl;
	for (int i = 0; i < nombreCreatures_; i++)
	{
		if (creatures_[i] == nullptr) continue;
		cout << "- " << i + 1 << " - ";
		creatures_[i]->information();
		cout << endl;
	}
}
