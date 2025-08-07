const display = document.getElementById("display");
const buttons = document.querySelectorAll(".btn");
let current = "";
let operator = null;
let firstValue = null;

buttons.forEach(button => {
  const value = button.dataset.value;

  button.addEventListener("click", () => {
    if (button.id === "clear") {
      current = "";
      operator = null;
      firstValue = null;
      display.textContent = "0";
    } else if (button.id === "equals") {
      if (operator && firstValue !== null && current !== "") {
        let secondValue = parseFloat(current);
        let result = 0;

        switch (operator) {
          case "+": result = firstValue + secondValue; break;
          case "-": result = firstValue - secondValue; break;
          case "*": result = firstValue * secondValue; break;
          case "/":
            if (secondValue === 0) {
              result = "Error";
            } else {
              result = firstValue / secondValue;
            }
            break;
        }

        display.textContent = result;
        current = result.toString();
        operator = null;
        firstValue = null;
      }
    } else if (button.classList.contains("operator")) {
      if (current !== "") {
        firstValue = parseFloat(current);
        operator = value;
        current = "";
      }
    } else {
      if (value === "." && current.includes(".")) return;
      current += value;
      display.textContent = current;
    }
  });
});
