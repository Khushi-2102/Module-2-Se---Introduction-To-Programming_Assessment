#include <stdio.h>
#include <string.h>

// Function to reverse the string
void reverseString(char str[]) {
    int len = strlen(str);
    printf("Reversed string: ");
    for (int i = len - 1; i >= 0; i--) {
        putchar(str[i]);
    }
    printf("\n");
}

// Function to concatenate two strings
void concatenateStrings(char str[]) {
    char str2[100];
    printf("Enter another string to concatenate: ");
    getchar(); // clear newline
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0'; // remove newline
    strcat(str, str2);
    printf("Concatenated string: %s\n", str);
}

// Function to check for palindrome
void checkPalindrome(char str[]) {
    int len = strlen(str);
    int isPalin = 1;
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            isPalin = 0;
            break;
        }
    }

    if (isPalin)
        printf("The string is a palindrome.\n");
    else
        printf("The string is not a palindrome.\n");
}

// Function to copy string
void copyString(char str[]) {
    char copied[100];
    strcpy(copied, str);
    printf("Copied string: %s\n", copied);
}

// Function to find length
void findLength(char str[]) {
    int i = 0;
    while (str[i] != '\0') i++;
    printf("Length of the string: %d\n", i);
}

// Function to find frequency of character
void frequencyOfCharacter(char str[]) {
    char ch;
    int count = 0;
    printf("Enter character to find frequency: ");
    getchar(); // clear newline
    scanf("%c", &ch);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch)
            count++;
    }

    printf("Frequency of '%c': %d\n", ch, count);
}

// Function to count vowels and consonants (manual check)
void countVowelsAndConsonants(char str[]) {
    int vowels = 0, consonants = 0;
    char ch;

    for (int i = 0; str[i] != '\0'; i++) {
        ch = str[i];

        // Check if character is alphabet manually
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            // Convert uppercase to lowercase
            if (ch >= 'A' && ch <= 'Z')
                ch += 32;

            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                vowels++;
            else
                consonants++;
        }
    }

    printf("Vowels: %d, Consonants: %d\n", vowels, consonants);
}

// Function to count spaces and digits (manual check)
void countSpacesAndDigits(char str[]) {
    int spaces = 0, digits = 0;
    char ch;

    for (int i = 0; str[i] != '\0'; i++) {
        ch = str[i];

        if (ch == ' ')
            spaces++;
        else if (ch >= '0' && ch <= '9')
            digits++;
    }

    printf("Blank spaces: %d, Digits: %d\n", spaces, digits);
}

// Function to display the menu
void displayMenu() {
    printf("\n--- String Operations Menu ---\n");
    printf("1. Reverse the string\n");
    printf("2. Concatenation\n");
    printf("3. Check Palindrome\n");
    printf("4. Copy the string\n");
    printf("5. Find Length of the string\n");
    printf("6. Frequency of a character\n");
    printf("7. Count Vowels and Consonants\n");
    printf("8. Count Blank Spaces and Digits\n");
    printf("9. Exit\n");
    printf("Enter your choice (1-9): ");
}

// Main function
int main() {
    char str[100], cont;
    int choice;

    do {
        // Input the string
        printf("\nEnter a string: ");
        getchar(); // clear leftover newline
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = '\0'; // remove newline

        // Show menu and take choice
        displayMenu();
        scanf("%d", &choice);

        printf("\n--- Operation Result ---\n");

        // Perform selected operation
        switch (choice) {
            case 1:
                reverseString(str);
                break;
            case 2:
                concatenateStrings(str);
                break;
            case 3:
                checkPalindrome(str);
                break;
            case 4:
                copyString(str);
                break;
            case 5:
                findLength(str);
                break;
            case 6:
                frequencyOfCharacter(str);
                break;
            case 7:
                countVowelsAndConsonants(str);
                break;
            case 8:
                countSpacesAndDigits(str);
                break;
            case 9:
                printf("Exiting program. Thank you!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }

        // Ask user to continue
        printf("\nDo you want to continue? (y/n): ");
        getchar(); // clear newline
        scanf("%c", &cont);

    } while (cont == 'y' || cont == 'Y');

    printf("Program ended. Have a nice day!\n");
    return 0;
}
