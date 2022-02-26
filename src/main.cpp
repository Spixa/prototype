#include "axe.hpp"

int main(int argc, char **argv)
{
  using namespace axe;
  return Axe::getInstance()->exec();
}