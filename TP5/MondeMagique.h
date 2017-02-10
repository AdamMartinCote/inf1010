#ifndef MONDEMAGIQUE_H
#define MONDEMAGIQUE_H

#include <list>
#include <algorithm>

template<class T, class S>
class MondeMagique
{
public:
	/**
	 * @brief Construteur par défaut
	 */
	MondeMagique();
	/**
	 * @brief Destructeur par défaut
	 */
	~MondeMagique();
	/**
	 * @brief accesseur des Maitres
	 * @param unMaitre
	 */
	std::list<T*> obtenirListMaitre() const;
	/**
	 * @brief acceseur des Compagnons
	 * @param unCompagnon
	 */
	std::list<S*> obtenirListCompagnon() const;
	/**
	 * @brief ajoute un Maitre à la fin de la liste
	 * @param unMaitre
	 */
	void ajouter(T unMaitre);
	/**
	 * @brief ajoute un Compagnon à la fin de la liste
	 * @param unCompagnon
	 */
	void ajouter(S unCompagnon);
	/**
	 * @brief supprime un maitre de la liste
	 * @param maitre
	 */
	void supprimer(T maitre);
	/**
	 * @brief supprime un compagnon de la liste
	 * @param compagnon
	 */
	void supprimer(S compagnon);
	/**
	 * @brief Supprime tout les maitres de la liste qui ne satisfont pas au
	 * prédicat passé en paramètre
	 * @param pred unaire
	 */
	template<class FuncType> void supprimerMaitre(FuncType pred);
	/**
	 * @brief Supprime tout les compagnons de la liste qui ne satisfont pas au
	 * prédicat passé en paramètre
	 * @param pred unaire
	 */
	template<class FuncType> void supprimerCompagnon(FuncType pred);
	/**
	 * @brief vide complètement les listes de Maitres et de Compagnons
	 */
	void vider();
	/**
	 * @brief ajoute un maitre et retourn le MondeMagique incrémenté
	 * @param maitre
	 * @return MondeMagique
	 */
	MondeMagique<T, S>& operator+=(T maitre);
	/**
	 * @brief ajoute un maitre et retourn le MondeMagique décrémenté
	 * @param maitre
	 * @return MondeMagique
	 */
	MondeMagique<T, S>& operator-=(T maitre);
	/**
	 * @brief ajoute un maitre et retourn le MondeMagique incrémenté
	 * @param compagnon
	 * @return MondeMagique
	 */
	MondeMagique<T, S>& operator+=(S compagnon);
	/**
	 * @brief supprime un compagnon et retourn le MondeMagique décrémenté
	 * @param compagnon
	 * @return MondeMagique
	 */
	MondeMagique<T, S>& operator-=(S compagnon);


private:
	std::list<T*> listMaitre_;		// agregation
	std::list<S*> listCompagnon_;	// agregation

};

template<class T, class S>
MondeMagique<T, S>::MondeMagique()
{
}

template<class T, class S>
MondeMagique<T, S>::~MondeMagique()
{
}

template<class T, class S>
std::list<T*> MondeMagique<T, S>::obtenirListMaitre() const
{
	return listMaitre_;
}

template<class T, class S>
std::list<S*> MondeMagique<T, S>::obtenirListCompagnon() const
{
	return listCompagnon_;
}

template<class T, class S>
void MondeMagique<T, S>::ajouter(T unMaitre)
{
	listMaitre_.push_back(&unMaitre);
}

template<class T, class S>
void MondeMagique<T, S>::ajouter(S unCompagnon)
{
	listCompagnon_.push_back(&unCompagnon);
}

template<class T, class S>
void MondeMagique<T, S>::supprimer(T maitre)
{
	listMaitre_.erase(find(listMaitre_.begin(), listMaitre_.end(), maitre));
}

template<class T, class S>
void MondeMagique<T, S>::supprimer(S compagnon)		// avec find et erase
{
	listCompagnon_.erase(find(listCompagnon_.begin(), listCompagnon_.end(), compagnon));
}

template<class T, class S>
template<class FuncType>
void MondeMagique<T, S>::supprimerMaitre(FuncType pred){
	for (auto i : listMaitre_) {
		std::remove_if(listMaitre_.begin(), listMaitre_.end(), pred);
	}
}

template<class T, class S>
template<typename FuncType>
void MondeMagique<T, S>::supprimerCompagnon(FuncType pred){
	for (auto i : listCompagnon_) {
		std::remove_if(listCompagnon_.begin(), listCompagnon_.end(), pred);
	}
}

template <class T, class S>
void MondeMagique<T, S>::vider()
{
	listMaitre_.erase(listMaitre_.begin(), listMaitre_.end());
	listCompagnon_.erase(listCompagnon_.begin(), listCompagnon_.end());
}

template<class T, class S>
MondeMagique<T, S>& MondeMagique<T, S>::operator+=(T maitre){
	ajouter(maitre);
	return *this;
}

template<class T, class S>
MondeMagique<T, S>& MondeMagique<T, S>::operator-=(T maitre){
	supprimer(maitre);
	return *this;
}

template<class T, class S>
MondeMagique<T, S>& MondeMagique<T, S>::operator+=(S compagnon){
	ajouter(compagnon);
	return *this;
}

template<class T, class S>
MondeMagique<T, S>& MondeMagique<T, S>::operator-=(S compagnon){
	supprimer(compagnon);
	return *this;
}


#endif // MONDEMAGIQUE_H