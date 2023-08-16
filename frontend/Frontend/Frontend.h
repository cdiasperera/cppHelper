#ifndef FRONTEND_h_1692193373
#define FRONTEND_h_1692193373

#include <memory>
#include <vector>
#include "../../controller/Command/Command.h"

class Frontend
{
  public:
    Frontend() = default;
    virtual ~Frontend() = default;
    virtual std::unique_ptr<Command> readCommand
    (
      size_t argc, std::vector<std::string> argv
    ) = 0;
};

#endif
