//
// Created by ACER on 16/12/2024.
//

#ifndef PROJET_GTK_WINDOW_H
#define PROJET_GTK_WINDOW_H
#include "global.h"
#include "colors.h"

#define MAX 100
typedef struct window
{
GtkWidget *window;
    dimension dim;        // Dimensions de la fenêtre
    gint border_size;     // Épaisseur de la bordure de la fenêtre
    gchar title[MAX];     // Titre de la fenêtre (maximum MAX caractères)
    gchar icon_name[MAX]; // Nom de l'icône de la fenêtre
    gint  resisable;      // Indique si la fenêtre est redimensionnable
    // (0: FALSE, 1: TRUE)
    gchar position;       // Position initiale de la fenêtre [c: GTK_WIN_POS_CENTER]
    // ou  [m: GTK_WIN_POS_MOUSE] ...
    coordonnees cord;     // Coordonnées de positionnement de la fenêtre
    // par rapport à l'axe y et x
    hexa_color bgColor;   // Couleur de fond de la fenêtre
    MonImage bgImg;       // Image de fond de la fenêtre

}Mywindow;


Mywindow * init_window(dimension dim , gint border , gchar titre[MAX], gchar icone[MAX],gint bool , gchar pos , coordonnees coord, hexa_color bgcolor , MonImage bgimg){

    Mywindow *fenetre= NULL;

    fenetre= (Mywindow*) malloc(sizeof (Mywindow));

    if(!fenetre)
    {
        g_print("\n Erreur d'allocation");
        exit(EXIT_FAILURE);
    }

    fenetre->dim= dim;
    fenetre->border_size = border;
    strcpy(fenetre->title,titre);
    strcpy(fenetre->icon_name,icone);
    fenetre->position=pos;
    fenetre->cord=coord;
    fenetre->bgColor=bgcolor;
    fenetre->bgImg=bgimg;

    return (Mywindow*)fenetre;



}


// fonction pour creer une fenetre

void create_window(Mywindow *fenetre){

    if(!fenetre)
    {
        g_print("\n Erreur");
        exit(EXIT_FAILURE);
    }
fenetre->window= gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_window_set_title(GTK_WINDOW(fenetre->window),fenetre->title);
    gtk_window_set_default_size(GTK_WINDOW(fenetre->window),fenetre->dim.width,fenetre->dim.height);
    gtk_window_set_position(GTK_WINDOW(fenetre->window),fenetre->position);

    if(fenetre->resisable==1)
        gtk_window_set_resizable(GTK_WINDOW(fenetre->window),FALSE);
    else
        gtk_window_set_resizable(GTK_WINDOW(fenetre->window),TRUE);

    gtk_window_move(GTK_WINDOW(fenetre->window),fenetre->cord.x,fenetre->cord.y);

    gtk_widget_override_background_color(GTK_WINDOW(fenetre->window),GTK_STATE_FLAG_NORMAL,&fenetre->bgColor);

    if (strlen(fenetre->icon_name) > 0) {
        gtk_window_set_icon_from_file(GTK_WINDOW(fenetre->window), fenetre->icon_name, NULL);
    }




    // Image de fond
    if (fenetre->bgImg.Image != NULL) {
        GtkWidget *background = redimmensionner_Img(fenetre->bgImg.Image,
                                                    fenetre->dim.height,
                                                    fenetre->dim.width);

    }


}

#endif //PROJET_GTK_WINDOW_H
