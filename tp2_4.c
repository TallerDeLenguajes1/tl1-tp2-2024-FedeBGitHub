#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMA 5
struct compu
{
    int velocidad;  // 1-3 Ghz
    int anio;       // 2015 - 2023
    int cantidad;   // 1-8
    char *tipo_cpu; // valores del arreglo tipos
};

void mostrar_pc (struct compu Pcs[TAMA],int longitud);
void pc_mas_vieja (struct compu Pcs[TAMA],int longitud);
void pc_mas_veloz (struct compu Pcs[TAMA],int longitud);
int main()
{
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    struct compu Pcs[TAMA];
    srand(time(NULL));
    int tipo;

    for (int i = 0; i <TAMA; i++)
    {
        
        Pcs[i].cantidad = rand() % 8 + 1;
        Pcs[i].anio = rand() % 9 + 2015;
        Pcs[i].velocidad = rand() % 3 + 1;
        tipo = rand() %6;
        Pcs[i].tipo_cpu = tipos[tipo];        
    }
   
    
    mostrar_pc(Pcs, TAMA);
    pc_mas_vieja (Pcs,TAMA);
    pc_mas_veloz (Pcs,TAMA);
    return 0;
}

void mostrar_pc (struct compu Pcs[TAMA],int longitud){
    for (int i = 0; i < longitud; i++)
    {
        printf("\n############# Pc %d ############# \n",i+1);
        printf("Cantidad de nucleos: %d \n",Pcs[i].cantidad);
        printf("Anio de fabricacion: %d \n",Pcs[i].anio);
        printf("Velocidad (GHz): %d \n",Pcs[i].velocidad);
        printf("Tipo de CPU: %s \n",Pcs[i].tipo_cpu);
    }
}

void pc_mas_vieja (struct compu Pcs[TAMA],int longitud){
    int pc,anio;
    pc = 0;
    anio = 3000;
    for (int i = 0; i < longitud; i++)
    {
        if (Pcs[i].anio<anio)
        {
            pc = i+1;
            anio = Pcs[i].anio;
        }
    }
     printf("\n------------ La Pc mas antigua es la %d: anio %d ------------\n",pc,anio);
}

void pc_mas_veloz (struct compu Pcs[TAMA],int longitud){
    int pc,velocidad;
    pc = 0;
    velocidad = 0;
    for (int i = 0; i < longitud; i++)
    {
        if (Pcs[i].velocidad>velocidad)
        {
            pc = i+1;
            velocidad = Pcs[i].velocidad;
        }
    }
     printf("\n************ La Pc mas veloz es la %d: %d GHz ************\n",pc,velocidad);
}