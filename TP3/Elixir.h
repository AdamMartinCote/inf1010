/**
 * Elixir.h
 *
 * auteurs: Adam Martin-Cote
 * 			Jad Sebti
 *
 * date: 25 octobre 2016
 **/
#ifndef ELIXIR_H
#define ELIXIR_H

#include <iostream>
#include <string>

#include "PotionMagique.h"
#include "ObjetMagique.h"


class Elixir : public PotionMagique
{
public:
	/**
	 * Constructeur par defaut
	 */
	Elixir();
	/**
	 * Constructeur par parametres
	 * @param nom le nom de l'elixir
	 * @param bonus son potentiel de guerison
	 */
	Elixir(const std::string& nom, int bonus);
	/**
	 * operateur d'affichage
	 * @param out un typiquement cout
	 * @param elixir la potion a afficher
	 */
	friend std::ostream& operator<<(std::ostream& out, const Elixir& elixir);
	/**
	 * permet de restorer les points de vie d'une creature de 2*bonus
	 * et l'energie de 1*bonus
	 * l'elixir est consommée par la méthode utiliser de dresseur
	 * @param creature la cible
	 */
	void utiliserSur(Creature& creature);
};

#endif //ELIXIR_H
