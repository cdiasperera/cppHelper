#ifndef GENORDER_h_1681748128
#define GENORDER_h_1681748128

#include "../Command/Command.h"
#include "../CommandRecipe/CommandRecipe.h"

#include "../Config/Config.h"

#include <unordered_map>
class GenOrder : public Command
{
  using path = std::filesystem::path;
  using vp = std::vector<path>;
  using vs = std::vector<std::string>;
  using FolderGroups = std::unordered_map<std::string, vp>;

  enum
  {
    // Location in main arguments that holds the set folder that contains the
    // exercises we must generate the order.txt for.
    SET_FLDR_ARG_POS = 0,
    // Location in main arguments that contains the first exercise (of
    // potentially many) that we should not generate order.txt's for.
    IGNORE_ARG_START = 1,
    // The number of path elements that construct the prefix of a file path in
    // an exercise. i.e: the size of ./setN/exM/ == 3.
    SIZE_EX_FLDR_PREF = 3
  };

  // A name for the bucket in the folder groups map to hold files under:
  // ./setN/exM/
  std::string const EX_ROOT_FLDR = "root";

  Config const &d_config = Config::instance();

  // The path to set we are generating the order.txt's for: .setN/exM/
  path const d_setFolder;

  // The exercises we should not generate order.txt for.
  vs d_exExclList;

  public:
    GenOrder(CommandRecipe recipe);
    void execute() override;

  private:
    // Get the files to add to the order.txt
    vp getFilesToAdd(path const &exerciseFolder) const;
    // For all the files we will put into an order.txt, we put them int a map
    // where each bucket contains all files under a specific folder.
    // Then, for each bucket, we order them in the order of how they will be
    // written to the order.txt
    FolderGroups reorderFilesToAdd(vp const &filesToAdd) const;
    // Write the files in our folder groups to the order.txt
    void writeToOrderFile(FolderGroups const &folderGroups) const;

    // Get the exercise folder paths that we should generate order.txt for
    vp getExerciseFolders() const;
    // If a folder is an exercise we should not generate an order.txt for
    bool excludedExercise(path const &folder) const;

    // Returns true if we should not add a file to the order.txt
    bool excluded(path const &toCheck) const;

    // Get a prefix of a path, upto some point. For example:
    // a/b/c/d/e/f with upto = 3 => a/b/c
    path prefPath(path const &fileInExFolder, size_t upto) const;
    // Check if a file is in ./setN/exM/
    bool inExRootFolder(path const &file) const;


    // Check if toCheck is the same file as toExclude, if you prepend
    // ./setN/exM/ to toExclude.
    // TODO: An optimization would be to switch the exPrefix to each element in
    //  toExclude only if the prefix is different from the last one.
    bool sameFile(
      path const &exPrefix, path const &toCheck, path const &toExclude
    ) const;
    // Check if toCheck is the same folder as toExclude, if you prepend
    // ./setN/exM/ to toExclude.
    bool sameFolder(path const &toCheck, path const &toExclude) const;
};

#endif
