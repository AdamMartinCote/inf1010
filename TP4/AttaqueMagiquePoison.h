#ifndef ATTAQUEMAGIQUEPOISON_H
#define ATTAQUEMAGIQUEPOISON_H

#include "AttaqueMagique.h"

class AttaqueMagiquePoison : public AttaqueMagique
{
public:
	/**
	 * Constructeur par défaut
	 */
	AttaqueMagiquePoison(int duree = 2);
	/**
	 * Constructeur de copie
	 */
	AttaqueMagiquePoison(const AttaqueMagique& attaqueMagique);
	/**
	 * Operateur d'assignation supprimé par sécurité
	 */
	AttaqueMagiquePoison operator=(const AttaqueMagique& attaqueMagique) = delete;
	/**
	 * Destructeur
	 */
	virtual ~AttaqueMagiquePoison();
	/*
	 * La Méthode obtenirTypeAttaque n'est pas réimplémenté
	 * on utilise celle de AttaqueMagique
	 */

	/**
	 * Méthode appliquerAttaque spécialisé,
	 * Cette attaque magique fait diminuer l'énergie de le cible,
	 * ce qui est tout à fait logique :)
	 */
	virtual void appliquerAttaque(Creature& creature) override;
	/**
	 * Spécialisation de la méthode estFini
	 * @return true si duree == 0
	 */
	bool estFini() const override;

};

#endif // ATTAQUEMAGIQUEPOISON_H
