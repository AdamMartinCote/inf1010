#include "CreatureMagique.h"

CreatureMagique::CreatureMagique(const std::string& nom,
                                 unsigned int attaque,
                                 unsigned int defense,
                                 unsigned int pointDeVie,
                                 unsigned int energie,
                                 int bonus)
    : Creature(nom, attaque, defense, pointDeVie, energie)
    , bonus_(bonus)
{
}

CreatureMagique::CreatureMagique(const CreatureMagique& creatureMagique)
    : Creature(creatureMagique)
    , bonus_(creatureMagique.bonus_)
{
}

CreatureMagique::~CreatureMagique()
{
}

void CreatureMagique::operator=(const CreatureMagique& creatureMagique)
{
    Creature::operator=(static_cast<Creature>(creatureMagique));
    this->bonus_ = creatureMagique.bonus_;
}

std::ostream& operator<<(std::ostream& out, const CreatureMagique& creatureMagique)
{
	return out << "La créature magique " << static_cast<const Creature&>(creatureMagique);
}

void CreatureMagique::attaquer(const Pouvoir& pouvoir, Creature& creature)
{
    Creature::attaquer(pouvoir, creature);
	
    if(bonus_ + pointDeVie_ >= pointDeVieTotal_)
	pointDeVie_ = pointDeVieTotal_;
    else
	pointDeVie_ += bonus_;

    modifierPointDeVie(bonus_);
}