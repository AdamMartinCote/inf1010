/**
* Classe Pouvoir
*
* @author      Adam Martin-Cote
* @author      Jad Sebti
* version finale: 3 octobre 2016
*/
#ifndef POUVOIR_H
#define POUVOIR_H

#include <string>
#include <iostream>
class Pouvoir
{
public:
	/**
	* @brief Constructeur par defaut
	*/
	Pouvoir();
	/**
	* @brief Constructeur par parametre
	* @param initialisent les attributs correspondants
	*/
	Pouvoir(const std::string& nom, 
		unsigned int nombreDeDegat, unsigned int energieNecessaire);
	/**
	* @brief Constructeur de copie
	*/
	Pouvoir(const Pouvoir&);
	/**
	* @brief Destructeur
	*/
	~Pouvoir();
	/**
	* @return nombreDeDegat_
	*/
	unsigned int obtenirNombreDeDegat() const;
	/**
	* @return energieNecessaire_
	*/
	unsigned int obtenirEnergieNecessaire() const;
	/**
	* @return nom_
	*/
	std::string obtenirNom() const;
	/**
	* @brief mutateur
	* @param nombreDeDegat nouvelle valeur
	*/
	void modifierNombreDeDegat(unsigned int nombreDegat);
	/**
	* @brief mutateur
	* @param energieNecessaire nouvelle valeur
	*/
	void modifierEnergieNecessarie(unsigned int energieNecessaire);
	/**
	* @brief mutateur
	* @param nom nouvelle valeur
	*/
	void modifierNom(const std::string& nom);

	//________TP2________

	/**
	* @brief affichage vers le stream
	*/
	friend std::ostream& operator<<(std::ostream& out, const Pouvoir& pouvoir);
	/**
	* @brief operateur de copie
	*/
	void operator=(const Pouvoir&);
	/**
	* @brief operateur de comparaison
	* comparation par nom
	*/
	bool operator==(const std::string& nomPouvoir) const;


private:
	std::string nom_;
	unsigned int nombreDeDegat_ ;
	unsigned int energieNecessaire_;
};

#endif