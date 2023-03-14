/*Composite Coding Exercise
Consider the code presented below. The sum()  function takes a vector of pointers to either SingleValue or ManyValues instances and adds up all their elements together.

Please complete the implementation so that the sum()  function starts to operate correctly. This may involve giving the classes a common interface, among other things.

Here is an example of how the function might be used:

SingleValue single_value{ 1 };
ManyValues other_values;
other_values.add(2);
other_values.add(3);
sum({ &single_value, &other_values }); // returns 6*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ContainsIntegers
{
  virtual int sum() const = 0;
};
struct SingleValue : ContainsIntegers
{
  int value{0};

  SingleValue() = default;

  explicit SingleValue(const int value)
      : value{value}
  {
  }

  int sum() const override
  {
    return value;
  }
};

struct ManyValues : SingleValue
{
  vector<SingleValue> values;
  void add(const int value)
  {
    values.push_back(SingleValue(value));
  }

  int sum() const override
  {
    int sum_of_elems{0};
    for (auto it = values.begin(); it != values.end(); ++it)
    {
      sum_of_elems += it->sum();
    }
    return sum_of_elems;
  }
};

int sum(const vector<ContainsIntegers *> items)
{
  int sum_of_elems{0};
  for (auto it = items.begin(); it != items.end(); ++it)
  {
    sum_of_elems += (*it)->sum();
  }
  return sum_of_elems;
}