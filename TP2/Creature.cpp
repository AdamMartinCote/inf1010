#include "Creature.h"

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;


Creature::Creature():nom_(""), attaque_(0), defense_(0), pointDeVie_(0),
	energie_(0), experience_(0), niveau_(1)
{
	energieTotal_ = 0;
	experienceNecessaire_ = 0;
	pointDeVieTotal_ = 0;
}

Creature::Creature(const string& nom, unsigned int attaque,
	unsigned int defense, unsigned int pointDeVie, unsigned int energie):
	nom_(nom), attaque_(attaque), defense_(defense), pointDeVie_(pointDeVie),
	energie_(energie), experience_(0), niveau_(1)
{
	energieTotal_ = energie;
	experienceNecessaire_ = 100;
	pointDeVieTotal_ = pointDeVie;
}

Creature::Creature(const Creature& autreCreature) :
	nom_(autreCreature.obtenirNom()),
	attaque_(autreCreature.obtenirAttaque()),
	defense_(autreCreature.obtenirDefense()),
	pointDeVie_(autreCreature.obtenirPointDeVie()),
	energie_(autreCreature.obtenirEnergie()),
	experience_(autreCreature.obtenirExperience()),
	niveau_(autreCreature.obtenirNiveau()),
	energieTotal_(autreCreature.obtenirEnergieTotale()),
	experienceNecessaire_(autreCreature.obtenirExperienceNecessaire()),
	pointDeVieTotal_(autreCreature.obtenirPointDeVieTotal())
{
	for (int i = 0; i < autreCreature.obtenirPouvoirs().size(); i++)
	{
		pouvoir_.push_back(new Pouvoir(*autreCreature.obtenirPouvoirs()[i]));
	}
}


Creature::~Creature()
{
	for (auto i : pouvoir_)
	{
		delete i;
		i = nullptr;
	}
}

string Creature::obtenirNom() const
{
	return nom_;
}

unsigned int Creature::obtenirAttaque() const
{
	return attaque_;
}

unsigned int Creature::obtenirDefense() const
{
	return defense_;
}

unsigned int Creature::obtenirPointDeVie() const
{
	return pointDeVie_;
}

unsigned int Creature::obtenirPointDeVieTotal() const
{
	return pointDeVieTotal_;
}

unsigned int Creature::obtenirEnergie() const
{
	return energie_;
}

unsigned int Creature::obtenirEnergieTotale() const
{
	return energieTotal_;
}

unsigned int Creature::obtenirExperience() const
{
	return experience_;
}

unsigned int Creature::obtenirExperienceNecessaire() const
{
	return experienceNecessaire_;
}

unsigned int Creature::obtenirNiveau() const
{
	return niveau_;
}

vector<Pouvoir*> Creature::obtenirPouvoirs() const
{
	return pouvoir_;
}


void Creature::attaquer(Pouvoir& pouvoir,  Creature& creature)
{
	bool possedeLePouvoir = false;
	for(auto i : pouvoir_)
	{
		if (*i == pouvoir.obtenirNom()) possedeLePouvoir = true;
		break;
	}
	if(possedeLePouvoir)
	{
		if(energie_ >= pouvoir.obtenirEnergieNecessaire())
		{
			if (creature.obtenirPointDeVie() > 0)
			{
				//Calcul du nombre de degat selon une formule 
				unsigned int degat = (pouvoir.obtenirNombreDeDegat())* (attaque_ / 2 - creature.defense_);

				// ajout: overflow de degat possible si defense est grand:
				if (degat > 1000000000) degat = 0;

				int tentative = rand() % 6;
				//l'attaque rate une fois sur 6
				if (tentative != 3) {
					cout << nom_ << " lance " << pouvoir.obtenirNom() << " qui inflige " << degat << " degat a " << creature.obtenirNom() << endl;
					if (degat > creature.obtenirPointDeVie()) {
						creature.modifierPointDeVie(0);
						int xp = experienceGagnee(creature);
						cout << nom_ << " a gagné " << xp << " XP" << endl;
					}
					else
						creature.modifierPointDeVie(creature.obtenirPointDeVie() - degat);
					cout << creature.obtenirNom() << " a encore " << creature.obtenirPointDeVie() << " PV" << endl;
					energie_ -= pouvoir.obtenirEnergieNecessaire();
				}
				else {
					cout << "Attaque " << pouvoir.obtenirNom() << " a échouée" << endl;
				}
			}
			else
				cout << "Vous deja avez vaincu " << creature.obtenirNom() << endl;
		}

	}
	else
	{
		cout << this->nom_ << " n'a pas ce pouvoir! " << endl;
	}
}

int Creature::experienceGagnee(const Creature& creature)
{
	if (creature.obtenirPointDeVie() <= 0) 
    {
		//Calcul de l'experience selon une formule mystérieuse
		int experience = (creature.obtenirNiveau() + 1 - niveau_) * ((creature.obtenirAttaque() + 5 - attaque_) * (creature.obtenirDefense() + 3 - defense_)) + (pointDeVie_ / 2);
		if (experience > (experienceNecessaire_ - experience_)) 
        {
			//Cas ou la creature va monter d'un niveau
			int experienceRestante = experience - (experienceNecessaire_ - experience_);
			niveau_++;
			attaque_ += 1;
			defense_ += 1;
			pointDeVie_ += 5;
			energie_ += 5;
			energieTotal_ += 5;
			pointDeVieTotal_ += 5;
			experience_ = experienceRestante;
			experienceNecessaire_ = experienceNecessaire_ * 15 / 10;
		}
		else 
        {
			//Sinon elle recupère juste de l'expérience
			experience_ += experience;
		}
		return experience;
	}
	return 0;
}

void Creature::modifierAttaque(unsigned int attaque)
{
	attaque_ = attaque;
}

void Creature::modifierDefense(unsigned int defense)
{
	defense_ = defense;
}

void Creature::modifierPointDeVie(unsigned int pointDeVie)
{
	pointDeVie_ = pointDeVie;
}

void Creature::modifierEnergie(unsigned int energie)
{
	energie_ = energie;
}

void Creature::modifierExperience(unsigned int experience)
{
	experience_ = experience;
}

void Creature::modifierNiveau(unsigned int niveau)
{
	niveau_ = niveau;
}

// _______TP2________
void Creature::modifierNom(string nom)
{
	nom_ = nom;
}

void Creature::operator=(const Creature& autreCreature)
{
	nom_ = (autreCreature.obtenirNom());
	attaque_ = (autreCreature.obtenirAttaque());
	defense_ = (autreCreature.obtenirDefense());
	pointDeVie_ = (autreCreature.obtenirPointDeVie());
	energie_ = (autreCreature.obtenirEnergie());
	experience_ = (autreCreature.obtenirExperience());
	niveau_ = (autreCreature.obtenirNiveau());
	energieTotal_ =(autreCreature.obtenirEnergieTotale());
	experienceNecessaire_ =(autreCreature.obtenirExperienceNecessaire());
	pointDeVieTotal_ =(autreCreature.obtenirPointDeVieTotal());
}

void Creature::apprendrePouvoir(const Pouvoir& nouveauPouvoir)
{
	pouvoir_.push_back(new Pouvoir(nouveauPouvoir));
}

bool Creature::oublierPouvoir(const string& nomPouvoir)
{
	for(auto i : pouvoir_)
	{
		if (*i == nomPouvoir)
		{
			delete i;
			i = pouvoir_[pouvoir_.size()];
			pouvoir_.pop_back();
			pouvoir_.resize(pouvoir_.size() - 1);
			cout << "Le pouvoir " << nomPouvoir << " a bien ete retire." << endl;
			return true;
		}
	}
	cout << "Le pouvoir " << nomPouvoir << " n'a pas ete retire." << endl;
	return false;
}

bool Creature::oublierPouvoir(Pouvoir* pouvoir)
{
	for (auto i : pouvoir_)
	{
		if (*i == pouvoir->obtenirNom())
		{
			if (pouvoir_.size() > 1)
			{
				delete i;
				i = pouvoir_[pouvoir_.size() - 1];

			}
			pouvoir_.pop_back();
			cout << "Le pouvoir " << pouvoir->obtenirNom() << " a bien ete retire." << endl;
			return true;
		}
	}
	cout << "Le pouvoir " << pouvoir->obtenirNom() << " n'a pas ete retire." << endl;
	return false;

}

bool Creature::operator==(const Creature& autreCreature) const
{
	if (
		nom_ == autreCreature.obtenirNom() &&
		attaque_ == autreCreature.obtenirAttaque() &&
		defense_ == autreCreature.obtenirDefense() &&
		pointDeVie_ == autreCreature.obtenirPointDeVie() &&
		energie_ == autreCreature.obtenirEnergie() &&
		experience_ == autreCreature.obtenirExperience() &&
		niveau_ == autreCreature.obtenirNiveau() &&
		energieTotal_ == autreCreature.obtenirEnergieTotale() &&
		experienceNecessaire_ == autreCreature.obtenirExperienceNecessaire() &&
		pointDeVieTotal_ == autreCreature.obtenirPointDeVieTotal()
	)return true;
	
	else return false;
}

bool Creature::operator==(const string& nomCreature)const
{
	if (nom_ == nomCreature) return true;
	else return false;
}

bool operator==(const string nomCreature, const Creature& creature)
{
	return (creature == nomCreature);
}

ostream& operator<<(ostream& out, const Creature& creature) 
{
	out << creature.obtenirNom() << " a " << creature.obtenirAttaque()
		<< " en attaque et " << creature.obtenirDefense() << " en defense, " << endl
		<< "Il a " << creature.obtenirPointDeVie() << "/"
		<< creature.obtenirPointDeVieTotal() << " PV et "
		<< creature.obtenirEnergie() << "/" << creature.obtenirEnergieTotale() << " Energie" << endl
		<< "Il est au niveau " << creature.obtenirNiveau() << " avec "
		<< creature.obtenirExperience() << "d'XP" << endl
		<< "Il lui manque " << creature.obtenirExperienceNecessaire() - creature.obtenirExperience()
		<< " jusqu'au prochain niveau " << endl
		<< "Pouvoirs : " << endl;
	if (creature.obtenirPouvoirs().size() > 0)
		for (auto i : creature.obtenirPouvoirs()) out << *i;
	else out << creature.obtenirNom() << " ne connait aucun pouvoir" << endl;
	out << endl;
	return out;
}