
export class Stack<T>{
    private data: Array<T>;

    constructor(){
        this.data = new Array();
    }

    public push(element: T) : void {
        this.data.push(element);
    }

    public pop() : T{
        return this.data.pop();
    }

    public peek() : T{
        return this.data[this.data.length-1];
    }

}