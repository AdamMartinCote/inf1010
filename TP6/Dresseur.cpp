/*
Fichier: Dresseur.cpp
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification: 6 septembre 2016 par Maude Carrier

Modifications par Adam Martin-Cote et Jad Sebti
devoir remis le 1er decembre 2016
*/

#include "Dresseur.h"
#include "Foncteur.h"
#include "ExceptionEchecCapture.h"

Dresseur::Dresseur() :nom_(""), equipe_("") {};

Dresseur::Dresseur(const std::string& nom, const std::string& equipe) : nom_(nom), equipe_(equipe) {};

Dresseur::~Dresseur()
{
	for (auto it = creatures_.begin(); it != creatures_.end(); ++it) {
		delete *it;
	}
}

std::string Dresseur::obtenirNom() const
{
	return nom_;
}

void Dresseur::modifierNom(const std::string& nom)
{
	nom_ = nom;
}

unsigned int Dresseur::obtenirNombreCreatures() const
{
	return creatures_.size();
}

std::vector<Creature*> Dresseur::obtenirCreatures() const
{
	return creatures_;
}

Creature* Dresseur::obtenirUneCreature(const std::string& nom) const //A Compl�ter
{
    FoncteurCreaturesDeMemeNom fronteurComparaison(nom);
    auto position = find_if(creatures_.begin(), creatures_.end(), fronteurComparaison);
    if (position == creatures_.end())
        return nullptr;

	return *position;
}

void Dresseur::modifierCreature(std::vector<Creature*> creatures) //A Compl�ter
{
	creatures_ = creatures;
}

// L'ajout de creature echoue si cette une creature du meme nom est deja possede
// par le joueur
void Dresseur::ajouterCreature(Creature* creature)
{
    //!!!!!! A COMPLETER !!!!!!
    //! Utilisation d'un foncteur different pour faire une comparaison par nom seulement:
    //! La version original permettait par exemple de capturer un 2e pokachu si son niveau
    //! de vie etait different

    // FoncteurEgalCreatures comparaison(creature);

    FoncteurCreaturesDeMemeNom comparaison(creature->obtenirNom());
    auto position_creature = find_if(creatures_.begin(), creatures_.end(), comparaison);
    if (position_creature != creatures_.end()){

        throw ExceptionEchecCapture();

    }
	else{
		creatures_.push_back(new Creature(*creature));
	}
}

bool Dresseur::enleverCreature(const std::string& nom)
{
    FoncteurCreaturesDeMemeNom fronteurComparaison(nom);
    auto position = find_if(creatures_.begin(), creatures_.end(), fronteurComparaison);
    if (position == creatures_.end())
        return false;
	delete *position;
    creatures_.erase(position);

	return true;
}

ObjetMagique Dresseur::obtenirObjetMagique() const
{
	return objetMagique_;
}

void Dresseur::modifierObjetMagique(const ObjetMagique & objetMagique)
{
	objetMagique_ = objetMagique;
}

void Dresseur::utiliserObjetMagique(Creature* creature)
{
    // ajout de casts pour rendre le compilateur heureux

    if ((creature->obtenirPointDeVieTotal() - creature->obtenirPointDeVie()) >= (unsigned int)objetMagique_.obtenirBonus()) {
		creature->modifierPointDeVie(creature->obtenirPointDeVie() + objetMagique_.obtenirBonus());
	}
	else {
		creature->modifierPointDeVie(creature->obtenirPointDeVieTotal());
	}
    if ((creature->obtenirEnergieTotale() - creature->obtenirEnergie()) > (unsigned int)objetMagique_.obtenirBonus()) {
		creature->modifierEnergie(creature->obtenirEnergie() + objetMagique_.obtenirBonus());
	}
	else {
		creature->modifierEnergie(creature->obtenirEnergieTotale());
	}
}

std::string Dresseur::obtenirEquipe() const
{
	return equipe_;
}

void Dresseur::modifierEquipe(const std::string& equipe)
{
	equipe_ = equipe;
}

bool Dresseur::operator==(const Dresseur& dresseur) const
{
    if (creatures_.size() == 0 && dresseur.creatures_.size() == 0)
        return true;
    else if (creatures_.size() != dresseur.creatures_.size())
        return false;

    for (auto it = creatures_.begin(); it != creatures_.end(); ++it) {
        FoncteurEgalCreatures comparaison(*it);
        auto position_creature = find_if(dresseur.creatures_.begin(), dresseur.creatures_.end(), comparaison);
        if (position_creature == dresseur.creatures_.end())
            return false;
    }

	return true;
}

bool Dresseur::operator==(const std::string& nom) const
{
	return (nom_ == nom);
}

bool operator==(const std::string& nom, const Dresseur& dresseur)
{
	return dresseur == nom;
}

std::ostream& operator<<(std::ostream& os, const Dresseur& dresseur)
{
    return os << dresseur.nom_ << " possede " << dresseur.creatures_.size()
        << " creature(s) et appartient a l'equipe " << dresseur.equipe_ << std::endl;
}
