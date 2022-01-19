# Roots-of-quadratic-eqn-using-ternary-operator
//Write a program in C to find roots of a quadratic equation using ternary operator.

#include <stdio.h>
#include <math.h>

int main() 
    {
    int a, b, c;
    float d;
    printf("Enter the value of a: ");
    scanf("%d", &a);
    printf("Enter the value of b: ");
    scanf("%d", &b);
    printf("Enter the value of c: ");
    scanf("%d", &c);

    //discriminant
    d = pow(b, 2) - (4 * a * c);

    d==0.0 ? printf("Root1 = Root2 = %f", -(float)b/(2*a)) :
    d>0.0 ? printf("Root1 = %f and Root2 = %f", (-b+sqrt(d))/(2*a), (-b-sqrt(d))/(2*a)) :
    printf("Root1 = %f + (%f)i and Root2 = %f - (%f)i", -((float)b/(2*a)), sqrt(-d)/(2*a), -((float)b/(2*a)), sqrt(-d)/(2*a));
    return 0;
    }
