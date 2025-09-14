# GESTOR DE VUELOS
## Gestor OOP + Grafos

Se creará una aplicación usando CLI, esta gestionará diferentes vuelos que serán programados. El código funcionará usando OOP de esta manera poder tener manejo con los diferentes objetos. Tambien se utilizaran grafos, herramienta que se utiliza en las practicas de la UAB.

* Crear diferentes gestores para maneajar arrays reservados
* Crear un gestor de vuelos con un template de vector
* Crear una clase para utilizar grafos

# Mètodo de Instalación:

1 -> Para Windows
Para poder abrir este archivo es necesario tener instalado MSYS2 -> https://code.visualstudio.com/docs/cpp/config-mingw
Video: https://youtu.be/oC69vlWofJQ

2 -> Para MACOS
make distclean  
find . -name "*.o" -delete
find . -name "*.d" -delete
make -f Makefile_MacOS 

3 -> Clonar el proyecto

# FAQ:
- ¿Porqué se ha desarrollado este proyecto? 
Trabajo desarrollado para practica universitaria.

# Posibles mejoras:
    - Creacion de la clase CCadena por mi (Ahora esta en uso una version de la universidad UAB)
    - Verificacion antes de pedir los datos como puede ser de Pilotos (comprobacion anterior para ver si caben en el array reservado)
    - Crear las excepciones de datos si a un int se le coloca una letra...
    - DNI con letra al final
    - Al eliminar un piloto el vuelo se cancela

# Cosas muy importantes

    - Los array reservados siempre hay que inicializarlos, sino el delete da segmentation fault.
    - He creado en CPiloto y CPasajero CPersona en la parte privada, haciendo que no haya herencia y sea composicion
    esto se puede hacer porque tengo 2 gestores tanto para pilotos como para pasajeros, sino se deberia de usar herencia
    - - CPersona piloto; // Composicion, de esta manera CPiloto no es un CPersona ** No hay polimorfismo **

# Actualizaciónes:

**v0.1 -> Primera subida, cosas a tener en cuenta**
    - Constructor y constructor por defecto, estos tienen la diferencia de cuando el constructor por defecto es llamado, aplica valores por
    defecto de 0.

**v0.2 -> Segunda subida, cosas a tener en cuenta**
    - Creacion de una funcion con AI, sirve para esperar unos segundos antes de decirle al usuario que se han aplicado los cambios
    - Se ha añadido plugin TODO a VSC (Visual Studio Code), de esta manera poder destacar aquellas tareas que faltan.
    - Se ha añadido CPP y Header de CCadena de los profesores de la UAB, de esta manera poder conseguir utilizar una cadena de caracteres.
    - (UI en consola) Creacion de un menu en el main.exe para poder llamar a las funciones, 
    
**v0.3 -> Tercera subida, cosas a tener en cuenta**
    - Creacion de la clase CGestorVuelos, esto es para controlar el array desde el gestor de vuelos y no desde los vuelos como tal
    - Se ha eliminado la funcion creada por inteligencia artificial para realizar una espera en el login de crearVuelo ahora se utiliza en el main.
    - Implementación de funciones: creacionVuelos, mostrarVuelos, eliminarVuelos, modificarVuelos

**v0.4 -> Cuarta subida, cosas a tener en cuenta**
    - Mejora del README
    - Arreglo de los setters de CVuelo
    - Descubiertos varios bugs con el array a la hora de ordenarPorID, ordenarporPrecio, ordenarPorDuracion arreglado
    - Mas bugs a la hora de eliminar posiciones del array arreglado.
    - Funciones de organizar con array estatico.

**v0.5 -> Cuarta subida, cosas a tener en cuenta**
    - Se ha cambiado las 3 funciones parecidas de organizar por un template, llamando a "gestor.ordenar(&CVuelo::getId);" se 
    recoge la direccion de la funcion miembro de CVuelo que en este caso es getId() y desde la clase CGestorVuelos gracias al
    puntero "m_vuelo[i].*getter" que apunta a la funcion miebro.
    - Futura creación de arrays estaticos para pasajeros que se asignaran a aviones y estos aviones se asignaran a Vuelos
    - Futura adaptacion para que los aviones tengan un array dinamico que este se adapte a la cantidad maxima de aviones que caben en
    el aeropuerto
    - Al declarar un avion se indicaran el numero maximo de pasajeros que caben dentro del avion (esto servira para practicar arrays reservados (se les llama array dinamicos en la UAB))
    - La cantidad de vuelos seran un array dinamico, de esta manera se conseguira poder muchos vuelos y el array se adaptara gracias a 
    - El numero de gente en plantilla se indica antes de empezar en el menu, se supone ya de por si que la persona que tiene acceso a este menu es un administrador.

**v0.5.1 -> Quinta subida, cosas a tener en cuenta**
    - Mejoras varias de errores y warnings por consola

**v0.6 -> Sexta subida, cosas a tener en cuenta**
    - Mejora de makefile y la distribución de los archivos
    - Uso de archivos para CPiloto con <fstream>
    - Deshabiltar el uso del array reservado dinamico (próximamente reactivación)
    - Cambios por AI del makefile (necesarios para mejorar la distribucion de los archivos)
    - Ahora los pilotos se recogen de un txt