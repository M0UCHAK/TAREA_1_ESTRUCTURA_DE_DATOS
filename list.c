#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h" // Contiene las definiciones de estructuras y funciones utilizadas en este código.

//////////////////////////////////// FUNCION REGISTRAR LIBRO //////////////////////////////////////////

void registrarLibro(Libro* biblioteca, int* numLibros){
  
  Libro nuevoLibro; // Crea una estructura Libro llamado nuevoLibro para almacenar los datos del nuevo libro a registrar.
  printf("Ingrese el titulo del libro: ");
  scanf(" %[^\n]s", nuevoLibro.titulo);
  
  printf("Ingrese el autor del libro: ");
  scanf(" %[^\n]s", nuevoLibro.autor);
  
  printf("Ingrese el genero del libro: ");
  scanf(" %[^\n]s", nuevoLibro.genero);
  
  printf("Ingrese el ISBN del libro: ");
  scanf(" %[^\n]s", nuevoLibro.ISBN);
  
  printf("Ingrese la ubicacion del libro: ");
  scanf(" %[^\n]s", nuevoLibro.ubicacion);
  
  strcpy(nuevoLibro.estado, "Disponible"); // Establece el estado del libro como "Disponible".
  strcpy(nuevoLibro.reservas, ""); // Inicializa las reservas como una cadena vacía.

  // Comprueba si algún campo excede la longitud máxima permitida.
  if (strlen(nuevoLibro.titulo) > MAX_CARACTERES || strlen(nuevoLibro.autor) > MAX_CARACTERES ||
    strlen(nuevoLibro.genero) > MAX_CARACTERES || strlen(nuevoLibro.ISBN) > MAX_CARACTERES ||
    strlen(nuevoLibro.ubicacion) > MAX_CARACTERES){
    printf("Uno o más campos exceden la longitud máxima permitida (50 caracteres).\n", MAX_CARACTERES);
  } 
  else{  // Almacena el nuevo libro en la biblioteca y aumenta el contador de libros registrados.
    biblioteca[*numLibros] = nuevoLibro;
    (*numLibros)++;
    printf("Libro registrado exitosamente.\n");
  }
}

/////////////////////////////// FUNCION MOSTRAR DATOS DEL LIBRO //////////////////////////////////////////

void mostrarDatosLibro(Libro* biblioteca, int numLibros, ColaReservas* colasReservas){
  
  // Declaración de variables locales.
  char tituloBuscado[MAX_CARACTERES];
  char autorBuscado[MAX_CARACTERES];
  bool encontrado = false;
  
  // Solicitar al usuario los detalles del libro.  
  printf("Ingrese el titulo del libro: ");
  scanf(" %[^\n]s", tituloBuscado);
  
  printf("Ingrese el autor del libro: ");
  scanf(" %[^\n]s", autorBuscado);
    
  // Bucle para buscar el libro en la biblioteca.
  for (int i = 0; i < numLibros; i++){ 
      // Muestra los detalles del libro si se encuentra.
      if (strcmp(biblioteca[i].titulo, tituloBuscado) == 0 && strcmp(biblioteca[i].autor, autorBuscado) == 0){
          printf("Titulo: %s\n", biblioteca[i].titulo);
          printf("Autor: %s\n", biblioteca[i].autor);
          printf("Genero: %s\n", biblioteca[i].genero);
          printf("ISBN: %s\n", biblioteca[i].ISBN);
          printf("Ubicacion: %s\n", biblioteca[i].ubicacion);
          printf("Estado: %s\n", biblioteca[i].estado);

          // Si el estado es "Reservado", mostrar información adicional.
          if (strcmp(biblioteca[i].estado, "Reservado") == 0) {  
            
            // Imprimir los nombres de estudiantes en la cola de reservas.
            printf("Cola de reservas:\n");
            printf("- %s\n", biblioteca[i].reservas);
            ReservaNode* actual = colasReservas[i].frente;
            while (actual != NULL) {
              printf("- %s\n", actual->nombre_estudiante);
              actual = actual->siguiente;
            }
          }           
          encontrado = true;
          break;
      }
  }
  if (!encontrado) printf("El libro no existe en la biblioteca.\n");    
}
//////////////////////////////////// FUNCION MOSTRAR TODOS LOS LIBROS //////////////////////////////////////////

void mostrarTodosLosLibros(Libro* biblioteca, int numLibros){

  // Mostrar lista de todos los libros.
  printf("Lista de todos los libros en la biblioteca:\n");

  for (int i = 0; i < numLibros; i++){  // Bucle para buscar el libro en la biblioteca.
      printf("Titulo: %s\n", biblioteca[i].titulo);
      printf("Autor: %s\n", biblioteca[i].autor);
      printf("\n");
  }
}

//////////////////////////////// FUNCION INGRESAR Y MOSTRAR INFORMACION //////////////////////////////////////////

void ingresar_y_mostrar_detalles_libro_y_estudiante(char *titulo,char *autor,char *estudiante,char *mensaje){

  // Solicitar al usuario los detalles del libro y nombre del estudiante.  
  printf("Ingrese el titulo del libro: ");
  scanf(" %[^\n]s", titulo);
  
  printf("Ingrese el autor del libro: ");
  scanf(" %[^\n]s", autor);
  
  printf("Ingrese el nombre del estudiante que desea %s", mensaje);
  scanf(" %[^\n]s", estudiante);
}

//////////////////////////////////// FUNCION ENCOLAR RESERVA //////////////////////////////////////////

void encolarReserva(ColaReservas* colaReservas, const char* nombreEstudiante){
  
  // Crear un nuevo nodo de reserva y agregarlo a la cola.
  ReservaNode* nuevoNodo = (ReservaNode*)malloc(sizeof(ReservaNode));
  strcpy(nuevoNodo -> nombre_estudiante, nombreEstudiante);
  nuevoNodo -> siguiente = NULL;

  if (colaReservas -> frente == NULL){
      colaReservas -> frente = nuevoNodo;
      colaReservas -> final = nuevoNodo;
  } 
  else {
      colaReservas -> final -> siguiente = nuevoNodo;
      colaReservas -> final = nuevoNodo;
  }
}

//////////////////////////////////// FUNCION RESERVAR LIBRO //////////////////////////////////////////

void reservarLibro(Libro* biblioteca, int numLibros, ColaReservas* colasReservas){

  // Declaración de variables locales.
  char tituloBuscado[MAX_CARACTERES];
  char autorBuscado[MAX_CARACTERES];
  char nombreEstudiante[MAX_CARACTERES];
  bool encontrado = false;
  char mensaje[] = "reservar: ";

  ingresar_y_mostrar_detalles_libro_y_estudiante(tituloBuscado,autorBuscado,nombreEstudiante, mensaje);

  for (int i = 0; i < numLibros; i++){ // Bucle para buscar el libro en la biblioteca.    
    if (strcmp(biblioteca[i].titulo, tituloBuscado) == 0 && strcmp(biblioteca[i].autor, autorBuscado) == 0){
      
      // Cambiar el estado a "Reservado" y asignar el nombre del estudiante.
      if (strcmp(biblioteca[i].estado, "Disponible") == 0){  
        strcpy(biblioteca[i].estado, "Reservado");
        strcpy(biblioteca[i].reservas, nombreEstudiante);
        encontrado = true;
        printf("El libro ha sido reservado por %s.\n", nombreEstudiante);
      } 
      // Agregar a la cola de reservas si el libro ya está reservado.
      else if (strcmp(biblioteca[i].estado, "Reservado") == 0){
        encolarReserva(&colasReservas[i], nombreEstudiante);
        encontrado = true;
        printf("El libro está reservado. Se ha agregado a la cola de reservas.\n");
      }
      // Si el libro ya esta reservado, se muestra un mensaje.
      else if (strcmp(biblioteca[i].estado, "Prestado") == 0) {
        encontrado = true;  
        encolarReserva(&colasReservas[i], nombreEstudiante);
        printf("El libro está prestado. Se ha agregado a la cola de reservas.\n");
        }
        break;
      }
  }
  if (!encontrado) printf("El libro no existe en la biblioteca.\n");
}

//////////////////////////////////// FUNCION ELIMINAR RESERVAR //////////////////////////////////////////

void eliminarReserva(ColaReservas* colaReservas){

  // Eliminar el nodo de reserva de la cola.
  if (colaReservas -> frente != NULL){
    ReservaNode* nodoEliminado = colaReservas -> frente;
    colaReservas -> frente = colaReservas -> frente -> siguiente;
    free(nodoEliminado);
  }
}

//////////////////////////////////// FUNCION CANCELAR RESERVA LIBRO //////////////////////////////////////////

void cancelarReservaLibro(Libro* biblioteca, int numLibros, ColaReservas* colasReservas){

  // Declaración de variables locales.
  char tituloBuscado[MAX_CARACTERES];
  char autorBuscado[MAX_CARACTERES];
  char nombreEstudiante[MAX_CARACTERES];
  bool encontrado = false;
  char mensaje[] = "cancelar la reserva: ";
  
  ingresar_y_mostrar_detalles_libro_y_estudiante(tituloBuscado,autorBuscado,nombreEstudiante, mensaje);

  // Bucle para buscar y cancelar la reserva del libro en la biblioteca.
  for (int i = 0; i < numLibros; i++){
    if (strcmp(biblioteca[i].titulo, tituloBuscado) == 0 && strcmp(biblioteca[i].autor, autorBuscado) == 0){
      encontrado = true;
      if (strcmp(biblioteca[i].estado, "Reservado") == 0){
        if (strcmp(biblioteca[i].reservas, nombreEstudiante) == 0){
          
          // Cancelar la reserva y asignar el siguiente estudiante si hay en cola.
          strcpy(biblioteca[i].estado, "Disponible");
          strcpy(biblioteca[i].reservas, "");

          // Si hay reservas en cola, se retira al siguiente estudiante.
          if (colasReservas[i].frente != NULL){
            strcpy(biblioteca[i].estado, "Reservado");
            strcpy(biblioteca[i].reservas, colasReservas[i].frente->nombre_estudiante);
            eliminarReserva(&colasReservas[i]);
          }
          printf("La reserva ha sido cancelada.\n");
        } 
        else printf("El estudiante que intenta cancelar la reserva no coincide con el titular de la reserva.\n");
      } 
      else if (strcmp(biblioteca[i].estado, "Disponible") == 0) 
        printf("El libro no está reservado por ningún estudiante.\n");
             
      else if (strcmp(biblioteca[i].estado, "Prestado") == 0) 
        printf("El libro está prestado. No se puede cancelar la reserva en este momento.\n");
            
      break; // Salir del bucle una vez que se encuentra el libro.
    }
  }
  if (!encontrado) printf("El libro no existe en la biblioteca.\n");
}



//////////////////////////////////// FUNCION RETIRAR LIBRO //////////////////////////////////////////

void retirarLibro(Libro* biblioteca, int numLibros, ColaReservas* colasReservas){

  // Declaración de variables locales.
  char tituloBuscado[MAX_CARACTERES];
  char autorBuscado[MAX_CARACTERES];
  char nombreEstudiante[MAX_CARACTERES];
  bool encontrado = false;
  char mensaje[] = "retirar: ";

  ingresar_y_mostrar_detalles_libro_y_estudiante(tituloBuscado,autorBuscado,nombreEstudiante,mensaje);
  
    for (int i = 0; i < numLibros; i++){  // Bucle para buscar el libro en la biblioteca.
      if (strcmp(biblioteca[i].titulo, tituloBuscado) == 0 && strcmp(biblioteca[i].autor, autorBuscado) == 0){  
        if (strcmp(biblioteca[i].estado, "Disponible") == 0){
          encontrado = true;
          
          // Cambia el estado a "Prestado" y asigna al estudiante
          strcpy(biblioteca[i].estado, "Prestado");
          strcpy(biblioteca[i].reservas, nombreEstudiante);
          printf("El libro ha sido prestado a %s.\n", nombreEstudiante);
        } 
        else if (strcmp(biblioteca[i].estado, "Reservado") == 0){
          encontrado = true;
          // Cambia el estado a "Prestado" y elimina la reserva
          if (strcmp(biblioteca[i].reservas, nombreEstudiante) == 0){
            strcpy(biblioteca[i].estado, "Prestado");
            eliminarReserva(&colasReservas[i]);
            printf("El libro ha sido prestado a %s.\n", nombreEstudiante);
          } 
          else printf("El estudiante que intenta retirar el libro no coincide con el titular de la reserva.\n");        
        } 
        else if (strcmp(biblioteca[i].estado, "Prestado") == 0) {
          encontrado = true;
          printf("El libro está prestado. No se puede retirar en este momento.\n"); 
        }
        break;
        }
    }  
  if (!encontrado) printf("El libro no existe en la biblioteca.\n");
}

//////////////////////////////////// FUNCION DEVOLVER LIBRO //////////////////////////////////////////

void devolverLibro(Libro* biblioteca, int numLibros, ColaReservas* colasReservas){

  // Declaración de variables locales.
  char tituloBuscado[MAX_CARACTERES];
  char autorBuscado[MAX_CARACTERES];
  bool encontrado = false;

  // Solicitar al usuario los detalles del libro.  
  printf("Ingrese el titulo del libro: ");
  scanf(" %[^\n]s", tituloBuscado);
  
  printf("Ingrese el autor del libro: ");
  scanf(" %[^\n]s", autorBuscado);

  for (int i = 0; i < numLibros; i++){  // Bucle para buscar el libro en la biblioteca.
    if (strcmp(biblioteca[i].titulo, tituloBuscado) == 0 && strcmp(biblioteca[i].autor, autorBuscado) == 0){
      encontrado = true;
      if (strcmp(biblioteca[i].estado, "Prestado") == 0){
        
        // Hay una reserva en cola, se cambia el estado a "Reservado" y se asigna al siguiente estudiante.
        if (colasReservas[i].frente != NULL){  
          strcpy(biblioteca[i].estado, "Reservado");
          strcpy(biblioteca[i].reservas, colasReservas[i].frente->nombre_estudiante);
          eliminarReserva(&colasReservas[i]);
        } 
        // Cambia el estado a "Disponible" si no hay reservas pendientes.
        else{
          strcpy(biblioteca[i].estado, "Disponible");
          strcpy(biblioteca[i].reservas, "");
        }
        encontrado = true;
        printf("El libro ha sido devuelto.\n");
      } 
      else if (strcmp(biblioteca[i].estado, "Reservado") == 0) 
        printf("El libro está reservado. No se puede devolver en este momento.\n");
             
      else if (strcmp(biblioteca[i].estado, "Disponible") == 0){
        encontrado = true;
        printf("El libro ya está disponible.\n");  
      }
      break;
    }
  }
  if (!encontrado) printf("El libro no existe en la biblioteca.\n");
}

//////////////////////////////////// FUNCION MOSTRAR LIBROS PRESTADOS //////////////////////////////////////////

void mostrarLibrosPrestados(Libro* biblioteca, int numLibros){

  // Imprime la lista de libros prestados
  printf("Lista de libros prestados:\n");
  for (int i = 0; i < numLibros; i++){  // Bucle para buscar el libro en la biblioteca.
    
    // Verifica si el estado del libro es "Prestado", imprimiendo los detalles correspondientes.
    if (strcmp(biblioteca[i].estado, "Prestado") == 0){
      printf("Titulo: %s\n", biblioteca[i].titulo);
      printf("Autor: %s\n", biblioteca[i].autor);
      printf("Estudiante: %s\n", biblioteca[i].reservas);
      printf("\n");
    }
  }
}

//////////////////////////////////// FUNCION IMPORTAR LIBROS CSV //////////////////////////////////////////

void importarLibrosCSV(Libro* biblioteca, int* numLibros, ColaReservas* colasReservas, const char* nombreArchivo){

  // Abre el archivo CSV y procesa sus datos para importarlos a la biblioteca.
  FILE* archivo = fopen(nombreArchivo, "r");
  if (archivo == NULL){
    printf("No se pudo abrir el archivo %s.\n", nombreArchivo);
    return;
  }
  // Divide cada línea en tokens utilizando "," como delimitador y almacena los valores en la estructura Libro. 
  char linea[1024];
  while (fgets(linea, sizeof(linea), archivo)){
    char* token = strtok(linea, ",");
    if (token != NULL) strcpy(biblioteca[*numLibros].titulo, token);
    token = strtok(NULL, ",");
        
    if (token != NULL) strcpy(biblioteca[*numLibros].autor, token);
    token = strtok(NULL, ",");

    if (token != NULL) strcpy(biblioteca[*numLibros].genero, token);
    token = strtok(NULL, ",");

    if (token != NULL) strcpy(biblioteca[*numLibros].ISBN, token);
    token = strtok(NULL, ",");
        
    if (token != NULL) strcpy(biblioteca[*numLibros].ubicacion, token);
    token = strtok(NULL, ",");
        
    if (token != NULL) strcpy(biblioteca[*numLibros].estado, token);
    token = strtok(NULL, ",");
        
    if (token != NULL) strcpy(biblioteca[*numLibros].reservas, token);

    // Si el estado es "Reservado", se agrega la reserva a la cola correspondiente
    if (strcmp(biblioteca[*numLibros].estado, "Reservado") == 0 && strlen(biblioteca[*numLibros].reservas) > 0)
      encolarReserva(&colasReservas[*numLibros], biblioteca[*numLibros].reservas);
      (*numLibros)++; // Incrementa el contador numLibros a medida que procesa los libros.
    }

    fclose(archivo);
    printf("Se han importado los libros desde el archivo %s.\n", nombreArchivo);
}

//////////////////////////////////// FUNCION EXPORTAR LIBROS A CSV //////////////////////////////////////////

void exportarLibrosCSV(Libro* biblioteca, int numLibros, ColaReservas* colasReservas, const char* nombreArchivo){
  
  // Abre un archivo CSV en modo escritura y recorre el arreglo de libros
  FILE* archivo = fopen(nombreArchivo, "w");
  if (archivo == NULL){
    printf("No se pudo crear el archivo %s.\n", nombreArchivo);
    return;
  }

  for (int i = 0; i < numLibros; i++){ // Bucle para buscar el libro en la biblioteca.
    fprintf(archivo, "%s,%s,%s,%s,%s,%s,%s\n", biblioteca[i].titulo, biblioteca[i].autor, biblioteca[i].genero,
            biblioteca[i].ISBN, biblioteca[i].ubicacion, biblioteca[i].estado, biblioteca[i].reservas);

    // Si hay reservas en cola, se exportan.
    if (strcmp(biblioteca[i].estado, "Reservado") == 0 && colasReservas[i].frente != NULL){
      ReservaNode* nodo = colasReservas[i].frente;
      while (nodo != NULL){
        fprintf(archivo, ",,,,%s,Reservado,%s\n", biblioteca[i].ubicacion, nodo->nombre_estudiante);
        nodo = nodo->siguiente;
      }
    }
  }
  fclose(archivo);
  printf("Se han exportado los libros al archivo %s.\n", nombreArchivo);
}