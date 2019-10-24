#include <math.h>

#include <stdio.h>


// Function taking a function pointer as an argument




double square(double x) {

     return x * x;

}


int main(void) {

    double  sum;


    // Use standard library function 'sin()' as the pointed-to function

    sum = compute_sum(sin, 0.0, 1.0);

    printf("sum(sin): %g\n", sum);


    // Use standard library function 'cos()' as the pointed-to function

    sum = compute_sum(cos, 0.0, 1.0);

    printf("sum(cos): %g\n", sum);


    // Use user-defined function 'square()' as the pointed-to function

    sum = compute_sum(square, 0.0, 1.0);

    printf("sum(square): %g\n", sum);


    return 0;

}
