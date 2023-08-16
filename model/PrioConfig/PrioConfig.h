#ifndef CONFIGPRIO_h_1691140681
#define CONFIGPRIO_h_1691140681

#include <string>
#include <filesystem>
#include <vector>

// TODO: Probably should make this a singleton

class PrioConfig
{
    using path = std::filesystem::path;
    using vs = std::vector<std::string>;

    enum
    {
      FILE_NAME_PREFIX = '$'
    };

    // File of extension / filename priorities for order.txt
    path d_prioFileName =  "prio.txt";
    path d_prioFile;

    // Extension / filename priorities for order.txt
    // Filenames are prefixed by FILE_NAME_PREFIX to differentiate it
    // from extensions (as some files might start with a '.')
    vs d_prioList;

  public:
    PrioConfig(path const &configFolder);

    // Returns true if p1 has higher priority than p2 in the order.txt
    bool higherPriority(path const &p1, path const &p2) const;
  private:
    // Set filename / extension priorities
    void initPrioList();

    // Create default priority file
    void createDefaultPrioFile() const;

    // Return -1 if p1 matches but p2 doesn't
    //         1 if p2 matches but p1 doesn't
    //         0 if both or neither match
    int comparePrioWith
    (
      std::string const &prioItem, path const &p1, path const &p2
    ) const;

    int comparePrioWithFile
    (
      std::string const &prioName, path const &p1, path const &p2
    ) const;
    int comparePrioWithExt
    (
      std::string const &prioItem, path const &p1, path const &p2
    ) const;

    //  Whether the line (from the priority file) denotes a file, based on our
    // convention.
    bool isFile(std::string const &prioFileLine) const;
    // The filename of a line (from the priority file).
    std::string fileName(std::string const &prioFileLine) const;
};

inline bool PrioConfig::isFile(std::string const &prioFileLine) const
{
  return prioFileLine.front() == FILE_NAME_PREFIX;
}

inline std::string PrioConfig::fileName
(
  std::string const &prioFileLine
) const
{
  // Just remove the file name prefix
  return prioFileLine.substr(1);
}

#endif
