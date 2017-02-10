/**
* Classe Creature
*
* @author      Adam Martin-Cote
* @author      Jad Sebti
* version finale: 3 octobre 2016
*/
#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <string>
#include <vector>
#include "ObjetMagique.h"
#include "Pouvoir.h"

class Creature
{
public:
	/**
	* @brief Constructeur par 
	*/
	Creature();
	/**
	* @brief Constructeur par parametres
	* @param initialisent leurs attribus correspondant
	*/
	Creature(
		const std::string& nom, 
		unsigned int attaque, 
		unsigned int defense, 
		unsigned int pointDeVie, 
		unsigned int energie);
	/**
	* @brief Constructeur de copie
	* @param une creature est copiee selon son etat actuel
	*/
	Creature(const Creature&);
	/**
	* @brief Destructeur
	* gere la desallocation de memoire des pouvoirs
	*/
	~Creature();
	/**
	* @return nom_
	*/
	std::string obtenirNom() const;
	/**
	* @return attaque_
	*/
	unsigned int obtenirAttaque() const;
	/**
	* @return defense_
	*/
	unsigned int obtenirDefense() const;
	/**
	* @return pointDeVie_
	*/
	unsigned int obtenirPointDeVie() const;
	/**
	* @return pointDeVieTotal_
	*/
	unsigned int obtenirPointDeVieTotal() const;
	/**
	* @return Energie_
	*/
	unsigned int obtenirEnergie() const;
	/**
	* @return energieTotale_
	*/
	unsigned int obtenirEnergieTotale() const;
	/**
	* @return experience_
	*/
	unsigned int obtenirExperience() const;
	/**
	* @return experienceNecessaire_
	*/
	unsigned int obtenirExperienceNecessaire() const;
	/**
	* @return nom_
	*/
	unsigned int obtenirNiveau() const;
	/**
	* @return pouvoir_
	*/
	std::vector<Pouvoir*> obtenirPouvoirs() const;
	/**
	* @brief attaque une creature enemie à l'aide d'un pouvoir choisie
	* @param pouvoir choisie de la creature, message d'erreur si la creature ne le possede pas
	* @param creature cible
	*/
	void attaquer(Pouvoir&, Creature&);
	/**
	* @brief attribut l'experience selon une formule mysterieuse
	* @param creature vaincu
	*/
	int experienceGagnee(const Creature& creature);
	/**
	* @param nouvelle valeur attaque_
	*/
	void modifierAttaque(unsigned int attaque);
	/**
	* @param nouvelle valeur defense_
	*/
	void modifierDefense(unsigned int defense);
	/**
	* @param nouvelle valeur pointDeVie_
	*/
	void modifierPointDeVie(unsigned int pointDeVie);
	/**
	* @param nouvelle valeur energie_
	*/
	void modifierEnergie(unsigned int energie);
	/**
	* @param nouvelle valeur experience_
	*/
	void modifierExperience(unsigned int experience);
	/**
	* @param nouvelle valeur niveau_
	*/
	void modifierNiveau(unsigned int niveau);
	/**
	* @deprecated DO NOT USE
	*/
	void modifierPouvoirs(const Pouvoir& pouvoirs);
	/**
	* @deprecated DO NOT USE
	*/
	void information() const;

	// _________TP2___________

	/**
	* @param nouveau nom_
	*/
	void modifierNom(std::string);
	/**
	* @brief attribut tout les qualificatifs de la cible a l'instance courante
	* @param autreCreature
	*/
	void operator=(const Creature& autreCreature);
	/**
	* @brief ajoute un Pouvoir
	* la creature obtient sa propre copie (composition)
	*/
	void apprendrePouvoir(const Pouvoir& nouveauPouvoir);
	/**
	* @brief retire un pouvoir 
	* @param nomPouvoir recherche par nom
	* desalloue la memoire
	*/
	bool oublierPouvoir(const std::string& nomPouvoir);
	/**
	* @brief retire un pouvoir
	* @param pouvoir 
	*/
	bool oublierPouvoir(Pouvoir* pouvoir);
	/**
	* @brief operateur de comparaison par objet
	*/
	bool operator==(const Creature&) const;
	/**
	* @brief operateur de comparaison par nom
	*/
	bool operator==(const std::string&) const;
	/**
	* @brief operateur de comparaison par nom, pour permettre la commutativite
	*/
	friend bool operator==(const std::string, const Creature&);
	/**
	* @brief operateur d'affichage
	*/
	friend std::ostream& operator<<(std::ostream&, const Creature&);

private:

	std::string nom_;
	unsigned int attaque_;
	unsigned int defense_;
	unsigned int pointDeVie_;
	unsigned int pointDeVieTotal_;
	unsigned int energie_;
	unsigned int energieTotal_;
	unsigned int experience_;
	unsigned int experienceNecessaire_;
	unsigned int niveau_;
	
	// _________TP2___________
	
	std::vector<Pouvoir*> pouvoir_;		// relation de composition**
};

#endif