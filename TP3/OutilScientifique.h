/*
Fichier: ObjetScientifique.h
Auteur(s): Philippe Troclet
Date de creation: 30 septembre 2016
Description: Il s'agit des différents outils utilisables par un professeur
*/
#ifndef OUTIL_SCIENTIFIQUE_H
#define OUTIL_SCIENTIFIQUE_H

#include <string>

#include "Creature.h"

class OutilScientifique
{
public:
	OutilScientifique();
    OutilScientifique(const std::string& nom, const std::string& description);
	OutilScientifique(const OutilScientifique&);
    ~OutilScientifique();

    std::string obtenirNom() const;
    std::string obtenirDescription() const;

    void utiliser(Creature& creature);

    friend std::ostream& operator<<(std::ostream& os, const OutilScientifique& outil);
private:
    std::string nom_;
    std::string description_;
};
#endif // !OUTIL_SCIENTIFIQUE_H


