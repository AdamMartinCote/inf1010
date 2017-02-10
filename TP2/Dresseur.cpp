#include "Dresseur.h"

using namespace std;


Dresseur::Dresseur() 
	:nom_(""), equipe_("")
{}

Dresseur::Dresseur(const std::string& nom, const std::string equipe)
	:	nom_(nom), equipe_(equipe)
{
	creatures_.reserve(MAX_NOMBRE_CREATURES);
}
Dresseur::Dresseur(const Dresseur& dresseur):
	nom_(dresseur.obtenirNom()), 
	equipe_(dresseur.obtenirEquipe()),
	objetMagique_(dresseur.obtenirObjetMagique())
{
	for(int i = 0; i < dresseur.obtenirNombreCreatures(); i++)
	{
		creatures_.push_back(new Creature(*dresseur.obtenirCreature(i)));
	}
}

Dresseur::~Dresseur()
{
	for (unsigned int i = 0; i < creatures_.size(); i++)
	{
		delete creatures_[i];
		creatures_[i] = nullptr;
	}
}

std::string Dresseur::obtenirNom() const
{
	return nom_;
}

void Dresseur::modifierNom(const std::string& nom)
{
	nom_ = nom;
}

unsigned int Dresseur::obtenirNombreCreatures() const
{
	return creatures_.size();
}

Creature* Dresseur::obtenirCreature(int indice) const
{
	if (indice <= creatures_.size()) return creatures_[indice];
	else return nullptr;
}

Creature* Dresseur::obtenirUneCreature(const string& nomCreature) const 
{
	for (auto i : creatures_)
	{
		if (*i == nomCreature) return i;
	}
	return nullptr;
}


ObjetMagique Dresseur::obtenirObjetMagique() const
{
	return objetMagique_;
}

void Dresseur::modifierObjetMagique(const ObjetMagique & objetMagique)
{
	objetMagique_ = objetMagique;
}

void Dresseur::utiliserObjetMagique(Creature* creature)
{

	if ((creature->obtenirPointDeVieTotal() - creature->obtenirPointDeVie()) >= objetMagique_.obtenirBonus()) {
		creature->modifierPointDeVie(creature->obtenirPointDeVie() + objetMagique_.obtenirBonus());
	}
	else {
		creature->modifierPointDeVie(creature->obtenirPointDeVieTotal());
	}
	if ((creature->obtenirEnergieTotale() - creature->obtenirEnergie()) > objetMagique_.obtenirBonus()) {
		creature->modifierEnergie(creature->obtenirEnergie() + objetMagique_.obtenirBonus());
	}
	else {
		creature->modifierEnergie(creature->obtenirEnergieTotale());
	}
}

bool Dresseur::ajouterCreature(Creature* creature)
{
	if (creatures_.size() <= MAX_NOMBRE_CREATURES) {
		for (unsigned int i = 0; i < creatures_.size(); i++)
		{
			if (creatures_[i]->obtenirNom() == creature->obtenirNom())
				return false;
		}
		creatures_.push_back(new Creature(*creature));
		return true;
	}
	else {
		return false;
	}
}

bool Dresseur::enleverCreature(const std::string& nom) // A MODIFIER... (si necessaire)
{
	for (unsigned int i = 0; i < creatures_.size(); i++)
	{
		if (creatures_[i]->obtenirNom() == nom)
		{
			delete creatures_[i];
			if(i != creatures_.size()-1)
			{
				creatures_[i] = creatures_[creatures_.size() - 1];
			}
			creatures_.pop_back();
			return true;
		}
	}
	return false;
}


// ___TP2___
// surcharge externe:

std::ostream& operator<<(ostream& out, Dresseur dresseur)
{
	return out << dresseur.obtenirNom() << " possede " << dresseur.obtenirNombreCreatures()
		<< " creature(s) et appartient à l'équipe " << dresseur.obtenirEquipe() << std::endl;
}

bool Dresseur::operator==(const Dresseur& autreDresseur) const
{
	if (creatures_.size() != autreDresseur.obtenirNombreCreatures()) return false;
	
	int pairs = 0;
	for (int i = 0; i < obtenirNombreCreatures(); i++)
	{
		for (int j = 0; j < autreDresseur.obtenirNombreCreatures(); j++)
		{
			if (*obtenirCreature(i) == *autreDresseur.obtenirCreature(j)) pairs++;
		}
	}
	if (pairs == obtenirNombreCreatures()) return true;
	else return false;
}

bool Dresseur::operator==(const string& nomDresseur) const
{
	if (nom_ == nomDresseur)
		return true;
	else return false;
}

bool Dresseur::operator!=(const string& nomDresseur) const
{
	if (*this == nomDresseur) return false;
	else return true;
}

bool operator==(const std::string& nomDresseur, const Dresseur& dresseur)
{
	return (dresseur == nomDresseur);
}

std::string Dresseur::obtenirEquipe() const
{
	return equipe_;
}
