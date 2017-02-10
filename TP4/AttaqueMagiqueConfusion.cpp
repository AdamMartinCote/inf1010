#include "AttaqueMagiqueConfusion.h"


AttaqueMagiqueConfusion::AttaqueMagiqueConfusion(int duree)
	:AttaqueMagique(duree)
{
}

AttaqueMagiqueConfusion::AttaqueMagiqueConfusion(const AttaqueMagique& attaqueMagique)
	:AttaqueMagique(attaqueMagique)
{}

AttaqueMagiqueConfusion::~AttaqueMagiqueConfusion()
{
}

void AttaqueMagiqueConfusion::appliquerAttaque(Creature& creature)
{

	if(
	    (rand()%3 == 0)						// if rand[0..2] == 0
	    && (creature.obtenirPointDeVie() > 5)
	    && duree_ != 0
	)
	{
		creature.modifierPointDeVie(creature.obtenirPointDeVie() - DOMMAGE_ATTAQUE_MAGIQUE);
		duree_--;
	}
}

bool AttaqueMagiqueConfusion::estFini() const
{
	return(duree_ == 0);
}
