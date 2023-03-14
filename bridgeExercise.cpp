/*
Bridge Coding Exercise
You are given an example of an inheritance hierarchy which results in Cartesian-product duplication.

Please refactor this hierarchy, giving the base class Shape  an initializer that takes a Renderer  defined as

struct Renderer
{
  virtual string what_to_render_as() const = 0;
}
as well as VectorRenderer and RasterRenderer.

The expectation is that each constructed object has a member called str()  that returns its textual representation, for example,

Triangle(RasterRenderer()).str() // returns "Drawing Triangle as pixels"
*/

#include <string>
using namespace std;

struct Renderer
{
  virtual string what_to_render_as() const = 0;
};

struct RasterRenderer : Renderer
{
  string what_to_render_as() const override
  {
    return "pixels";
  }
};

struct VectorRenderer : Renderer
{
  string what_to_render_as() const override
  {
    return "lines";
  }
};

struct Shape
{
  string name;
  const Renderer &renderer;
  Shape(const Renderer &renderer) : renderer{renderer}
  {
  }

  std::string str() const
  {
    return "Drawing " + name + " as " + renderer.what_to_render_as();
  }
};

struct Triangle : Shape
{
  explicit Triangle(const Renderer &renderer)
      : Shape{renderer}
  {
    name = "Triangle";
  }
};

struct Square : Shape
{
  explicit Square(const Renderer &renderer)
      : Shape{renderer}
  {
    name = "Square";
  }
};
