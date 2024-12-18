#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<gtk/gtk.h>
#include "global.h"


int main(int argc, char *argv[])
{

    gtk_init(&argc, &argv);
    //creation d'un type color
    hexa_color *myColor = NULL;
    myColor =init_hexa_color(myColor, "pink");
    //creation type dimension
    dimension *dim= creer_dimension(1000,1000);

    //creation type coordonees
    coordonnees *cord= create_coordonnees(20,30);

    // Chemin vers l'image de fond
     gchar *bg_path="bg.jpg";
    MonImage *bgImg = creer_image(bg_path,*dim, *cord);


    //creation+initialisation
    Mywindow *maFenetre= init_window(*dim,3,"hafsa's window","bg.jpg",1,
                                   GTK_WIN_POS_CENTER_ALWAYS,*cord,*myColor,*bgImg);
    create_window(maFenetre);
    gtk_window_set_resizable(GTK_WINDOW(maFenetre->window),FALSE);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Création de widgets
    GtkWidget *img= maFenetre->bgImg.Image;

    GtkWidget *label = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(label), "<span font='40'><b>Bienvenue dans GTK !</b></span>");
    GtkWidget *button = gtk_button_new_with_label("Cliquez-moi");


////////////////////////////////////////////////////////////////////////////////////////////////////////////

    GtkWidget *fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(maFenetre->window),fixed);
    gtk_fixed_put(GTK_FIXED(fixed),img, 0,0);
    gtk_fixed_put(GTK_FIXED(fixed), label, 50, 100);  // Ajouter un label à la position (50, 100)
    gtk_fixed_put(GTK_FIXED(fixed), button, 400, 700); // Ajouter un bouton à la position (200, 300)

    GtkWidget *entry = gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(entry), 100);  // Limite à 50 caractères
    gtk_entry_set_visibility(GTK_ENTRY(entry), FALSE); // Masquer les caractères
    gtk_fixed_put(GTK_FIXED(fixed), entry, 300, 300); // Placer l'Entry à (100, 100)


    GtkWidget *checkButton= gtk_check_button_new_with_label("labele");
    gtk_fixed_put(GTK_FIXED(fixed),checkButton,900,900);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    GtkWidget *radio;






    radio= gtk_radio_button_new_with_label(NULL,"ouiiiiiiii");

    gtk_fixed_put(GTK_FIXED(fixed),radio, 600,900);





//////////////////////////////////////////////////////////////////////////////////////////////////////////////:

    gtk_widget_show_all(maFenetre->window);
    gtk_main();
    return 0;
}
