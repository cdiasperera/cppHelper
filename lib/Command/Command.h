#ifndef COMMAND_h_1681332386
#define COMMAND_h_1681332386

// Base class for a command, follows Command pattern
class Command
{
  public:
    virtual ~Command();
    virtual void execute() = 0;
};

#endif
