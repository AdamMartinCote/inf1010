/*
Fichier: ExceptionEchecCapture.h
inf1010 TP 6
par Adam Martin-Cote et Jad Sebti
remis le 1er decembre 2016
*/
#ifndef EXCEPTIONECHECCAPTURE_H
#define EXCEPTIONECHECCAPTURE_H

#include <stdexcept>
class ExceptionEchecCapture : public std::runtime_error
{
public:
    ExceptionEchecCapture(std::string what_args = "")
        :std::runtime_error(what_args)
    {}
};
#endif // EXCEPTIONECHECCAPTURE_H
