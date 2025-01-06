#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold information about each student
struct Student
{
    char *name; // This will store the name of the student (we will allocate memory for it)
    int age; // The student's age
    int roll; // The student's roll number
    long phone; // The student's phone number
    long governmentID; // The student's government ID number
    int id; // A unique ID for each student
};

// We create an array to hold multiple students. This array will be created dynamically.
struct Student **students = NULL;
int studentCount = 0; // Keeps track of how many students we have added.

int main()
{
    int choice;
    // Start an infinite loop to keep showing the menu
    while (1)
    {
        // Display the menu to the user
        printf("Student Manager v1.0\n");
        printf("1. Create\n");  // Option to create a new student
        printf("2. Read\n");    // Option to read/display all students
        printf("3. Update\n");  // Option to update student details
        printf("4. Delete\n");  // Option to delete a student
        printf("5. Exit\n");    // Option to exit the program

        // Ask the user to enter their choice
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); // This removes the extra newline character after input

        // Based on the user's choice, perform the corresponding operation
        switch (choice)
        {
        case 1:
            // Create a student dynamically
            {
                // Allocate memory for a new student
                struct Student *student = (struct Student *)malloc(sizeof(struct Student));

                // Check if memory allocation was successful
                if (student == NULL)
                {
                    printf("Memory allocation failed!\n");
                    break;
                }

                // Allocate memory for the student's name
                student->name = (char *)malloc(100 * sizeof(char));

                // If memory allocation for name fails
                if (student->name == NULL)
                {
                    printf("Memory allocation for name failed!\n");
                    free(student); // Free the memory for student
                    break;
                }

                // Ask the user to enter the student's name
                printf("Enter student name: ");
                fgets(student->name, 100, stdin); // Read the name
                student->name[strcspn(student->name, "\n")] = '\0'; // Remove extra newline

                // Ask for other details like age, roll number, phone, and government ID
                printf("Enter student age: ");
                scanf("%d", &student->age);

                printf("Enter student roll: ");
                scanf("%d", &student->roll);

                printf("Enter student phone: ");
                scanf("%ld", &student->phone);

                printf("Enter student governmentID: ");
                scanf("%ld", &student->governmentID);

                // Assign a unique ID to the student (based on the current number of students)
                student->id = studentCount + 1;

                // Resize the array of students to add the new student
                students = (struct Student **)realloc(students, (studentCount + 1) * sizeof(struct Student *));
                if (students == NULL)
                {
                    printf("Memory reallocation failed!\n");
                    free(student->name); // Free memory for name
                    free(student); // Free memory for student
                    break;
                }

                // Add the new student to the students array
                students[studentCount] = student;

                // Increase the student count by 1
                studentCount++;

                printf("Student created successfully!\n\n\n");
            }
            break;
        case 2:
            // Display all student details
            printf("Student Details\n");
            printf("ID\t\tName\t\tAge\t\tRoll\t\tPhone\t\tGovernmentID\n");

            // Loop through all students and display their details
            for (int i = 0; i < studentCount; i++)
            {
                // Print each student's details
                printf("%d\t\t%s\t\t%d\t\t%d\t\t%ld\t\t%ld\n", students[i]->id, students[i]->name, students[i]->age, students[i]->roll, students[i]->phone, students[i]->governmentID);
            }

            printf("\n\n\n");
            break;
        case 3:
            // Update student details
            {
                int id;
                printf("Enter student ID to update: ");
                scanf("%d", &id);
                getchar(); // To consume any extra newline character

                // Check if the entered ID is valid
                if (id < 1 || id > studentCount)
                {
                    printf("Invalid student ID!\n");
                    break;
                }

                // Find the student whose details we want to update
                struct Student *studentToUpdate = students[id - 1];

                char tempName[100];
                char tempInput[100];

                // Update Name
                printf("Enter student name (leave empty to keep current): ");
                fgets(tempName, 100, stdin);
                tempName[strcspn(tempName, "\n")] = '\0'; // Remove newline

                // If the user entered a new name, update it
                if (strlen(tempName) > 0)
                {
                    free(studentToUpdate->name); // Free the old name
                    studentToUpdate->name = (char *)malloc(strlen(tempName) + 1); // Allocate new memory for the new name
                    strcpy(studentToUpdate->name, tempName); // Copy the new name
                }

                // Update other fields (age, roll, phone, government ID) if the user provides new values
                // Age
                printf("Enter student age (leave empty to keep current): ");
                fgets(tempInput, 100, stdin);
                if (strlen(tempInput) > 0)
                {
                    sscanf(tempInput, "%d", &studentToUpdate->age); // Update age
                }
                else
                {
                    printf("Keeping current age: %d\n", studentToUpdate->age);
                }

                // Roll number
                printf("Enter student roll Number (leave empty to keep current): ");
                fgets(tempInput, 100, stdin);
                if (strlen(tempInput) > 0)
                {
                    sscanf(tempInput, "%d", &studentToUpdate->roll); // Update roll number
                }
                else
                {
                    printf("Keeping current roll number: %d\n", studentToUpdate->roll);
                }

                // Phone number
                printf("Enter student phone (leave empty to keep current): ");
                fgets(tempInput, 100, stdin);
                if (strlen(tempInput) > 0)
                {
                    sscanf(tempInput, "%ld", &studentToUpdate->phone); // Update phone number
                }
                else
                {
                    printf("Keeping current phone: %ld\n", studentToUpdate->phone);
                }

                // Government ID
                printf("Enter student governmentID (leave empty to keep current): ");
                fgets(tempInput, 100, stdin);
                if (strlen(tempInput) > 0)
                {
                    sscanf(tempInput, "%ld", &studentToUpdate->governmentID); // Update government ID
                }
                else
                {
                    printf("Keeping current governmentID: %ld\n", studentToUpdate->governmentID);
                }

                printf("Student updated successfully!\n\n\n");
            }
            break;

        case 4:
            // Delete a student
            {
                int idToDelete;
                printf("Enter student ID to delete: ");
                scanf("%d", &idToDelete);

                // Check if the ID is valid
                if (idToDelete < 1 || idToDelete > studentCount)
                {
                    printf("Invalid student ID!\n");
                    break;
                }

                // Free memory used by the student to delete
                free(students[idToDelete - 1]->name);
                free(students[idToDelete - 1]);

                // Shift remaining students up to fill the gap
                for (int i = idToDelete - 1; i < studentCount - 1; i++)
                {
                    students[i] = students[i + 1]; // Shift students one position to the left
                }

                // Decrease the student count
                studentCount--;

                // Optionally, reallocate memory to shrink the student array
                students = (struct Student **)realloc(students, studentCount * sizeof(struct Student *));
                if (students == NULL && studentCount > 0)
                {
                    printf("Memory reallocation failed!\n");
                    break;
                }

                printf("Student deleted successfully!\n\n\n");
            }
            break;

        case 5:
            // Exit the program
            printf("Exiting...\n\n");

            // Free memory used by all students before exiting
            for (int i = 0; i < studentCount; i++)
            {
                free(students[i]->name); // Free memory for name
                free(students[i]); // Free memory for student
            }
            free(students); // Free the students array

            return 0;
        default:
            // If the user enters an invalid option
            printf("Invalid choice! Please try again.\n");
        }
    }
}
