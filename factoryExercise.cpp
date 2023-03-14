/*Factory Coding Exercise
You are given a class called Person . The person has two fields: id , and name .

Please implement a non-static PersonFactory that has a create_person()  method that takes a person's name.

The id  of the person should be set as a 0-based index of the object created. So, the first person the factory makes should have id=0, second id=1 and so on.*/

#include <string>
#include <iostream>
using namespace std;

static int id_count = -1;

struct Person
{
  int id;
  string name;

  Person(int in_id, string in_name) : id(in_id), name(in_name) {}
  ~Person()
  {
    std::cout << "destroyed person" << std::endl;
  }
};

class PersonFactory
{
public:
  Person create_person(const string &name)
  {
    id_count++;
    return {id_count, name};
  }
};