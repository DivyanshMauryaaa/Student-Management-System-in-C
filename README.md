<h1>Student Manager v1.0</h1>

<p>A simple console-based program that allows you to manage student information. It allows the user to perform the following actions:</p>
    <ul>
        <li><strong>Create</strong> a new student record.</li>
        <li><strong>Read</strong> (Display) all student records.</li>
        <li><strong>Update</strong> existing student records.</li>
        <li><strong>Delete</strong> a student record.</li>
        <li><strong>Exit</strong> the program safely, freeing any allocated memory.</li>
    </ul>

<h2>Features</h2>
    <ul>
        <li><strong>Dynamic Memory Allocation</strong>: The program uses dynamic memory allocation to store student information. The number of students can grow or shrink as required, and memory is freed when no longer needed.</li>
        <li><strong>Student Details</strong>: The details stored for each student include:
            <ul>
                <li>Name</li>
                <li>Age</li>
                <li>Roll Number</li>
                <li>Phone Number</li>
                <li>Government ID</li>
                <li>A unique student ID</li>
            </ul>
        </li>
    </ul>

<h2>Program Flow</h2>
    <ol>
        <li><strong>Create</strong>: Add a new student by entering their details.</li>
        <li><strong>Read</strong>: Display a list of all students, showing their details.</li>
        <li><strong>Update</strong>: Modify an existing student's details by providing the student ID.</li>
        <li><strong>Delete</strong>: Remove a student by entering their student ID.</li>
        <li><strong>Exit</strong>: Quit the program and free all dynamically allocated memory to avoid memory leaks.</li>
    </ol>

<h2>Table of Contents</h2>
    <ul>
        <li><a href="#installation">Installation</a></li>
        <li><a href="#usage">Usage</a></li>
        <li><a href="#how-it-works">How It Works</a></li>
        <li><a href="#memory-management">Memory Management</a></li>
        <li><a href="#license">License</a></li>
    </ul>

<h2 id="installation">Installation</h2>
    <p>Since this program is written in C, you need a C compiler to run it. Here’s how you can set it up on your system:</p>

<h3>Step 1: Install a C Compiler</h3>
    <ul>
        <li><strong>Windows</strong>: Install <a href="https://sourceforge.net/projects/mingw/">MinGW</a> or use an IDE like <a href="http://www.codeblocks.org/">Code::Blocks</a>.</li>
        <li><strong>Linux</strong>: Install GCC using the following command:
            <pre><code>sudo apt install build-essential</code></pre>
        </li>
        <li><strong>macOS</strong>: Install Xcode Command Line Tools:
            <pre><code>xcode-select --install</code></pre>
        </li>
    </ul>

<h3>Step 2: Clone the Repository</h3>
    <p>Clone this repository to your local machine:</p>
    <pre><code>git clone https://github.com/DivyanshMauryaaa/Student-Management-System-in-C</code></pre>

<h3>Step 3: Compile the Program</h3>
    <p>Navigate to the project directory and run the following command to compile the program:</p>
    <pre><code>gcc -o student_manager student_manager.c</code></pre>

<h3>Step 4: Run the Program</h3>
    <p>Once compiled, you can run the program by typing:</p>
    <pre><code>./student_manager</code></pre>

<h2 id="usage">Usage</h2>
    <p>When you run the program, you will see a simple text menu with options to create, read, update, delete, or exit the program.</p>

<h3>Here’s how each option works:</h3>
    <ol>
        <li><strong>Create</strong>: When you select the <strong>Create</strong> option (1), you will be prompted to enter the following details for a new student:
            <ul>
                <li>Name</li>
                <li>Age</li>
                <li>Roll Number</li>
                <li>Phone Number</li>
                <li>Government ID</li>
            </ul>
            After entering the information, the program assigns a unique ID to the student and saves the data.
        </li>
        <li><strong>Read</strong>: Selecting the <strong>Read</strong> option (2) will display all the students' details in a formatted table, showing the student ID, name, age, roll number, phone number, and government ID.</li>
        <li><strong>Update</strong>: In the <strong>Update</strong> option (3), you will be prompted to enter the student ID of the student whose details you want to update. You can update the student's name, age, roll number, phone number, and government ID.</li>
        <li><strong>Delete</strong>: To delete a student, select <strong>Delete</strong> (4) and enter the student ID of the student you want to remove. The program will free the memory allocated for that student and shift the remaining students in the array to fill the gap.</li>
        <li><strong>Exit</strong>: Select <strong>Exit</strong> (5) to quit the program. The program will free all memory before exiting to ensure there are no memory leaks.</li>
    </ol>

<h2 id="how-it-works">How It Works</h2>
    <p>The program uses dynamic memory allocation to store student records in an array. Each student is represented by a <code>Student</code> structure, and the program dynamically adjusts the size of the array as students are added or removed.</p>

<h3>Student Structure:</h3>
    <pre><code>struct Student
{
    char *name; // Name of the student (dynamically allocated memory)
    int age; // Age of the student
    int roll; // Roll number of the student
    long phone; // Phone number of the student
    long governmentID; // Government ID of the student
    int id; // Unique student ID
};
</code></pre>

<h3>Creating a Student:</h3>
    <p>When creating a new student, the program dynamically allocates memory for the student's name and stores all the details in a new <code>Student</code> structure. It then adds the student to a dynamically allocated array of <code>Student</code> pointers.</p>

<h3>Deleting a Student:</h3>
    <p>When deleting a student, the program frees the memory allocated for the student’s name and the student structure itself. It then shifts the remaining students to fill the gap and updates the student count.</p>

<h3>Reallocating Memory:</h3>
    <p>When adding or removing students, the program uses <code>realloc()</code> to resize the array that holds the students dynamically.</p>

<h2 id="memory-management">Memory Management</h2>
    <p>Since this program uses dynamic memory allocation, it is important to free any memory that is no longer needed to avoid memory leaks. Here's how memory is managed:</p>

<ul>
        <li><strong>Creating a student</strong>: Memory is allocated for both the student's structure and their name.</li>
        <li><strong>Updating a student</strong>: If the name is updated, the old memory for the name is freed, and new memory is allocated for the updated name.</li>
        <li><strong>Deleting a student</strong>: Memory for both the student structure and their name is freed.</li>
</ul>

<p>Before the program exits, it ensures that all memory is freed, preventing any memory leaks.</p>
    <p>This project is licensed under the MIT License - see the <a href="LICENSE">LICENSE</a> file for details.</p>

<h3>Thank you for using <strong>Student Manager v1.0</strong>!</h3>
    <p>If you have any suggestions or issues, feel free to open an issue in the GitHub repository!</p>
