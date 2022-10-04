//
// Created by kevin on 22-10-4.
//

#ifndef PETRINETSOLVER_PETRINETERROR_H
#define PETRINETSOLVER_PETRINETERROR_H

#include <boost/system/error_code.hpp>
#include <boost/exception/exception.hpp>
#include <boost/exception/all.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/shared_array.hpp>
#include <exception>
#include <string>

class PetriNetError : public boost::exception,public std::exception  {
public:
    const char* name() const noexcept{ return "application"; }
    std::string message(int ev) const { return "error message"; }
    PetriNetError(std::size_t size) : what_("allocation of " + boost::lexical_cast<std::string>(size) + " bytes failed")
    {
    }

    virtual const char *what() const throw()
    {
        return what_.c_str();
    }

private:
    std::string what_;
};


#endif //PETRINETSOLVER_PETRINETERROR_H
