#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store student details
struct Student
{
    char *name; // Pointer to dynamically allocated memory for name
    int age;
    int roll;
    long phone;
    long governmentID;
    int id; // Unique student ID
};

// Array to store students (dynamically allocated)
struct Student **students = NULL;
int studentCount = 0; // To keep track of the number of students

int main()
{
    int choice;
    while (1)
    {
        printf("Student Manager v1.0\n");
        printf("1. Create\n");
        printf("2. Read\n");
        printf("3. Update\n");
        printf("4. Delete\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character left by scanf

        switch (choice)
        {
        case 1:
            // Create a student dynamically
            {
                struct Student *student = (struct Student *)malloc(sizeof(struct Student)); // Dynamically allocate memory for a new student

                if (student == NULL)
                {
                    printf("Memory allocation failed!\n");
                    break;
                }

                student->name = (char *)malloc(100 * sizeof(char)); // Dynamically allocate memory for the name (up to 100 characters)

                if (student->name == NULL)
                {
                    printf("Memory allocation for name failed!\n");
                    free(student);
                    break;
                }

                printf("Enter student name: ");
                fgets(student->name, 100, stdin);                   // Use fgets to read the name
                student->name[strcspn(student->name, "\n")] = '\0'; // Remove the newline character

                printf("Enter student age: ");
                scanf("%d", &student->age);

                printf("Enter student roll: ");
                scanf("%d", &student->roll);

                printf("Enter student phone: ");
                scanf("%ld", &student->phone);

                printf("Enter student governmentID: ");
                scanf("%ld", &student->governmentID);

                student->id = studentCount + 1; // Assign a unique ID to the student

                // Dynamically reallocate students array to add the new student
                students = (struct Student **)realloc(students, (studentCount + 1) * sizeof(struct Student *));
                if (students == NULL)
                {
                    printf("Memory reallocation failed!\n");
                    free(student->name);
                    free(student);
                    break;
                }

                students[studentCount] = student; // Add student to the array
                studentCount++;                   // Increment student count

                printf("Student created successfully!\n\n\n");
            }
            break;
        case 2:
            // Read (Display all students)
            printf("Student Details\n");
            printf("ID\t\tName\t\tAge\t\tRoll\t\tPhone\t\tGovernmentID\n");

            for (int i = 0; i < studentCount; i++)
            {
                printf("%d\t\t%s\t\t%d\t\t%d\t\t%ld\t\t%ld\n", students[i]->id, students[i]->name, students[i]->age, students[i]->roll, students[i]->phone, students[i]->governmentID);
            }

            printf("\n\n\n");
            break;
        case 3:
            // Update (Modify student details)
            {
                int id;
                printf("Enter student ID to update: ");
                scanf("%d", &id);
                getchar(); // To consume the newline character left by scanf

                if (id < 1 || id > studentCount)
                {
                    printf("Invalid student ID!\n");
                    break;
                }

                struct Student *studentToUpdate = students[id - 1]; // Get the student to update

                char tempName[100];
                char tempInput[100];

                // Update Name
                printf("Enter student name (leave empty to keep current): ");
                fgets(tempName, 100, stdin);
                tempName[strcspn(tempName, "\n")] = '\0'; // Remove newline

                if (strlen(tempName) > 0)
                {                                                                 // If the user entered a name, update it
                    free(studentToUpdate->name);                                  // Free the old name memory
                    studentToUpdate->name = (char *)malloc(strlen(tempName) + 1); // Allocate memory for the new name
                    strcpy(studentToUpdate->name, tempName);
                }

                // Update Age
                printf("Enter student age (leave empty to keep current): ");
                fgets(tempInput, 100, stdin);
                if (strlen(tempInput) > 0)
                {
                    sscanf(tempInput, "%d", &studentToUpdate->age);
                }
                else
                {
                    printf("Keeping current age: %d\n", studentToUpdate->age);
                }

                // Update Roll Number
                printf("Enter student roll Number (leave empty to keep current): ");
                fgets(tempInput, 100, stdin);
                if (strlen(tempInput) > 0)
                {
                    sscanf(tempInput, "%d", &studentToUpdate->roll);
                }
                else
                {
                    printf("Keeping current roll number: %d\n", studentToUpdate->roll);
                }

                // Update Phone
                printf("Enter student phone (leave empty to keep current): ");
                fgets(tempInput, 100, stdin);
                if (strlen(tempInput) > 0)
                {
                    sscanf(tempInput, "%ld", &studentToUpdate->phone);
                }
                else
                {
                    printf("Keeping current phone: %ld\n", studentToUpdate->phone);
                }

                // Update Government ID
                printf("Enter student governmentID (leave empty to keep current): ");
                fgets(tempInput, 100, stdin);
                if (strlen(tempInput) > 0)
                {
                    sscanf(tempInput, "%ld", &studentToUpdate->governmentID);
                }
                else
                {
                    printf("Keeping current governmentID: %ld\n", studentToUpdate->governmentID);
                }

                printf("Student updated successfully!\n\n\n");
            }
            break;

        case 4:
            // Delete (Remove a student) - You can implement this
            break;
        case 5:
            printf("Exiting...\n\n");

            // Free all dynamically allocated memory before exiting
            for (int i = 0; i < studentCount; i++)
            {
                free(students[i]->name); // Free memory for name
                free(students[i]);       // Free memory for student
            }
            free(students); // Free the student array

            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
}
