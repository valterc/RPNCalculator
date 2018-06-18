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
#include "PrintStackTopOperator.h"
#include "InvalidOperatorException.h"

template<typename T>
class Calculator
{

private:	
	std::unordered_map<std::string, std::unique_ptr<Operator<T>>> operators;
	std::stack<T> stack;

public:
	Calculator();
	virtual ~Calculator() = default;

	const bool isOperator(const std::string &str) const;
	void applyOperator(const std::string &str);
	void addToStack(const T &value);

};

template<typename T>
Calculator<T>::Calculator()
{
	operators.emplace("+", make_unique<AdditionOperator<T>>());
	operators.emplace("-", make_unique<SubtractionOperator<T>>());
	operators.emplace("*", make_unique<MultiplicationOperator<T>>());
	operators.emplace("/", make_unique<DivisionOperator<T>>());
	operators.emplace("~", make_unique<SwapSignOperator<T>>());
	operators.emplace("@", make_unique<PrintStackTopOperator<T>>(cout));
}

template<typename T>
inline const bool Calculator<T>::isOperator(const std::string &str) const
{
	return operators.find(str) != operators.end();
}

template<typename T>
inline void Calculator<T>::applyOperator(const std::string &str)
{
	auto it = operators.find(str);

	if (it == operators.end()) 
	{
		std::ostringstream strstream;
		strstream << "The operator '";
		strstream << str;
		strstream << "' is not valid";

		throw InvalidOperatorException(strstream.str().c_str());
	}

	it->second->apply(this->stack);
}

template<typename T>
inline void Calculator<T>::addToStack(const T &value)
{
	this->stack.push(value);
}
