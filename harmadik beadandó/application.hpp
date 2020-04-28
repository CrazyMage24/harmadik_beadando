#include "window.hpp"

#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED

class Application
{
protected:
    Window* focus;
    int aw;
    int ah;
public:
    void event_loop();
};

#endif // APPLICATION_HPP_INCLUDED
