#ifndef  FONCTEUR
#define  FONCTEUR

#include "Dresseur.h"
#include "Creature.h"
#include <string>
#include <stdlib.h>

#define RAND_MIN_DEFAUT 0
#define RAND_MAX_DEFAUT 6

//Froncteur permettant d'obtenir l'attaque de la créature passée en argument
class FoncteurObtenirAttaqueCreature
{
public:
    FoncteurObtenirAttaqueCreature() {}
    ~FoncteurObtenirAttaqueCreature() {}

    unsigned int operator() (const Creature* creature) const {
        return creature->obtenirAttaque();
    }
};

/**
 * @class FoncteurComparerCreatures
 * @brief Ce foncteur prend en argument deux pointeurs de créature et renvoie 
 * true si la première créature a une attaque inférieure à celle de la deuxième
 */
class FoncteurComparerCreature
{
public:
	FoncteurComparerCreature() {}
	~FoncteurComparerCreature() {}
	bool operator()(const Creature& a, const Creature& b) const {
		return ((a.obtenirAttaque()) < (b.obtenirAttaque()));
	}
};

/**
 * @class FoncteurComparerDresseurs
 * @brief Ce foncteur prend en argument deux pointeurs de dresseurs et renvoie true 
 * si le premier a un nom strictement inférieur au nom du second. Cette comparaison 
 * se fera selon l’ordre alphanumérique
 */
class FoncteurComparerDresseurs
{
public:
	FoncteurComparerDresseurs() {}
	~FoncteurComparerDresseurs() {}
	bool operator()(Dresseur* a, Dresseur* b) const {
		return (a->obtenirNom() <= b->obtenirNom());
	}
};

/**
 * @class FoncteurComparerPouvoirs
 * @brief Ce foncteur prend en argument deux pointeurs de pouvoir et renvoie true 
 * si le premier pouvoir a un nombre de dégâts inférieur à celui du deuxième
 */
class FoncteurComparerPouvoir
{
public:
	FoncteurComparerPouvoir() {}
	~FoncteurComparerPouvoir() {}
	bool operator()(Pouvoir* a, Pouvoir* b) const {
		return (a->obtenirNombreDeDegat() < b->obtenirNombreDeDegat());
	}
};

/**
 * @class FoncteurCreaturesDeMemeNom
 * @brief Ce foncteur prend en argument un pointeur de créature et renvoie true 
 * si cette créature a le même nom que l’attribut de la classe correspondant
 */
class FoncteurCreaturesDeMemeNom
{
public:
	FoncteurCreaturesDeMemeNom(Creature* c)
		:nom_(c->obtenirNom())
	{}
	~FoncteurCreaturesDeMemeNom() {}
	
	bool operator()(Creature* a) const {
		return (a->obtenirNom() == nom_);
	}
private:
	std::string nom_;
};

/**
 * @class FoncteurEgalCreatures
 * @brief Ce foncteur prend en argument un pointeur de créature et renvoie true
 * si cette créatures est égale à l’attribut creature du foncteur (au sens de 
 * leur opérateur ==)
 */
class FoncteurEgalCreatures
{
public:
	FoncteurEgalCreatures(const Creature& c)
		:creature_(c)
	{}
	~FoncteurEgalCreatures() {}
	
	bool operator()(Creature* a) const {
		return (*a == creature_);
	}
private:
	Creature creature_;
};

/**
 * @class FoncteurCreatureVie
 * @brief Ce foncteur prend en argument un pointeur vers une créature et 
 * incrémente une variable interne si les points de vie de la créature sont 
 * entre ces bornes
 */
class FoncteurCreatureVie
{
public:
	FoncteurCreatureVie(int min, int max)
		:vieMinimale_(min), vieMaximale_(max), compteur_(0)
	{}
	~FoncteurCreatureVie() {}
	
	void operator()(Creature creature) {
		if (creature.obtenirPointDeVie() > vieMinimale_
		 && creature.obtenirPointDeVie() < vieMaximale_)
			 compteur_++;
	}
	
	int obtenirCompteur() const { return compteur_; }
	
private:
	unsigned int vieMinimale_;
	unsigned int vieMaximale_;
	int compteur_;
};

/**
 * @class FoncteurGenerateurDeNombreAlea
 * @brief Ce foncteur permet de générer un nombre aléatoire compris dans un
 * intervalle (requiere srand() dans le main)
 */
class FoncteurGenerateurDeNombreAlea
{
public:
	FoncteurGenerateurDeNombreAlea( int min = RAND_MIN_DEFAUT, 
									int max = RAND_MAX_DEFAUT)
		:borneInferieure_(min)
		,borneSuperieure_(max)
	{}
	~FoncteurGenerateurDeNombreAlea() {}
	
	int operator()() const {
		return ((rand() % borneSuperieure_ - borneInferieure_ + 1 ) 
				+ borneInferieure_);
	}
	
private:
	int borneInferieure_;
	int borneSuperieure_;
};


#endif	//FONCTEUR