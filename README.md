TAREA_1_ESTRUCTURA_DE_DATOS
Cristopher Dauros, Javier Díaz

INTRODUCCIÓN
La presente tarea consiste en una aplicación de biblioteca que ayude al usuario gestionar los libros almacenados en ella, la cual tiene como funcionalidades :

* Registrar Libros.
* Mostrar Datos de un Libros.
* Mostrar Todos los Libros.

También tiene un sistema de :

* Reservas de Libros.
* Cancelación de Reservas de Libros.
* Retiro de Libros.
* Devolución de Libros.
* Mostrar los Libros Prestados
* Importar Archivos CSV.
* Exportar Archivos CSV.

PROBLEMA CONOCIDO :
* Al momento de que el usuario no sea el primero en la cola de reservas, no se puede eliminar la reserva de este.Tiene que pasar los otros usuarios antes que él, para poder cancelar.

A MEJORAR :
* Corregir el problema de las cancelaciones de reservas a los que están después del primer usuario, para así ellos no tener que esperar a que este cancele la reserva.
* Mostrar inmediatamente cuando un campo posee más de 50 caracteres, en vez de esperar a que se asignen todos los campos.


CONTRIBUCIONES :

JAVIER DÍAZ :
* Estructura del programa.
* Desarrollo del código.
* Redacción y diseño del README.
* Comentarios y documentación.
* Auto-Evaluación: 3(Aporte Excelente).

CRISTOPHER DAUROS :
* Apoyo en desarrollo de código
* Revisión y corrección de errores de sintaxis y compilación del código 
* Redacción del README.
* Comentarios y documentación.
* Auto-Evaluación: 3(Aporte Excelente).



CÓMO COMPILAR Y EJECUTAR EL PROGRAMA

Primero debemos clonar el repositorio en un compilador e intérprete de preferencia. Una vez clonado el repositorio completo se debe correr el programa principal para que se ejecute la aplicación, la cuál debiese desplegar inicialmente el siguiente menú:

*** Menu de la Biblioteca ***
1. Registrar libro
2. Mostrar datos de libro
3. Mostrar todos los libros
4. Reservar libro
5. Cancelar reserva de libro
6. Retirar libro
7. Devolver libro
8. Mostrar libros prestados
9. Importar libros desde un archivo CSV
10. Exportar libros a un archivo CSV
0. Salir
Seleccione una opcion:

Una vez se haya desplegado el menú de la aplicación, se debe ingresar el índice de cualquiera de las opciones mostradas. A continuación se muestra una breve explicación sobre las funcionalidades de cada opción:

1) Registrar libro (título, autor, género,ISBN, ubicación): La usuaria ingresa los datos del libro y la aplicación los almacena. Debe validarse que ningún string tenga un largo mayor a 50 caracteres.

2) Mostrar datos de libro (título, autor): La usuaria ingresa el título y autor de un libro y la aplicación muestra sus datos y las reservas si las hay. Si el libro no existe, se debe mostrar un aviso.

3) Mostrar todos los libros (): La aplicación muestra por pantalla los títulos y autores de todos los libros registrados.

4) Reservar libro (título, autor, nombre_estudiante): La usuaria ingresa el título y autor del libro y el nombre del estudiante que quiere reservarlo. La aplicación agrega la reserva a la cola de reservas del libro. Si el libro no existe, se debe mostrar un aviso.

5) Cancelar reserva de libro (título, autor, nombre_estudiante): La usuaria ingresa el título y autor del libro y el nombre del estudiante que quiere cancelar la reserva. La aplicación elimina la reserva de la cola de reservas del libro. Si el libro o la reserva no existen, se debe mostrar un aviso.

6) Retirar libro (título, autor, nombre_estudiante): Si el libro está "Disponible" o si el estudiante es el primero en la cola de reservas para un libro "Reservado", entonces el libro puede ser retirado y su estado cambia a "Prestado". Si el libro ya está "Prestado" o el estudiante no tiene prioridad, se muestra un aviso. Un libro prestado lo tiene el primer estudiante de la cola de reservas.

7) Devolver libro (título, autor): Al devolver un libro, si hay una cola de reservas, el estado cambia a "Reservado". Si no hay reservas, el estado cambia a "Disponible".

8) Mostrar libros prestados (): La aplicación muestra por pantalla los títulos y autores de todos los libros que están prestados y el estudiante al que se le prestó.

9) Importar libros desde un archivo CSV (nombre_archivo): La usuaria ingresa el nombre del archivo y la aplicación carga todos los libros y sus datos, incluyendo las colas de reservas.

10) Exportar libros a un archivo CSV (nombre_archivo): La aplicación exporta todos los libros, sus datos y las colas de reservas a un archivo csv indicado por la usuaria.
Una vez concluida la utilización de la aplicación se debe ingresar la opción “0” para cerrarla. Al hacer esto dejará de existir el ejecutable creado al correr el programa por lo que toda la información almacenada en la aplicación será eliminada de la memoria.
