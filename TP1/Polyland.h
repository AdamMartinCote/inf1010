/**
* Classe Polyland
* represente un monde. contient des dresseurs et des creatures
*
* @author      Adam Martin-Cote
* @author      Jad Sebti
* version finale: 25 septembre 2016
*/
#ifndef POLYLAND_H
#define POLYLAND_H

#include "Dresseur.h"


class Polyland
{
public:
	/**
	* @brief Constructeur par defaut
	*/
	Polyland();
	/**
	* @brief Destructeur par defaut
	*/
	~Polyland();
	/**
	* @brief ajoute un dresseur exisant a Polyland
	* @param pointeur sur un dresseur (cree dans le main)
	*/
	void ajouterDresseur(Dresseur*);
	/**
	* @brief retire un dresseur de Polyland
	* @param nom du dresseur a retirer
	* @return true si le nom etait present dans le tableau et que le dresseur a donc ete retire avec succes
	* !ATTENTION l'objet n'est pas supprime par cette methode puisqu'il a ete cree par le main
	*/
	bool retirerDresseur(const std::string&);
	/**
	* @brief Ajoute une creature a Polyland
	*/
	void ajouterCreature(const Creature&);	
	/**
	* @brief retire une creature de Polyland
	* @return true si le nom etait present dans le tableau et que la creature a donc ete retire avec succes
	*/
	bool retirerCreature(const std::string&);
	/**
	* @brief choisie un dresseur au hasard parmi les dresseurs de Polyland
	* @return un pointeur sur le dresseur choisi
	*/
	Dresseur* choisirDresseurAleatoire() const;
	/**
	* @brief choisi une creature au hasard parmi les creatures de Polyland
	* @return un pointeur sur la creature choisie
	*/
	Creature* choisirCreatureAleatoire() const;
	/**
	* @brief ajouter une creature de Polyland a un dresseur. Cette nouvelle creature est une copie independante
	* @see Dresseur.h/ajouterCreature
	* @param dresseur a qui ajouter la creature
	* @param creature de Polyland a ajouter au dresseur
	* @return true si la creature a ete ajoutee avec succes
	*/
	bool attraperCreature(Dresseur*, const Creature&);
	/**
	* @brief retire une creature au dresseur. L'espace memoire de la creature est desallouee
	* @see Dresseur.h/retirerCreature
	* @param dresseur a qui retirer la creature
	* @param non de la creature a retirer
	* @return true si la creature a ete retirer avec succes
	*/
	bool relacherCreature(Dresseur*, const std::string&);
	/**
	* @brief information sur un dresseur de Polyland
	* @see Dresseur.h/affichage
	* @param nom du dresseur
	* ! message d'erreur si nom de dresseur est inexistant ou ne fait plus partie de Polyland
	*/
	void infoDresseur(std::string) const;

private:
	Dresseur** tableauDeDresseurs_;
	int nDresseurs_;
	Creature** tableauDeCreatures_;
	int nCreatures_;
};

#endif
