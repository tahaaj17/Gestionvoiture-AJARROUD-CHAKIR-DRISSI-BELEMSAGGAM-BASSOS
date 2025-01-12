Rapport sur les Fonctionnalités du Code de Gestion de Location de Voitures en Langage C :

ENCADRÉ PAR : Pr .EL ALAOUI ALI
REALISÉ  PAR : AJARROUD MOHAMED TAHA - DRISSI ABDELLAH - BELEMSAGGAM ANAS - CHAKIR KHALIL - BASSOS TAHA MUSTAPHA

Introduction

Ce programme en langage C est une application de gestion de location de voitures. Il permet de manipuler un inventaire de voitures via diverses opérations comme l'ajout, la modification, la suppression, la recherche, le tri et la sauvegarde des données. Le programme interagit avec un fichier CSV pour la persistance des données.

Fonctionnalités Principales
1. Chargement des données depuis un fichier CSV
Fonction: charger_csv
Description: Cette fonction lit les données des voitures à partir d'un fichier CSV (« voitures.csv ») et les stocke dans un tableau de structures Voiture.
2. Ajout d'une voiture
Fonction: ajouter_voiture
Description: Permet à l'utilisateur d'ajouter une nouvelle voiture en entrant les détails comme l'ID, la marque, le modèle, le carburant, le nombre de places, la transmission, le prix par jour et la disponibilité.
3. Modification d'une voiture
Fonction: modifier_voiture
Description: Permet de modifier les informations d'une voiture existante en utilisant son ID comme référence.
4. Suppression d'une voiture
Fonction: supprimer_voiture
Description: Supprime une voiture de l'inventaire à partir de son ID.
5. Affichage des voitures
Fonction: afficher_voitures
Description: Affiche toutes les voitures enregistrées avec leurs détails (ID, marque, modèle, prix, disponibilité).
6. Recherche de voitures
Fonction: rechercher_voiture
Description: Permet de rechercher des voitures par marque ou par disponibilité.
7. Tri des voitures
Fonctions: trier_voitures et trier_voitures_par_prix
Description:
trier_voitures trie les voitures par ordre alphabétique de la marque.
trier_voitures_par_prix trie les voitures par prix de location journalier de manière croissante.
8. Sauvegarde des données
Fonction: sauvegarder_csv
Description: Sauvegarde les données des voitures dans un fichier CSV afin d'assurer la persistance des modifications.

Interface Utilisateur

Le programme propose une interface textuelle où l'utilisateur peut sélectionner les options suivantes :
Ajouter une voiture
Modifier une voiture
Supprimer une voiture
Afficher toutes les voitures
Rechercher une voiture
Trier les voitures
Sauvegarder et quitter

Gestion des Erreurs
Vérification des entrées utilisateur (ex. nom vide, choix invalide).
Messages d'erreur en cas de fichier introuvable ou de données non valides.

Conclusion
Ce programme offre une gestion complète d'un parc automobile pour une application de location de voitures. Il combine des opérations CRUD (Create, Read, Update, Delete) et des fonctions de tri/recherche pour faciliter la gestion des voitures, avec une sauvegarde dans un fichier CSV pour la persistance des données.






