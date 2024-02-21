import random

def seleccionar_palabra(palabras):
    """Selecciona una palabra al azar de una lista de palabras."""
    return random.choice(palabras)

def mostrar_tablero(intentos, letras_correctas, palabra):
    """Muestra el estado actual del juego."""
    print(fallos[intentos])
    resultado = [letra if letra in letras_correctas else "_" for letra in palabra]
    print("    " + " ".join(resultado))

def solicitar_letra(letras_todas):
    """Solicita al usuario ingresar una letra, asegurándose de que sea válida."""
    while True:
        letra = input("Dime una letra: ").upper()
        if len(letra) != 1:
            print("Por favor, introduce una sola letra.")
        elif letra in letras_todas:
            print("Esa letra ya la has dicho.")
        elif not letra.isalpha():
            print("Introduce una letra válida.")
        else:
            return letra

def juego_del_ahorcado(palabras, fallos):
    """Ejecuta el juego del ahorcado."""
    palabra = seleccionar_palabra(palabras)
    letras_correctas = ""
    letras_todas = ""
    intentos = 0

    while intentos < len(fallos) - 1:
        mostrar_tablero(intentos, letras_correctas, palabra)
        letra = solicitar_letra(letras_todas)
        letras_todas += letra

        if letra in palabra:
            letras_correctas += letra
            if all(letra in letras_correctas for letra in palabra):
                mostrar_tablero(intentos, letras_correctas, palabra)
                print("¡Has ganado! La palabra era:", palabra)
                break
        else:
            intentos += 1

        if intentos == len(fallos) - 1:
            mostrar_tablero(intentos, letras_correctas, palabra)
            print("Has perdido. La palabra era:", palabra)
            break

if __name__ == "__main__":
    palabras = ["SEQUENTIALACCESS", "BUFFER", "FILE"]
    fallos = [
        '''
          !===N
              N
              N
              N
        =======
        ''', 
        '''
          !===N
          0   N
              N
              N
        =======
        ''',
        '''
          !===N
         _0   N
              N
              N
        =======
        ''',
        '''
          !===N
         _0_  N
              N
              N
        =======
        ''',
        '''
          !===N
         _0_  N
          |   N
              N
        =======
        ''',
        '''
          !===N
         _0_  N
          |   N
         /    N
        =======
        ''',
        '''
          !===N
         _0_  N
          |   N
         / \  N
        =======
        '''
    ]

    juego_del_ahorcado(palabras, fallos)
