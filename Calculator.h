#pragma once

#include <string>
#include <sstream>
#include <unordered_map>
#include <stack>
#include <iostream>

#include "Operator.h"
#include "AdditionOperator.h"
#include "SubtractionOperator.h"
#include "MultiplicationOperator.h"
#include "DivisionOperator.h"
#include "SwapSignOperator.h"
#include "PrintStackOperator.h"

#include "InvalidOperatorException.h"

using namespace std;

template<typename T>
class Calculator
{

private:
	unordered_map<string, unique_ptr<Operator<T>>> operators;
	stack<T> stack;

public:
	Calculator();
	~Calculator();

	const bool isOperator(const string& str);
	void applyOperator(const string & str);
	void addToStack(const T & value);

};

template<typename T>
inline Calculator<T>::Calculator()
{
	operators.emplace(string("+"), make_unique<AdditionOperator<T>>());
	operators.emplace(string("-"), make_unique<SubtractionOperator<T>>());
	operators.emplace(string("*"), make_unique<MultiplicationOperator<T>>());
	operators.emplace(string("/"), make_unique<DivisionOperator<T>>());
	operators.emplace(string("~"), make_unique<SwapSignOperator<T>>());
	operators.emplace(string("@"), make_unique<PrintStackTopOperator<T>>(cout));
}

template<typename T>
inline Calculator<T>::~Calculator()
{
}

template<typename T>
inline const bool Calculator<T>::isOperator(const string & str)
{
	return operators.find(str) != operators.end();
}

template<typename T>
inline void Calculator<T>::applyOperator(const string & str)
{
	if (operators.find(str) == operators.end()) {

		ostringstream strstream;
		strstream << "The operator '";
		strstream << str;
		strstream << "' is not valid";

		throw InvalidOperatorException(strstream.str().c_str());
	}

	operators[str]->apply(this->stack);
}

template<typename T>
inline void Calculator<T>::addToStack(const T & value)
{
	this->stack.push(value);
}
