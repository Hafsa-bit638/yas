//
// Created by ACER on 16/12/2024.
//

#ifndef PROJET_GTK_COLORS_H
#define PROJET_GTK_COLORS_H
#include "global.h"

typedef struct {
    GdkRGBA color;
    gfloat red;    // Composant rouge (valeur entre 0.0 et 1.0)
    gfloat green;  // Composant vert (valeur entre 0.0 et 1.0)
    gfloat blue;   // Composant bleu (valeur entre 0.0 et 1.0)
    gfloat alpha;  // Composant alpha (transparence) (valeur entre 0.0 et 1.0)
} MyColor;

MyColor * Init_color(MyColor *new_color , gfloat red , gfloat green , gfloat blue , gfloat alpha){
    new_color->red=red;
    new_color->green=green;
    new_color->blue= blue;
    new_color->alpha= alpha ;
    return new_color;
}



typedef struct hex
{
  GdkRGBA color ;
   gchar couleur[100];
}hexa_color;

hexa_color* init_hexa_color(hexa_color *mycolor , gchar *hex_code) {
    if (mycolor == NULL) {
        mycolor = malloc(sizeof(hexa_color));
        if (mycolor == NULL) {
            // Gestion de l'échec de l'allocation mémoire
            fprintf(stderr, "Erreur d'allocation mémoire\n");
            return NULL;
        }
    }


// Copie de la couleur hexadécimale dans la structure
    g_strlcpy(mycolor->couleur, hex_code, sizeof(mycolor->couleur));
// Conversion de la couleur hexadécimale en GdkRGBA
    gdk_rgba_parse(&(mycolor->color), mycolor->couleur);
// Retour de la structure initialisée
    return mycolor;
}




#endif //PROJET_GTK_COLORS_H
