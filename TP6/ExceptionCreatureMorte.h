/*
Fichier: ExceptionCreatureMorte.h
inf1010 TP 6
par Adam Martin-Cote et Jad Sebti
remis le 1er decembre 2016
*/
#ifndef EXCEPTIONCREATUREMORTE_H
#define EXCEPTIONCREATUREMORTE_H

#include <stdexcept>

class ExceptionCreatureMorte : public std::runtime_error
{
public:
    ExceptionCreatureMorte(std::string what_args = "");
    static int obtenirValeurCompteur();
private:
    static int compteur_;
};

#endif // EXCEPTIONCREATUREMORTE_H
