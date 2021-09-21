// Bisection method for solving x^2 - 4x - 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const double R = 5.741657387;
const double L = -1.741657387;
float sign_value(float x)
{
    return ((x * x) -4*x - 10);
}

float *generate_random_number(int upper, int left )
{
    static float arr[2] = {0};
    float n1 = (float)(rand() % upper)+1;
    if (left)
        n1 *= -1;
    float n1_value = sign_value(n1);
    float n2 = (float)(rand() % upper) + 1;
    if (left)
        n2 *= -1;
    float n2_value = sign_value(n2);
    while((n2 == n1) || (n2_value * n1_value >= 0))
    {
        n2 = (float)(rand() % upper) + 1;
        if (left)
            n2 *= -1;
        n2_value = sign_value(n2);
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

void find_root(float n1, float n2, int epochs, int left)
{
    int step = 1;
    float root;
    if (left)
        root = L;
    else
        root = R;
    while(epochs--)
    {
        float n3 = (float)(n1 + n2) / 2;
        float n3_value = sign_value(n3);
        if (n3_value > 0)
            n2 = n3;
        else
            n1 = n3;
        printf("%i \t\t\t\t %f \t\t\t\t %f\n",step,n3,root);
        step++;
    }

}

int main() {
    srand(time(0));
    float *arr_right = generate_random_number(10,0);
    float n1_right = *(arr_right+0); // contains x where f(x) < 0
    float n2_right = *(arr_right+1); // contains x where f(x) > 0
    printf("\n\n***********************************************************************\n");
    printf("Calculating through Bisection method for right root\n");
    printf("***********************************************************************\n");
    printf("Initial guesses are: %f and %f \n",n1_right,n2_right);
    printf("***********************************************************************\n");
    printf("Iteration \t result after iteration \t Actual\n");
    find_root(n1_right,n2_right,10,0);

    float *arr_left = generate_random_number(10,1);
    float n1_left = *(arr_left+0); // contains x where f(x) < 0
    float n2_left = *(arr_left+1); // contains x where f(x) > 0
    printf("\n\n***********************************************************************\n");
    printf("Calculating through Bisection method for left root\n");
    printf("***********************************************************************\n");
    printf("Initial guesses are: %f and %f \n",n1_left,n1_right);
    printf("***********************************************************************\n");
    printf("Iteration \t result after iteration \t Actual\n");
    find_root(n1_left,n2_left,10,1);

    return 0;
}
