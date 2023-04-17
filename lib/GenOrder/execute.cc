#include "GenOrder.ih"
void GenOrder::execute()
{
  // Go to folder
  // For each exercise that is not excluded, create an order.txt file
  // In this file, recursively add all files to order.txt

  // Ordering goals:

  // Minimum: Put summary.txt at the very top
  // Ideally: Construct a relation "#dInc". Let A,B be two source files such
  // that A #dInc B iff A includes B. #dInc should be asymmetric.
  // Let "#inc" be the closure of #dInc, under transitivity and reflexitivity.

  // Now construct some topological sorting of #inc, which we call #tInc.

  // Order the files under #tInc.

  // Ideally Ideally: If file A,B defines members for class S, and if A is
  // declared lower than B, then A appears lower in the order.txt than B.
}
