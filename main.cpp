// RPNCalculator.cpp : Defines the entry point for the console application.
//

#include <iostream>  
#include <string>

#include "Calculator.h"

using namespace std;

int main(int argc, char **argv)
{
	Calculator<int> calculator = Calculator<int>();

	for (int i = 1; i < argc; i++)
	{
		string value = argv[i];

		if (calculator.isOperator(value)) 
		{
			calculator.applyOperator(value);
		}
		else
		{
			int nValue = 0;
			istringstream (value) >> nValue;
			calculator.addToStack(nValue);
		}
	}
	
	return 0;
}

