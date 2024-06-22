# S.M.S Unix Version

This project is based on the [student-management-system](https://github.com/AveyBD/student-management-system) repository by **AveyDB**

I created this project with two objectives in mind: 
- Practice C language project 
- Create a version that uses Unix C libraries instead of Windows ones 

Also, this project uses [C Project Template](https://github.com/pantuza/c-project-template) to generate the project structure and make file


## SMSLIB.C wiki

This C program implements a basic Student Management System, allowing users to perform various operations related to student data. The program includes features for adding, modifying, and removing student records, as well as changing the system password. Below is a detailed explanation of the different components of the code:

## Terminal Colors

The code defines terminal colors using ANSI escape sequences to enhance the visual appearance of the terminal interface. The defined colors include:

- `KNRM` - Normal color
- `KRED` - Red color
- `KGRN` - Green color
- `KYEL` - Yellow color
- `KBLU` - Blue color
- `KMAG` - Magenta color
- `KCYN` - Cyan color
- `KWHT` - White color

## Structures

The code defines two structures:

- `struct pass` - This structure is used to store a password, with a maximum length of 25 characters.
- `struct Stud` - This structure represents a student and has two fields, namely `name` and `dept`, for storing the student's name and department, respectively.

## Library Functions

The program includes several library functions that facilitate different functionalities:

- `printChar(char ch, int n)` - This function prints a specified character `ch` a certain number of times, as determined by the integer value `n`.
- `title()` - The `title` function clears the terminal screen and displays a stylized title for the Student Management System.
- `mainMenu()` - This function displays the main menu options for users to interact with the program.
- `checkIfFileExists(const char *filename)` - This function checks the existence of a specified file in the current directory.
- `printFileContent(const char *filename)` - This function reads the content of a file and prints it to the console.
- `password()` - The `password` function allows users to set a new password for the Student Management System. It prompts the user for input and saves the password in a file named `password.txt`.
- `add()` - This function is used to add a new student to the system. It takes input for the student's name and department and stores this information in a file named `db.txt`.
- `show()` - The `show` function displays the contents of the student database file (`db.txt`) on the terminal.

## Usage

The program offers a simple and intuitive interface for managing student information. Users can add new student records, modify existing records, view all student data, and remove student entries. The system also allows users to change the password for added security. The main menu provides users with a clear set of options to navigate through the program's functionalities.

Note: The code contains several sections marked as "WIP" (work in progress), indicating that certain features are still under development and may not be fully implemented.

For a more comprehensive understanding, refer to the source code provided in the corresponding file.

## Warnings

To compile this project with no problems you will need to create two folders inside the project:

`mkdir bin`
`mkdir lib`

#### Author

Julian Hinojosa Gil <julianhinojosagil@gmail.com>
