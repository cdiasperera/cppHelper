#ifndef COMMAND_h_1690877737
#define COMMAND_h_1690877737

class Command
{
  public:
    virtual ~Command() = default;
    virtual void execute() = 0;
};

#endif
