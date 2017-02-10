/**
 * GreenBull.h
 *
 * auteurs: Adam Martin-Cote
 * 			Jad Sebti
 *
 * date: 25 octobre 2016
 **/
#ifndef GREEN_BULL_H
#define GREEN_BULL_H

#include <iostream>
#include <string>

#include "ObjetMagique.h"

class GreenBull : public ObjetMagique
{
public:
	/**
	 * Constructeur par defaut
	 */
	GreenBull();
	/**
	 * Constructeur par parametres
	 * @param nom le nom du greenBull
	 * @param bonus son potentiel de guerison
	 */
	GreenBull(const std::string& nom, int bonus);
	/**
	 * operateur d'affichage
	 * @param out un typiquement cout
	 * @param greenBull la potion a afficher
	 */
	friend std::ostream& operator<<(std::ostream& out, const GreenBull& greenBull);
	/**
	 * permet de restorer l'energie d'une creature en fonction du bonus du greenbull.
	 * La potion est consommée par la méthode utiliser de dresseur
	 * @param creature la cible
	 */
	void utiliserSur(Creature& creature);
};

#endif //GREEN_BULL_H
