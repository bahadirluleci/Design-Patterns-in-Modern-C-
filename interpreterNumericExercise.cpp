/*
Interpreter Coding Exercise
You are asked to write an expression processor for simple numeric expressions with the following constraints:

Expressions use integral values (e.g., "13" ), single-letter variables defined in variables , as well as + and - operators only
There is no need to support braces or any other operations
If a variable is not found in Variables  (or if we encounter a variable with >1 letter, e.g. ab), the evaluator returns 0 (zero)
In case of any parsing failure, evaluator returns 0
Example:

calculate("1+2+3")  should return 6
calculate("1+2+xy")  should return 0
calculate("10-2-x")  when x=3 is in variables should return 5
*/
#include <iostream>
#include <map>
#include <string>
#include <vector>

inline std::vector<std::string> split(const std::string &inString)
{
	std::vector<std::string> result;
	size_t pos = 0, lastPos = 0;
	while ((pos = inString.find_first_of("+-", lastPos)) != std::string::npos)
	{
		result.push_back(inString.substr(lastPos, pos - lastPos + 1));
		lastPos = pos + 1;
	}
	result.push_back(inString.substr(lastPos));
	return result;
}

struct ExpressionProcessor
{
	std::map<char, int> variables;

	enum Type
	{
		nothing,
		plus,
		minus
	} type;

	int calculate(const std::string &expression)
	{
		int current;
		type = nothing;

		auto parts = split(expression);

		std::cout << "parts (" << parts.size() << "): ";
		for (auto &part : parts)
			std::cout << "`" << part << "` ";
		std::cout << std::endl;

		for (auto &part : parts)
		{
			auto no_op = split(part);
			auto first = no_op[0];
			int value, z;

			try
			{
				value = stoi(first);
			}
			catch (const std::invalid_argument &)
			{
				if (first.length() == 1 &&
					variables.find(first[0]) != variables.end())
				{
					value = variables[first[0]];
				}
				else
					return 0;
			}

			switch (type)
			{
			case nothing:
				current = value;
				break;
			case plus:
				current += value;
				break;
			case minus:
				current -= value;
				break;
			}

			if (*part.rbegin() == '+')
				type = plus;
			else if (*part.rbegin() == '-')
				type = minus;
		}

		return current;
	}
};

int main()
{
	const std::string str("1+2+3");
	int x = 3;
	const std::string str1("10-2-x");
	ExpressionProcessor ex;
	auto cal = ex.calculate(str);
	auto cal2 = ex.calculate(str1);
	std::cout << cal << std::endl;
	std::cout << cal2 << std::endl;
	
	return 0;
}