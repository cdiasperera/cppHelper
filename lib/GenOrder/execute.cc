#include "GenOrder.ih"
void GenOrder::execute()
{
  cout << d_setFolder;
  // Go to folder
  // For each exercise that is not excluded, create an order.txt file
  // In this file, recursively add all files to order.txt

  // Ordering goals:

  // Minimum: Put summary.txt at the very top
  // Next: Group files in the same folder
  // Next: Make sure that a.ih always follows after a.h
}
