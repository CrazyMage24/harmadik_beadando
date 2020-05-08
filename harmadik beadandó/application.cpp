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
                checkWin(palya);
                checkDraw(palya);
            }

            if(ev.type == ev_mouse && !nyert)
            {
                for(int i = 0; i < palya.size(); i++)
                {
                    for(int j = 0; j < palya[i].size(); j++)
                    {
                        palya[i][j]->handleMouse(ev,gep_ellen);
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
                    wi->handleMouse(ev,false);
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

void Application::menu()
{
    jatek = false;
    nyert = false;

    palya.clear();
    widgets.clear();
    Widget* jatek_15_gep = new Button(this,150,75,300,50,"Új játék gép ellen (15x15)");
    Widget* jatek_15_ember = new Button(this,150,175,300,50,"Új játék ember ellen (15x15)");
    Widget* jatek_30_gep = new Button(this,150,275,300,50,"Új játék gép ellen (30x30)");
    Widget* jatek_30_ember = new Button(this,150,375,300,50,"Új játék ember ellen (30x30)");
    Widget* kilepes = new Button(this,150,475,300,50,"Kilépés");
    widgets.push_back(jatek_15_gep);
    widgets.push_back(jatek_15_ember);
    widgets.push_back(jatek_30_gep);
    widgets.push_back(jatek_30_ember);
    widgets.push_back(kilepes);
}

void Application::jatek_gep_15()
{
    jatek = true;
    gep_ellen = true;
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
    gep_ellen = false;
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
    gep_ellen = true;
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
    gep_ellen = false;
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

void Application::checkWin(vector<vector<Widget*> > palya)
{
    int x_score = 0;
    int o_score = 0;
    /// oszlopokra
    for(int i = 0; i < palya.size(); i++)
    {
        for(int j = 0; j < palya[i].size(); j++)
        {
            if(palya[i][j]->getSelect() == "x")
            {
                x_score++;
                o_score = 0;
            }

            if(palya[i][j]->getSelect() == "o")
            {
                o_score++;
                x_score = 0;
            }

            if(palya[i][j]->getSelect() == "")
            {
                o_score = 0;
                x_score = 0;
            }

            if(x_score>=5)
            {
                endGame("X nyert");
            }

            if(o_score>=5)
            {
                endGame("O nyert");
            }
        }
        o_score = 0;
        x_score = 0;
    }

    /// sorokra
    o_score = 0;
    x_score = 0;
    for(int i = 0; i < palya.size(); i++)
    {
        for(int j = 0; j < palya[i].size(); j++)
        {
            if(palya[j][i]->getSelect() == "x")
            {
                x_score++;
                o_score = 0;
            }

            if(palya[j][i]->getSelect() == "o")
            {
                o_score++;
                x_score = 0;
            }

            if(palya[j][i]->getSelect() == "")
            {
                o_score = 0;
                x_score = 0;
            }

            if(x_score>=5)
            {
                endGame("X nyert");
            }

            if(o_score>=5)
            {
                endGame("O nyert");
            }
        }
        o_score = 0;
        x_score = 0;
    }

    /// jobbra átlósan

    o_score = 0;
    x_score = 0;
    for(int i = 0; i < palya.size(); i++)
    {
        for(int j = 0; j < palya[i].size(); j++)
        {
            for(int k = 0; k < 5; k++)
            {
                if(i+k < palya.size() && j+k<palya[i].size())
                {
                    if(palya[i+k][j+k]->getSelect() == "x")
                    {
                        x_score++;
                        o_score = 0;
                    }
                    if(palya[i+k][j+k]->getSelect() == "o")
                    {
                        o_score++;
                        x_score = 0;
                    }
                    if(palya[i+k][j+k]->getSelect() == "")
                    {
                        x_score = 0;
                        o_score = 0;
                    }
                }
            }

            if(x_score>=5)
            {
                endGame("X nyert");
            }

            x_score = 0;
            o_score = 0;

            for(int k = 0; k < 5; k++)
            {
                if(i+k < palya.size() && j-k>=0)
                {
                    if(palya[i+k][j-k]->getSelect() == "x")
                    {
                        x_score++;
                        o_score = 0;
                    }
                    if(palya[i+k][j-k]->getSelect() == "o")
                    {
                        o_score++;
                        x_score = 0;
                    }
                    if(palya[i+k][j-k]->getSelect() == "")
                    {
                        x_score = 0;
                        o_score = 0;
                    }
                }
            }
            if(x_score>=5)
            {
                endGame("X nyert");
            }

            x_score = 0;
            o_score = 0;

            for(int k = 0; k < 5; k++)
            {
                if(i+k < palya.size() && j+k<palya[i].size())
                {
                    if(palya[i+k][j+k]->getSelect() == "o")
                    {
                        o_score++;
                        x_score = 0;
                    }

                    if(palya[i+k][j+k]->getSelect() == "x")
                    {
                        x_score++;
                        o_score = 0;
                    }

                    if(palya[i+k][j+k]->getSelect() == "")
                    {
                        x_score = 0;
                        o_score = 0;
                    }
                }
            }
            if(o_score>=5)
            {
                endGame("O nyert");
            }

            x_score = 0;
            o_score = 0;

            for(int k = 0; k < 5; k++)
            {
                if(i+k < palya.size() && j-k>=0)
                {
                    if(palya[i+k][j-k]->getSelect() == "o")
                    {
                        o_score++;
                        x_score = 0;
                    }

                    if(palya[i+k][j-k]->getSelect() == "x")
                    {
                        x_score++;
                        o_score = 0;
                    }

                    if(palya[i+k][j-k]->getSelect() == "")
                    {
                        x_score = 0;
                        o_score = 0;
                    }
                }
            }
            if(o_score>=5)
            {
                endGame("O nyert");
            }
        }
        x_score = 0;
        o_score = 0;
    }


    /// balra átlósan
    o_score = 0;
    x_score = 0;
    for(int i = 0; i < palya.size(); i++)
    {
        for(int j = 0; j < palya[i].size(); j++)
        {
            for(int k = 0; k < 5; k++)
            {
                if(i-k >= 0 && j-k >= 0)
                {
                    if(palya[i-k][j-k]->getSelect() == "x")
                    {
                        x_score++;
                        o_score = 0;
                    }
                    if(palya[i-k][j-k]->getSelect() == "o")
                    {
                        o_score++;
                        x_score = 0;
                    }
                    if(palya[i-k][j-k]->getSelect() == "")
                    {
                        x_score = 0;
                        o_score = 0;
                    }
                }
            }

            if(x_score>=5)
            {
                endGame("X nyert");
            }

            x_score = 0;
            o_score = 0;

            for(int k = 0; k < 5; k++)
            {
                if(i-k >= 0 && j-k >= 0)
                {
                    if(palya[i-k][j-k]->getSelect() == "x")
                    {
                        x_score++;
                        o_score = 0;
                    }
                    if(palya[i-k][j-k]->getSelect() == "o")
                    {
                        o_score++;
                        x_score = 0;
                    }
                    if(palya[i-k][j-k]->getSelect() == "")
                    {
                        x_score = 0;
                        o_score = 0;
                    }
                }
            }
            if(x_score>=5)
            {
                endGame("X nyert");
            }

            x_score = 0;
            o_score = 0;

            for(int k = 0; k < 5; k++)
            {
                if(i-k >= 0 && j+k<palya[i].size())
                {
                    if(palya[i-k][j+k]->getSelect() == "o")
                    {
                        o_score++;
                        x_score = 0;
                    }

                    if(palya[i-k][j+k]->getSelect() == "x")
                    {
                        x_score++;
                        o_score = 0;
                    }

                    if(palya[i-k][j+k]->getSelect() == "")
                    {
                        x_score = 0;
                        o_score = 0;
                    }
                }
            }
            if(o_score>=5)
            {
                endGame("O nyert");
            }

            x_score = 0;
            o_score = 0;

            for(int k = 0; k < 5; k++)
            {
                if(i-k >= 0 && j+k<palya[i].size())
                {
                    if(palya[i-k][j+k]->getSelect() == "o")
                    {
                        o_score++;
                        x_score = 0;
                    }

                    if(palya[i-k][j+k]->getSelect() == "x")
                    {
                        x_score++;
                        o_score = 0;
                    }

                    if(palya[i-k][j+k]->getSelect() == "")
                    {
                        x_score = 0;
                        o_score = 0;
                    }
                }
            }
            if(o_score>=5)
            {
                endGame("O nyert");
            }
        }
        x_score = 0;
        o_score = 0;
    }

}


void Application::checkDraw(vector<vector<Widget*> > palya)
{
    bool dontetlen = true;

    for(int i = 0; i < palya.size(); i++)
    {
        for(int j = 0; j < palya[i].size(); j++)
        {
            if(palya[i][j]->getSelect() == "")
            {
                dontetlen = false;
            }
        }
    }
    if(dontetlen)
    {
        endGame("Döntetlen");
    }

}

void Application::endGame(string message)
{
    gout << color(255,255,255) << move_to(0,0) << box(150,75);
    gout << color(0,0,0) << move_to(15,25) << text(message);
    gout << color(0,0,0) << move_to(15,50) << text("ESC a menübe");
    nyert = true;
}

void Application::valaszt()
{
    palya[rand()%10][rand()%10]->gepValaszt();
}

