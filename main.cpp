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

double random_number(double min_num, double max_num);
double distance(struct Point Point1, struct Point Point2);
double surfaceArea(double r, double h);
double volume(double r, double h);
void writeRandomCones(int cones);
void readFile();

/**
 * This is the main
 *
 * @return 0
 */
int main() {

    //number of cones
    int cones;

    printf("Please enter the number of cones you want: ");
    scanf("%d", &cones);

    writeRandomCones(cones);

    readFile();

    printf("Done");
    return 0;
}   //end of main

/**
 * function to generate a random double value
 *
 * @param min_num
 * @param max_num
 * @return
 */
double random_number(double min_num, double max_num)
{
    double f = (double)rand() / RAND_MAX;
    return min_num + f * (max_num - min_num);
}

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

        //loop through and generate the coordinate of the center and tip
        for (int j = 0; j < 6; j++) {
            float max = 20;
            float min = -20;
            float x = random_number(min, max);
            fprintf(file, "%.2f\t", x);
        }   //end of j loop

            //generate a random radius value
            float r = random_number(1, 20);
            fprintf(file, "%.2f\t", r);

        fprintf(file,"\n");

    }   //end of i loop

    printf("%d cones has been generated into PreprocessedConeData.txt \n\n", cones);

    fclose(file);

}   //end of void writeRandomCones(int cones)

/**
 *
 * */
void readFile() {

    FILE *source;
    FILE *output;

    //coordinates of center
    double xC, yC, zC;
    //coordinates of tip
    double xT, yT, zT;
    //cone radius
    double r;

    //open file
    source = fopen("PreprocessedConeData.txt", "r");
    //open and create a file to put the result
    output = fopen("output.txt", "w+");


    //check line
    double l = fscanf(source, "%lf%lf%lf%lf%lf%lf%lf", &xC, &yC,&zC, &xT, &yT, &zT, &r);

    while (l != EOF) {

        struct Point center {xC, yC, zC};
        struct Point tip {xT, yT, zT};
        struct Cone myCone {center, tip, r};

        //Calculate the Height of the Cone
        double h = distance(myCone.center, myCone.tip);
        //Calculate the Surface Area of the Cone
        double s = surfaceArea(myCone.radius, h);
        //Calculate the Volume of the Cone
        double v = volume(myCone.radius, h);

        //put the result in the output.txt
        fprintf(output, "%.2f\t%.2f\t%.2f\n" , h , s, v);

        printf("The height of the Cone is: %.2f\n" , h);
        printf("The surface area of the Cone is: %.2f\n" , s);
        printf("The Volume of the Cone is: %.2f\n", v);

        printf("\n");

        //Check the next line
        l = fscanf(source, "%lf%lf%lf%lf%lf%lf%lf", &xC, &yC,&zC, &xT, &yT, &zT, &r);


    }   //end of while (l != EOF)

    printf("The output has been store in the output.txt");
    fclose(source);
    fclose(output);

}   //end of void readFile(char sourceFile[])