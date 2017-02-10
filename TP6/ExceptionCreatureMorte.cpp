/*
Fichier: ExceptionCreatureMorte.cpp
inf1010 TP 6
par Adam Martin-Cote et Jad Sebti
remis le 1er decembre 2016
*/
#include "ExceptionCreatureMorte.h"

    ExceptionCreatureMorte::ExceptionCreatureMorte(std::string what_args)
        : std::runtime_error(what_args)
    {
        compteur_++;
    }

    int ExceptionCreatureMorte::obtenirValeurCompteur(){
        return compteur_;
    }

    int ExceptionCreatureMorte::compteur_ = 0;
