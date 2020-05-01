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
        if(jatek)
        {
            if(ev.type == ev_timer)
            {
                background(aw,ah);
                for(int i = 0; i < palya.size(); i++)
                {
                    for(int j = 0; j < palya[i].size(); j++)
                    {
                        palya[i][j]->handleTimer(ev);
                    }
                }
            }

            if(ev.type == ev_mouse)
            {
                for(int i = 0; i < palya.size(); i++)
                {
                    for(int j = 0; j < palya[i].size(); j++)
                    {
                        palya[i][j]->handleMouse(ev);
                    }
                }
            }

            if(ev.type == ev_key)
            {
                for(int i = 0; i < palya.size(); i++)
                {
                    for(int j = 0; j < palya[i].size(); j++)
                    {
                        palya[i][j]->handleKeys(ev);
                    }
                }
            }
        }
        else
        {
            if(ev.type == ev_timer)
            {
                background(aw,ah);
                for(Widget* wi : widgets)
                {
                    wi->handleTimer(ev);
                }
            }

            if(ev.type == ev_mouse)
            {
                for(Widget* wi : widgets)
                {
                    wi->handleMouse(ev);
                }
            }

            if(ev.type == ev_key)
            {
                for(Widget* wi : widgets)
                {
                    wi->handleKeys(ev);
                }
            }
        }

        gout << refresh;
    }
}

void Application::jatek_gep_15()
{
    jatek = true;
    palya.clear();
    widgets.clear();

    for(int i = 0; i < 15; i++)
    {
        palya.push_back(vector<Widget*>());
        for(int j = 0; j < 15; j++)
        {
            Widget* c = new Cube(this,i*40,j*40,40,40,i,j);
            palya[i].push_back(c);
        }
    }
}
void Application::jatek_ember_15()
{
    jatek = true;
    palya.clear();
    widgets.clear();

    for(int i = 0; i < 15; i++)
    {
        palya.push_back(vector<Widget*>());
        for(int j = 0; j < 15; j++)
        {
            Widget* c = new Cube(this,i*40,j*40,40,40,i,j);
            palya[i].push_back(c);
        }
    }
}
void Application::jatek_gep_30()
{
    jatek = true;
    palya.clear();
    widgets.clear();

    for(int i = 0; i < 30; i++)
    {
        palya.push_back(vector<Widget*>());
        for(int j = 0; j < 30; j++)
        {
            Widget* c = new Cube(this,i*20,j*20,20,20,i,j);
            palya[i].push_back(c);
        }
    }
}
void Application::jatek_ember_30()
{
    jatek = true;
    palya.clear();
    widgets.clear();

    for(int i = 0; i < 30; i++)
    {
        palya.push_back(vector<Widget*>());
        for(int j = 0; j < 30; j++)
        {
            Widget* c = new Cube(this,i*20,j*20,20,20,i,j);
            palya[i].push_back(c);
        }
    }
}
