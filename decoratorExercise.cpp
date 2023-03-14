/*
Decorator Coding Exercise
Roses can be red, blue or red and blue. Given the class interface Flower and class Rose, build decorators RedFlower and BlueFlower that would print the following:

Rose rose;
RedFlower red_rose{rose};
RedFlower red_red_rose{red_rose};
BlueFlower blue_red_rose{red_rose};
cout << rose.str();          // "A rose"
cout << red_rose.str();      // "A rose that is red"
cout << red_red_rose.str();  // "A rose that is red"
cout << blue_red_rose.str(); // "A rose that is red and blue"
*/

#include <string>
using namespace std;

struct Flower
{
  virtual string str() = 0;
};

struct Rose : Flower
{
  string str() override
  {
    return "A rose";
  }
};

struct RedFlower : Flower
{
  string m_color;
  Flower &m_flower;

  RedFlower(Flower &in_flower) : m_flower(in_flower), m_color("red")
  {
  }

  string str() override
  {
    string result = m_flower.str();

    if (result.find("that is") == std::string::npos)
    {
      result += " that is " + m_color;
    }
    else if (result.find(m_color) == std::string::npos)
    {
      result += " and " + m_color;
    }

    return result;
  }
};

struct BlueFlower : Flower
{
  string m_color;
  Flower &m_flower;

  BlueFlower(Flower &in_flower) : m_flower(in_flower), m_color("blue")
  {
  }

  string str() override
  {
    string result = m_flower.str();

    if (result.find("that is") == std::string::npos)
    {
      result += " that is " + m_color;
    }
    else if (result.find(m_color) == std::string::npos)
    {
      result += " and " + m_color;
    }

    return result;
  }
};