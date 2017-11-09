#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

using namespace std;

int temp1[1800],temp2[1800];             //temporales de las posiciones de la serpiente
int marcox=118,marcoy=28;                //tamaño del marco
int origenx=marcox/2,origeny=marcoy/2;   //lugar original del objeto
int longitud=5;                          //tamaño de la serpiente
int xa[1800],ya[1800];                   //posiciones de la serpiente
char tecla;                              //tecla presionada

COORD coord={0,0};                       // coordenadas
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void xymensaje(int x, int y,string mensaje)
{
    gotoxy(x,y);cout<<mensaje;
}

void guardarPosicion()                   //guarda las posiciones del temporal a las posiciones actuales
{
    for (int j=0;j<longitud-2;j++)
    {
        temp1[j]=xa[j+1];
        temp2[j]=ya[j+1];
    }
    for (int k=1;k<longitud-2;k++)
    {
        xa[k+1]=temp1[k];
        ya[k+1]=temp2[k];
    }
}

char controles()                         //controles de la serpiente
{
    if (kbhit())
    {
        tecla=getch();
        if (tecla=='a' || tecla=='w' || tecla=='s' || tecla=='d')
        {
            if ((tecla=='a' || tecla=='A') && xa[0]>1)
            {
                xymensaje(xa[longitud-1],ya[longitud-1],"8");
                xa[0]--;
                xymensaje(xa[0],ya[0],"*");
            }
            if ((tecla=='d' || tecla=='D') && xa[0]<marcox-1)
            {
                xymensaje(xa[longitud-1],ya[longitud-1]," ");
                xa[0]++;
                xymensaje(xa[0],ya[0],"*");
            }
            if ((tecla=='w' || tecla=='W') && ya[0]>1)
            {
                xymensaje(xa[longitud-1],ya[longitud-1]," ");
                ya[0]--;
                xymensaje(xa[0],ya[0],"*");
            }
            if ((tecla=='s' || tecla=='S') && ya[0]<marcoy-1)
            {
                xymensaje(xa[longitud-1],ya[longitud-1]," ");
                ya[0]++;
                xymensaje(xa[0],ya[0],"*");
            }
            guardarPosicion();
        }
    }
    return tecla;
}

void inicio()                            //reinicio o configuraciones por defecto
{
    xa[0]=origenx;
    xa[1]=origenx-1;
    xa[2]=origenx-2;
    xa[3]=origenx-3;
    xa[4]=origenx-4;
    ya[0]=origeny;
    ya[1]=origeny;
    ya[2]=origeny;
    ya[3]=origeny;
    ya[4]=origeny;
}

int main()
{
    srand(time(NULL));
    inicio();
    while (tecla!='t')
    {
        guardarPosicion();
        controles();
    }
    cout<<xa[longitud]<<endl;
    cout<<ya[longitud]<<endl;
    return 0;
}

