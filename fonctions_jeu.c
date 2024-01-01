#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char lireCaractere()
{
    char caractere = 0;
    caractere = getchar(); // On lit le premier caractère
    caractere = toupper(caractere);  //// On met la lettre en majuscule si elle ne l'est pas déjà

    while (getchar() != '\n') ;

    return caractere; // On retourne le premier caractère qu'on a lu

}

// Initialisation de chaine affiche
void initialisationChaineAffichage (char* chaineAffiche ,int longueur)
{
    int i = 0;
    for (i = 0; i < longueur; i++)
    {
        chaineAffiche[i] = '*';
    }
    chaineAffiche[longueur] = '\0';

}

// Stockage des lettres trouvees
void stockerLettre (char* lettreTrouvee, char lettre, int i)
{
    lettreTrouvee[i] = lettre;
    lettreTrouvee[i+1] = '\0';  // Fermeture de la chaine

}

/* Affichage des Lettres Trouvees. Ici je compare chaqu'un des lettres trouvees avec le mot original, lorsque
ca correspond, je revele le caractere via la chaine 'chaineAffichage' */
// N.B char* motSecret = char motSecret[]
void affichageLettre (const char* motSecret, const char* lettreTrouvee, char* chaineAffichage)
{
    int j = 0, k = 0;
    while (lettreTrouvee[k] != '\0')
    {
        j = 0;
        while (motSecret[j] != '\0')
        {
            if ((lettreTrouvee[k] == motSecret[j]) && (chaineAffichage[j] == '*'))
            {
                chaineAffichage[j] = motSecret[j];
            }
            j++;

        }
        k++;
    }
}

// Code pour obtenir le nombre de mots dans le dictionnaire
int compteurMot ()
{
    int cpt = 0, caractere_actu=0;
    FILE* fichier = NULL;
    fichier = fopen("liste_mots.txt", "r");
    if (fichier != NULL)
    {
        rewind(fichier);
        caractere_actu = fgetc(fichier);
        while (caractere_actu != EOF)
        {
            if (caractere_actu == '\n')
            {
                cpt++;
            }
            caractere_actu = fgetc(fichier);  // Repositionnement du curseur
        }
        fclose(fichier);
    }
    return cpt;
}

// Choix  du Mot Secret
void choixMotSecret (int noMot, char* motSecret)
{
    FILE* fichier = NULL;
    int caractereLu = 0;
    fichier = fopen("liste_mots.txt", "r");
    if (fichier != NULL)
    {
        /* Technique pour placer le curseur a la bonne position.
        On recommence à lire le fichier depuis le début. On s'arrête lorsqu'on arrive au bon mot */
        rewind(fichier);
        while (noMot > 1)
        {
        caractereLu = fgetc(fichier);
        if (caractereLu == '\n')
            noMot--;
        }
        // Le curseur etant au bon endroit, on a n'a plus qu'a recuperer le Mot via un fgets
        fgets(motSecret, 100, fichier);
        // On vire l'\n à la fin. L'indice ici est tres correct, en effet, strlen(motSecret) - 1 nous renvoie a la position exacte du '\n'
        motSecret[strlen(motSecret) - 1] = '\0';
        fclose(fichier);
    }
    else
        printf("Echec d'ouverture du dictionnaire\n\n");

}


