#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h" // Incluye el archivo de encabezado "list.h" y contiene las declaraciones de las funciones.

int main(){
    int opcion;
    int numLibros = 0;
    Libro biblioteca[50]; 
    ColaReservas colasReservas[50];

    while (true){  // Inicia un bucle infinito para mostrar el menú y permitir al usuario realizar diversas acciones.
        printf("\n*** Menu de la Biblioteca ***\n");
        printf("1. Registrar libro\n");
        printf("2. Mostrar datos de libro\n");
        printf("3. Mostrar todos los libros\n");
        printf("4. Reservar libro\n");
        printf("5. Cancelar reserva de libro\n");
        printf("6. Retirar libro\n");
        printf("7. Devolver libro\n");
        printf("8. Mostrar libros prestados\n");
        printf("9. Importar libros desde un archivo CSV\n");
        printf("10. Exportar libros a un archivo CSV\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion); // Lee la opción seleccionada por el usuario.

        switch (opcion){  // Inicia un bloque switch para manejar las diferentes opciones del menú.
            case 1:
                registrarLibro(biblioteca, &numLibros);
                break;
            case 2:
                mostrarDatosLibro(biblioteca, numLibros, colasReservas);
                break;
            case 3:
                mostrarTodosLosLibros(biblioteca, numLibros);
                break;
            case 4:
                reservarLibro(biblioteca, numLibros, colasReservas);
                break;
            case 5:
                cancelarReservaLibro(biblioteca, numLibros, colasReservas);
                break;
            case 6:
                retirarLibro(biblioteca, numLibros, colasReservas);
                break;
            case 7:
                devolverLibro(biblioteca, numLibros, colasReservas);
                break;
            case 8:
                mostrarLibrosPrestados(biblioteca, numLibros);
                break;
            case 9:{
              
                char nombreArchivo[MAX_CARACTERES];
                printf("Ingrese el nombre del archivo CSV para importar libros: ");
                scanf("%s", nombreArchivo);
                importarLibrosCSV(biblioteca, &numLibros, colasReservas, nombreArchivo);
                break;
            }
            case 10:{
              
                char nombreArchivo[MAX_CARACTERES];
                printf("Ingrese el nombre del archivo CSV para exportar libros: ");
                scanf("%s", nombreArchivo);
                exportarLibrosCSV(biblioteca, numLibros, colasReservas, nombreArchivo);
                break;
            }
            case 0: 
                printf("Saliendo del programa. ¡Hasta luego!\n");
                return 0; // Termina el programa.
            default: 
                printf("Opción no válida. Intente de nuevo.\n"); // Mensaje para opciones no válidas.
        }
    }
    return 0; // Llegará aquí solo al salir del bucle while, lo que indica que el programa ha terminado.
}