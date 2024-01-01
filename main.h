#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

/* Le jeu avec les ifndef, def, et endif permet de s'assurer que les fxn du main.h soient inclus une fois pour toutes,
   afin d'eviter les boucles infinies */
char lireCaractere();
void initialisationChaineAffichage (char* chaineAffiche, int longueur);
void stockerLettre (char* lettreTrouvee, char lettre, int i);
void affichageLettre (const char* motSecret, const char* lettreTrouvee, char* chaineAffichage);
int compteurMot ();
void choixMotSecret (int noMot, char* motSecret);

#endif // MAIN_H_INCLUDED
