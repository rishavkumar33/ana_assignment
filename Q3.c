#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
const double R = 5.741657387;
float sign_value(float x, int derivative)
{
    if (derivative)
        return (2*x - 4);
    return ((x * x) -4*x - 10);
}

float generate_random_number_newton_raphson(int upper)
{
    float n = (float) ((rand() % upper) + 1 );
    while (sign_value(n,1) <= 0)
    {
        n = (float) ((rand() % upper) + 1 );
    }
    return n;
}

float *generate_random_number(int upper)
{
    float arr[2] = {0};
    float n1 = (float)(rand() % upper)+1;
    float n1_value = sign_value(n1,0);
    float n2 = (float)(rand() % upper) + 1;
    float n2_value = sign_value(n2,0);
    while((n2 == n1) || (n2_value * n1_value >= 0))
    {
        n2 = (float)(rand() % upper) + 1;
        n2_value = sign_value(n2,0);
    }
    if (n2_value < n1_value)
    {
        arr[0] = n2;
        arr[1] = n1;
    }
    else
    {
        arr[0] = n1;
        arr[1] = n2;
    }
    return arr;
}

void bisection(float n1, float n2, int epochs)
{
    printf("\n\n***********************************************************************\n");
    printf("Calculating through Bisection method\n");
    printf("***********************************************************************\n");
    printf("Iteration \t Error(true - the value at current iteration)\n");
    int step = 1;
    while(epochs--)
    {
        float n3 = (float)(n1 + n2) / 2;
        float n3_value = sign_value(n3,0);
        if (n3_value > 0)
            n2 = n3;
        else
            n1 = n3;
        printf("%i \t\t\t %f\n",step,fabs(R-n3));
        step ++ ;
    }

}

void regula_falsi(float n1, float n2, int epochs)
{
    printf("\n\n***********************************************************************\n");
    printf("Calculating through Regula-Falsi method\n");
    printf("***********************************************************************\n");
    printf("Iteration \t Error(true - the value at current iteration)\n");
    int step = 1;
    float n3 = 0;
    while(epochs--)
    {
        n3 = (float)((n2*sign_value(n1,0)) - (n1*sign_value(n2,0))) / (sign_value(n1,0) - sign_value(n2,0));
        float n3_value = sign_value(n3,0);
        if (n3_value > 0)
            n2 = n3;
        else
            n1 = n3;
        printf("%i \t\t\t %f\n",step,fabs(R-n3));
        step ++ ;
    }

}

void newton_raphson(float n,int epochs)
{
    printf("\n\n***********************************************************************\n");
    printf("Calculating through Newton-Raphson method\n");
    printf("***********************************************************************\n");
    printf("Iteration \t Error(true - the value at current iteration)\n");
    int step = 1;
    float n3 = 0;
    while(epochs--)
    {
        n3 = n - (sign_value(n,0) / sign_value(n,1));
        n = n3;
        printf("%i \t\t\t %f\n",step,fabs(R-n3));
        step ++ ;
    }

}
int main() {
    srand(time(0));

    float *arr_right = generate_random_number(10);
    float n1_right = *(arr_right+0); // contains x where f(x) < 0
    float n2_right = *(arr_right+1); // contains x where f(x) > 0
    bisection(n1_right,n2_right,10);
    regula_falsi(n1_right,n2_right,10);

    float n_right = generate_random_number_newton_raphson(10);
    newton_raphson(n_right,10);


    return 0;
}
