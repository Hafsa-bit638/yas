//
// Created by ACER on 16/12/2024.
//

#ifndef PROJET_GTK_DIMENSION_H
#define PROJET_GTK_DIMENSION_H
#include "global.h"



typedef struct dim
{
    gint height ; // la hauteur de l'objet
    gint width;  // la largeur de l'objet
}dimension;

// fonction pour creer une dimmension

dimension* creer_dimension(gint h , gint w)
{
    dimension *dim=(dimension *) malloc(sizeof (dimension ));
    if(dim == NULL){
        g_print("\n Erreur d'allocation ");
        exit(EXIT_FAILURE);
    }
    dim->height=h;
    dim->width=w;
    return ((dimension*)dim);
}







#endif //PROJET_GTK_DIMENSION_H
