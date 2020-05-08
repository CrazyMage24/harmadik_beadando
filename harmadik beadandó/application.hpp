#include "widget.hpp"

#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED

class Application
{
protected:
    int aw;
    int ah;
    vector<Widget*> widgets;
    vector<vector<Widget*> > palya;
    bool jatek;
    bool nyert;
    bool gep_ellen;
public:
    void event_loop();
    void menu();
    void jatek_gep_15();
    void jatek_ember_15();
    void jatek_gep_30();
    void jatek_ember_30();

    void checkWin(vector<vector<Widget*> > palya);
    void checkDraw(vector<vector<Widget*> > palya);

    void endGame(string message);
    void valaszt();
};

#endif // APPLICATION_HPP_INCLUDED
