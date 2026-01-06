#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "loading.h"

// Структура для хранения пароля
typedef struct {
    char website[50];
    char login[50];
    char password[50];
} Password;

// Прототипы функций
void showMenu();
void addPassword();
void showAllPasswords();
void findPassword();


int main() {
    int choice;
    void showLoading();
    
    while (1) {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                showLoading();
                showAllPasswords();
                break;
            case 3:
                findPassword();
                break;
            case 4:
                printf("Выход из программы.\n");
                return 0;
            default:
                printf("Неверный выбор!\n");
        }
    }
}

// Меню
void showMenu() {
    printf("\n=== МЕНЕДЖЕР ПАРОЛЕЙ ===\n");
    printf("1. Добавить пароль\n");
    printf("2. Показать все пароли\n");
    printf("3. Найти пароль\n");
    printf("4. Выход\n");
    printf("Выбери действие: ");
}

// Добавление пароля
void addPassword() {
    Password p;
    FILE *file = fopen("passwords.txt", "a");

    if (file == NULL) {
        printf("Ошибка открытия файла!\n");
        return;
    }

    printf("Введи сайт: ");
    scanf("%s", p.website);

    printf("Введи логин: ");
    scanf("%s", p.login);

    printf("Введи пароль: ");
    scanf("%s", p.password);

    fprintf(file, "%s %s %s\n", p.website, p.login, p.password);
    fclose(file);

    printf("Пароль добавлен!\n");
}

// Показ всех паролей
void showAllPasswords() {
    Password p;
    FILE *file = fopen("passwords.txt", "r");

    if (file == NULL) {
        printf("Файл пуст или не найден!\n");
        return;
    }

    printf("\n%-20s %-20s %-20s\n", "Сайт", "Логин", "Пароль");
    printf("------------------------------------------------------------\n");

    while (fscanf(file, "%s %s %s", p.website, p.login, p.password) != EOF) {
        printf("%-20s %-20s %-20s\n", p.website, p.login, p.password);
    }

    fclose(file);
}

// Поиск пароля по сайту
void findPassword() {
    Password p;
    char search[50];
    int found = 0;

    FILE *file = fopen("passwords.txt", "r");

    if (file == NULL) {
        printf("Файл не найден!\n");
        return;
    }

    printf("Введи сайт для поиска: ");
    scanf("%s", search);

    while (fscanf(file, "%s %s %s", p.website, p.login, p.password) != EOF) {
        if (strcmp(p.website, search) == 0) {
            printf("\nНайдено:\n");
            printf("Сайт: %s\nЛогин: %s\nПароль: %s\n",
                   p.website, p.login, p.password);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Пароль для сайта \"%s\" не найден.\n", search);
    }

    fclose(file);
}
