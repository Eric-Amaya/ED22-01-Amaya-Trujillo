![UCN](images/60x60-ucn-negro.png)


# Informe Técnico 
## Curso: Estructura de datos
### Detección de personas en secuencias de imágenes o video
![ImagenContador](images/ConteoPersonas.jpg)

**Alumnos:**

* Eric Amaya (Coordinador)
* Bastián Trujillo (Planificador)

## Resumen 

>Para la realización del sistema de vigilancia se crearon tres tipos de clases, “Personas” encargada de contener los atributos de la ubicación de cada persona en la zona escaneada, “Nodos” encargada de crear nodos y también trae y almacena la información de “Personas” en cada uno de los nodos creados, y “Detector” encargada de realizar los procedimientos para detectar a las personas. Añadido a lo anterior, se generó la lista “ListaPersonas” la cual va almacenando los datos solicitados por la empresa.
>
>La creación de esto permitirá en esta primera entrega detectar personas que pasan por la imagen de video de vigilancia y dibujar un cuadro verde alrededor de ella, en su centro un puntero rojo, el cual también proporciona la habilidad de contar cuantas personas entran por la zona delimitada y cuantas a su vez salen, lo que posibilita lograr calcular la velocidad con la que entran y salen estas mismas, además, permite contar cuantas personas diferentes han entrado por aquella zona y cuantas han salido.


## 1. Introducción

Hoy en día se está en una era donde los avances tecnológicos progresan a pasos agigantados y como profesionales y sobre todo como ingenieros de la información y computación es relevante mantenerse actualizado en cuanto a las herramientas que ayudan a agilizar las tareas de las personas.
A pesar de que C++, lenguaje de programación compilado, multiparadigma, principalmente imperativo y orientado a objetos y que evolucionó del lenguaje informático “C”, no es un lenguaje nuevo, hoy en día es sigue utilizándose para realizar programación estructurada de alto nivel y rendimiento, tales como, sistemas operativos, videojuegos, bases de datos, entre otros.
Es por ello que a lo largo del presente trabajo se mostrará la realización de un software que permita a la empresa ACME acceder un sistema de vigilancia que posibilite contar personas en una zona determinada de un edificio de su organización.  Los objetivos del mismo son lograr contar cuantas personas entran y salen dentro de una zona previamente determinada, contar cuantas personas distintas han entrado o salido de la zona y listar las identidades que más han aparecido en el video, tanto en la entrada como en la salida.
Para cumplir con los objetivos anteriormente mencionados se codificará con lenguaje C++ a través del programa Visual Studio Code, editor de código fuente desarrollado por Microsoft. En este se aplicará principalmente lo que son las listas enlazadas, conjunto de nodos, los cuales almacenan 2 tipos de información: dato que contiene y un puntero al siguiente nodo en la lista, terminando con un nodo con el valor NULL.
Finalmente, el logro del sistema de vigilancia para la empresa ACME, además de entregarle un sistema moderno y adecuado a sus necesidades, les facilitará la toma de sus datos para el análisis de ellos.


### 1.1 Descripción del problema

La empresa ACME dado a sus pocos avances tecnológicos presenta una dificultad para llevar una correcta cuenta de las personas que entraban y salían de una zona predeterminada, lo cual a llevado además a presentar un problema con el análisis de las personas tales como identificar según las características físicas, frecuencia de cada persona, entre otros. Por lo cual, la empresa ha decidido crear un sistema de vigilancia para tener un conteo de personas, esto lo realizará externalizando esta problemática mediante la contratación de los alumnos de Ingeniería Civil en Computación e Informática de la Universidad Católica del Norte.

### 1.2 Objetivos 

**Objetivo General**

Desarrollar un sistema que identifique y contabilice la cantidad de personas que entren y salgan dentro de una zona previamente determinada.

**Objetivos específicos**

1. Interpretar los resultados obtenidos entre las dos muestras (entrada y salida de la zona).
2. Implementar el lenguaje c++ para elaborar el sistema contador de personas. 
3. Enumerar el total de personas que entran y salen de la zona.
4. Organizar los datos obtenidos dentro de listas.

### 1.3 Solución propuesta

El equipo de trabajo se propone utilizar el lenguaje c++ a través de la IDE Visual Studio Code el cual compilará y ejecutará un código para solucionar la problemática de la empresa ACME, dicho programa detectará a las personas, las almacenarán los datos recopilados y pedidos por le empresa.

## 2. Materiales y métodos

Para el desarrollo del presente trabajo se realizará una planificación a través de un cronograma y el registro de una bitácora para así lograr un avance más ordenado y estructurado.
Este proyecto se elaborará mediante codificación en lenguaje c++, reforzado con la librería OpenCV, utilizando la IDE Visual Studio Code.
En el Anexo C se puede apreciar con detalle el cronograma que se realizó, en el cual se consideró como primera tarea la formación del equipo de trabajo, avanzando hasta la fecha de entrega final. En el anexo C.1 se detalló exactamente la fecha de la tarea, con los dias que tuvieron disponibles para el desarrollo del proyecto y en el anexo C.2 se detalla en forma de tabla el avance logrado por el equipo de trabajo.

### 2.1 Instalación

Como anteriormente se mencionó, se descargó la IDE Visual Studio Code, el cual a través de la librería OpenCV y el apoyo de CMake ejecutará el código que contendrá el sistema de vigilancia.
La librería OpenCV fue descargada desde el explorador y enlazada al sistema del computador mediante la configuración del path en las variables de entorno, el cual buscará directamente los programas a utilizar.
Para el desarrollo del código, se utilizará la IDE Visual Studio Code, la cual se descarga de forma gratuita desde el explorador, nosotros como equipo trabajamos con la extensión de C/C++ extension pack, el cual puede ser añadido directamente desde Visual Studio Code.
Como modo de apoyo se ocupará CMake que consiste en una herramienta de autotools, dicho de otra forma, es una herramienta de generación o automatización de código.

### 2.2 Diseño 

![DiagramaClases](images/Diagrama_de_clases.png)

Se crearán las clases Persona, Nodo y detector, por parte de listas, se generará la ListaPersonas la cual irá almacenando los datos solicitados por la empresa ACME.
Por parte de la clase persona contendrá los atributos de su ubicación en la zona al ser escaneada. por otra parte, la clase Nodo contiene los valores de persona y su id. Finalmente, la clase detector la cual se encargará de realizar todo el procedimiento de detectar a la persona.


### 2.3 Implementación

Explicar brevemente algunos aspectos de implementación: Por ejemplo, detector de caras utilizado. Se pueden realizar pequeñas reseñas al código para indicar elementos importantes en el trabajo.

Por ejemplo, 

#### Detector de caras

El detector de caras utilizado fue xxx. Para utilizarlo se debe.... El código para detectar una cara en una imagen se muestra a continuación:

```c++
 1. faceCascadePath = "./haarcascade_frontalface_default.xml";
 2. faceCascade.load( faceCascadePath )
 3. std::vector<Rect> faces;
 4. faceCascade.detectMultiScale(frameGray, faces);

 5. for ( size_t i = 0; i < faces.size(); i++ )
 6. {
 7.  int x1 = faces[i].x;
 8.  int y1 = faces[i].y;
 9.  int x2 = faces[i].x + faces[i].width;
10.  int y2 = faces[i].y + faces[i].height;
11. }
```
La primera linea carga el archivo de entrenamiento... etc

## 3. Resultados obtenidos

## 4. Conclusiones

# Anexos

## Anexo A: Instalación librerías OpenCV
![OpenCV](images/OpenCV.png)

Se descargó la librería OpenCV directamente del navegador en el link que se puede apreciar en la imagen del anexo.

## Anexo B: Instalación de IDE y configuración librerías OpenCV


## Anexo C: Cronograma de trabajo
## Anexo C.1: ![Crono1](images/Cronograma1.png)
## Anexo C.2: ![Crono2](images/Cronograma2.png)

# Referecia
Ronny Yabar Aizcorbe. Listas enlazadas – Clase Lista,Nodo en c++. https://ronnyml.com/2009/07/04/listas-enlazadas-clase-lista-en-c/#:~:text=Una%20lista%20enlazada%20tiene%20un,siguiente%20nodo%20el%20valor%20NULL.

Frankier Flores. Qué es Visual Studio Code y qué ventajas ofrece. https://openwebinars.net/blog/que-es-visual-studio-code-y-que-ventajas-ofrece/

Escuela de Ingenierías Industriales. El lenguaje c++. https://www2.eii.uva.es/fund_inf/cpp/temas/1_introduccion/introduccion.html#:~:text=lenguaje%20C%2B%2B-,El%20lenguaje%20C%2B%2B,más%20adelante%20en%20el%20curso.

S.A. Qué es c++. https://i.workana.com/glosario/que-es-c/

Adrian Rosebrock. OpenCV People Counter. https://pyimagesearch.com/2018/08/13/opencv-people-counter/.

