#include "taquin.h"
#include <MLV/MLV_image.h>
#include <stdio.h>
#include <MLV/MLV_all.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    /* Vérification de la présence du fichier en argument */
    if(argc < 2){
        printf("Usage : %s fichier_grille\n", argv[0]);
        return 1;
    }

    Plateau P;
    initialisationPlateau(&P);

    MLV_create_window("Jeu de Taquin", "panda.png", 512, 512);

    MLV_Image* img = MLV_load_image(argv[1]);

    if (img == NULL) {
        printf("Erreur : Impossible de charger l'image '%s'.\n", argv[1]);
        MLV_free_window();
        return 1;
    }

    MLV_resize_image_with_proportions(img, 512, 512);

    melanger(&P);

    afficherPlateau(&P, img);

    MLV_update_window();

    int gagne = 0;
    int clic_x, clic_y;

    // La boucle du jeu
    while (!gagne) {
        MLV_wait_mouse(&clic_x, &clic_y);

        int col_clic = clic_x / 128;
        int lig_clic = clic_y / 128;

        // On vérifie si la case cliquée est collée à la case vide
        int diff_col = abs(col_clic - P.vide.col);
        int diff_lig = abs(lig_clic - P.vide.lig);

        if (diff_col + diff_lig == 1) {
            echanger(&P, col_clic, lig_clic);
            
            // On redessine
            afficherPlateau(&P, img);
            MLV_update_window();

            gagne = estGagnant(&P);
        }
    }

    // Affichage message victoire
    MLV_draw_text_box(
        100, 200, 312, 50, 
        "You win!", 
        2, 
        MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK,
        MLV_TEXT_CENTER,
        MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
    );
    MLV_update_window();

    MLV_wait_seconds(10);

    // on libère
    MLV_free_image(img);
    MLV_free_window();
    return 0;
}
