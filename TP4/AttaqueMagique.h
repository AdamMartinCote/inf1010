#ifndef ATTAQUEMAGIQUE_H
#define ATTAQUEMAGIQUE_H

#include <string>
#include <typeinfo>

#include "AttaqueMagique.h"
#include "Creature.h"

const int DOMMAGE_ATTAQUE_MAGIQUE = 2;

class AttaqueMagique
{
public:
	/**
	 * Constructeur par paramètre
	 * @param dure
	 */
	AttaqueMagique(int duree);
	/**
	 * Destructeur
	 */
	virtual ~AttaqueMagique();
	/**
	 * accesseur duree
	 */
	int obtenirDuree() const;
	/**
	 * Modificateur duree
	 */
	void modifierDuree(int nouvelleDuree);
	/**
	 * methode retournant un hashage du type
	 * @return un type_info pour comparaison
	 */
	std::string obtenirTypeAttaque() const;
	/**
	 * méthode virtuelle pure
	 * appliquerAttaque. pas d'implementation
	 */
	virtual void appliquerAttaque(Creature& creature) = 0;
	/**
	 * retourne toujours true
	 */
	virtual bool estFini() const
	{
		return true;
	}
	/**
	 * Opérateur d'affiche
	 */
	friend std::ostream& operator<<(std::ostream& out, const AttaqueMagique& attaqueMagique);

protected:
	int duree_;
};

#endif // ATTAQUEMAGIQUE_H
