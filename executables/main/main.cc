#include "main.ih"

int main(int argc, char *argv[])
try
{
  Config::instance();
}
catch (...)
{
  handleExceptions();
}