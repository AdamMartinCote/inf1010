/*
Fichier: Dresseur.h
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification:  6 septembre 2016 par Maude Carrier
Description: les dresseurs sont les etres capables d'attraper des creatures
*/
#ifndef DRESSEUR_H
#define DRESSEUR_H

#include <string>
#include <iostream>
#include <list>
#include <algorithm>

#include "Creature.h"
#include "ObjetMagique.h"


class Dresseur
{
public:
	Dresseur();
	Dresseur(const std::string& nom, const std::string& equipe);
	~Dresseur();

	std::string obtenirNom() const;
	void modifierNom(const std::string& nom);
	
	unsigned int obtenirNombreCreatures() const;

	auto obtenirCreatures() const;
	auto obtenirUneCreature(Creature* creature) const; //À MODIFIFIER !!
	void modifierCreature(std::list<Creature*>  creatures);
	
	bool ajouterCreature(Creature* creature);
	bool enleverCreature(const std::string& nom);

	ObjetMagique obtenirObjetMagique() const;
	void modifierObjetMagique(const ObjetMagique& objetMagique);

	void utiliserObjetMagique(Creature* creature);

	std::string obtenirEquipe() const;
	void modifierEquipe(const std::string& equipe);

	friend std::ostream& operator<<(std::ostream& os, const Dresseur& dresseur);

	bool operator==(const Dresseur& dresseur) const;
	bool operator==(const std::string& nom) const;
	friend bool operator==(const std::string& nom, const Dresseur& dresseur);
	
	/**
	 * @brief applique le foncteur à toutes les créatures du conteneur
	 * @param pred
	 */
	template<class FuncType> void appliquerFoncteurUnaire(FuncType pred){	
		for (auto i : creatures_) {
			pred(*i);
		}
	}
	
	template<class FuncType>
	void supprimerElements(FuncType foncteur){
		auto it = find_if(creatures_.begin(), creatures_.end(), foncteur);
		creatures_.erase(it, creatures_.end());
	}
	/**
	 * @brief prend un foncteur en argument, et retourne la créature max selon 
	 * l’ordre induit par le foncteur.
	 * @param foncteur
	 * @return creature
	 */
	//template<class FuncType>
	Creature* obtenirCreatureMax(auto foncteur){
		std::sort(creatures_.begin(), creatures_.end(), foncteur);
		
		return creatures_.back();
	}
	
private:
	std::string nom_;
	std::string equipe_;
	ObjetMagique objetMagique_;
	
	std::list<Creature*> creatures_;


};

#endif
