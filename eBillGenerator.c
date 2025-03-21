#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Meter Reading
struct meterReading {
    int meterId;
    int unitsConsumed;
    float billAmount;
    char readingDate[15];
    struct meterReading *prev, *next;
};

// Function to calculate bill amount
float calculateBill(int unitsConsumed) {
    float bill = 0.0;
    float serviceCharge = 0.0;
    
    if (unitsConsumed <= 20) {
        bill = 0;
        serviceCharge = 30;
    } else if (unitsConsumed <= 30) {
        bill = (20 * 3.0) + ((unitsConsumed - 20) * 6.5);
        serviceCharge = 50;
    } else if (unitsConsumed <= 50) {
        bill = (20 * 3.0) + (10 * 6.5) + ((unitsConsumed - 30) * 8.0);
        serviceCharge = 50;
    } else if (unitsConsumed <= 100) {
        bill = (20 * 3.0) + (10 * 6.5) + (20 * 8.0) + ((unitsConsumed - 50) * 9.5);
        serviceCharge = 75;
    } else if (unitsConsumed <= 250) {
        bill = (20 * 3.0) + (10 * 6.5) + (20 * 8.0) + (50 * 9.5) + ((unitsConsumed - 100) * 9.5);
        serviceCharge = 100;
    } else {
        bill = (20 * 3.0) + (10 * 6.5) + (20 * 8.0) + (50 * 9.5) + (150 * 9.5) + ((unitsConsumed - 250) * 11.0);
        serviceCharge = 150;
    }
    
    bill += serviceCharge;
    return bill;
}

// Function to insert a new reading
struct meterReading* insertReading(struct meterReading* head) {
    struct meterReading* newReading = (struct meterReading*)malloc(sizeof(struct meterReading));
    
    if (!newReading) {
        printf("Memory allocation failed!\n");
        return head;
    }
    
    printf("Enter Meter ID: ");
    scanf("%d", &newReading->meterId);
    printf("Enter Units Consumed: ");
    scanf("%d", &newReading->unitsConsumed);
    printf("Enter Date (DD/MM/YYYY): ");
    scanf("%s", newReading->readingDate);
    
    newReading->billAmount = calculateBill(newReading->unitsConsumed);
    newReading->prev = newReading->next = NULL;
    
    if (!head) {
        head = newReading;
    } else {
        struct meterReading* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newReading;
        newReading->prev = temp;
    }
    
    printf("Reading Added Successfully!\n");
    return head;
}

// Function to display all readings
void displayReadings(struct meterReading* head) {
    if (!head) {
        printf("No meter readings available!\n");
        return;
    }
    
    printf("\nElectricity Meter Readings:\n");
    struct meterReading* temp = head;
    
    while (temp) {
        printf("Meter ID: %d | Units: %d | Bill: Rs. %.2f | Date: %s\n",
               temp->meterId, temp->unitsConsumed, temp->billAmount, temp->readingDate);
        temp = temp->next;
    }
}

// Function to modify a reading
void modifyReading(struct meterReading* head, int meterId) {
    struct meterReading* temp = head;
    
    while (temp) {
        if (temp->meterId == meterId) {
            printf("Enter new Units Consumed: ");
            scanf("%d", &temp->unitsConsumed);
            printf("Enter new Date (DD/MM/YYYY): ");
            scanf("%s", temp->readingDate);
            
            temp->billAmount = calculateBill(temp->unitsConsumed);
            printf("Reading Updated Successfully!\n");
            return;
        }
        temp = temp->next;
    }
    
    printf("Meter ID %d not found!\n", meterId);
}

// Main function
int main() {
    struct meterReading* head = NULL;
    int choice, meterId;
    
    while (1) {
        printf("\nElectricity Meter Reading System (only for 5 ampere meter)\n");
        printf("1. Insert New Reading\n");
        printf("2. Display All Readings\n");
        printf("3. Modify Reading\n");
        printf("4. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                head = insertReading(head);
                break;
            case 2:
                displayReadings(head);
                break;
            case 3:
                printf("Enter Meter ID to Modify: ");
                scanf("%d", &meterId);
                modifyReading(head, meterId);
                break;
            case 4:
                printf("Exiting Program...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    
    return 0;
}