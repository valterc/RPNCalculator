// RPNCalculator.cpp : Defines the entry point for the console application.
//

#include <iostream>  
#include <string>

#include "Calculator.h"
#include "InvalidInputArgumentException.h"

using namespace std;
using ValueType = int;

int main(int argc, char **argv)
{
	Calculator<ValueType> calculator;

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
				ValueType nValue = 0;
				istringstream stream(value);
				stream >> nValue;

				if (!stream.eof())
				{
					ostringstream strstream;
					strstream << "The input argument '";
					strstream << value;
					strstream << "' is not a valid operator nor number.";

					throw InvalidInputArgumentException(strstream.str().c_str());
				}

				calculator.addToStack(nValue);
			}
		}
	}
	catch (const std::exception& ex)
	{
		cerr << "An error caused the application to abort: " << ex.what() << endl;
		return -1;
	}	
	
	return 0;
}

