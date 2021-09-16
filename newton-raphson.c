// Newton-Raphson method for solving x^2 - 4x - 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const double R = 5.741657387;
const double L = -1.741657387;
float sign_value(float x, int derivative)
{
    if (derivative)
        return (2*x - 4);
    return ((x * x) -4*x - 10);
}

float generate_random_number(int upper, int left )
{

    if(left)
    {
        float n = (float) ((rand() % upper) + 1 );
        while (sign_value(n,1) >= 0)
        {
            n = (float) ((rand() % upper) + 1 );
        }
        return n;
    }
    else
    {
        float n = (float) ((rand() % upper) + 1 );
        while (sign_value(n,1) <= 0)
        {
            n = (float) ((rand() % upper) + 1 );
        }
        return n;
    }

}

void find_root(float n,int epochs,int left)
{
    float n3 = 0;
    int step = 1;
    float root;
    if (left)
        root = L;
    else
        root = R;
    while(epochs--)
    {
        n3 = n - (sign_value(n,0) / sign_value(n,1));
        n = n3;
        printf("%i \t\t\t\t %f \t\t\t\t %f\n",step,n3,root);
        step ++ ;
    }

}
int main() {
    srand(time(0));
    float n_right = generate_random_number(10,0);
    printf("\n\n***********************************************************************\n");
    printf("Calculating through Newton-Raphson method for right root\n");
    printf("***********************************************************************\n");
    printf("Initial guess: %f\n",n_right);
    printf("***********************************************************************\n");
    printf("Iteration \t result after iteration \t Actual\n");
    find_root(n_right,10,0);

    float n_left = generate_random_number(10,1);
    printf("\n\n***********************************************************************\n");
    printf("Calculating through Newton-Raphson method for left root\n");
    printf("***********************************************************************\n");
    printf("Initial guess: %f\n",n_left);
    printf("***********************************************************************\n");
    printf("Iteration \t result after iteration \t Actual\n");
    find_root(n_left,10,1);

    return 0;
}
