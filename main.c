#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Vector.h"


void printVector(int* vec, size_t ce);


int main()
{
    // Change the code page to support spanish characters in Windows terminal
    system("chcp 65001 > nul");

    Vector vector;
    if(!vectorCrear(&vector))
    {
        puts("\nno se pudo reservar memoria...");
        return 1;
    }

    srand(time(NULL));

    for(int i = 1; i <= 10; i++)
    {
        vectorInsertarAlFinal(&vector, rand()%100);//para que me aparezca numeros de 2 cifras
    }

    puts("\nAntes de ordenar:\t");
    vectorMostrar(&vector);

    //time_t segIni = time(NULL);

    vectorOrdenar(&vector,BURBUJEO);

    //time_t segFin = time(NULL);

    //printf("\nTiempo que tardo en darse el ordenamiento: %lld\n", segFin - segIni); //EN EL FOR PONER NUMEROS GRANDES EJEMPLO 10000 PARA QUE TARDE ALGUNOS SEGUNDOS

    puts("\nDespués de ordenar:\t");
    vectorMostrar(&vector);

    vectorDestruir(&vector);
    puts("\n\nvector destruido.....");

    return 0;
}


void printVector(int* vec, size_t ce)
{
//    size_t tamVec = sizeof(vec);
//    printf("printVector(): Tam Vec en bytes: %Iu\n", tamVec);

    int* ult = vec + ce - 1;

    for(int* i = vec; i <= ult; i++)
    {
        printf("%d ", *i);
    }

    putchar('\n');
}

