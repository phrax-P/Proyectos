#include<stdio.h>
#include<math.h>
//Universidad de Costa Rica
//Escuela de Ingenieria Electrica
//Curso de Matematica superior IE-305
//Profesor: Marvin Coto Jimenes
//Estudiante: Kenny Wu Wen C08592 
// I-2021
double f(double x)
{
    return (x-42)*(x-42) - 3*x*log((x-100)*(x-100)); // f(x)= x^3-4
}
int s(double a, double b, int n)
{
    int count = 1;
    double e1 = 0.0001;
    double e2 = 0.00001;
    double c = 0;
    do
    {
        if(f(a)==f(b))
        {
            printf("\nSoluciones no encontradas porque a y b tienen el mismo valor.\n");
            return 0;
        }
        c=(a*f(b)-b*f(a))/(f(b)-f(a));
        a=b;
        b=c;
        if (fabs(f(c))>e1)
        {
            printf("%d & %lf & %lf \\\\ \n",count,c,c);
        }
        else
        {
            printf("%d & - & %lf \\\\ \n",count,c);
            printf("%f %f\n",f(c),e1);
            printf("%f %f\n",f(c),e2);
        }
        count++;
        if(count==n)
        {
            break;
        }
    } while(fabs(f(c))>e2);
    printf("\n La solucion es  %lf\n",c);
    return 1;
}
void main()
{
    double a,b;
    int n;
    printf("\n\nIngrese los valores a y b:\n"); //(a,b) deben pertencer al dominio de f(x).
    scanf("%lf%lf",&a,&b);
    printf("Ingrese el numero de iteraciones:\n");
    scanf("%d",&n);
    s(a,b,n);
}