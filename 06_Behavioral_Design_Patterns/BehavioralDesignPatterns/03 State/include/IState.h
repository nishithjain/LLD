#pragma once
#include <stdexcept>
class DocumentContext;

class IState {
public:
    virtual ~IState() = default;
    virtual void view(DocumentContext& context) = 0;
    virtual void edit(DocumentContext& context) 
    {
        throw std::runtime_error(
            "Editing is not allowed in the current state.");
    }
    virtual void lock(DocumentContext& context) 
    {
        throw std::runtime_error(
            "Locking is not allowed in the current state.");
    }
};
