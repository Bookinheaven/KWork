function calculateBMI() {
    const weight = document.getElementById('weight').value;
    const height = document.getElementById('height').value;
    const messageBox = document.getElementById('messageBox');
    const messageText = document.getElementById('messageText');

    messageBox.classList.remove('visible');

    if (weight === '' || height === '') {
        messageText.textContent = 'Error: Please enter both weight and height.';
        messageBox.classList.add('visible');
        return;
    }

    const weightNum = parseFloat(weight);
    const heightNum = parseFloat(height);

    if (isNaN(weightNum) || isNaN(heightNum) || weightNum <= 0 || heightNum <= 0) {
        messageText.textContent = 'Error: Please enter valid positive numbers for weight and height.';
        messageBox.classList.add('visible');
        return;
    }

    const heightInMeters = heightNum / 100;
    const bmi = weightNum / (heightInMeters * heightInMeters);
    const bmiRounded = bmi.toFixed(1);

    let status = '';
    let color = '';
    if (bmi < 18) {
        status = 'Underweight';
        color = 'blue';
    } else if (bmi >= 18 && bmi < 25) {
        status = 'Normal';
        color = 'green';
    } else if (bmi >= 25 && bmi < 30) {
        status = 'Overweight';
        color = 'orange';
    } else {
        status = 'Obese';
        color = 'red';
    }

    document.getElementById('bmi-value').textContent = bmiRounded;
    const statusElement = document.getElementById('bmi-status');
    statusElement.textContent = status + ' BMI';
    statusElement.style.color = color;
}

function clearFields() {
    document.getElementById('weight').value = '';
    document.getElementById('height').value = '';
    document.getElementById('bmi-value').textContent = '-';
    const statusElement = document.getElementById('bmi-status');
    statusElement.textContent = '-';
    statusElement.style.color = '#374151';
    document.getElementById('messageBox').classList.remove('visible');
}
