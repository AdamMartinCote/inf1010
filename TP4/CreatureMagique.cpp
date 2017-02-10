#include "CreatureMagique.h"
#include "AttaqueMagiquePoison.h"
#include "AttaqueMagiqueConfusion.h"

CreatureMagique::CreatureMagique()
	: Creature()
	, bonus_(0)
{
	attaqueMagique_ = nullptr;
}

CreatureMagique::CreatureMagique(const Creature& creature, int bonus)
	: Creature(creature)
	, bonus_(bonus)
{
	attaqueMagique_ = nullptr;
}

CreatureMagique::CreatureMagique(const CreatureMagique& creatureMagique)
	:Creature(creatureMagique), bonus_(creatureMagique.bonus_)
{
	// detecte la nature réelle de l'attaque magique à copier et alloue un objet de la
	// classe correspondante
	delete attaqueMagique_;
	if(creatureMagique.attaqueMagique_->obtenirTypeAttaque() == "AttaqueMagiquePoison")
		attaqueMagique_ = new AttaqueMagiquePoison();
	else if(creatureMagique.attaqueMagique_->obtenirTypeAttaque() == "AttaqueMagiqueConfusion")
		attaqueMagique_ = new AttaqueMagiqueConfusion();
	else
	{
		attaqueMagique_ = nullptr;
		std::cout << "**DEBUG** allocation d'attaqueMagique a " << this->obtenirNom() << " a echoue." << std::endl;
	}
}


CreatureMagique::~CreatureMagique()
{
	if(attaqueMagique_ != nullptr) {
		delete attaqueMagique_;
		attaqueMagique_ = nullptr;
	}
}



CreatureMagique& CreatureMagique::operator=(const CreatureMagique& creatureMagique)
{
	static_cast<Creature>(*this) = creatureMagique;
	bonus_ = creatureMagique.bonus_;
	return (*this);
}

void CreatureMagique::attaquer(const Pouvoir& pouvoir,Creature& creature)
{
	(bonus_ + pointDeVie_ > pointDeVieTotal_) ? (pointDeVie_ = pointDeVieTotal_) : (pointDeVie_ += bonus_);
	attaqueMagique_->appliquerAttaque(creature);
	Creature::attaquer(pouvoir, creature);
}


void CreatureMagique::apprendreAttaqueMagique(AttaqueMagique& attaqueMagique)
{
	delete attaqueMagique_;

	// determine la nature de l'attaque magique pour allouer la bonne classe
	if(attaqueMagique.obtenirTypeAttaque() == typeid(AttaqueMagiquePoison).name())
	{
		attaqueMagique_ = new AttaqueMagiquePoison(attaqueMagique);
	}
	else if(attaqueMagique.obtenirTypeAttaque() == typeid(AttaqueMagiqueConfusion).name())
	{
		attaqueMagique_ = new AttaqueMagiqueConfusion(attaqueMagique);
	}
	else
	{
		attaqueMagique_ = nullptr;
		// Ne devrait jamais s'executer
		std::cout << "**DEBUG** allocation de l'attaqueMagique a échoué" << std::endl;
	}
}

bool CreatureMagique::oublierAttaqueMagique()
{
	if(attaqueMagique_ != nullptr)
	{
		delete attaqueMagique_;
		attaqueMagique_ = nullptr;
		return true;
	}
	else return false;
}

AttaqueMagique* CreatureMagique::obtenirAttaqueMagique() const
{
	return attaqueMagique_;
}

int CreatureMagique::obtenirBonus() const
{
	return bonus_;
}

std::ostream& operator<<(std::ostream& os, const CreatureMagique& creatureMagique)
{
	return os
	       << static_cast<Creature>(creatureMagique) << std::endl
	       << "Cette créature de la classe " << creatureMagique.obtenirTypeCreature()
	       << "a aussi une attaque magique de type "
	       << *(creatureMagique.obtenirAttaqueMagique()) << std::endl;
}
