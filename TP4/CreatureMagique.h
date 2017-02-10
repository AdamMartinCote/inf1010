#ifndef CREATUREMAGIQUE_H
#define CREATUREMAGIQUE_H

#include "Creature.h"
#include "AttaqueMagique.h"

class CreatureMagique : public Creature
{
public:
	/**
	 * Construteur par défaut
	 * attaqueMagique initialisé à nullptr
	 */
	CreatureMagique();
	/**
	 * Construteur par paramètres
	 * attaqueMagique initialisé à nullptr
	 * @param creature une creature à transformer en CreatureMagique
	 * @param bonus (optionnel) le bonus de la nouvelle CreatureMagique
	 */	
	CreatureMagique(const Creature& creature, int bonus = 0);
	/**
	 * Construteur de copie
	 */
	CreatureMagique(const CreatureMagique& creatureMagique);
	/**
	 * Operateur d'assignation
	 */
	CreatureMagique& operator=(const CreatureMagique& creatureMagique);
	/**
	 * Destructeur
	 * @param creatureMagique (Même classe)
	 */
	~CreatureMagique();
	/**
	 * Acceseur de l'attribut AttaqueMagique
	 */
	AttaqueMagique* obtenirAttaqueMagique() const;
	/**
	 * Acceseur de l'attribut bonus
	 */
	int obtenirBonus() const;
	/**
	 * Permet d'initialiser l'attribut attaqueMagique
	 */
	void apprendreAttaqueMagique(AttaqueMagique& attaqueMagique);
	/**
	 * Permet d'initialiser l'attribut attaqueMagique
	 * @param aucun puisque l'attaque magique est unique
	 * @return true si la deletion a eu lieu, et false si le pointeur était déjà null
	 */
	bool oublierAttaqueMagique();
	/**
	 * modificateur de l'attribut bonus
	 */
	void modifierBonus(int nouveauBonus);
	/* 
	 * méthode obtenirTypeCreature n'est pas réimplémentée, on utilise
	 * celle de la classe mère
	 */
	 
	 /**
	  * La méthode attaquer est spécialisée pour permettre le comportement spécifique de la 
	  * créature magique:
	  * 	*la creature voit ses PV augmenter de [bonus_] avant l'attaque
	  * 	*l'effet de l'attaque est appliquée à la créature attaquée
	  * on invoque ensuite la méthode d'attaque de créature
	  * @see Creature::Attaquer 
	  */
	void attaquer(const Pouvoir& pouvoir,Creature& creature) override;
	/**
	 * Méthode globale pour l'affichage de la creature magique au stream
	 * fait appel aux méthode analogue de Creature et AttaqueMagique
	 */
	friend std::ostream& operator<<(std::ostream& os, const CreatureMagique& creatureMagique);
	
private:
	AttaqueMagique* attaqueMagique_;
	int bonus_;
};

#endif // CREATUREMAGIQUE_H
