//
// Created by ACER on 17/12/2024.
//

#ifndef PROJET_GTK_BUTTON_H
#define PROJET_GTK_BUTTON_H
#include "global.h"

typedef struct bt{
    GtkWidget *button ;
    gchar label[100];
    Myicon button_icon;

    hexa_color button_color;
    dimension button_dim;
    coordonnees button_coord;
}Button;

// fonction pour initialiser un bouton

Button * initier_button(gchar l[100], gchar icon[100], hexa_color bc, dimension bdim, coordonnees bcord){
    Button *new_button;
    new_button= (Button*) malloc(sizeof (Button));
    if(!new_button)
    {
        g_print("\n erreur d'allocation ");
        exit(EXIT_FAILURE);
    }
    strcpy(new_button->label,l);

    strcpy(new_button->button_icon.icon_path , icon);
    new_button->button_dim=bdim;
    new_button->button_coord=bcord;

}





#endif //PROJET_GTK_BUTTON_H
