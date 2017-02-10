#include "AttaqueMagiquePoison.h"
#include "AttaqueMagique.h"

AttaqueMagiquePoison::AttaqueMagiquePoison(int duree)
	:AttaqueMagique(duree)
{
}

AttaqueMagiquePoison::AttaqueMagiquePoison(const AttaqueMagique& attaqueMagique)
	: AttaqueMagique(attaqueMagique.obtenirDuree())
{
}

AttaqueMagiquePoison::~AttaqueMagiquePoison()
{
}

void AttaqueMagiquePoison::appliquerAttaque(Creature& creature)
{
	if(
	    (rand()%3 == 0)						// if rand[0..2] == 0
	    && (creature.obtenirEnergie() > 5)
	    && duree_ != 0
	)
	{
		creature.modifierEnergie(creature.obtenirEnergie() - DOMMAGE_ATTAQUE_MAGIQUE);
		duree_--;
	}
}

bool AttaqueMagiquePoison::estFini() const
{
	return(duree_ == 0);
}
