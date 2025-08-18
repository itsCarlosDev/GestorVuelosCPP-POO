**GESTOR DE VUELOS**

**Descripción: **
Se creará una aplicación usando CLI, esta gestionará diferentes vuelos que serán programados.
El código funcionará usando OOP de esta manera poder tener manejo con los diferentes objetos.

**Instalación: **
Para poder abrir este archivo es necesario tener instalado MSYS2 -> https://code.visualstudio.com/docs/cpp/config-mingw
Video: https://youtu.be/oC69vlWofJQ

**FAQ: **
- ¿Porqué se ha desarrollado este proyecto? 
Trabajo desarrollado para practica universitaria.

**Posibles mejoras: **
    - Creacion de la clase CCadena por mi (Ahora esta en uso una version de la universidad UAB)

**Actualizaciónes**

# **v0.1 -> Primera subida, cosas a tener en cuenta**
    - Constructor y constructor por defecto, estos tienen la diferencia de cuando el constructor por defecto es llamado, aplica valores por
    defecto de 0.

# **v0.2 -> Segunda subida, cosas a tener en cuenta**
    - Creacion de una funcion con AI, sirve para esperar unos segundos antes de decirle al usuario que se han aplicado los cambios
    - Se ha añadido plugin TODO a VSC (Visual Studio Code), de esta manera poder destacar aquellas tareas que faltan.
    - Se ha añadido CPP y Header de CCadena de los profesores de la UAB, de esta manera poder conseguir utilizar una cadena de caracteres.
    - (UI en consola) Creacion de un menu en el main.exe para poder llamar a las funciones, 
    
# **v0.3 -> Tercera subida, cosas a tener en cuenta**
    - Creacion de la clase CGestorVuelos, esto es para controlar el array desde el gestor de vuelos y no desde los vuelos como tal
    - Se ha eliminado la funcion creada por inteligencia artificial para realizar una espera en el login de crearVuelo ahora se utiliza en el main.
    - Implementación de funciones: creacionVuelos, mostrarVuelos, eliminarVuelos, modificarVuelos

# **v0.4 -> Cuarta subida, cosas a tener en cuenta**
    - Mejora del README
    - Arreglo de los setters de CVuelo
    - Descubiertos varios bugs con el array a la hora de ordenarPorID, ordenarporPrecio, ordenarPorDuracion arreglado
    - Mas bugs a la hora de eliminar posiciones del array arreglado.
    - Funciones de organizar con array estatico.