//
// Created by ACER on 16/12/2024.
//

#ifndef PROJET_GTK_COORDONNEES_H
#define PROJET_GTK_COORDONNEES_H
#include "global.h"
typedef struct cd
{
    gint x;
    gint y;
}coordonnees;


coordonnees* create_coordonnees(gint x, gint y)
{
    // Allocation dynamique de mémoire
    coordonnees *cord = (coordonnees*)malloc(sizeof(coordonnees));
    if (cord == NULL)
    {
        // Gestion de l'échec d'allocation mémoire
        perror("Erreur lors de l'allocation de la structure coordonnees");
        exit(EXIT_FAILURE);
    }
    cord->x = x;
    cord->y = y;
    // Retourne un pointeur vers la structure coordonnees initialisée
    return cord;
}//Fin fonction create_coordonnees()



#endif //PROJET_GTK_COORDONNEES_H
