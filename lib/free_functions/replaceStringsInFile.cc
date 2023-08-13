#include "free_functions.ih"

void replaceStringsInFile(path const &file,ReplaceMap const &replaceMap)
{
  // Read file into a string
  ifstream ifs{file};
  string fileData{istreambuf_iterator<char>{ifs}, {}};

  // Replace strings in string
  for (auto const &[toReplace, replaceWith] : replaceMap)
  {
    // Find all instances of toReplace and replace it with replaceWith
    size_t replaceAt;
    while ((replaceAt = fileData.find(toReplace)) != string::npos)
      fileData.replace(replaceAt, toReplace.length(), replaceWith);
  }

  // Write back to file
  ifs.close();
  ofstream{file} << fileData;
}
