/**
 * PotionMagique.h
 *
 * auteurs: Adam Martin-Cote
 * 			Jad Sebti
 *
 * date: 25 octobre 2016
 **/
#ifndef POTION_MAGIQUE_H
#define POTION_MAGIQUE_H

#include <iostream>
#include <string>

#include "ObjetMagique.h"

class PotionMagique : public ObjetMagique
{
public:
	/**
	 * Constructeur par defaut
	 */
	PotionMagique();
	/**
	 * Constructeur par parametres
	 * @param nom le nom de la potion magique
	 * @param bonus son potentiel de guerison
	 */
	PotionMagique(const std::string& nom, int bonus);
	/**
	 * operateur d'affichage
	 * @param out un typiquement cout
	 * @param potionMagique la potion a afficher
	 */
	friend std::ostream& operator<<(std::ostream& out, const PotionMagique& potionMagique);
	/**
	 * permet de restorer les PV d'une creature en fonction du bonus de la
	 * potion. La potion est consommée par la méthode utiliser de dresseur
	 * @param creature la cible
	 */
	void utiliserSur(Creature& creature) const;
};

#endif //POTION_MAGIQUE_H
