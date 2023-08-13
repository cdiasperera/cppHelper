#ifndef EXCLUDEDEXERCISES_h_1691399746
#define EXCLUDEDEXERCISES_h_1691399746

#include <vector>
#include <filesystem>
#include <string>

class Exercises
{
  using path = std::filesystem::path;
    
  enum
  {
    // The number of path elements that construct the prefix of a file path in
    // an exercise. i.e: the size of ./setN/exM/ == 2.
    SIZE_EX_FLDR_PREF = 2,
    SIZE_EX_FLDR_NAME = 2
  };

  std::vector<size_t> d_exercises;

  path d_setLoc;
  
  public:
    Exercises(path const &setLoc, std::vector<size_t> const &excl);
    Exercises
    (
      path setLoc, std::vector<size_t> const &excl,
      size_t exStr, size_t exEnd
    );


    std::vector<path> getExercisesAsPaths() const;
    std::vector<size_t> const &getExercisesAsNumbers() const;

    path getExercisePath(size_t ex) const;
    path getSetFolder() const;
};

#endif
