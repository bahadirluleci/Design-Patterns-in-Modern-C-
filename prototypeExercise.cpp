/*Prototype Coding Exercise
Given the provided code, you are asked to implement Line::deep_copy()  to perform a deep copy of the current Line  object.

Beware memory leaks!*/

struct Point
{
  int x{0}, y{0};

  Point() {}
  ~Point() = default;

  Point(const int x, const int y) : x{x}, y{y} {}
  Point(const Point &other) : x{other.x}, y{other.y} {}
};

struct Line
{
  Point *start, *end;

  Line(Point *const start, Point *const end)
      : start(start), end(end)
  {
  }

  ~Line()
  {
    delete start;
    start = nullptr;
    delete end;
    end = nullptr;
  }

  Line deep_copy() const
  {
    Line *dc = new Line(new Point(start->x, start->y), new Point(end->x, end->y));
    return *dc;
  }
};