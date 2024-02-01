# Función de encriptacion

Una empresa requiere un programa que encripte los datos de entrada que se reciben en un archivo llamado ```datos.txt``` transformando cada caracter del mensaje según la siguiente tabla:

| Original | Encriptado |
|----------|------------|
|a| z|
|b| y|
|c| x|
|d| w|
|e| v|
|f| u|
|g| t|
|h| s|
|i| r|
|j| q|
|k| p|
|l| o|
|m| n|
|n| m|
|o| l|
|p| k|
|q| j|
|r| i|
|s| h|
|t| g|
|u| f|
|v| e|
|w| d|
|x| c|
|y| b|
|z| a|

En la primera columna de la tabla se encuentra el caracter que lee del archivo y en la segunda fila se encuentra la conversion que se debe realizar para la respectiva letra. Por ejemplo:

Mensaje original: ```Hola como se encuentran```

Mensaje encriptado: ```Sloz xlnl hv vmxfvmgizm```

A partir del enunciado, se pide:

1. Leer el archivo ```datos.txt``` con el mensaje original.
2. Crear la funcion para encriptar y desencriptar el mensaje usando apuntadores a funciones.
3. Guardar el mensaje encriptado en un archivo llamado ```encriptado.txt```. con el mensaje generado en el punto anterior.

# Lectura ded estructuras

Suponga que los resultados de presentacion de examenes estan grabadas en un archivo binario con tipo llamado ```notas.dat``` que contiene cada persona: numero de identificacion, nombre de la persona, tipo de examen (INICIAL o SUPLETORIO) y la nota obtenida con un decimal, como se muestra en el siguiente ejemplo:

| Identificacion | Nombre | Tipo de examen | Nota |
|----------------|--------|----------------|------|
1111 | Juan Perez | INICIAL | 4.5
2222 | Maria Lopez | SUPLETORIO | 3.5
3333 | Pedro Gomez | INICIAL | 2.5

Desarrolle una funcion que cree dos archivos de texto llamados ```inicial.txt``` y ```supletorio.txt```. Cada tipo de archivo debe contener: El tipo de examen, el nombre y la nota obtenida por todos los estudiantes, el numero de examenes presentados, y la nota promedio de los examenes. Un ejemplo de este archivo es:

```bash
INICIAL
Juan Perez 4.5
Pedro Gomez 2.5
Numero de examenes presentados: 2
Nota promedio: 3.5
```

NOTA: los arreglos deben generarse con memoria dinamica y deben recorreerse con punteros. (sin subindices)