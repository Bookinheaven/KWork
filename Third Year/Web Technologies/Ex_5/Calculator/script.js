function calculate(operation) {
    const num1 = document.getElementById('num1').value;
    const num2 = document.getElementById('num2').value;
    const messageBox = document.getElementById('messageBox');
    const messageText = document.getElementById('messageText');

    messageBox.classList.remove('visible');

    if (num1 === '' || num2 === '') {
        messageText.textContent = 'Error: Please enter both numbers.';
        messageBox.classList.add('visible');
        return;
    }

    const number1 = parseFloat(num1);
    const number2 = parseFloat(num2);

    if (isNaN(number1) || isNaN(number2)) {
        messageText.textContent = 'Error: Please enter valid numbers.';
        messageBox.classList.add('visible');
        return;
    }

    let result;
    switch (operation) {
        case 'add':
            result = number1 + number2;
            break;
        case 'subtract':
            result = number1 - number2;
            break;
        case 'multiply':
            result = number1 * number2;
            break;
        case 'divide':
            if (number2 === 0) {
                messageText.textContent = 'Error: Cannot divide by zero.';
                messageBox.classList.add('visible');
                return;
            }
            result = number1 / number2;
            break;
        default:
            return;
    }

    document.getElementById('result').value = 'Result: ' + result;
}

function clearFields() {
    document.getElementById('num1').value = '';
    document.getElementById('num2').value = '';
    document.getElementById('result').value = '';
    document.getElementById('messageBox').classList.remove('visible');
}
