#include <stdio.h>
#include <string.h>
#include "voiture.h"

// Fonction pour ajouter une nouvelle voiture
void ajouter_voiture(Voiture voitures[], int *nombre) {
    Voiture nouvelle;
    printf("Entrez le nom de l'utilisateur : ");
    scanf("%s", nouvelle.utilisateur);
    printf("Entrez l'ID : ");
    scanf("%d", &nouvelle.id);
    printf("Entrez la marque : ");
    scanf("%s", nouvelle.marque);
    printf("Entrez le modele : ");
    scanf("%s", nouvelle.modele);
    printf("Entrez le type de carburant : ");
    scanf("%s", nouvelle.carburant);
    printf("Entrez le nombre de places : ");
    scanf("%d", &nouvelle.places);
    printf("Entrez la transmission (Automatique/Manuelle) : ");
    scanf("%s", nouvelle.transmission);
    printf("Entrez le prix par jour : ");
    scanf("%f", &nouvelle.prix_par_jour);
    printf("Est-elle disponible ? (1 pour oui, 0 pour non) : ");
    scanf("%d", &nouvelle.disponible);

    voitures[*nombre] = nouvelle;
    (*nombre)++;
    printf("Voiture ajoutee avec succes !\n");
}
// Fonction pour modofier une nouvelle voiture
void modifier_voiture(Voiture voitures[], int nombre) {
    int id;
    printf("Entrez l'ID de la voiture a modifier : ");
    scanf("%d", &id);
    for (int i = 0; i < nombre; i++) {
        if (voitures[i].id == id) {
            printf("Entrez les nouvelles informations :\n");
            ajouter_voiture(voitures, &i);
            printf("Voiture modifiee avec succes !\n");
            return;
        }
    }
    printf("Voiture non trouvee.\n");
}
// Fonction pour supprimer une nouvelle voiture
void supprimer_voiture(Voiture voitures[], int *nombre) {
    int id;
    printf("Entrez l'ID de la voiture a supprimer : ");
    scanf("%d", &id);
    for (int i = 0; i < *nombre; i++) {
        if (voitures[i].id == id) {
            for (int j = i; j < *nombre - 1; j++) {
                voitures[j] = voitures[j + 1];
            }
            (*nombre)--;
            printf("Voiture supprimee avec succes !\n");
            return;
        }
    }
    printf("Voiture non trouvee.\n");
}
// Fonction pour afficher toutes les voitures
void afficher_voitures(Voiture voitures[], int nombre) {
    printf("\nListe des voitures disponibles :\n");
    for (int i = 0; i < nombre; i++) {
        printf("ID: %d, Marque: %s, Modele: %s, %s , %s , %d places , Prix: %.2f, Disponible: %s\n",
               voitures[i].id, voitures[i].marque, voitures[i].modele,
               voitures[i].carburant,
               voitures[i].transmission,
               voitures[i].places,
               voitures[i].prix_par_jour,
               voitures[i].disponible ? "Oui" : "Non");
    }
}
// Fonction pour rechercher une voiture
void rechercher_voiture(Voiture voitures[], int nombre) {
    int choix;
    printf("Rechercher par :\n");
    printf("1. Marque\n");
    printf("2. Disponibilite\n");
    printf("Entrez votre choix : ");
    if (scanf("%d", &choix) != 1) {
        printf("Entrée invalide.\n");
        while (getchar() != '\n'); // Vider le buffer
        return;
    }
    if (choix == 1) {
        char marque[50];
        printf("Entrez la marque a rechercher : ");
        while (getchar() != '\n'); // Vider le buffer
        fgets(marque, sizeof(marque), stdin);
        marque[strcspn(marque, "\n")] = '\0'; // Enlever le saut de ligne

        printf("\nResultats de la recherche pour la marque '%s':\n", marque);
        int trouve = 0;
        for (int i = 0; i < nombre; i++) {
            if (strcmp(voitures[i].marque, marque) == 0) {
                printf("ID: %d, Marque: %s, Modele: %s, %s , %s , %d places , Prix: %.2f, Disponible: %s\n",
                       voitures[i].id, voitures[i].marque, voitures[i].modele,
               voitures[i].carburant,
               voitures[i].transmission,
               voitures[i].places,
               voitures[i].prix_par_jour,
               voitures[i].disponible ? "Oui" : "Non");
                trouve = 1;
            }
        }
        if (!trouve) {
            printf("Aucune voiture trouvee pour cette marque.\n");
        }

    } else if (choix == 2) {
        int dispo;
        printf("Entrez la disponibilite (1 pour disponible, 0 pour non disponible) : ");
        if (scanf("%d", &dispo) != 1 || (dispo != 0 && dispo != 1)) {
            printf("Entrée invalide.\n");
            while (getchar() != '\n'); // Vider le buffer
            return;
        }

        printf("\nResultats de la recherche pour les voitures %s:\n",
               dispo ? "disponibles" : "non disponibles");
        int trouve = 0;
        for (int i = 0; i < nombre; i++) {
            if (voitures[i].disponible == dispo) {
                printf("ID: %d, Marque: %s, Modele: %s, %s , %s , %d places , Prix: %.2f, Disponible: %s\n",
                       voitures[i].id, voitures[i].marque, voitures[i].modele,
               voitures[i].carburant,
               voitures[i].transmission,
               voitures[i].places,
               voitures[i].prix_par_jour,
               voitures[i].disponible ? "Oui" : "Non");
                trouve = 1;
            }
        }
        if (!trouve) {
            printf("Aucune voiture trouvee avec cette disponibilite.\n");
        }

    } else {
        printf("Choix invalide. Veuillez reessayer.\n");
    }
}

// Fonction pour trier les voitures par marque
void trier_voitures(Voiture voitures[], int nombre) {
    for (int i = 0; i < nombre - 1; i++) {
        for (int j = i + 1; j < nombre; j++) {
            if (strcmp(voitures[i].marque, voitures[j].marque) > 0) {
                Voiture temp = voitures[i];
                voitures[i] = voitures[j];
                voitures[j] = temp;
            }
        }
    }
    printf("Voitures triees avec succes !\n");
}
// Fonction pour trier les voitures par prix
void trier_voitures_par_prix(Voiture voitures[], int nombre) {
    for (int i = 0; i < nombre - 1; i++) {
        for (int j = i + 1; j < nombre; j++) {
            if (voitures[i].prix_par_jour > voitures[j].prix_par_jour) {
                Voiture temp = voitures[i];
                voitures[i] = voitures[j];
                voitures[j] = temp;
            }
        }
    }
    printf("Les voitures ont ete triees par prix (ordre croissant).\n");
}
// Fonction pour sauvegarder les données dans un fichier CSV
void sauvegarder_csv(Voiture voitures[], int nombre, const char *nom_fichier) {
    FILE *fichier = fopen(nom_fichier, "w");
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        return;
    }
    fprintf(fichier, "ID,Marque,Utilisateur,Modele,Carburant,Places,Transmission,Prix,Disponibilite\n");
    for (int i = 0; i < nombre; i++) {
        fprintf(fichier, "%d,%s,%s,%s,%s,%d,%s,%.2f,%d\n",
                voitures[i].id, voitures[i].marque, voitures[i].utilisateur,
                voitures[i].modele, voitures[i].carburant, voitures[i].places,
                voitures[i].transmission, voitures[i].prix_par_jour, voitures[i].disponible);
    }
    fclose(fichier);
    printf("Donnees sauvegardees avec succes !\n");
}
// Fonction pour charger les données dans un fichier CSV
void charger_csv(Voiture voitures[], int *nombre, const char *nom_fichier) {
    FILE *fichier = fopen(nom_fichier, "r");
    char ligne[256];
    *nombre = 0;
    fgets(ligne, sizeof(ligne), fichier);
    while (fgets(ligne, sizeof(ligne), fichier)) {
        Voiture v;
        sscanf(ligne, "%d,%49[^,],%49[^,],%49[^,],%19[^,],%d,%19[^,],%f,%d",&v.id, v.marque, v.utilisateur, v.modele, v.carburant, &v.places,v.transmission, &v.prix_par_jour, &v.disponible);
        voitures[*nombre] = v;
        (*nombre)++;
    }
    fclose(fichier);
}
