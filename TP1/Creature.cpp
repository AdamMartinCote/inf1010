#include <cstdlib>
#include <iostream>

#include "Creature.h"

using namespace std;

Creature::Creature() :	
	nom_(""),
	attaque_(0), 
	defense_(0), 
	pointDeVie_(0), 
	pointDeVieTotal_(0), 
	energie_(0), 
	energieTotal_(0),
	experience_(0),
	experienceNecessaire_(0),
	niveau_(0)
{}

Creature::Creature(string nom, int attaque, int defense, int pointDeVie, int energie, Pouvoir pouvoir) :
	nom_(nom),
	attaque_(attaque),
	defense_(defense),
	pointDeVie_(pointDeVie),
	pointDeVieTotal_(pointDeVie),
	energie_(energie),
	energieTotal_(energie),
	experience_(0),
	experienceNecessaire_(100),
	niveau_(1),
	pouvoir_(pouvoir)
{}

Creature::Creature(const Creature& autreCreature):
	nom_(autreCreature.nom_),
	attaque_(autreCreature.attaque_),
	defense_(autreCreature.defense_),
	pointDeVie_(autreCreature.pointDeVieTotal_),
	pointDeVieTotal_(autreCreature.pointDeVieTotal_),
	energie_(autreCreature.energieTotal_),
	energieTotal_(autreCreature.energieTotal_),
	experience_(0),
	experienceNecessaire_(100),
	niveau_(1),
	pouvoir_(autreCreature.pouvoir_)
{
	
}
Creature::~Creature()
{}

// accesseurs:
string Creature::obtenirNom() const
{
	return nom_;
}

int Creature::obtenirValeurAttaque() const
{
	return attaque_;
}

int Creature::obtenirValeurDefense() const
{
	return defense_;
}

int Creature::obtenirPointDeVie() const
{
	return pointDeVie_;
}

int Creature::obtenirPointDeVieTotal() const
{
	return pointDeVieTotal_;
}

int Creature::obtenirEnergie() const
{
	return energie_;
}

int Creature::obtenirEnergieTotale() const
{
	return energieTotal_;
}

int Creature::obtenirExperience() const
{
	return experience_;
}

int Creature::obtenirExperienceNecessaire() const
{
	return experienceNecessaire_;
}

int Creature::obtenirNiveau() const
{
	return niveau_;
}

Pouvoir Creature::obtenirPouvoir() const
{
	return pouvoir_;
}

// mutateurs:
void Creature::modifierNom(const string& nom)
{
	nom_ = nom;
}

void Creature::modifierValeurAttaque(int valeurAttaque)
{
	attaque_ = valeurAttaque;
}

void Creature::modifierValeurDefense(int valeurDefense)
{
	defense_ = valeurDefense;
}

void Creature::modifierPointDeVie(int modif)
{
	pointDeVie_ = modif;
}

void Creature::modifierPointDeVieTotal(int pointDeVieTotal)
{
	pointDeVieTotal_ = pointDeVieTotal;
}

void Creature::modifierEnergie(int energie)
{
	energie_ = energie;
}

void Creature::modifierEnergieTotal(int energieTotal)
{
	energieTotal_ = energieTotal;
}

void Creature::modifierExperience(int experience)
{
	experience_ = experience;
}

void Creature::modifierExperienceNecessaire(int experienceNecessaire)
{
	experienceNecessaire_ = experienceNecessaire;
}

void Creature::modifierNiveau(int niveau)
{
	niveau_ = niveau;
}

void Creature::modifierPouvoir(const Pouvoir& pouvoir)
{
	pouvoir_ = pouvoir;
}

void Creature::attaquer(Creature& creature)
{
	if (!(energie_ > pouvoir_.obtenirValeurEnergieNecessaire() && pointDeVie_ > 0)) return;

	if (creature.obtenirPointDeVie() <= 0)
	{
		cout << "la creature adverse n'a plus de points de vie, lache la crisse" << endl;
	}

	unsigned int degat = (pouvoir_.obtenirNombreDeDegat())* (attaque_ / 2 - creature.defense_);

	int tentative = (rand() % 6) + 1;
	//l'attaque rate une fois sur 6
	if (tentative != 3) {
		cout << nom_ << " lance " << pouvoir_.obtenirNom() << " qui inflige " << degat
			<< " degat a " << creature.obtenirNom() << endl;
		energie_ -= pouvoir_.obtenirValeurEnergieNecessaire();
		creature.modifierPointDeVie(creature.obtenirPointDeVie() - degat);

		if (creature.obtenirPointDeVie() <=0)
		{
			auto xp = experienceGagner(creature);
			cout << nom_ << " a gagné " << xp << " XP" << endl;
			if (creature.obtenirPointDeVie() < 0) creature.modifierPointDeVie(0);
		}
		cout << creature.obtenirNom() << " a encore "
			<< creature.obtenirPointDeVie() << " PV" << endl;
	}
	else {
		// L'attaque a raté
		std::cout << "Attaque " << pouvoir_.obtenirNom() << " a échouée" << endl;
	}

}

int Creature::experienceGagner(const Creature& creature)
{
	if (creature.obtenirPointDeVie() <= 0) {
		//Calcul de l'experience selon une formule mystérieuse
		int experience = (creature.obtenirNiveau() + 1 - niveau_) * ((creature.obtenirValeurAttaque() + 5 -attaque_) *
		 (creature.obtenirValeurDefense() + 3 - defense_)) + (pointDeVie_ / 2);
		if (experience > (experienceNecessaire_ - experience_)) {
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
		else {
			experience_ += experience;
		}
		return experience;
	}
	return 0;
}


void Creature::information() const
{
	cout << nom_ << " a " << attaque_ << " en attaque et " << defense_ << " en defense," << endl;
	cout << "Il a " << pointDeVie_ << "/" << pointDeVieTotal_ << " PV et "
		<< energie_ << "/" << energieTotal_ << " Energie" << endl;
	cout << "Il est au niveau " << niveau_ << " avec " << experience_ << "d'XP" << endl;
	cout << "Il lui manque " << experienceNecessaire_-experience_ << " jusqu'au prochain niveau" << endl;
	cout << "Son pouvoir est : ";
	pouvoir_.description();
}