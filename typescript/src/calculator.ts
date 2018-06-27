import { Stack } from "./stack.js";

export class Calculator<T>{
    stack: Stack<T>;
    operators: Map<string, (stack: Stack<T>) => void>;

    constructor() {
        this.stack = new Stack();
        this.operators = new Map();
    }

    public isOperator(symbol: string): boolean {
        return this.operators.has(symbol);
    }

    public addOperator(symbol: string, operator: (stack: Stack<T>) => void): void {
        this.operators.set(symbol, operator);
    }

    public addToStack(value: T): void {
        this.stack.push(value);
    }

    public applyOperator(symbol: string): void {

        if (this.isOperator(symbol) == false) {
            throw new Error("Invalid operator: " + symbol);
        }

        this.operators.get(symbol)(this.stack);
    }
}
