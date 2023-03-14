/*
Flyweight Coding Exercise
You are given a class called Sentence , which takes a string such as "hello world". You need to provide an interface such that the indexer (operator [] ) returns a WordToken  that can be used to capitalize a particular word in the sentence.

Typical use would be something like:

Sentence sentence("hello world");
sentence[1].capitalize = true;
cout << sentence.str(); // prints "hello WORLD"
*/
#include <string>
#include <vector>
#include <sstream>

struct Sentence
{
	Sentence(const std::string &text)
	{
		std::istringstream stream(text);
		std::string inner_word;

		while (std::getline(stream, inner_word, ' '))
		{
			sentence.push_back({inner_word, false});
		}
	}

	struct WordToken
	{
		std::string word;
		bool capitalize;
	};

	WordToken &operator[](size_t index)
	{
		return sentence[index];
	}

	std::string str() const
	{
		std::string result;

		for (size_t tokenIndex = 0; tokenIndex < sentence.size(); ++tokenIndex)
		{
			WordToken token = sentence[tokenIndex];

			if (token.capitalize)
			{
				for (size_t i = 0; i < token.word.length(); ++i)
				{
					auto c = std::toupper(token.word[i]);
					token.word[i] = c;
				}
			}

			result += token.word + (tokenIndex < sentence.size() - 1 ? " " : "");
		}

		return result;
	}

private:
	std::vector<WordToken> sentence;
};