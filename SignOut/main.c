#include <stdio.h>
#include <string.h>

// Return 2 - Error With File
// Return 1 - Error
// Return 0 - Good

int SCORE = 0;
char PASSWORDS[5][5] = {
    "a123",
    "j231",
    "t345",
    "o103",
    "r938"
};


int checkPassword(char password[5]) {

    for (int i = 0; i < 5; i++) {

        if (strcmp(password, PASSWORDS[i]) == 0) {
            return 0;
        }

    }

    return 1;
}


int checkUserBan() {

    char line[50];
    FILE *file = fopen("user.txt", "r");

    if (file == NULL) {
        return 2;
    }

    fgets(line, sizeof(line), file);
    
    line[strcspn(line, "\n")] = '\0';

    if (strcmp(line, "User Is Banned") == 0) {
        fclose(file);
        return 1;
    }

    return 0;

}

int writeBan() {
    FILE *file = fopen("user.txt", "w");

    fprintf(file, "User Is Banned");
    return 1;
}


int main() {

    if (checkUserBan() == 1) {
        printf("You are banned!");
        return 1;
    }

    if (checkUserBan() == 2) {
        printf("Error With File");
        return 2;
    }

    while (1) {

        char input[10];

        printf("Enter password: ");
        fgets(input, sizeof(input), stdin);

        input[strcspn(input, "\n")] = '\0';

        if (SCORE == 3) {
            printf("OverFlow Score.\nYou Are Banned.");
            writeBan();
            return 1;
        }

        if (checkPassword(input) == 0) {
            printf("Welcome To System!");
            return 0;
        }

        if (checkPassword(input) == 1) {
            printf("Invalid Password. Try Again.\n");
            SCORE++;
        }

    }

}