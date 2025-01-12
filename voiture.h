#pragma once
#include <stdio.h>

// Définition de la structure Voiture
typedef struct {
    int id;                    // Identifiant unique de la voiture
    char marque[50];           // Marque de la voiture
    char utilisateur[50];      // Nom de l'utilisateur actuel de la voiture
    char modele[50];           // Modèle de la voiture
    char carburant[20];        // Type de carburant (essence, diesel, etc.)
    int places;                // Nombre de places dans la voiture
    char transmission[20];     // Type de transmission (manuelle, automatique, etc.)
    float prix_par_jour;       // Prix de location par jour
    int disponible;            // Disponibilité de la voiture (1 pour disponible, 0 pour non disponible)
} Voiture;
// Fonction pour ajouter une voiture à la liste
void ajouter_voiture(Voiture voitures[], int *nombre);
// Fonction pour modifier les informations d'une voiture existante
void modifier_voiture(Voiture voitures[], int nombre);
// Fonction pour supprimer une voiture de la liste
void supprimer_voiture(Voiture voitures[], int *nombre);
// Fonction pour afficher toutes les voitures dans la liste
void afficher_voitures(Voiture voitures[], int nombre);
// Fonction pour rechercher une voiture par des critères spécifiques
void rechercher_voiture(Voiture voitures[], int nombre);
// Fonction pour trier les voitures (par exemple, par modèle, marque, etc.)
void trier_voitures(Voiture voitures[], int nombre);
// Fonction pour trier les voitures par prix (prix par jour)
void trier_voitures_par_prix(Voiture voitures[], int nombre);
// Fonction pour sauvegarder la liste des voitures dans un fichier CSV
void sauvegarder_csv(Voiture voitures[], int nombre, const char *nom_fichier);
// Fonction pour charger la liste des voitures depuis un fichier CSV
void charger_csv(Voiture voitures[], int *nombre, const char *nom_fichier);
