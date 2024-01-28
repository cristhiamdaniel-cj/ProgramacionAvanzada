// main.js

const arraySize = 10; // Tamaño de la lista

// Función para generar una lista de números enteros aleatorios
function generateRandomArray(size) {
    const array = [];
    for (let i = 0; i < size; i++) {
        array.push(Math.floor(Math.random() * 100) + 1); // Números entre 1 y 100
    }
    return array;
}

// Inicializar la lista aleatoria
const originalArray = generateRandomArray(arraySize);

// Función para reiniciar la lista original
function resetArray() {
    return [...originalArray];
}

// Función para obtener un elemento aleatorio de la lista
function getRandomElement(array) {
    const randomIndex = Math.floor(Math.random() * array.length);
    return array[randomIndex];
}

// Función para mostrar el estado actual del arreglo en el área designada
function drawArrayDisplay(array) {
    const arrayDisplay = document.getElementById("array");
    arrayDisplay.innerHTML = array.map(value => `<span>${value}</span>`).join(" ");
}

// Función para pausar la ejecución por un tiempo determinado
function sleep(ms) {
    return new Promise(resolve => setTimeout(resolve, ms));
}

// Función de búsqueda lineal
async function linearSearch(array, target) {
    for (let i = 0; i < array.length; ++i) {
        array[i] === target ? array[i] = `(${target})` : array[i] = `${array[i]}`;
        drawArrayDisplay(array);
        await sleep(500);
        if (array[i] === target) {
            return true;
        }
    }
    return false;
}

// Función de búsqueda binaria
async function binarySearch(array, target) {
    let low = 0;
    let high = array.length - 1;

    while (low <= high) {
        const mid = Math.floor((low + high) / 2);
        array[mid] === target ? array[mid] = `(${target})` : array[mid] = `${array[mid]}`;
        drawArrayDisplay(array);
        await sleep(500);

        if (array[mid] === target) {
            return true;
        }

        if (array[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return false;
}

// Función de ordenamiento: Bubble Sort
async function bubbleSort(array) {
    for (let i = 0; i < array.length - 1; ++i) {
        for (let j = 0; j < array.length - i - 1; ++j) {
            array[j] > array[j + 1] ? [array[j], array[j + 1]] = [array[j + 1], array[j]] : null;
            drawArrayDisplay(array);
            await sleep(500);
        }
    }
}

// Función de ordenamiento: QuickSort
async function quickSort(array, low, high) {
    if (low < high) {
        const pivotIndex = await partition(array, low, high);
        await quickSort(array, low, pivotIndex - 1);
        await quickSort(array, pivotIndex + 1, high);
    }
}

// Función auxiliar para QuickSort: Partición
async function partition(array, low, high) {
    const pivot = array[high];
    let i = low - 1;

    for (let j = low; j <= high - 1; ++j) {
        array[j] > pivot ? [array[j], array[i + 1]] = [array[i + 1], array[j]] : null;
        drawArrayDisplay(array);
        await sleep(500);

        if (array[j] < pivot) {
            i++;
        }
    }

    [array[i + 1], array[high]] = [array[high], array[i + 1]];
    drawArrayDisplay(array);
    await sleep(500);

    return i + 1;
}

// Función principal para visualizar algoritmos
function visualize() {
    const algorithmSelect = document.getElementById("algorithmSelect");
    const selectedAlgorithm = algorithmSelect.value;

    let array;

    // Resetear la lista original antes de cada visualización
    array = resetArray();

    // Visualización inicial del arreglo
    drawArrayDisplay(array);

    switch (selectedAlgorithm) {
        case "linearSearch":
            linearSearch(array, getRandomElement(array));
            break;
        case "binarySearch":
            array.sort((a, b) => a - b);
            binarySearch(array, getRandomElement(array));
            break;
        case "bubbleSort":
            bubbleSort(array);
            break;
        case "quickSort":
            quickSort(array, 0, array.length - 1);
            break;
        default:
            break;
    }
}
