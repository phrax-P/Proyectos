#include <stdio.h>
#include <math.h>
//Universidad de Costa Rica
//Escuela de Ingenieria Electrica
//Curso de Matematica superior IE-305
//Profesor: Marvin Coto Jimenes
//Estudiante: Kenny Wu Wen C08592 
// I-2021

float f(float x)
{
    return (x-42)*(x-42) - 3*x*log((x-100)*(x-100));
}

float df (float x)
{
    return (2*x-3*(log((x-100)*(x-100)))-(6*x)/(x-100)-84);
}

int np(int itr, int maxmitr, float h, float x0)
{
    float allerr = 0.0001;
    float allerr2 = 0.00001;
    float x1,temp;
    int itr2;
    for (itr=1; itr<=maxmitr; itr++)
    {
        h=f(x0)/df(x0);
        x1=x0-h;
        if (fabs(h)> allerr2)
        {
            if (fabs(h)>allerr)
            {
                printf("%3d & %9.6f & %9.6f \\\\   \n", itr, x1,x1);
                temp=x1;
                itr2=itr;
            }
            else
            {
                printf("%3d & - & %9.6f \\\\  \n", itr, x1);
            }
        }
        if (fabs(h) < allerr2)
        {
            printf("%3d & - & %9.6f \\\\  \n", itr, x1);
            printf("Despues de %3d iterateraciones con error maximo de 0.0001, raiz = %lf\n", itr2, temp);
            printf("Despues de %3d iterateraciones con error maximo de 0.00001, raiz = %lf\n", itr, x1);
            return 1;
        }
        x0=x1;
    }
    printf(" No se encontro la solucion porque no converge o por insuficiente iteraciones\n");
    return 0;
}

int main()
{
    int itr, maxmitr;
    float h, x0, x1;
    printf("\nIngrese x0 y el maximo de iteraciones\n");
    scanf("%f %d", &x0, &maxmitr);
    printf("  0 & %.2f & %.2f \\\\\n",x0,x0);
    np(itr,maxmitr,h,x0);
    return 1;
}