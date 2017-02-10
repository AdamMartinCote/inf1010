/**
* Classe ObjetMagique
*
* @author      Adam Martin-Cote
* @author      Jad Sebti
* version finale: 3 octobre 2016
*/
#ifndef OBJETMAGIQUE_H
#define OBJETMAGIQUE_H
#include <string>

class ObjetMagique
{
public:
	/**
	* @brief Constructeur par default
	*/
	ObjetMagique();
	/**
	* @brief Constructeur par parametre
	* @param initialisent les attributs correspondant
	*/
	ObjetMagique(const std::string &nom, int bonus);
	/**
	* @brief Destructeur par default
	*/
	~ObjetMagique();
	/**
	* @return nom_
	*/
	std::string obtenirNom() const;
	/**
	* @return bonus_
	*/
	int obtenirBonus() const;
	/**
	* @param nouveau nom
	*/
	void modifierNom(const std::string& nom);
	/**
	* @param nouvelle valeur bonus
	*/
	void modifierBonus(int bonus);
	/**
	* @brief affiche les informations de l'objet magique dans le ostream
	*/
	friend std::ostream& operator<<(std::ostream&, const ObjetMagique&);
private:
	std::string nom_;
	int bonus_;
};

#endif
