/**
* Classe Creature
*
* @author      Adam Martin-Cote
* @author      Jad Sebti
* version finale: 25 septembre 2016
*/
#ifndef CREATURE_H_
#define CREATURE_H_

#include "Pouvoir.h"

class Creature
{
public:
	/**
	* @brief Constructeur par defaut
	*/
	Creature();
	/**
	* @brief Constructeur par parametres
	* @param initialisent leurs attribus correspondant
	*/
	Creature(
		const std::string nom,
		int attaque,
		int defense,
		int pointDeVie,
		int energie,
		Pouvoir pouvoir
	);
	/**
	* @brief Constructeur par copie
	* @param reference a une creature existante
	*/
	Creature(const Creature&);
	/**
	* @brief Destructeur par defaut
	*/
	~Creature();
	/**
	* @brief Accesseurs
	*/
	std::string obtenirNom() const;
	int obtenirValeurAttaque() const;
	int obtenirValeurDefense() const;
	int obtenirPointDeVie() const;
	int obtenirPointDeVieTotal() const;
	int obtenirEnergie() const;
	int obtenirEnergieTotale() const;
	int obtenirExperience() const;
	int obtenirExperienceNecessaire() const;
	int obtenirNiveau() const;
	Pouvoir obtenirPouvoir() const;
	/**
	* @brief Mutateurs
	*/
	void modifierNom(const std::string& nom);
	void modifierValeurAttaque(int valeurAttaque);
	void modifierValeurDefense(int valeurDefense);
	void modifierPointDeVie(int pointDeVie);
	void modifierPointDeVieTotal(int pointDeVieTotal);
	void modifierEnergie(int energie);
	void modifierEnergieTotal(int energieTotal);
	void modifierExperience(int experience);
	void modifierExperienceNecessaire(int experienceNecessaire);
	void modifierNiveau(int niveau);
	void modifierPouvoir(const Pouvoir& pouvoir);

	/**
	* @brief Attaquer gere l'utilisation de pouvoir pour infliger des degats a la cible
	* @param creature la cible de l'attaque
	*/
	void attaquer(Creature& creature);
	/**
	* @brief experienceGagner
	* @param creature la creature vaincu
	*/
	int experienceGagner(const Creature& creature);
	/**
	* @brief informations sur la creature
	*/
	void information() const;

private:
	std::string nom_;
	int attaque_;
	int defense_;
	int pointDeVie_;
	int pointDeVieTotal_;
	int energie_;
	int energieTotal_;
	int experience_;
	int experienceNecessaire_;
	int niveau_;
	Pouvoir pouvoir_;
};


#endif
