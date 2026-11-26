#include <stdio.h>
#include <string.h>

struct Contact {
    char name[50];
    char phone[20];
};

void addRecord() {
    struct Contact c;
    FILE *fp = fopen("contacts.dat", "ab");

    if (fp == NULL) {
        printf("File error\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", c.name);

    printf("Enter phone: ");
    scanf("%s", c.phone);

    fwrite(&c, sizeof(c), 1, fp);
    fclose(fp);

    printf("Record added successfully\n");
}

void searchByName() {
    struct Contact c;
    char name[50];
    int found = 0;

    FILE *fp = fopen("contacts.dat", "rb");

    if (fp == NULL) {
        printf("No records found\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", name);

    while (fread(&c, sizeof(c), 1, fp)) {
        if (strcmp(c.name, name) == 0) {
            printf("Name: %s\nPhone: %s\n", c.name, c.phone);
            found = 1;
        }
    }

    if (!found)
        printf("Record not found\n");

    fclose(fp);
}

void searchByPhone() {
    struct Contact c;
    char phone[20];
    int found = 0;

    FILE *fp = fopen("contacts.dat", "rb");

    if (fp == NULL) {
        printf("No records found\n");
        return;
    }

    printf("Enter phone number: ");
    scanf("%s", phone);

    while (fread(&c, sizeof(c), 1, fp)) {
        if (strcmp(c.phone, phone) == 0) {
            printf("Name: %s\nPhone: %s\n", c.name, c.phone);
            found = 1;
        }
    }

    if (!found)
        printf("Record not found\n");

    fclose(fp);
}

void updateRecord() {
    struct Contact c;
    char phone[20];
    int found = 0;

    FILE *fp = fopen("contacts.dat", "rb");
    FILE *tp = fopen("temp.dat", "wb");

    if (fp == NULL || tp == NULL) {
        printf("File error\n");
        if (fp != NULL) fclose(fp);
        if (tp != NULL) fclose(tp);
        return;
    }

    printf("Enter phone number to update: ");
    scanf("%s", phone);

    while (fread(&c, sizeof(c), 1, fp)) {
        if (strcmp(c.phone, phone) == 0) {
            printf("Enter new name: ");
            scanf("%s", c.name);

            printf("Enter new phone: ");
            scanf("%s", c.phone);

            found = 1;
        }

        fwrite(&c, sizeof(c), 1, tp);
    }

    fclose(fp);
    fclose(tp);

    if (found) {
        remove("contacts.dat");
        rename("temp.dat", "contacts.dat");
        printf("Record updated successfully\n");
    } else {
        remove("temp.dat");
        printf("Record not found\n");
    }
}

void deleteRecord() {
    struct Contact c;
    char phone[20];
    int found = 0;

    FILE *fp = fopen("contacts.dat", "rb");

    if (fp == NULL) {
        printf("No records found\n");
        return;
    }

    FILE *tp = fopen("temp.dat", "wb");

    if (tp == NULL) {
        fclose(fp);
        printf("File error\n");
        return;
    }

    printf("Enter phone number to delete: ");
    scanf("%s", phone);

    while (fread(&c, sizeof(c), 1, fp)) {
        if (strcmp(c.phone, phone) == 0) {
            found = 1;
        } else {
            fwrite(&c, sizeof(c), 1, tp);
        }
    }

    fclose(fp);
    fclose(tp);

    if (found) {
        remove("contacts.dat");
        rename("temp.dat", "contacts.dat");
        printf("Record deleted successfully\n");
    } else {
        remove("temp.dat");
        printf("Record not found\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n--- TELEPHONE DIRECTORY ---\n");
        printf("1. Add Record\n");
        printf("2. Search by Name\n");
        printf("3. Search by Phone\n");
        printf("4. Update Record\n");
        printf("5. Delete Record\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addRecord(); break;
            case 2: searchByName(); break;
            case 3: searchByPhone(); break;
            case 4: updateRecord(); break;
            case 5: deleteRecord(); break;
            case 6: printf("Thank you\n"); break;
            default: printf("Invalid choice\n");
        }

    } while (choice != 6);

    return 0;
}