#include <string>
#include <unordered_map>
#include <filesystem>
#include <vector>
#include <functional>
#include <sstream>

// Returns a string representation of the unsigned integer with leading zeros
std::string withLeadingZeros(size_t width, size_t num);

// Replaces replaceMap[i].first with replaceMap[i].second in every file in
// folder
void replaceStringsInFolder(
  std::filesystem::path const &folder,
  std::unordered_map<std::string, std::string> const &replaceMap
);
// Replaces replaceMap[i].first with replaceMap[i].second in file
void replaceStringsInFile(
  std::filesystem::path const &file,
  std::unordered_map<std::string, std::string> const &replaceMap
);

// Gets all the files inside a folder, except for those that are excluded
std::vector<std::filesystem::path> allFilesIn
(
  std::filesystem::path const &folder,
  std::function<bool (std::filesystem::path)> const &excluded
);

// Splits a path into two
std::pair<std::filesystem::path,std::filesystem::path> splitPath
(
  std::filesystem::path const &pth, size_t splitAt
);

// Check if a vector contains an element
template <typename T>
bool contains(std::vector<T> vec, T elem);

// Get a string containing elements seperated by a (single char) delim into a
// vector.
template <typename T>
std::vector<T>stringToVectorByDelim
(
  std::string str, char delim, T from_string(std::string const &)
);

#include "contains.hi"
#include "stringToVectorByDelim.hi"