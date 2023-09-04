#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

#define MAX_CARACTERES 51

// Estructura para representar un libro
typedef struct{
    char titulo[MAX_CARACTERES];
    char autor[MAX_CARACTERES];
    char genero[MAX_CARACTERES];
    char ISBN[MAX_CARACTERES];
    char ubicacion[MAX_CARACTERES];
    char estado[MAX_CARACTERES];
    char reservas[MAX_CARACTERES];
} Libro;

// Estructura para representar un nodo de reserva
typedef struct{
    char nombre_estudiante[MAX_CARACTERES];
    struct ReservaNode* siguiente;
} ReservaNode;

// Estructura para representar una cola de reservas
typedef struct{
    ReservaNode* frente;
    ReservaNode* final;
} ColaReservas;

// Prototipos de funciones

void registrarLibro(Libro* biblioteca, int* numLibros);
// Almacena un nuevo libro

void mostrarDatosLibro(Libro* biblioteca, int numLibros, ColaReservas* colasReservas);
// Imprime por pantalla el título, autor y el estado del libro. En caso de estar "reservado", muestar el listado de estudiantes que lo tienen reservado. 

void mostrarTodosLosLibros(Libro* biblioteca, int numLibros);
// Muestra por pantalla los títulos y autores de los libros registrados en la biblioteca.

void reservarLibro(Libro* biblioteca, int numLibros, ColaReservas* colasReservas);
// Agrega al estudiante a la cola de reservas del libro.

void cancelarReservaLibro(Libro* biblioteca, int numLibros, ColaReservas* colasReservas);
// Elimina al estudiante titular de la lista de reservas 

void retirarLibro(Libro* biblioteca, int numLibros, ColaReservas* colasReservas);
// Cambia el estado a "Prestado" de un libro si esta disponible o lo desea retirar el estudiante titular de la cola de reservas. 

void devolverLibro(Libro* biblioteca, int numLibros, ColaReservas* colasReservas);
// Cambia el estado del libro de "prestado" a "reservado" o " disponible" según corresponda 

void mostrarLibrosPrestados(Libro* biblioteca, int numLibros);
// Entrega un listado de los libros prestados, imprimiendo el título y autor del libro, junto al nombre del estudiante que lo tiene prestado.

void importarLibrosCSV(Libro* biblioteca, int* numLibros, ColaReservas* colasReservas, const char* nombreArchivo);
// Importa libros a la biblioteca desde un CSV. Almacenando todas las categorías que posee la struct "Libro"

void exportarLibrosCSV(Libro* biblioteca, int numLibros, ColaReservas* colasReservas, const char* nombreArchivo);
// Exporta todos los libros registrados en la biblioteca hacia un archivo CSV definido por el usuario.

#endif //LIST_H