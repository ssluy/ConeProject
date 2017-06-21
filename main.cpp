#include <iostream>
#include <stdio.h>
#include <math.h>

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
 * @return
 */
double surfaceArea(double r, double h){

}

/**
 * This is the function to find the Volume of a Cone
 *
 * @return
 */
double Volume(double r, double h){

}

//----------------------------Main---------------------------------//

/**
 * This is the main class
 *
 * @return 0
 */
int main() {

    struct Point center;
    printf("Please enter the coordinates of the Center of the base area of the Cone: ");
    scanf("%f %f %f", &center.x, &center.y, &center.z);

    struct Point tip;
    printf("Please enter the coordinates of the Tip of the Cone: ");
    scanf("%f %f %f", &tip.x, &tip.y, &tip.z);

    struct Cone myCone{
            center,
            tip,
    };

    printf("Please enter the radius the Cone: ");
    scanf("%f", &myCone.radius);

    //Calculate the Height of the Cone
    double h = distance(myCone.center, myCone.tip);

    //Calculate the Surface Area of the Cone
    double s = surfaceArea(myCone.radius, h);

    //Calculate the Volume of the Cone
    double v = Volume(myCone.radius, h);

    //Print the Results
    printf("The height of the Cone is: %f" , h);
    printf("The surface area of the Cone is: %f" , s);
    printf("The Volume of the Cone is: %f", v);

    return 0;
}