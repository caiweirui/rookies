#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

// id,      math/6, english/3,  B1, B2, C1, C2, C3, C4
// 17382,   87,     87,         40, 60, 40, 20, 10, 10
// 02938,   94.5,   85,         40, 30, 0,  0,  20, 10
// 29387,   60,     72,         0,  0,  40, 20, 20, 0

struct stu
{
    char id[11];
    unsigned short credit1;
    double grade1;
    unsigned short credit2;
    double grade2;
    double B1;
    double B2;
    double C1;
    double C2;
    double C3;
    double C4;
    double GPA;
};

struct course
{
    unsigned short credit;
    double grade;
};


int main()
{
    int i = 0;
    double A = 0.0;
    double B = 0.0;
    double C = 0.0;
    struct stu student[3];
    student[0] = {"17382", 6, 87, 3, 87, 40, 60, 40, 20, 10, 10};
    student[1] = {"02938", 6, 94.5, 6, 85, 40, 30, 0, 0, 20, 10};
    student[0] = {"29387", 6, 60, 6, 72, 0, 0, 40, 20, 20, 0};

    for(i = 0; i < 3; i++)
    {
        A = (student[i].credit1 * student[i].grade1 + student[i].credit2 * student[i].grade2) * 0.8;
        B = (student[i].B1 + student[i].B2) * 0.1;
        C = (student[i].C1 + student[i].C2 + student[i].C3 + student[i].C4) * 0.1;
        student[i].GPA = A + B + C;
    }
    



    return 0;
}