![UCN](images/60x60-ucn-negro.png)


# Informe Técnico 
## Curso: Estructura de datos
### Detección y reidentificación de caras en secuencias de imágenes o video

**Alumnos:**

* Eric Amaya (Coordinador)
* Bastián Trujillo (Planificador)

## Resumen 

> Agregar un resumen que describa el trabajo realizado y sus resultados. (Entre 150 y 180 palabras)
> Más cosas...
> El resumen indicarlo como cita con el comando `>`

## 1. Introducción

La primera función de un reporte técnico es plasmar la información necesaria para que otras personas puedan reproducir el sistema propuesto o puedan entender su fucnionamiento . Para cumplir anterior se debe diferenciar claramente entre los artefactos de diseño e implementación. En el caso de un desarrollo tecnológico los algoritmos son importantes como componente de diseño y los programas generalmente son irrelevantes y deben resumidos o agregados en anexos en el documento. Los programas no son importantes en el documento, salvo si se quiere explicar conceptos expecíficos del lenguaje o del algoritmo implementado.

La redacción debe ser formal y de modo impersonal. No se debe utlizar primera persona del singular o plural. Se debe evitar el uso de cualquier calificativo sustituyéndolo siempre utilizando datos concretos y rastreables en documentos o publicaciones a través de referencias bibliográficas. Por ejemplo, no calificar algo como: "muy importante", "sustancial", "muy usadoo" o "mucho mejor".

Las comparaciones deben concretarse con hechos y datos, sin frases ambiguas o términos generales. Por ejemplo, nunca se debe redactar frases como "el método es mejor que el método B". Lo correcto es decir, el error promedio de el método A es de 5 %, correspondiendo a la mitad del error de 10% obtenido utilizando el método B". El tiempo verbal es usualmente presente. No se debe perder de vista que se está explicando ”como hacer algo”, en vez de ”qué se hizo”. Todo aspecto circunstancial es irrelevante para el documento. Por ejemplo, si se ha desarrollado en el laboratorio X, o en el curso Y, con el profesor Z, etc.

### 1.1 Descripción del problema

La empresa ACME dado a sus pocos avances tecnologicos presenta una dificultad para llevar una correcta cuenta de las personas que entraban y salían de una zona predeterminada, lo cual a llevado además a presentar un problema con el analisis de las personas tales como identificar según las caracteristicas fisicas, frecuencia de cada persona, entre otros. Por lo cual, la empresa ha decidido crear un sistema de vigilancia para tener un conteo de personas, esto lo realizará externalizando esta problematica mediante la contratación de los alumnos de Ingeniería Civil en Computación e Informática de la Universidad Católica del Norte.

### 1.2 Objetivos 

**Objetivo General**

Desarrollar un sistema que identifique y contabilice la cantidad de personas que entren y salgan dentro de una zona previamente determinada

**Objetivos específicos**

1. Interpretar los resultados obtenidos entre las dos muestras (entrada y salida de la zona).
2. Implementar el lenguaje c++ para elaborar el sistema contador de personas. 
3. Enumerar el total de personas que entran y salen de la zona.
4. Organizar los datos obtenidos dentro de listas.

### 1.3 Solución propuesta

Esbozo de la solución propuesta, se espera que esta vaya evolucionando a medida que se avanza en el proyecto.

## 2. Materiales y métodos

Para el desarrollo del presente trabajo se realizará una planificación a través de un cronograma y el registro de una bitácora para así lograr un avance más ordenado y estructurado.
Este proyecto se elaborará mediante codificación en lenguaje c++, reforzado con la libreria OpenCV, utilizando la IDE Visual Studio Code.

### 2.1 Instalación

Describir brevemente las librerías utilizadas para la instalación y programas utilizados para la ejecución del código. (Agregar una sección de anexo para describir como fueron instaladas las librerías de OpenCV y la IDE utilzada para el trabajo)

### 2.2 Diseño 

Explicar los componentes (módulos o clases) utilizados para resolver el problema. Indicar arquitectura propuesta, diagrama de clases u otro artefacto que estime conveniente para explicar el diseño de su implimentación.

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

## Anexo B: Instalación de IDE y configuración librerías OpenCV

# Referecia

Adrian Rosebrock. OpenCV People Counter. https://pyimagesearch.com/2018/08/13/opencv-people-counter/.

