#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Menu();
void Lunch();

int main() {

    system("clear");

    Menu();

    return 0;
}

void Menu() {
    int option;
    do {
        system("clear");

        printf("Menu:\n");
        printf("1. Lista de Combos\n");
        printf("2. Lista de Pedidos\n");
        printf("3. logs\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
        case 1:
            printf("1 - Lista de Combos\n");
            Lunch();
            break;
        case 2:
            printf("2 - Lista de Pedidos\n");
            break;
        case 3:
          
            break;
        case 4:
            printf("Exiting...\n");
        default:
            printf("Invalid option. Please try again.\n");
            Menu();
        }
        fflush(stdin);
    } while (option != 4);
}

void Lunch() {
    int option;
    int quantity;
    float total;
    char name[20];
    char choiceBurger[20];

    do {
        system("clear");

        printf("====================================================\n");
        printf("           ULTRA BURGER - LUNCH MENU               \n");
        printf("====================================================\n");

        printf("1. APOCALYPSE BURGER - R$ 149,90\n");
        printf("   10 carnes, 20 fatias de bacon, 10 queijos,\n");
        printf("   2 ovos, cebola crispy e molho especial!\n\n");

        printf("2. MEGA MONSTER - R$ 199,90\n");
        printf("   15 carnes, 30 fatias de bacon, 15 queijos,\n");
        printf("   5 ovos, onion rings e molho barbecue!\n\n");

        printf("3. TITAN BURGER - R$ 299,90\n");
        printf("   20 carnes, 40 fatias de bacon, 20 queijos,\n");
        printf("   10 ovos, 2 hambúrgueres de frango e molho secreto!\n\n");

        printf("4. HEART ATTACK BURGER - R$ 499,90\n");
        printf("   30 carnes, 60 fatias de bacon, 30 queijos,\n");
        printf("   15 ovos, 10 salsichas, onion rings e cheddar!\n\n");

        printf("5. INFERNO BURGER - R$ 999,90\n");
        printf("   50 carnes, 100 fatias de bacon, 50 queijos,\n");
        printf("   20 ovos, 20 salsichas e 1 litro de cheddar!\n\n");

        printf("6. Back to Main Menu\n");

        printf("====================================================\n");
        printf("Choose your monster: ");
        scanf("%d", &option);

        switch (option) {
        case 1:
            printf("\nYou selected APOCALYPSE BURGER!\n");
            strcpy(choiceBurger, "APOCALYPSE BURGER");
            total = 149.90;
            break;

        case 2:
            printf("\nYou selected MEGA MONSTER!\n");
            strcpy(choiceBurger, "MEGA MONSTER");
            total = 199.90;
            break;

        case 3:
            printf("\nYou selected TITAN BURGER!\n");
            strcpy(choiceBurger, "TITAN BURGER");
            total = 299.90;
            break;

        case 4:
            printf("\nYou selected HEART ATTACK BURGER!\n");
            strcpy(choiceBurger, "HEART ATTACK BURGER");
            total = 499.90;
            break;

        case 5:
            printf("\nYou selected INFERNO BURGER!\n");
            strcpy(choiceBurger, "INFERNO BURGER");
            total = 999.90;
            break;

        case 6:
            return;

        default:
            printf("\nInvalid option. Please try again.\n");
            printf("Press Enter to continue...");
            fflush(stdin);

            continue;
        }

        printf("How many burgers do you want? ");
        scanf("%d", &quantity);

        printf("What is your name? ");
        scanf("%s", name);

        if (quantity <= 0) {
            printf("\nInvalid quantity!\n");
        } else {
            FILE *file = fopen("Log.txt", "a");

            fprintf(file, "\n========== ORDER SUMMARY ==========\n");
            fprintf(file, "Burger Selected: %s\n", choiceBurger);
            fprintf(file, "Customer: %s\n", name);
            fprintf(file, "Price per burger: R$ %.2f\n", total);
            fprintf(file, "Quantity: %d\n", quantity);
            fprintf(file, "Total price: R$ %.2f\n", total * quantity);
            fprintf(file, "===================================\n");
            fclose(file);
        }
        fflush(stdin);

    } while (option != 6);
}