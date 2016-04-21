/*
* Program to calculate GPA
* Author Olajide Afeez <https://schoolnetwork.io/@djade>
*/


/*
C is a very, very small
language and it can do
almost nothing without
the use of external
libraries. You will need
to tell the compiler what
external code to use by
including header files
for the relevant libraries.
The header you will see
more than any other
is stdio.h. The stdio
library contains code
that allows you to read
and write data from and
to the terminal.
*/
#include <stdio.h>

int courses_count = 0;

int units[];
int grades[];

int main()
{
    // intro
    puts("I can help you calculate your GPA");

    askNumberOfCourses();

    if(courses_count < 1) { // if number entered is 0 or a non integer number was entered
        // stop the program
        puts("You need to enter a digit greater than one");
        puts("Please run the program again");
        return close();
    }

    askForScores();

    calculateGp();

    // all done
    close();
}

int askNumberOfCourses() {
    printf("\nNumber of courses? ");
    scanf("%d", &courses_count); // ask
    return 0;
}

int askForScores() {
    // initialize the counter
    int i = 0;

    // ask the grades for the number of courses given
    for(i; i<courses_count; i++) {
        int unit;
        printf("\n\nUnit for course %d: ", i+1); // ask
        scanf("%d", &unit); // save and put in units variable
        units[i] = unit; // store in units array

        int valid_grade = 0; // variable to know if the user entered a valid grade

        char grade; // initialise grade

        while(valid_grade == 0) { // continue asking if the user entered an invalid grade

            valid_grade = 1; // set as valid. To be changed to 0 if the grade entered is not A-F

            printf("\nGrade for course %d: ", i+1); // ask
            scanf(" %c", &grade); // insert

            grade = toupper(grade); // convert the grade entered to upper case

            int score;

            switch(grade) {
                case 'A':
                    score = 5;
                    break;

                case 'B':
                    score = 4;
                    break;

                case 'C':
                    score = 3;
                    break;

                case 'D':
                    score = 2;
                    break;

                case 'E':
                    score = 1;
                    break;

                case 'F':
                    score = 0;
                    break;

                default: // no valid grade was entered
                    valid_grade = 0;
                    printf("\nINVALID: The grade must be from A-F. Please try again\n"); // error
            }

            // store grade for the particular course in grades array
            grades[i] = score; // using not using & will not store it in the global grades declared at the top
        }
    }
}

int calculateGp() {

    double score = 0;
    // initialize the counter

    int i = 0;
    int total_units = 0;

    // loop through to add the units and scores
    for(i; i<courses_count; i++) {
        // scores
        score = score + (units[i] * grades[i]);
        total_units = total_units + units[i];
    }

    double gp = score / total_units;

    printf("\nYour GPA is %.2f\n\n", gp); // display the gp in 2 dp

    return 0;
}

int close() {
    puts("type 'exit' to close\n");
    int a;
    scanf("%g", &a); // to keep the console open
    return 0;
}
