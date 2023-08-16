#ifndef FRONTENDEXCEPTION_h_1692175847
#define FRONTENDEXCEPTION_h_1692175847

#include <exception>
#include <string>

class FrontendException : public std::exception
{

  std::string d_msg;

  public:
    FrontendException(std::string msg);
    FrontendException(FrontendException const &other) noexcept = default;
    FrontendException(FrontendException &&other) = default;

    ~FrontendException() override = default;
    char const *what() const noexcept override;
};

#endif
