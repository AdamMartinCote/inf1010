#ifndef ATTAQUEMAGIQUECONFUSION_H
#define ATTAQUEMAGIQUECONFUSION_H

#include <typeinfo>

#include "AttaqueMagique.h"

class AttaqueMagiqueConfusion : public AttaqueMagique
{
public:
	/**
	 * Constructeur par Defaut
	 */
	AttaqueMagiqueConfusion(int duree = 2);
	/**
	 * Constructeur par copie
	 */
	AttaqueMagiqueConfusion(const AttaqueMagique& attaqueMagique);
	/**
	 * Operateur d'assignation supprimé par sécurité
	 */
	AttaqueMagiqueConfusion operator=(const AttaqueMagique& attaqueMagique) = delete;
	/**
	 * Destructeur
	 */
	virtual ~AttaqueMagiqueConfusion();
	/*
	 * La Méthode obtenirTypeAttaque n'est pas réimplémenté
	 * on utilise celle de AttaqueMagique
	 */

	/**
	 * Méthode appliquerAttaque spécialisé,
	 * Cette attaque magique fait diminuer la vie de le cible,
	 * exactement comme on s'y attendrait
	 */
	void appliquerAttaque(Creature& creature) override;
	/**
	 * Spécialisation de la méthode estFini
	 * @return true si la duree == 0
	 */
	bool estFini() const override;

};

#endif // ATTAQUEMAGIQUECONFUSION_H
