#ifndef EXCEPTIONS_H_
# define EXCEPTIONS_H_

# include <exception>
# include <string>
# include <string.h>
# include <errno.h>

namespace Exceptions
{

class NetworkExcept : public std::exception
{
public:
  NetworkExcept(std::string const& msg, int error) throw()
    : _msg(msg), _errorCode(error) {}
  NetworkExcept(const NetworkExcept& other) throw()
    : _msg(other._msg), _errorCode(other._errorCode) {}
  virtual ~NetworkExcept() throw() {}
  virtual const char*	what() const throw()
  {
    return std::string(_msg + " : " + strerror(_errorCode)).c_str();
  }

private:
  std::string		_msg;
  int			_errorCode;

  NetworkExcept &operator=(const NetworkExcept &) throw();
};

};


#endif /* !EXCEPTIONS_H_ */
