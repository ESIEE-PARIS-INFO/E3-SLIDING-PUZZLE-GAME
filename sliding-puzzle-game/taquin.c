#include "taquin.h"
#include <MLV/MLV_image.h>
#include <MLV/MLV_all.h>
#include <stdlib.h>

void initialisationPlateau(Plateau *P)
{
    int i, j;

    for (i = 0; i < NB_COL; i++)
    {
        for (j = 0; j < NB_LIG; j++)
        {
            (P->bloc[i][j]).col = i;
            (P->bloc[i][j]).lig = j;
        }
    }

    P->vide.col = NB_COL - 1;
    P->vide.lig = NB_LIG - 1;
}

// pas encore utilisé, pour dessiner les contours de case
void decouper(Plateau *P){
    int i, j;
    
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            int x = j * 128;
            int y = i * 128;

            MLV_draw_rectangle(x, y, 128, 128, MLV_COLOR_GRAY);
        }
    }
}

void afficherPlateau(Plateau *P, MLV_Image* img) {
    int x, y; // x = colonne, y = ligne

    for (x = 0; x < NB_COL; x++) {
        for (y = 0; y < NB_LIG; y++) {
            
            // Si on est sur la case vide
            if (P->vide.col == x && P->vide.lig == y) {
                MLV_draw_filled_rectangle(x * 128, y * 128, 128, 128, MLV_COLOR_BLACK);
            } else {
                int orig_x = P->bloc[x][y].col;
                int orig_y = P->bloc[x][y].lig;

                MLV_draw_partial_image(
                    img,
                    orig_x * 128, orig_y * 128,
                    128, 128,
                    x * 128, y * 128
                );
            }
        }
    }
}

void echanger(Plateau *P, int col, int lig){
    int lig_vide = P->vide.lig;
    int col_vide = P->vide.col;

    Carre tmp = P->bloc[col][lig];
    P->bloc[col][lig] = P->bloc[col_vide][lig_vide];
    P->bloc[col_vide][lig_vide] = tmp;

    P->vide.col = col;
    P->vide.lig = lig;
}

void melanger(Plateau *P){
    int k;

    for(k = 0; k < 120; k++){
        int c = rand() % 4;

        int vl = P->vide.lig;
        int vc = P->vide.col;

        switch(c){
            // aller en haut
            case 0:
                if(vl > 0){
                    echanger(P, vc, vl - 1); // vc d'abord, vl ensuite
                }
                break;
            // aller en bas
            case 1:
                if(vl < NB_LIG - 1){
                    echanger(P, vc, vl + 1);
                }
                break;
            // aller à gauche
            case 2:
                if(vc > 0){
                    echanger(P, vc - 1, vl);
                }
                break;
            // aller à droite
            case 3:
                if(vc < NB_COL - 1){
                    echanger(P, vc + 1, vl);
                }
                break;
        }
    }
}

// Ajoute ceci dans taquin.c (et n'oublie pas le prototype dans taquin.h)
int estGagnant(Plateau *P) {
    int i, j;
    for (i = 0; i < NB_COL; i++) {
        for (j = 0; j < NB_LIG; j++) {
            // Si une seule case n'est pas à sa place d'origine
            if (P->bloc[i][j].col != i || P->bloc[i][j].lig != j) {
                return 0;
            }
        }
    }
    return 1;
}