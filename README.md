# Integrantes
Martina Miranda, 21.872.747-6, martina.miranda@alumnos.ucn.cl, Paralelo C1.

Nicolas Galleguillos, , 21.764.662-6 nicolas.galleguillos03@alumnos.ucn.cl, Paralelo C1.

# Biblioteca digital

Este proyecto consiste en un simulador de biblioteca digital que permite realizar diversas acciones, como la gestión de materiales bibliográficos y usuarios, la búsqueda de libros y revistas, y la administración de préstamos y devoluciones.

## Funcionalidades

### Agregar Material a la Biblioteca
Los usuarios pueden añadir libros y revistas con atributos específicos como título, autor, ISBN, entre otros.

### Mostrar Información de los Materiales
Se puede generar un listado detallado de todos los materiales presentes en la biblioteca.

### Buscar Material
Los usuarios pueden buscar materiales bibliográficos por título o autor.

### Préstamo y Devolución de Material
Los usuarios pueden solicitar el préstamo de un máximo de cinco materiales a la vez, con la opción de devolverlos cuando lo deseen. El estado de los materiales se actualiza automáticamente tras cada operación.

### Gestión de Usuarios
El sistema permite crear, buscar y eliminar usuarios. Cada usuario tiene un registro de los materiales que ha solicitado en préstamo.

## Persistencia de Datos

El sistema permite guardar y cargar la información de la biblioteca y los usuarios desde archivos de texto utilizando la biblioteca `fstream` para garantizar la persistencia de datos.

## Estructura del Código

- **Lenguaje de Programación:** C++
- **Compilador:** g++
- **Estructura del Código:**
    - El código está organizado en múltiples archivos `.cpp` y `.h` para mantener una estructura modular y ordenada.
    - Uso de punteros y arrays estáticos para la gestión de la memoria dinámica.

## Ejecución del Programa

Para compilar y ejecutar el programa, utiliza los siguientes comandos:

g++ -o Taller1 main.cpp Sistema.cpp Libro.cpp Revista.cpp Usuario.cpp MaterialBibliografico.cpp

### Ejemplo de Objetos Creados en el `main`

Sistema* sistema = new Sistema(); sistema->MostrarMenu();

El objeto `sistema` de tipo `sistema` gestiona las interacciones con el usuario a través de un menú en la consola.
