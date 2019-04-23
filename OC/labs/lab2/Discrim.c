
#include <stdio.h>
#include <math.h>




int main()
{
    float a, b, c;

   scanf("%f %f %f", &a, &b, &c);
    // a = 4;
    // b = 10;
    // c = 25;

    double first_root, second_root;

    double d = pow(b, 2) - 4 * a * c;

    if (d == 0)
    {
        first_root = -b / (2 * a);

        printf("roots = %0.1f\n", first_root);
    }
    else if (d > 0)
    {
        first_root = (-b + sqrt(d)) / (2 * a);
        second_root = (-b - sqrt(d)) / (2 * a);

        printf("first root = %0.1f and second root = %0.1f\n", first_root, second_root);
    }
    else
    {
        double complex_discriminant = -pow(b, 2) + 4 * a * c;
        double complex_part = sqrt(complex_discriminant) / (2 * a);
        double number_part = (-b) / (2 * a);

        printf("first root = %0.1f + %0.1fi\n", number_part, complex_part);
        printf("second root = %0.1f - %0.1fi\n", number_part, complex_part);
    }
    return 0;

}

// =======
// #include<stdio.h>
// #include<math.h>

// int main(void)
// {
//     int a,b,c;
//     int x1,x2;
//     double D;
//     printf("====Discriminant calculator===\n");
//     printf("\n Enter a:");
//     scanf("%d",&a);
//     printf("\n Enter b:");
//     scanf("%d",&b);
//     printf("\n Enter c:");
//     scanf("%d",&c);


//     D = b*b - 4*a*c;

//     if(D >= 0)
//     {
//         if(D > 0){
//         printf("D = %f (equation has two roots)\n", D);
//               x1 = (-b + (sqrt(D)))/(2*a); 
//               x2 = (-b - (sqrt(D)))/(2*a);
//               printf("x1 = %d \n", x1);
//               printf("x2 = %d \n", x2);
//         }else{
//             printf("D = %f (equation has single root)\n", D);
//             x1 = -b / (2*a);
//             printf("x1 = %d \n", x1);
//         }
//     }else
//     printf("D = %f (equation has no real roots)", D);

//      return 0;
// }
// >>>>>>> Maks7
