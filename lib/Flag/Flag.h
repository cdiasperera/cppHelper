#ifndef FLAG_h_1681233022
#define FLAG_h_1681233022

#include <string>
#include <vector>

// A flag and its associated arguments, as strings
struct Flag
{
  char d_flag;
  std::vector<std::string> d_args;
  public:
    Flag(char flag, std::vector<std::string> const &args);
};

#endif
