
#include "Dresseur.h"
#include "Professeur.h"

Professeur::Professeur()
	: Dresseur()
{
	outilScientifique_ = new OutilScientifique();
}

Professeur::Professeur(const std::string& nom, const std::string equipe)
	: Dresseur(nom, equipe)
{
	outilScientifique_ = new OutilScientifique();
}

Professeur::Professeur(const Professeur& professeur)
	: Dresseur(professeur)
{
	outilScientifique_ = new OutilScientifique(*professeur.obtenirOutilScientifique());
}

Professeur::~Professeur()
{
	delete outilScientifique_;
	outilScientifique_ = nullptr;
}

void Professeur::modifierOutilScientifique(const OutilScientifique& outilScientique)
{
	delete outilScientifique_;
	outilScientifique_ = nullptr;
	outilScientifique_ = new OutilScientifique(outilScientique);
}

void Professeur::soigner(Creature& creature)
{
	creature.modifierPointDeVie(creature.obtenirPointDeVieTotal());
	creature.modifierEnergie(creature.obtenirEnergieTotale());
}

Professeur& Professeur::operator=(const Professeur& professeur)
{
	this->Dresseur::operator=(static_cast<Dresseur>(professeur));
	modifierOutilScientifique(*professeur.outilScientifique_);
}

void Professeur::utiliserOutil(Creature& creature)
{
	std::cout << "Vous avez utilisez " << obtenirOutilScientifique()->obtenirNom() << " sur " << creature.obtenirNom() << std::endl;
}

OutilScientifique* Professeur::obtenirOutilScientifique() const
{
	return outilScientifique_;
}

std::ostream& operator<<(std::ostream& out, const Professeur& professeur)
{
	return out << static_cast<Dresseur>(professeur) << "il utilise un outil : " << *(professeur.obtenirOutilScientifique());
}
