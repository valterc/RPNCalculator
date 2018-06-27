# -*- coding: utf-8 -*-


class Calculator:
    
    def __init__(self):
        self.stack = []
        
        self.operators = {
                "+": lambda s: s.append(s.pop() + s.pop()),
                "-": lambda s: s.append(s.pop(-2) - s.pop()),
                "*": lambda s: s.append(s.pop() * s.pop()),
                "/": lambda s: s.append(s.pop(-2) / s.pop()),
                "~": lambda s: s.append(-s.pop()),
                "@": lambda s: print(s[-1])
        }

            
    def __addToStack(self, value):
        self.stack.append(value)
    
    
    def __isOperator(self, symbol):
        return symbol in self.operators
    
    
    def __applyOperator(self, symbol):
        
        if not self.__isOperator(symbol):
            raise Exception("Invalid operator: " + symbol)
            
        self.operators[symbol](self.stack)


    def __processStep(self, input):
        
        try:
            value = int(input)
            self.__addToStack(value)
        except:
            self.__applyOperator(input)
        
        
    def processInput(self, input):
        
        [self.__processStep(x) for x in input.split()]



c = Calculator()
c.processInput("10 5 / @")