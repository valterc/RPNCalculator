import { Stack } from "./stack.js";
import { Calculator } from "./calculator.js";

/*
 * Set up calculator
 */

let calculator = new Calculator<number>();
calculator.addOperator("+", s => {
    let secondOperand = s.pop();
    let firstOperand = s.pop();
    s.push(firstOperand + secondOperand);
});
calculator.addOperator("-", s => {
    let secondOperand = s.pop();
    let firstOperand = s.pop();
    s.push(firstOperand - secondOperand);
});
calculator.addOperator("*", s => {
    let secondOperand = s.pop();
    let firstOperand = s.pop();
    s.push(firstOperand * secondOperand);
});
calculator.addOperator("/", s => {
    let secondOperand = s.pop();
    let firstOperand = s.pop();
    s.push(firstOperand / secondOperand);
});
calculator.addOperator("~", s => {
    let firstOperand = s.pop();
    s.push(-firstOperand);
});
calculator.addOperator("@", s => {
    console.log(s.peek());
});

/*
 * Process input
 */

function processInput(input : string): void {
    input.split(' ').forEach(element => {
        if (calculator.isOperator(element)){
            calculator.applyOperator(element);
        } else {
            let num = parseInt(element);
            calculator.addToStack(num);
        }
    });
}


processInput("4 5 * ~ @");

