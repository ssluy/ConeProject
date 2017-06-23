#include <iostream>
#include <stdio.h>
#include <math.h>

int const PI = 3.14;

//----------------------------Point--------------------------------//

/**
 * This is the Structure for the Point
 */
struct Point{
    double x;
    double y;
    double z;
};

/**
 * Function to find the Distance between 2 Points
 *
 * @return d
 */
double distance(struct Point Point1, struct Point Point2){
    //Below is the function to calculate the distance between 2 points
    double d = sqrt(pow(Point1.x - Point2.x, 2) + pow(Point1.y - Point2.y, 2) + pow(Point1.z - Point2.z, 2));
    return d;
}


//----------------------------Cone---------------------------------//

/**
 * This is the Structure for the Cone
 */
struct Cone{
    struct Point center;   // The center of the base area of the cone
    struct Point tip;   // The Tip of the cone
    double radius;     //The radius of the cone

};

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

//----------------------------Main---------------------------------//

/**
 * This is the main class
 *
 * @return 0
 */
int main() {

    double xC, yC, zC;
    double xT, yT, zT;
    double r;

    printf("Please enter the coordinates of the Center of the base area of the Cone: ");
    scanf("%lf %lf %lf", &xC, &yC, &zC);

    printf("Please enter the coordinates of the Tip of the Cone: ");
    scanf("%lf %lf %lf", &xT, &yT, &zT);

    printf("Please enter the radius the Cone: ");
    scanf("%lf", &r);

    struct Point center {xC, yC, zC};

    struct Point tip {xT, yT, zT};


    struct Cone myCone {
            center,
            tip,
            r
    };

    //Calculate the Height of the Cone
    double h = distance(myCone.center, myCone.tip);

    //Calculate the Surface Area of the Cone
    double s = surfaceArea(myCone.radius, h);

    //Calculate the Volume of the Cone
    double v = volume(myCone.radius, h);

    //Print the Results
    printf("The height of the Cone is: %.2f\n" , h);
    printf("The surface area of the Cone is: %.2f\n" , s);
    printf("The Volume of the Cone is: %.2f", v);

    return 0;
}