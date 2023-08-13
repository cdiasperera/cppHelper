#include "free_functions.ih"

string withLeadingZeros(size_t width, size_t num)
{
  string numStr = to_string(num);
  size_t nZeros = width - numStr.length();

  numStr.insert(0, nZeros, '0');

  return numStr;
}