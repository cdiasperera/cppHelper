#include "CLI.ih"

namespace {
    string usageString =
R"(Usage:
cppHelper -<command> <arguments>

  <command> == g : Generate Folders.
    <arguments> ::=  <pathToGenerateFolderAt> <setNo> <firstExNum> <LastExNum>
  <command> == o : Generate order files.
    <arguments> ::= <setToGenerateOrdersFor> <commaSeparatedExercisesToNotGenerateOrderTxtFor>
  <command> == z : Generate zip of set
    <arguments> ::= <zipPath> <setToZipPath> <commaSeparatedExercisesToIncludeInZip>

  See README.md @ https://github.com/cdiasperera/cppHelper for details.
)";
}
string CLI::usage() const
{
  return usageString;
}
