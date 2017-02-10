/**
* Classe PolyLand
*
* @author      Adam Martin-Cote
* @author      Jad Sebti
* version finale: 3 octobre 2016
*/
#ifndef POLYLAND_H
#define POLYLAND_H

#include <vector>
#include "Dresseur.h"
#include "Creature.h"
#define MAX_DRESSEURS 100
#define MAX_CREATURES 1000
#define MAX_OBJET_MAGIQUE 100
#define MAX_POUVOIRS 10

class PolyLand
{
public:
	/**
	* @brief Constructeur par default
	*/
	PolyLand();
	/**
	* @brief Destructeur
	* gere la destruction des creatures (relation de composition)
	*/
	~PolyLand();
	/**
	* @brief ajoute un dresseur a PolyLand (agregation)
	* @param dresseur un dresseur du main
	* @return true si reussi
	*/	
	bool ajouterDresseur(Dresseur* dresseur);
	/**
	* @brief ajoute une creature a PolyLand (composition)
	* @param creature une creature du main
	* @return true si reussi
	*/
	bool ajouterCreature(const Creature& creature);
	/**
	* @brief retire un dresseur, ne supprime ma la memoire
	* @param nom le nom du dresseur
	* @return true si reussi
	*/
	bool retirerDresseur(const std::string& nom);
	/**
	* @brief retire une creature et desalloue la memoire
	* @param nom le nom de la creature
	* @return true si reussi
	*/
	bool retirerCreature(const std::string& nom);
	/**
	* @brief choisis au hasard un dresseur de polyland
	* @return pointeur sur un dresseur
	*/
	Dresseur* choisirDresseurAleatoire();
	/**
	* @brief choisis au hasard une creature de polyland
	* @return pointeur sur une creature
	*/
	Creature* choisirCreatureAleatoire();
	/**
	* @brief ajoute une creature a un dresseur
	* @param dresseur le dresseur a rendre heureux
	* @param creature la creature a mettre en servitude
	* @return true si reussi
	*/
	bool attraperCreature(Dresseur* dresseur, Creature* creature);
	/**
	* @brief relache une creature, si le nom existe
	* @param dresseur a alleger
	* @param creature la creature a libere
	* @return true nom de la creature etait present
	*/
	bool relacherCreature(Dresseur* , const std::string&); 
	/**
	* @brief afficher les information d'un dresseur
	* @param nom le nom du dresseur a afficher
	*/
	void infoDresseur(const std::string& nom) const;

	//________TP2_______

	PolyLand& operator-=(Dresseur*);
	PolyLand& operator+=(Dresseur*);
	PolyLand& operator+=(const Creature&);
	PolyLand& operator-=(Creature&);

	friend std::ostream& operator<<(std::ostream&, const PolyLand&);

private:
	//________TP2_______
	std::vector<Dresseur*> dresseurs_;	// agregation
	std::vector<Creature*> creatures_;	// composition (on copie les creature du main)
};


#endif