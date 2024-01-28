// main.js

function drawArray(array, color) {
    const canvas = document.getElementById("canvas");
    const ctx = canvas.getContext("2d");
    const barWidth = canvas.width / array.length;

    ctx.clearRect(0, 0, canvas.width, canvas.height);

    array.forEach((value, index) => {
        ctx.fillStyle = color;
        ctx.fillRect(index * barWidth, canvas.height - value, barWidth - 1, value);
    });
}

function sleep(ms) {
    return new Promise(resolve => setTimeout(resolve, ms));
}

async function linearSearch(array, target) {
    for (let i = 0; i < array.length; ++i) {
        drawArray(array, "lightblue");
        drawArray([array[i]], "red");
        await sleep(500);
        if (array[i] === target) {
            drawArray(array, "green");
            return true;
        }
    }
    drawArray(array, "red");
    return false;
}

async function binarySearch(array, target) {
    let low = 0;
    let high = array.length - 1;

    while (low <= high) {
        const mid = Math.floor((low + high) / 2);
        drawArray(array, "lightblue");
        drawArray([array[mid]], "red");
        await sleep(500);

        if (array[mid] === target) {
            drawArray(array, "green");
            return true;
        }

        if (array[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    drawArray(array, "red");
    return false;
}

async function bubbleSort(array) {
    for (let i = 0; i < array.length - 1; ++i) {
        for (let j = 0; j < array.length - i - 1; ++j) {
            drawArray(array, "lightblue");
            drawArray([array[j], array[j + 1]], "red");
            await sleep(500);

            if (array[j] > array[j + 1]) {
                const temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    drawArray(array, "green");
}

async function quickSort(array, low, high) {
    if (low < high) {
        const pivotIndex = await partition(array, low, high);
        await quickSort(array, low, pivotIndex - 1);
        await quickSort(array, pivotIndex + 1, high);
    }
}

async function partition(array, low, high) {
    const pivot = array[high];
    let i = low - 1;

    for (let j = low; j <= high - 1; ++j) {
        drawArray(array, "lightblue");
        drawArray([array[j], pivot], "red");
        await sleep(500);

        if (array[j] < pivot) {
            i++;
            const temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    const temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    drawArray(array, "green");
    return i + 1;
}

function visualize() {
    const algorithmSelect = document.getElementById("algorithmSelect");
    const selectedAlgorithm = algorithmSelect.value;

    const array = [4, 2, 7, 1, 9];

    switch (selectedAlgorithm) {
        case "linearSearch":
            linearSearch([...array], 7);
            break;
        case "binarySearch":
            array.sort((a, b) => a - b);
            binarySearch([...array], 7);
            break;
        case "bubbleSort":
            bubbleSort([...array]);
            break;
        case "quickSort":
            quickSort([...array], 0, array.length - 1);
            break;
        default:
            break;
    }
}
