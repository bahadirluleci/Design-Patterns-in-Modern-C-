/*Builder Coding Exercise
You are asked to implement the Builder design pattern for rendering simple chunks of code.

Sample use of the builder you are asked to create:

auto cb = CodeBuilder{"Person"}.add_field("name", "string").add_field("age", "int");
cout << cb;
The expected output of the above code is:

class Person
{
  string name;
  int age;
};
Please observe the same placement of curly braces and use two-space indentation.*/

#include <string>
#include <vector>
#include <ostream>
using namespace std;

struct Field
{
  string name, type;

  Field(const string &name, const string &type)
      : name{name},
        type{type}
  {
  }

  friend ostream &operator<<(ostream &os, const Field &obj)
  {
    return os << obj.type << " " << obj.name << ";";
  }
};

struct Class
{
  string name;
  vector<Field> fields;

  friend ostream &operator<<(ostream &os, const Class &obj)
  {
    os << "class " << obj.name << "\n{\n";
    for (auto &&field : obj.fields)
    {
      os << "  " << field << "\n";
    }
    return os << "};\n";
  }
};

class CodeBuilder
{
public:
  Class m_class;

  CodeBuilder(const string &class_name)
  {
    m_class.name = class_name;
  }

  CodeBuilder &add_field(const string &name, const string &type)
  {
    m_class.fields.emplace_back(Field{name, type});
    return *this;
  }

  friend ostream &operator<<(ostream &os, const CodeBuilder &obj)
  {
    return os << obj.m_class;
  }
};