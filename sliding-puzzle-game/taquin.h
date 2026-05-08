#ifndef __TAQUIN__
#define __TAQUIN__

#include <MLV/MLV_image.h>

#define NB_COL 4
#define NB_LIG 4

typedef struct
{
    int lig;
    int col;
} Carre;

typedef struct
{
    Carre vide;
    Carre bloc [NB_COL][NB_LIG];
} Plateau;

void initialisationPlateau(Plateau *P);

void melanger(Plateau *P);

void afficherPlateau(Plateau *P, MLV_Image* img);

void echanger(Plateau *P, int l, int c);

int estGagnant(Plateau *P);

#endif