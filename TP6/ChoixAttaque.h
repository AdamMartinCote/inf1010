/*
Fichier: ChoixAttaque.h
Auteur(s): Alexandre MAO
Date de creation: 15 Novembre 2016
Description: Widget graphique permettant l'affichage des boutons des attaques

modifications par Adam Martin-Cote et Jad Sebti
devoir remis le 1er decembre 2016
*/
#ifndef CHOIXATTAQUE_H
#define CHOIXATTAQUE_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include "Creature.h"

class ChoixAttaque : public QWidget
{
    Q_OBJECT
public:
    explicit ChoixAttaque(QWidget *parent = 0);
    QPushButton* attaque1_;
    QPushButton* attaque2_;
    QPushButton* attaque3_;
    QPushButton* attaque4_;



public slots:
    void afficherAttaques();
    void afficherAttaques(Creature* creature);
    void masquerAttaques();


};

#endif // CHOIXATTAQUE_H
