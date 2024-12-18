#ifndef PROJET_GTK_IMAGE_H
#define PROJET_GTK_IMAGE_H
#include "global.h"

typedef struct img {
    GtkWidget *Image;
    gchar Img_path[100];
    dimension Img_dim;
    coordonnees Img_cord;
} MonImage;

// Fonction pour redimensionner une image (retourne un GtkWidget)
GtkWidget* redimmensionner_Img(GtkWidget *Img, gint height, gint width) {
    if (!Img) {
        g_print("\nErreur d'allocation\n");
        exit(EXIT_FAILURE);
    }

    // Extraire le pixbuf de l'image GTK
    GtkImage *gtk_image = GTK_IMAGE(Img);
    GdkPixbuf *original_pixbuf = gtk_image_get_pixbuf(gtk_image);

    // Redimensionner le pixbuf
    GdkPixbuf *resized_pixbuf = gdk_pixbuf_scale_simple(original_pixbuf, width, height, GDK_INTERP_BILINEAR);
    if (resized_pixbuf == NULL) {
        g_print("\nErreur lors du redimensionnement de l'image\n");
        exit(EXIT_FAILURE);
    }

    // Créer un nouveau widget GtkImage à partir du pixbuf redimensionné
    GtkWidget *resized_image_widget = gtk_image_new_from_pixbuf(resized_pixbuf);

    // Libérer le pixbuf redimensionné (il est maintenant utilisé dans le widget)
    g_object_unref(resized_pixbuf);

    return resized_image_widget;
}

// Fonction pour créer une image
MonImage *creer_image(gchar path[100], dimension dim, coordonnees cord) {
    MonImage *new_img = (MonImage*) malloc(sizeof(MonImage));
    if (new_img == NULL) {
        g_print("\nErreur d'allocation pour MonImage\n");
        exit(EXIT_FAILURE);
    }

    // Créer le widget GtkImage à partir du fichier
    new_img->Image = gtk_image_new_from_file(path);
    new_img->Img_dim.height = dim.height;
    new_img->Img_dim.width = dim.width;
    new_img->Img_cord.x = cord.x;
    new_img->Img_cord.y = cord.y;

    // Redimensionner l'image
    new_img->Image = redimmensionner_Img(new_img->Image, new_img->Img_dim.height, new_img->Img_dim.width);

    return new_img;
}

#endif // PROJET_GTK_IMAGE_H
