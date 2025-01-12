#include <stdio.h>
#include <string.h>
#include "voiture.h"

int main() {
    Voiture voitures[100];  // Tableau pour stocker jusqu'à 100 voitures
    int nombre = 0;  // Nombre de voitures actuellement dans le tableau
    int sous_choix;  // Variable pour les sous-options du menu
    char nom_utilisateur[50];  // Stocke le nom de l'utilisateur
    const char *fichier_csv = "voitures.csv";  // Nom du fichier CSV pour la sauvegarde

    // Charger les données existantes à partir du fichier CSV
    charger_csv(voitures, &nombre, fichier_csv);
    printf("Bienvenue dans l'application de location de voitures !\n");

    // Demander le nom de l'utilisateur et vérifier qu'il n'est pas vide
    do {
        printf("Veuillez entrer votre nom pour continuer : ");
        scanf(" %49[^\n]", nom_utilisateur);  // Correction ici
        if (strlen(nom_utilisateur) == 0) {
            printf("Erreur : Le nom ne peut pas etre vide. Veuillez reessayer.\n");
        }
    } while (strlen(nom_utilisateur) == 0);

    printf("Bonjour %s ! Vous pouvez maintenant acceder au menu principal.\n", nom_utilisateur);

    int choix;
    // Boucle principale du menu
    do {
        printf("\n--- MENU ---\n");
        printf("1. Ajouter une voiture\n");
        printf("2. Modifier une voiture\n");
        printf("3. Supprimer une voiture\n");
        printf("4. Afficher toutes les voitures\n");
        printf("5. Rechercher une voiture\n");
        printf("6. Trier les voitures\n");
        printf("7. Sauvegarder et quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouter_voiture(voitures, &nombre);  // Ajouter une nouvelle voiture
                break;
            case 2:
                modifier_voiture(voitures, nombre);  // Modifier les informations d'une voiture
                break;
            case 3:
                supprimer_voiture(voitures, &nombre);  // Supprimer une voiture
                break;
            case 4:
                afficher_voitures(voitures, nombre);  // Afficher toutes les voitures
                break;
            case 5:
                rechercher_voiture(voitures, nombre);  // Rechercher une voiture
                break;
            case 6:
                printf("1. Trier par marque\n");
                printf("2. Trier par prix\n");
                printf("Entrez votre choix : ");
                scanf("%d", &sous_choix);

                if (sous_choix == 1) {
                    trier_voitures(voitures, nombre);  // Trier par marque
                } else if (sous_choix == 2) {
                    trier_voitures_par_prix(voitures, nombre);  // Trier par prix
                } else {
                    printf("Choix invalide pour le tri.\n");
                }
                break;
            case 7:
                printf("Sauvegarde des donnees...\n");
                sauvegarder_csv(voitures, nombre, fichier_csv);  // Sauvegarder dans le fichier CSV
                printf("Merci d'avoir utilise l'application, %s. A bientot !\n", nom_utilisateur);
                break;
            default:
                printf("Choix invalide, veuillez reessayer.\n");
        }
    } while (choix != 7);  // Continuer tant que l'utilisateur ne choisit pas de quitter

    return 0;
}
