#include "example.h"

void main()
{
  Example* ex = new Example();
  ex->print();
  (*ex).print();
}