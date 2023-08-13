#ifndef GENORDER_h_1681748128
#define GENORDER_h_1681748128

#include "../Command/Command.h"

#include "../Config/Config.h"
#include "../Exercises/Exercises.h"

#include <unordered_map>
#include <functional>

class GenOrder : public Command
{
  using path = std::filesystem::path;
  using vp = std::vector<path>;
  using vs = std::vector<std::string>;
  using FolderGroups = std::unordered_map<std::string, vp>;
  typedef bool PrioCmpFunc(path const &p1, path const &p2);

  // A name for the bucket in the folder groups map to hold files under:
  // ./setN/exM/
  std::string const EX_ROOT_FLDR = "root";

  Exercises d_exercises;

  vp d_pathsToIgnore;
  std::function<PrioCmpFunc> d_higherPriority;

  public:
    GenOrder
    (
      path const &setLoc, std::vector<size_t> const &exsToIgnore,
      vp pathsToIgnore, std::function<PrioCmpFunc> higherPriority
    );
    ~GenOrder() override = default;
    void execute() override;

  private:
    // For all the files we will put into an order.txt, we put them int a map
    // where each bucket contains all files under a specific folder.
    // Then, for each bucket, we order them in the order of how they will be
    // written to the order.txt
    FolderGroups reorderFilesToAdd
    (
      path const &exRoot, vp const &filesToAdd
    ) const;
    // Write the files in our folder groups to the order.txt
    void writeToOrderFile
    (
      path const &exRoot, FolderGroups const &folderGroups
    ) const;

    // Returns true if we should not add a file to the order.txt
    bool excludedPath(path const &exRoot, path const &toCheck) const;

    // Check if a file is in ./setN/exM/
    static bool inExRootFolder(path const &exRoot, path const &file) ;


    // Check if toCheck is the same file as toExclude, if you prepend
    // ./setN/exM/ to toExclude.
    // TODO: An optimization would be to switch the exPrefix to each element in
    //  toExclude only if the prefix is different from the last one.
    bool sameFile
    (
      path const &exRoot, path const &toCheck, path const &toExclude
    ) const;
    // Check if toCheck is the same folder as toExclude, if you prepend
    // ./setN/exM/ to toExclude.
    bool inSameFolder
    (
      path const &exRoot, path const &toCheck, path const &toExclude
    ) const;
};

#endif