#include <stdio.h>
#include <math.h>
//Universidad de Costa Rica
//Escuela de Ingenieria Electrica
//Curso de Matematica superior IE-305
//Profesor: Marvin Coto Jimenes
//Estudiante: Kenny Wu Wen C08592 
// I-2021


//Funcion original f(x)
double f(double x)
{
    return x*x*x-2*x*x+1;
}
//Funcion g(x)=x
double g(double x)
{
    return x*x*x-2*x*x+1+x;
}
//Metodo de punto fijo recibe valor inicial, error y cantidad de iteraciones
void punto_fijo(double x, double err, int itr,FILE *fptr)
{
    fprintf(fptr,"\nx_0=%.1f\n",x);
    double x_i = x;
    int a=0;
    printf("\ni &    x_i\n");
    printf("%d & %9.6f\n",a,x_i);
    while (fabs(f(x_i))>err && itr!=0) //Usaremos la condicion de mientras valor absoluto de f(x_{i})>error introducido y limite de iteraciones
    {
        x_i = g(x_i); //Siguiente valor
        itr--;
        a++;
        printf("%d & %9.6f\n",a,x_i); //Imprimir iteracion y su valor
        fprintf(fptr,"%.6f,",x_i);// guardar datos en archivo
    }
    if (fabs(f(x_i))<err)
    {
        printf("La raiz encontrada fue: %9.6f\n",x_i);
    }
    else if (fabs(f(x_i))>err)
    {
        printf("No hubieron suficientes iteraciones o no hubo convergencia\n");
    }
}
int main()
{
    FILE *fptr;
    fptr = fopen("./datos_puntos_fijos","w+");
    int cant,itr;
    double x, err; 
    printf("Ingrese la cantidad de pruebas a hacer: \n");
    scanf("%d",&cant);
    
    for (int i = 0; i < cant; i++)
    {
        printf("Ingrese valor inicial, error y cantidad de iteraciones: \n");
        scanf("%lf%lf%d",&x,&err,&itr);
        punto_fijo(x,err,itr,fptr);
    }
    
    fclose(fptr);
    
    return 0;
}