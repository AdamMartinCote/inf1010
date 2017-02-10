/**
 * Professeur.h
 *
 * auteurs: Adam Martin-Cote
 * 			Jad Sebti
 *
 * date: 25 octobre 2016
 **/
#ifndef PROFESSEUR_H
#define PROFESSEUR_H

#include <iostream>
#include "OutilScientifique.h"
class Professeur : public Dresseur
{
public:
	/**
	 * Constructeur par defaut
	 */
	Professeur();
	/**
	 * Constructeur par parametres
	 * @param nom
	 * @param equipe
	 */
	Professeur(const std::string& nom, const std::string equipe);
	/**
	 * Constructeur par copie
	 * @param professeur le professeur a copier
	 */
	Professeur(const Professeur& professeur);
	/**
	 * destructeur
	 */
	~Professeur();
	/**
	 * mutateur pour l'attibut outilScientique
	 * @param professeur a copier
	 */
	void modifierOutilScientifique(const OutilScientifique& outilScientique);
	/**
	 * restore completement les PV et energie d'une creature
	 * @param creature la creature cible
	 */
	void soigner(Creature&);
	/**
	 * operateur d'assignation
	 */
	Professeur& operator=(const Professeur& professeur);
	/**
	 * utiliser un l'outil sur une creature
	 * @param creature la cible
	 */
	void utiliserOutil(Creature& creature);
	/**
	 * modificateur de l'outil, prend un outil deja alloué
	 * @param creature la cible
	 */
	OutilScientifique* obtenirOutilScientifique() const;
	/**
	 * Operateur d'affichage : nécessaire pour reproduire la sortie de l'énoncer
	 */
	friend std::ostream& operator<<(std::ostream& out, const Professeur& professeur);
private:
	OutilScientifique* outilScientifique_;
};


#endif
