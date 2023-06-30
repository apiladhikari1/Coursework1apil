#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define MAX_USERS 5

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} User;

User users[MAX_USERS] = {
    {"admin", "password"},
    {"user1", "pass123"},
    {"user2", "abc456"},
    {"john", "qwerty"},
    {"alice", "secret"}
};

int verifyCredentials(const char* username, const char* password) {
    // Iterate over the users in the database
    for (int i = 0; i < MAX_USERS; i++) {
        // Compare the provided username and password with the current user
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            return 1; // Credentials match
        }
    }

    return 0; // Credentials do not match
}

int main() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Secure Login System\n");

    printf("Username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0'; // Remove trailing newline

    printf("Password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0'; // Remove trailing newline

    if (verifyCredentials(username, password)) {
        printf("Login successful!\n");
    } else {
        printf("Invalid username or password. Login failed.\n");
    }

    return 0;
}
