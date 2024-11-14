#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <stdexcept>
#include <string>

namespace Synth {
    class NotImplemented : public std::runtime_error {
    public:
        NotImplemented(const std::string& message) : std::runtime_error(message) {}
    };

    class InvalidArgumentError : public std::logic_error {
    public:
        InvalidArgumentError(const std::string& message) : std::logic_error(message) {}
    }; 
}

#endif // EXCEPTION_H