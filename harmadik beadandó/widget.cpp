#include "application.hpp"

void kor(int x, int y, int r)
{
    for(int i = x-r; i<x+r; i++)
    {
        for(int j = y-r; j<y+r; j++)
        {
            if((i-x)*(i-x) + (j-y)*(j-y) <= r*r)
            {
                gout << move_to(i,j) << dot;
            }
        }
    }
}

Widget::Widget(Application* wiparent, int wix, int wiy, int wiw, int wih)
{
    this->wiparent=wiparent;
    this->wix=wix;
    this->wiy=wiy;
    this->wiw=wiw;
    this->wih=wih;
    folotte = false;
}

bool Widget::is_selected(int pos_x, int pos_y)
{
    if(pos_x>wix && pos_x<wix+wiw && pos_y>wiy && pos_y<wiy+wih)
    {
        folotte = true;
        return true;
    }
    else
    {
        folotte = false;
        return false;
    }
}

Button::Button(Application* wiparent, int wix, int wiy, int wiw, int wih, string szoveg) : Widget(wiparent,wix,wiy,wiw,wih)
{
    this->szoveg=szoveg;
}

void Button::handleTimer(event ev)
{
    show();
}
void Button::handleMouse(event ev,bool gep_ellen)
{
    if(ev.button == btn_left)
    {
        if(folotte)
        {
            action();
        }
    }
    if(ev.button == 0)
    {
        if(is_selected(ev.pos_x,ev.pos_y))
        {
            folotte = true;
        }
        else
        {
            folotte = false;
        }
    }
}
void Button::handleKeys(event ev)
{

}
void Button::show()
{
    if(folotte)
    {
        gout << color(0,0,205) << move_to(wix-5,wiy-5) << box(wiw+10,wih+10);
        gout << color(220,220,220) << move_to(wix,wiy) << box(wiw,wih);

        int sz_offset = gout.twidth(szoveg) / 2;
        gout << color(0,0,0) << move_to(wix+wiw/2-sz_offset,wiy+wih/2+5) << text(szoveg);
    }
    else
    {
        gout << color(120,120,120) << move_to(wix-5,wiy-5) << box(wiw+10,wih+10);
        gout << color(200,200,200) << move_to(wix,wiy) << box(wiw,wih);

        int sz_offset = gout.twidth(szoveg) / 2;
        gout << color(0,0,0) << move_to(wix+wiw/2-sz_offset,wiy+wih/2+5) << text(szoveg);
    }
}

void Button::action()
{
    if(szoveg=="Kilépés")
    {
        exit(0);
    }

    if(szoveg=="Új játék gép ellen (15x15)")
    {
        wiparent->jatek_gep_15();
    }

    if(szoveg=="Új játék ember ellen (15x15)")
    {
        wiparent->jatek_ember_15();
    }

    if(szoveg=="Új játék gép ellen (30x30)")
    {
        wiparent->jatek_gep_30();
    }

    if(szoveg=="Új játék ember ellen (30x30)")
    {
        wiparent->jatek_ember_30();
    }
}

string Button::getSelect()
{

}

void Button::gepValaszt()
{

}
Cube::Cube(Application* wiparent, int wix, int wiy, int wiw, int wih,int i, int j) : Widget(wiparent,wix,wiy,wiw,wih)
{
    marked = false;
    this->i=i;
    this->j=j;
    select = "";
}

void Cube::handleTimer(event ev)
{
    show();
}
void Cube::handleMouse(event ev,bool gep_ellen)
{
    if(ev.button == btn_left)
    {
        if(folotte && !marked)
        {
            action(gep_ellen);
        }
    }
    if(ev.button == 0)
    {
        if(is_selected(ev.pos_x,ev.pos_y))
        {
            folotte = true;
        }
        else
        {
            folotte = false;
        }
    }
}
void Cube::handleKeys(event ev)
{
    if(ev.keycode == key_escape)
    {
        wiparent->menu();
    }
}

void Cube::show()
{
    gout << color(120,120,120) << move_to(wix,wiy) << box(wiw,wih);
    gout << color(220,220,220) << move_to(wix+2,wiy+2) << box(wiw-4,wih-4);

    if(folotte)
    {
        gout << color(0,0,0) << move_to(wix,wiy) << box(wiw,wih);
        gout << color(220,220,220) << move_to(wix+2,wiy+2) << box(wiw-4,wih-4);
        if(marked)
        {
            if(select=="o")
            {
                gout << color(0,0,205) << move_to(wix,wiy) << box(wiw,wih);
                gout << color(220,220,220) << move_to(wix+2,wiy+2) << box(wiw-4,wih-4);

                gout << color (0,0,0);
                kor(wix+wiw/2,wiy+wih/2,wiw/2);
                gout << color(220,220,220);
                kor(wix+wiw/2,wiy+wih/2,wiw/3);
            }
            if(select=="x")
            {
                gout << color(205,0,0) << move_to(wix,wiy) << box(wiw,wih);
                gout << color(220,220,220) << move_to(wix+2,wiy+2) << box(wiw-4,wih-4);

                for(int i = 0; i < 5; i++)
                {
                    gout << color (0,0,0) <<move_to(wix-2+i,wiy) << line(wiw,wih) <<move_to(wix-2+i,wiy+wih) << line(wiw,-wih);
                }
            }

        }
    }
    else
    {
        if(marked)
        {
            if(select == "o")
            {
                gout << color(0,0,205) << move_to(wix,wiy) << box(wiw,wih);
                gout << color(220,220,220) << move_to(wix+2,wiy+2) << box(wiw-4,wih-4);

                gout << color (0,0,0);
                kor(wix+wiw/2,wiy+wih/2,wiw/2);
                gout << color(220,220,220);
                kor(wix+wiw/2,wiy+wih/2,wiw/3);
            }
            else if(select=="x")
            {
                gout << color(205,0,0) << move_to(wix,wiy) << box(wiw,wih);
                gout << color(220,220,220) << move_to(wix+2,wiy+2) << box(wiw-4,wih-4);

                for(int i = 0; i < 5; i++)
                {
                    gout << color (0,0,0) <<move_to(wix-2+i,wiy) << line(wiw,wih) <<move_to(wix-2+i,wiy+wih) << line(wiw,-wih);
                }
            }
        }
    }
}
void Cube::action(bool gep_ellen)
{
    if(gep_ellen)
    {
        marked = true;
        select = "x";
        Cube::Count++;
        //Sleep(1000);

        wiparent->valaszt();
    }
    else
    {
        marked = true;
        Cube::Count++;
        if(Cube::Count % 2 == 0)
        {
            select = "o";
        }
        else
        {
            select = "x";
        }
    }

}

string Cube::getSelect()
{
    return select;
}

void Cube::gepValaszt()
{
    marked = true;
    Cube::Count++;
    select = "o";
}





