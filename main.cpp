#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int const PI = 3.14;

struct Point{
    double x;
    double y;
    double z;
};

struct Cone {
    struct Point center;   // The center of the base area of the cone
    struct Point tip;   // The Tip of the cone
    double radius;     //The radius of the cone

};

double distance(struct Point Point1, struct Point Point2);
double surfaceArea(double r, double h);
double volume(double r, double h);
void writeRandomCones(int cones);
void readFile();


int main() {

    //number of cones
    int cones;

    printf("Please enter the number of cones you want: ");
    scanf("%d", &cones);

    writeRandomCones(cones);

    readFile();

    return 0;
}   //end of main

/**
 * Function to find the Distance between 2 Points
 *
 * @return d
 */
double distance(struct Point Point1, struct Point Point2) {
    //Below is the function to calculate the distance between 2 points
    double d = sqrt(pow(Point1.x - Point2.x, 2) + pow(Point1.y - Point2.y, 2) + pow(Point1.z - Point2.z, 2));
    return d;
}

/**
 * This is the function to find the surface area of a cone
 *
 * @param h - The height of the cone
 * @param r - The radius of the base of the cone
 * @return The surface area of the cone
 * @author Socretquuliqaa Lee
 */
double surfaceArea(double r, double h) {

    return (PI * r) * (r + sqrt(pow(h, 2) + pow(r,2)));

}   //end of surfaceArea(double r, double h)

/**
 * This is the function to find the Volume of a Cone
 *
 * @param h - The height of the cone
 * @param r - The radius of the base of the cone
 * @return The volume of the cone
 * @author Socretquuliqaa Lee
 */
double volume(double r, double h) {

    return (PI * pow(r, 2) * (h/(double)3));

}   //end of volume(double r, double h)

//---------------------------Others--------------------------------//

/**
 * A function to write random cone data to file.
 *
 * @param cones - The number of cones
 * @return void
 * @author Socretquuliqaa Lee
 * */
void writeRandomCones(int cones) {

    FILE *file;

    file = fopen("PreprocessedConeData.txt", "w+");

    for (int i = 0; i < cones; i++) {

        //loop through the numbers in one line
        for (int j = 0; j < 7; j++) {
            float a = 100.0;
            float x = (float)rand()/(RAND_MAX/a);
            fprintf(file, "%.2f\t", x);
        }   //end of j loop

        fprintf(file,"\n");

    }   //end of i loop

    printf("%d cones has been generated into PreprocessedConeData.txt", cones);

}   //end of void writeRandomCones(int cones)

/**
 *
 * */
void readFile() {

    FILE *source;

    //coordinates of center
    double xC, yC, zC;

    //coordinates of tip
    double xT, yT, zT;

    //cone radius
    double r;

    //open file
    source = fopen("PreprocessedConeData.txt", "r");

    //check line
    double l = fscanf(source, "%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf", &xC, &yC,&zC, &xT, &yT, &zT, &r);

    while (l != 7) {

        struct Point center {xC, yC, zC};

        struct Point tip {xT, yT, zT};

        struct Cone myCone {center, tip, r};

        //Calculate the Height of the Cone
        double h = distance(myCone.center, myCone.tip);

        //Calculate the Surface Area of the Cone
        double s = surfaceArea(myCone.radius, h);

        //Calculate the Volume of the Cone
        double v = volume(myCone.radius, h);

        printf("The height of the Cone is: %.2f\n" , h);
        printf("The surface area of the Cone is: %.2f\n" , s);
        printf("The Volume of the Cone is: %.2f\n", v);

        printf("\n");
        printf("\n");

        l = fscanf(source, "%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf", &xC, &yC,&zC, &xT, &yT, &zT, &r);

    }   //end of while (l != EOF)

    fclose(source);

}   //end of void readFile(char sourceFile[])