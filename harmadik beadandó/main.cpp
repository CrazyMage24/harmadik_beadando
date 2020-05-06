#include "application.hpp"

const int w = 600;
const int h = 601;

#ifndef MYAPP_HPP_INCLUDED
#define MYAPP_HPP_INCLUDED

class Myapp : public Application
{
private:
public:
    Myapp()
    {
        Widget* jatek_15_gep = new Button(this,150,75,300,50,"Új játék gép ellen (15x15)");
        Widget* jatek_15_ember = new Button(this,150,175,300,50,"Új játék ember ellen (15x15)");
        Widget* jatek_30_gep = new Button(this,150,275,300,50,"Új játék gép ellen (30x30)");
        Widget* jatek_30_ember = new Button(this,150,375,300,50,"Új játék ember ellen (30x30)");
        Widget* kilepes = new Button(this,150,475,300,50,"Kilépés");

        selected = nullptr;

        widgets.push_back(jatek_15_gep);
        widgets.push_back(jatek_15_ember);
        widgets.push_back(jatek_30_gep);
        widgets.push_back(jatek_30_ember);
        widgets.push_back(kilepes);
        aw = w;
        ah = h;

        jatek = false;
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

