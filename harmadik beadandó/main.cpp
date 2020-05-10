#include "application.hpp"

const int w = 600;
const int h = 601;

#ifndef MYAPP_HPP_INCLUDED
#define MYAPP_HPP_INCLUDED

class Myapp : public Application
{
private:
    vector<Widget*> widgets;
    vector<vector<Widget*> > palya;
    bool jatek;
    bool nyert;
    bool gep_ellen;
public:
    Myapp()
    {
        aw = w;
        ah = h;
        menu();
    }
};

#endif // MYAPP_HPP_INCLUDED

int Cube::Count = 0;

int main()
{
    setlocale(LC_ALL, "hu_HU.ISO88592");
    gout.open(w,h);

    Myapp app;
    app.event_loop();

    return 0;
}

