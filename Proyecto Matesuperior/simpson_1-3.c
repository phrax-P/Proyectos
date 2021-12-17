#include<stdio.h>
#include<math.h>
#include<stdlib.h>
//Universidad de Costa Rica
//Escuela de Ingenieria Electrica
//Curso de Matematica superior IE-305
//Profesor: Marvin Coto Jimenes
//Estudiante: Kenny Wu Wen C08592 
// I-2021
float f(float x)
{
    return(2/x + x*cos(x-1));
}
void s_t(float h,float x0,float xn)
{
    int i,n;
    float x0,xn,so,se,ans;
    float h1 = h;
    n=(xn-x0)/h;
    if(n%2==1)
    {
        n=n+1;
    }
    h=(xn-x0)/n;
    float y[n],x[n];
    printf("\n Los valores redifinidos de n y h son: %d %f\n",n,h);
    printf("\n Valores Y: \n");
    for(i=0; i<=n; i++)
    {
        x[i]=x0+i*h;
        y[i]=f(x[i]);
        if (n<=100)
        printf("\n %f\n",y[i]);
    }
    so=0;
    se=0;
    for(i=1; i<n; i++)
    {
        if(i%2==1)
        {
            so=so+y[i];
        }
        else
        {
            se=se+y[i];
        }
 
    }
    ans=h/3*(y[0]+y[n]+4*so+2*se);
    printf("\n La integracion final es: %9.6f\n",ans);
    printf("%f & %d & %f & %9.6f & -4.58076069 \\\\  \n",h1,n,h,ans);
    //Se guardaran los datos en archivo llamado datos.txt
    FILE* fp = fopen("datos.txt","a");
    fprintf(fp,"%f & %d & %f & %9.6f & -4.58076069 \\\\  \n",h1,n,h,ans);
    fclose(fp);
}
void main()
{   
    int cant;
    printf("\nIngrese cantidad de veces que desea probar: ");
    scanf("%d",&cant);
    float h,x0,xn;
    for (int i = 0; i < cant; i++)
    {
        printf("\nIngrese el valor de h y los intervalos x0 y xn: ");
        scanf("%f",&h,&x0,&xn);
        s_t(h,x0,xn);
    }
    
}
