#include <exception>
#include <string>

class MatrixExceptions : public std::exception
{
private:
    std::string s;
    
public:
    MatrixExceptions(std::string s)
    {
        this->s = s;
    }
    
    std::string to_string()
    {
        return ("Exception Occured:" + s) ;
    }

};
