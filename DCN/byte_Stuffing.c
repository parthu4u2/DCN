#include <stdio.h>
#include <string.h>

int main() {
    char frame[50][50], str[50][50];
    char flag[10];
    strcpy(flag, "flag");
    char esc[10];
    strcpy(esc, "esc");
    int i, k = 0, n;
    strcpy(frame[k++], flag);
    printf("Enter length of String : \n");
    scanf("%d", &n);
    printf("Enter the String: ");
    getchar(); // to clear the buffer
    for (i = 0; i < n; i++) {
        fgets(str[i], sizeof(str[i]), stdin);
        str[i][strcspn(str[i], "\n")] = '\0'; // remove newline character
    }
    printf("\nYou entered :\n");
    for (i = 0; i < n; i++) {
        puts(str[i]);
    }
    printf("\n");
    for (i = 0; i < n; i++) {
        if (strcmp(str[i], flag) != 0 && strcmp(str[i], esc) != 0) {
            strcpy(frame[k++], str[i]);
        } else {
            strcpy(frame[k++], esc);
            strcpy(frame[k++], str[i]);
        }
    }
    strcpy(frame[k++], flag);
    printf("------------------------------\n\n");
    printf("Byte stuffing at sender side:\n\n");
    printf("------------------------------\n\n");
    for (i = 0; i < k; i++) {
        printf("%s\t", frame[i]);
    }
    return 0;
}
