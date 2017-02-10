/**
* Classe Pouvoir
* Chaque Creature possede un pouvoir. utilise pour l'attaque
*
* @author      Adam Martin-Cote
* @author      Jad Sebti
* version finale: 25 septembre 2016
*/
#ifndef POUVOIR_H
#define POUVOIR_H

#include <string>

class Pouvoir
{
public:
	/**
	* @brief Constructeur par defaut
	*/
	Pouvoir();
	/**
	* @brief Constructeur par parametres
	* @param initialisent leur attributs correspondants
	*/
	Pouvoir(std::string nom, int nombreDegat, int valeurEnergieNecessaire);
	/**
	* @brief Constructeur par copie
	* @param pouvoir existant
	*/
	Pouvoir(const Pouvoir&);
	/**
	* @brief Destructeur par defaut
	*/
	~Pouvoir();
	/**
	* @brief Accesseurs
	*/
	std::string obtenirNom() const;
	int obtenirNombreDeDegat() const;
	int obtenirValeurEnergieNecessaire() const;
	/**
	* @brief Mutateurs
	*/
	void modifierNom(std::string nom);
	void modifierNombreDegat(int NombreDegat);
	void modifierValeurEnergieNecessaire(int valeurEnergieNecessaire);
	/**
	* @brief description detaille
	*/
	void description() const;

private:
	std::string nom_;
	int nombreDegat_;
	int valeurEnergieNecessaire_;
};
#endif
