#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Global variables
int restoExist = 0;
int repasTotal = 0;
int personTotal = 0;

// Forward structure declarations
struct Personne {
    int idPersonne;
    char nomPersonne[50];
    int age;
    float mtPaye;
};

struct Repas {
    int idRepas;
    char nom[50];
    char ingrediants[50];
    int prix;
    int qte;
    float valeurEnergetique;
};

struct Resto {
    int idResto;
    char nomResto[50];
    char adresse[200];
    int nbrEmployer;
    float heureTravaille;
    char post[50];
    struct Repas r[20];
    struct Personne p[20];
};

// Global restaurant instance
struct Resto resto;

// Function prototypes
void afficherTitre();
void afficherLigne(int length);
void ajouter();
void modifier();
void supprimer();
void afficher();

// Main function
int main() {
    system("chcp 65001 > nul"); // For Unicode support in Windows consoles
    
    int choix;
    
    do {
        // Clear screen for better UI (works in Windows)
        system("cls");
        
        afficherTitre();
        
        afficherLigne(50);
        printf("\n\t===== MENU PRINCIPAL =====\n");
        afficherLigne(50);
        printf("\n\t1. Ajouter\n");
        printf("\t2. Modifier\n");
        printf("\t3. Supprimer\n");
        printf("\t4. Afficher\n");
        printf("\t5. Quitter\n");
        afficherLigne(50);
        printf("\nVotre choix: ");
        
        if (scanf("%d", &choix) != 1) {
            // Clear input buffer in case of invalid input
            while (getchar() != '\n');
            choix = 0; // Set to invalid choice
        }
        
        switch (choix) {
            case 1:
                ajouter();
                break;
            case 2:
                modifier();
                break;
            case 3:
                supprimer();
                break;
            case 4:
                afficher();
                break;
            case 5:
                printf("\nMerci d'avoir utilisé notre programme. Au revoir!\n");
                break;
            default:
                printf("\nChoix invalide. Appuyez sur Entrée pour continuer...");
                while (getchar() != '\n'); // Clear input buffer
                getchar(); // Wait for Enter key
                break;
        }
    } while (choix != 5);

    return 0;
}

// Display title function
void afficherTitre() {
    printf("\n");
    printf(" _____           _   _              ______      ______          _                              _       \n");
    printf("|  __ \\         | | (_)             |  _  \\     | ___ \\        | |                            | |      \n");
    printf("| |  \\/ ___  ___| |_ _  ___  _ __   | | | |___  | |_/ /___  ___| |_ __ _ _   _ _ __ __ _ _ __ | |_ ___ \n");
    printf("| | __ / _ \\/ __| __| |/ _ \\| '_ \\  | | | / _ \\ |    // _ \\/ __| __/ _` | | | | '__/ _` | '_ \\| __/ __|\n");
    printf("| |_\\ \\  __/\\__ \\ |_| | (_) | | | | | |/ /  __/ | |\\ \\  __/\\__ \\ || (_| | |_| | | | (_| | | | | |_\\__ \\\n");
    printf(" \\____/\\___||___/\\__|_|\\___/|_| |_| |___/ \\___| \\_| \\_\\___||___/\\__\\__,_|\\__,_|_|  \\__,_|_| |_|\\__|___/\n");
    printf("\t\t\t\t\t\t\t\tby @s_modz & @yacine.pdf & @hamza4oudaha\n\n");
}

// Display horizontal line for UI separation
void afficherLigne(int length) {
    printf("\n");
    for (int i = 0; i < length; i++) {
        printf("-");
    }
    printf("\n");
}

// Add function
void ajouter() {
    char choix1;
    
    system("cls");
    afficherTitre();
    
    if (restoExist == 0) {
        printf("\n===== Il n'existe pas de restaurant =====\n");
        printf("Voulez-vous en ajouter un? (O = oui | N = non): ");
        scanf(" %c", &choix1);
        
        if (choix1 == 'O' || choix1 == 'o') {
            afficherLigne(50);
            printf("\n===== AJOUTER UN RESTAURANT =====\n");
            afficherLigne(50);
            
            printf("\nID: ");
            scanf("%d", &resto.idResto);  // Fixed: Added & operator

            printf("Nom: ");
            scanf(" %[^\n]", resto.nomResto);

            printf("Adresse: ");
            scanf(" %[^\n]", resto.adresse);

            printf("Nombre d'employés: ");
            scanf("%d", &resto.nbrEmployer);

            printf("Heures de travail: ");
            scanf("%f", &resto.heureTravaille);  // Fixed: Changed to float and added missing &
            
            restoExist = 1;
            printf("\nRestaurant ajouté avec succès!\n");
        } else {
            return;
        }
    } else if (restoExist == 1) {
        int choix;
        int nbrrepas;
        int nbrperso;
        
        do {
            system("cls");
            afficherTitre();
            
            afficherLigne(50);
            printf("\n===== MENU AJOUT =====\n");
            afficherLigne(50);
            printf("\n1. Ajouter un repas\n");
            printf("2. Ajouter une personne\n");
            printf("3. Retour au menu principal\n");
            afficherLigne(50);
            printf("\nVotre choix: ");
            
            scanf("%d", &choix);
            
            switch (choix) {
                case 1:
                    if (repasTotal >= 20) {
                        printf("\nLe nombre maximal de repas (20) est atteint.\n");
                        printf("Appuyez sur Entrée pour continuer...");
                        while (getchar() != '\n');
                        getchar();
                        break;
                    }
                    
                    printf("\nCombien de repas voulez-vous ajouter? ");
                    scanf("%d", &nbrrepas);
                    
                    for (int i = 0; i < nbrrepas && repasTotal < 20; i++) {
                        system("cls");
                        afficherTitre();
                        
                        afficherLigne(50);
                        printf("\n===== REPAS %d =====\n", i+1);
                        afficherLigne(50);
                        
                        printf("\nID: ");
                        scanf("%d", &resto.r[repasTotal].idRepas);

                        printf("Nom: ");
                        scanf(" %[^\n]", resto.r[repasTotal].nom);

                        printf("Ingrédients: ");
                        scanf(" %[^\n]", resto.r[repasTotal].ingrediants);

                        printf("Quantité: ");
                        scanf("%d", &resto.r[repasTotal].qte);

                        printf("Prix: ");
                        scanf("%d", &resto.r[repasTotal].prix);

                        printf("Valeur énergétique: ");
                        scanf("%f", &resto.r[repasTotal].valeurEnergetique);
                        
                        repasTotal++;
                        printf("\nRepas ajouté avec succès!\n");
                    }
                    
                    if (repasTotal == 20) {
                        printf("\nLe nombre maximal de repas (20) est atteint.\n");
                    }
                    
                    printf("\nAppuyez sur Entrée pour continuer...");
                    while (getchar() != '\n');
                    getchar();
                    break;
                    
                case 2:
                    if (personTotal >= 20) {
                        printf("\nLe nombre maximal de personnes (20) est atteint.\n");
                        printf("Appuyez sur Entrée pour continuer...");
                        while (getchar() != '\n');
                        getchar();
                        break;
                    }
                    
                    printf("\nCombien de personnes voulez-vous ajouter? ");
                    scanf("%d", &nbrperso);
                    
                    for (int i = 0; i < nbrperso && personTotal < 20; i++) {
                        system("cls");
                        afficherTitre();
                        
                        afficherLigne(50);
                        printf("\n===== PERSONNE %d =====\n", i+1);
                        afficherLigne(50);
                        
                        printf("\nID: ");
                        scanf("%d", &resto.p[personTotal].idPersonne);

                        printf("Nom: ");
                        scanf(" %[^\n]", resto.p[personTotal].nomPersonne);

                        printf("Age: ");
                        scanf("%d", &resto.p[personTotal].age);  // Fixed: Added missing &

                        printf("Montant Payé: ");
                        scanf("%f", &resto.p[personTotal].mtPaye);  // Fixed: Changed to float
                        
                        personTotal++;
                        printf("\nPersonne ajoutée avec succès!\n");
                    }
                    
                    if (personTotal == 20) {
                        printf("\nLe nombre maximal de personnes (20) est atteint.\n");
                    }
                    
                    printf("\nAppuyez sur Entrée pour continuer...");
                    while (getchar() != '\n');
                    getchar();
                    break;
                    
                case 3:
                    printf("\nRetour au menu principal...\n");
                    break;
                    
                default:
                    printf("\nChoix invalide. Appuyez sur Entrée pour continuer...");
                    while (getchar() != '\n');
                    getchar();
                    break;
            }
        } while (choix != 3);
    }
}

// Modify function
void modifier() {
    int choice;
    
    do {
        system("cls");
        afficherTitre();
        
        afficherLigne(50);
        printf("\n===== MENU MODIFICATION =====\n");
        afficherLigne(50);
        printf("\n1. Modifier le restaurant\n");
        printf("2. Modifier un repas\n");
        printf("3. Modifier une personne\n");
        printf("4. Retour au menu principal\n");
        afficherLigne(50);
        printf("\nVotre choix: ");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (restoExist == 0) {
                    printf("\nIl n'existe pas de restaurant.\n");
                } else {
                    system("cls");
                    afficherTitre();
                    
                    afficherLigne(50);
                    printf("\n===== MODIFIER LE RESTAURANT =====\n");
                    afficherLigne(50);
                    
                    printf("\nID: ");
                    scanf("%d", &resto.idResto);  // Fixed: Added & operator

                    printf("Nom: ");
                    scanf(" %[^\n]", resto.nomResto);

                    printf("Adresse: ");
                    scanf(" %[^\n]", resto.adresse);

                    printf("Nombre d'employés: ");
                    scanf("%d", &resto.nbrEmployer);

                    printf("Heures de travail: ");
                    scanf("%f", &resto.heureTravaille);  // Fixed: Changed to float and added missing &
                    
                    printf("\nModification réussie!\n");
                }
                
                printf("\nAppuyez sur Entrée pour continuer...");
                while (getchar() != '\n');
                getchar();
                break;
                
            case 2:
                if (repasTotal == 0) {
                    printf("\nAucun repas à modifier.\n");
                } else {
                    int repasMod;
                    
                    // Display existing meals for reference
                    printf("\nRepas existants:\n");
                    for (int i = 0; i < repasTotal; i++) {
                        printf("%d. %s\n", i+1, resto.r[i].nom);
                    }
                    
                    printf("\nEntrez le numéro du repas à modifier (1-%d): ", repasTotal);
                    scanf("%d", &repasMod);
                    
                    if (repasMod < 1 || repasMod > repasTotal) {
                        printf("\nNuméro de repas invalide.\n");
                    } else {
                        int index = repasMod - 1;  // Adjust for array index
                        
                        system("cls");
                        afficherTitre();
                        
                        afficherLigne(50);
                        printf("\n===== MODIFIER REPAS %d =====\n", repasMod);
                        afficherLigne(50);
                        
                        printf("\nID actuel: %d\n", resto.r[index].idRepas);
                        printf("Nouvel ID: ");
                        scanf("%d", &resto.r[index].idRepas);

                        printf("Nom actuel: %s\n", resto.r[index].nom);
                        printf("Nouveau nom: ");
                        scanf(" %[^\n]", resto.r[index].nom);

                        printf("Ingrédients actuels: %s\n", resto.r[index].ingrediants);
                        printf("Nouveaux ingrédients: ");
                        scanf(" %[^\n]", resto.r[index].ingrediants);

                        printf("Quantité actuelle: %d\n", resto.r[index].qte);
                        printf("Nouvelle quantité: ");
                        scanf("%d", &resto.r[index].qte);

                        printf("Prix actuel: %d\n", resto.r[index].prix);
                        printf("Nouveau prix: ");
                        scanf("%d", &resto.r[index].prix);

                        printf("Valeur énergétique actuelle: %.2f\n", resto.r[index].valeurEnergetique);
                        printf("Nouvelle valeur énergétique: ");
                        scanf("%f", &resto.r[index].valeurEnergetique);
                        
                        printf("\nModification réussie!\n");
                    }
                }
                
                printf("\nAppuyez sur Entrée pour continuer...");
                while (getchar() != '\n');
                getchar();
                break;
                
            case 3:
                if (personTotal == 0) {
                    printf("\nAucune personne à modifier.\n");
                } else {
                    int persoMod;
                    
                    // Display existing people for reference
                    printf("\nPersonnes existantes:\n");
                    for (int i = 0; i < personTotal; i++) {
                        printf("%d. %s\n", i+1, resto.p[i].nomPersonne);
                    }
                    
                    printf("\nEntrez le numéro de la personne à modifier (1-%d): ", personTotal);
                    scanf("%d", &persoMod);
                    
                    if (persoMod < 1 || persoMod > personTotal) {
                        printf("\nNuméro de personne invalide.\n");
                    } else {
                        int index = persoMod - 1;  // Adjust for array index
                        
                        system("cls");
                        afficherTitre();
                        
                        afficherLigne(50);
                        printf("\n===== MODIFIER PERSONNE %d =====\n", persoMod);
                        afficherLigne(50);
                        
                        printf("\nID actuel: %d\n", resto.p[index].idPersonne);
                        printf("Nouvel ID: ");
                        scanf("%d", &resto.p[index].idPersonne);

                        printf("Nom actuel: %s\n", resto.p[index].nomPersonne);
                        printf("Nouveau nom: ");
                        scanf(" %[^\n]", resto.p[index].nomPersonne);

                        printf("Age actuel: %d\n", resto.p[index].age);
                        printf("Nouvel age: ");
                        scanf("%d", &resto.p[index].age);

                        printf("Montant payé actuel: %.2f\n", resto.p[index].mtPaye);
                        printf("Nouveau montant payé: ");
                        scanf("%f", &resto.p[index].mtPaye);
                        
                        printf("\nModification réussie!\n");
                    }
                }
                
                printf("\nAppuyez sur Entrée pour continuer...");
                while (getchar() != '\n');
                getchar();
                break;
                
            case 4:
                printf("\nRetour au menu principal...\n");
                break;
                
            default:
                printf("\nChoix invalide.\n");
                printf("\nAppuyez sur Entrée pour continuer...");
                while (getchar() != '\n');
                getchar();
                break;
        }
    } while (choice != 4);
}

// Delete function
void supprimer() {
    int choice;
    
    do {
        system("cls");
        afficherTitre();
        
        afficherLigne(50);
        printf("\n===== MENU SUPPRESSION =====\n");
        afficherLigne(50);
        printf("\n1. Supprimer le restaurant\n");
        printf("2. Supprimer un repas\n");
        printf("3. Supprimer une personne\n");
        printf("4. Retour au menu principal\n");
        afficherLigne(50);
        printf("\nVotre choix: ");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (restoExist == 0) {
                    printf("\nIl n'existe pas de restaurant.\n");
                } else {
                    char confirm;
                    printf("\nÊtes-vous sûr de vouloir supprimer le restaurant? (O/N): ");
                    scanf(" %c", &confirm);
                    
                    if (confirm == 'O' || confirm == 'o') {
                        restoExist = 0;
                        repasTotal = 0;
                        personTotal = 0;
                        printf("\nRestaurant supprimé avec succès!\n");
                    } else {
                        printf("\nSuppression annulée.\n");
                    }
                }
                
                printf("\nAppuyez sur Entrée pour continuer...");
                while (getchar() != '\n');
                getchar();
                break;
                
            case 2:
                if (repasTotal == 0) {
                    printf("\nAucun repas à supprimer.\n");
                } else {
                    int repasSup;
                    
                    // Display existing meals for reference
                    printf("\nRepas existants:\n");
                    for (int i = 0; i < repasTotal; i++) {
                        printf("%d. %s\n", i+1, resto.r[i].nom);
                    }
                    
                    printf("\nEntrez le numéro du repas à supprimer (1-%d): ", repasTotal);
                    scanf("%d", &repasSup);
                    
                    if (repasSup < 1 || repasSup > repasTotal) {
                        printf("\nNuméro de repas invalide.\n");
                    } else {
                        int index = repasSup - 1;  // Adjust for array index
                        
                        // Ask for confirmation
                        char confirm;
                        printf("\nÊtes-vous sûr de vouloir supprimer '%s'? (O/N): ", resto.r[index].nom);
                        scanf(" %c", &confirm);
                        
                        if (confirm == 'O' || confirm == 'o') {
                            // Shift elements to the left
                            for (int i = index; i < repasTotal - 1; i++) {
                                resto.r[i] = resto.r[i + 1];
                            }
                            repasTotal--;
                            printf("\nRepas supprimé avec succès!\n");
                        } else {
                            printf("\nSuppression annulée.\n");
                        }
                    }
                }
                
                printf("\nAppuyez sur Entrée pour continuer...");
                while (getchar() != '\n');
                getchar();
                break;
                
            case 3:
                if (personTotal == 0) {
                    printf("\nAucune personne à supprimer.\n");
                } else {
                    int persoSup;
                    
                    // Display existing people for reference
                    printf("\nPersonnes existantes:\n");
                    for (int i = 0; i < personTotal; i++) {
                        printf("%d. %s\n", i+1, resto.p[i].nomPersonne);
                    }
                    
                    printf("\nEntrez le numéro de la personne à supprimer (1-%d): ", personTotal);
                    scanf("%d", &persoSup);
                    
                    if (persoSup < 1 || persoSup > personTotal) {
                        printf("\nNuméro de personne invalide.\n");
                    } else {
                        int index = persoSup - 1;  // Adjust for array index
                        
                        // Ask for confirmation
                        char confirm;
                        printf("\nÊtes-vous sûr de vouloir supprimer '%s'? (O/N): ", resto.p[index].nomPersonne);
                        scanf(" %c", &confirm);
                        
                        if (confirm == 'O' || confirm == 'o') {
                            // Shift elements to the left
                            for (int i = index; i < personTotal - 1; i++) {
                                resto.p[i] = resto.p[i + 1];
                            }
                            personTotal--;
                            printf("\nPersonne supprimée avec succès!\n");
                        } else {
                            printf("\nSuppression annulée.\n");
                        }
                    }
                }
                
                printf("\nAppuyez sur Entrée pour continuer...");
                while (getchar() != '\n');
                getchar();
                break;
                
            case 4:
                printf("\nRetour au menu principal...\n");
                break;
                
            default:
                printf("\nChoix invalide.\n");
                printf("\nAppuyez sur Entrée pour continuer...");
                while (getchar() != '\n');
                getchar();
                break;
        }
    } while (choice != 4);
}

// Display function
void afficher() {
    system("cls");
    afficherTitre();
    
    if (restoExist == 0) {
        printf("\nAucun restaurant n'existe. Veuillez d'abord en ajouter un.\n");
    } else {
        afficherLigne(50);
        printf("\n===== INFORMATIONS DU RESTAURANT =====\n");
        afficherLigne(50);
        
        printf("\nID: %d\n", resto.idResto);
        printf("Nom: %s\n", resto.nomResto);
        printf("Adresse: %s\n", resto.adresse);
        printf("Nombre d'employés: %d\n", resto.nbrEmployer);
        printf("Heures de travail: %.1f\n", resto.heureTravaille);
        
        if (repasTotal > 0) {
            afficherLigne(50);
            printf("\n===== LISTE DES REPAS (%d) =====\n", repasTotal);
            afficherLigne(50);
            
            for (int i = 0; i < repasTotal; i++) {
                printf("\n----- Repas %d -----\n", i+1);
                printf("ID: %d\n", resto.r[i].idRepas);
                printf("Nom: %s\n", resto.r[i].nom);
                printf("Ingrédients: %s\n", resto.r[i].ingrediants);
                printf("Prix: %d\n", resto.r[i].prix);
                printf("Quantité: %d\n", resto.r[i].qte);
                printf("Valeur énergétique: %.2f\n", resto.r[i].valeurEnergetique);
            }
        }
        
        if (personTotal > 0) {
            afficherLigne(50);
            printf("\n===== LISTE DES PERSONNES (%d) =====\n", personTotal);
            afficherLigne(50);
            
            for (int i = 0; i < personTotal; i++) {
                printf("\n----- Personne %d -----\n", i+1);
                printf("ID: %d\n", resto.p[i].idPersonne);
                printf("Nom: %s\n", resto.p[i].nomPersonne);
                printf("Age: %d\n", resto.p[i].age);
                printf("Montant payé: %.2f\n", resto.p[i].mtPaye);
            }
        }
    }
    
    printf("\nAppuyez sur Entrée pour revenir au menu principal...");
    while (getchar() != '\n');
    getchar();
}