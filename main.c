#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "main.h"

int main()
{
    srand(time(NULL)); // Initialisation du generateur de nombre aleatoire
    const int MIN = 1;
    char motSecret[100], lettreTrouvee[20];
    char chaineAffichage[20];
    char maLettre = 0;
    // FILE* fichier = NULL;
    char *suiteChaine = NULL;
    char *suitechainTest = NULL;
    int i = 0, longueurChaine = 0, coupsRestant = 10, cpt = 0, noMot=0;
    printf("\nBienvenu dans le Pendule\n\n");
    cpt = compteurMot();
    noMot = (rand() % (cpt - MIN + 1)) + MIN; // Prends un nb au hazard entre MIN et (cpt - MIN + 1)
    printf("\nLe no de Mots dans le Dictionnaire est %d, le no aleatoire generee est : %d\n", cpt, noMot);
    // On recommence � lire le fichier depuis le d�but. On s'arr�te lorsqu'on est arriv�s au bon mot
    choixMotSecret (noMot, motSecret);
    longueurChaine = strlen(motSecret);
    initialisationChaineAffichage(chaineAffichage, longueurChaine);
    while (1)
    {
        printf("Quel est le mot secret : %s\n", chaineAffichage);
        printf("Proposez une Lettre : ");
        maLettre = lireCaractere();
        printf("\n");
        suitechainTest= strchr(chaineAffichage, maLettre); //Pour s'assurer que l'utilisateur n'entre pas les caracteres deja connus
        if(suitechainTest!=NULL){
            printf("\aCaractere deja decouvert,entrez un autre caractere\n");
            continue;
        }
        suiteChaine = strchr(motSecret, maLettre); // On verifie si la lettre entree est dans le mot secret
        if (suiteChaine != NULL) // Si elle est presente
        {
            /* Le i permet d'acceder a la possition exacte ou l'on doit ajouter les nouveau caracteres
            trouve. On devoile ensuite le mot secret avec les lettres deja trouvees */
            stockerLettre(lettreTrouvee, maLettre, i);
            i++;
            affichageLettre(motSecret, lettreTrouvee, chaineAffichage);
            if (strcmp(motSecret, chaineAffichage) == 0)
            {
                printf("Gagne ! Le mot secret etait bien %s\n", motSecret);
                break;
            }

            coupsRestant = coupsRestant;
            printf("Vous avez %d coups restant\n", coupsRestant);

        }
        else
        {
            coupsRestant--;
            printf("Vous avez %d coups restant\n", coupsRestant);
        }
        if (coupsRestant == 0)
        {
            printf("\n\nFin de la partie. Le mot secret etait %s \n", motSecret);
            break;
        }

    }

    return 0;
}

