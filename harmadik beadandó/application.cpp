#include "application.hpp"

void background(int aw, int ah)
{
    gout << color(0,0,0) << move_to(0,0) << box(aw,ah);
    gout << color(255,255,255) << move_to(0,ah/2) <<line(aw,0);
    gout << color(255,255,255) << move_to(aw/2,0) <<line(0,ah);
}

void Application::event_loop()
{
    event ev;
    gin.timer(35);

    while(gin >> ev)
    {
        if(ev.type == ev_timer)
        {
            background(aw,ah);
            focus->show();
        }

        if(ev.type == ev_mouse)
        {
            focus->handleMouse(ev);
        }
        gout << refresh;
    }
}
