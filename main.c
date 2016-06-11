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
#include <ctype.h>

// prototype functions
int askNumberOfCourses();

double askForScores(int course_count);

double calculateGp(int courses_count, int scores[], int grades[]);

void flush(void);
int close();

int main()
{
    puts("Hi man");
    // intro
    puts("I can help you calculate your GPA");

    int number_of_courses;

    number_of_courses = askNumberOfCourses();

    double gp = askForScores(number_of_courses);

    printf("\nYour GPA is %.2f\n\n", gp); // display the gp in 2 dp

    // all done
    return close();
}

int askNumberOfCourses() {

    int valid = 0;

    while(valid == 0) {
        int number = 0; // to hold the number entered
        printf("\nNumber of courses? "); // ask


        scanf("%d", &number); // collect
        flush();

        if (number > 0) {
            valid = 1;
            return number;
        } else {
            // continue asking for a valid number
            puts("You need to enter a digit greater than one");
        }
    }

    return 0;
}

double askForScores(int courses_count) {


    // variables to store units and grades for each course
    int units[courses_count];
    int grades[courses_count];

    // initialize the counter
    int i;

    // ask the grades for the number of courses given
    for(i = 0; i<courses_count; i++) {
        int k = i + 1;
        int unit;

        printf("\n\nUnit for course %d: ", k); // ask

        scanf("%d", &unit); // save and put in unit variable
        flush();

        units[i] = unit; // store in units array

        int valid_grade = 0; // variable to know if the user entered a valid grade

        char grade; // initialise grade

        while(valid_grade == 0) { // continue asking if the user entered an invalid grade

            valid_grade = 1; // set as valid. To be changed to 0 if the grade entered is not A-F

            printf("\nGrade for course %d: ", k); // ask

            scanf("%c", &grade); // insert
            flush();

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
            grades[i] = score;
        }
    }

    return calculateGp(courses_count, grades, units);
}

double calculateGp(int courses_count, int grades[], int units[]) {

    double score = 0;

    // initialize the counter
    int i = 0;

    int total_units = 0;

    // loop through to add the units and scores
    for(i = 0; i<courses_count; i++) {
        // scores
        score = score + (grades[i] * units[i]);
        total_units = total_units + units[i];
    }

    double gp = score / total_units;

    return gp;
}

void flush(void) {
    while(getchar() != '\n');
}

int close() {
    puts("type 'exit' to close\n");
    int a;
    scanf("%d", &a); // to keep the console open
    return 0;
}
