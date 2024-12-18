//
// Created by ACER on 16/12/2024.
//

#ifndef PROJET_GTK_ICONE_H
#define PROJET_GTK_ICONE_H
#include "global.h"

typedef struct ic{
    GdkPixbuf *icon;
    gchar icon_path[100];
    dimension icon_dim;
    coordonnees icon_cord;
}Myicon;

Myicon* creat_icon_from_file(gchar path[100], dimension dim , coordonnees cord)
{
    Myicon *new_icon=(Myicon*) malloc(sizeof (Myicon));
    if(new_icon==NULL)
    {
        g_print("\n Erreur d'allocation \n");
        exit(EXIT_FAILURE);
    }

    new_icon->icon= gdk_pixbuf_new_from_file(path,NULL);
    new_icon->icon_dim.height= dim.height;
    new_icon->icon_dim.width= dim.width;
    gdk_pixbuf_scale_simple(new_icon->icon, new_icon->icon_dim.width, new_icon->icon_dim.height, GDK_INTERP_BILINEAR);
    return new_icon;

}








#endif //PROJET_GTK_ICONE_H
