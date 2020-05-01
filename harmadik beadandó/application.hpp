#include "widget.hpp"

#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED

class Application
{
protected:
    int aw;
    int ah;
    vector<Widget*> widgets;
    Widget* selected;

    vector<vector<Widget*> > palya;
    bool jatek;
public:
    void event_loop();

    void jatek_gep_15();
    void jatek_ember_15();
    void jatek_gep_30();
    void jatek_ember_30();
};

#endif // APPLICATION_HPP_INCLUDED
