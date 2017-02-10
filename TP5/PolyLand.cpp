/*
Fichier: Dresseur.cpp
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification:  6 septembre 2016 par Maude Carrier
Description:
*/

#include <list>
#include <algorithm>
#include <iterator>

#include "MondeMagique.h"
#include "PolyLand.h"
#include "Foncteur.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

template<typename T, typename S>
bool PolyLand<T, S>::attraperCreature(Dresseur* dresseur, Creature* creature)
{
	return dresseur->ajouterCreature(creature);
}

template<typename T, typename S>
bool PolyLand<T, S>::relacherCreature(Dresseur* dresseur, const std::string& nomCreature)
{
	return dresseur->enleverCreature(nomCreature);
}

template<typename T, typename S>
std::ostream& operator<<(std::ostream& out, const PolyLand<T, S>& polyland){
	
	FoncteurComparerDresseurs pred1();
	sort(polyland.listMaitre_.begin(), polyland.listMaitre_.end(), pred1);
	
	FoncteurComparerCreature pred2;
	sort(polyland.listCompagnon_.begin(), polyland.listCompagnon_.end(), pred2);
	std::copy(
		polyland.compagnon.begin(), 
		polyland.compagnon.end(), 
		std::ostream_iterator<int>(std::cout, "\n")
	);
	return out;
}