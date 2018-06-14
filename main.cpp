// RPNCalculator.cpp : Defines the entry point for the console application.
//

#include <iostream>  
#include <string>

#include "Calculator.h"

using namespace std;

int main(int argc, char **argv)
{
	Calculator<int> calculator;

	try
	{
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
				istringstream(value) >> nValue;
				calculator.addToStack(nValue);
			}
		}
	}
	catch (const std::exception& ex)
	{
		cerr << "An error caused the application to abort: " << ex.what() << endl;
	}	
	
	return 0;
}

