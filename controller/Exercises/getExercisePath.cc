#include "Exercises.ih"
path Exercises::getExercisePath(size_t ex) const
{
  return d_setLoc/withLeadingZeros(SIZE_EX_FLDR_NAME, ex);
}
