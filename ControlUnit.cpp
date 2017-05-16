#include "ControlUnit.h"
#include <string>
#include <iostream>
#include <conio2.h>
#include <time.h>
#include <windows.h>
#include <math.h>

using namespace std;

ControlUnit::ControlUnit()
{
    score = 0;
}

ControlUnit::~ControlUnit()
{
}

void ControlUnit::start()
{
    drawTable();
    srand(time(0));
    addTile();
    addTile();

    drawValues();
    int x0 = wherex(),y0 = wherey();
    gotoxy(35,6);
    cout << "Pontszam: ";
    gotoxy(46,6);
    cout << score;
    gotoxy(x0,y0);
}

void ControlUnit::core()
{
    int be, c = 0;
    int goal = 2048;
    bool noMoreSteps = false;
    while(((be = getch()) != 27) && (!contains(goal)) && !noMoreSteps)
    {
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
                t0.setTileAll(i,j,t.getTileValue(i,j));


        if((be == 'w') || (be == 'a') || (be == 's') || (be == 'd'))
        {
            merge(be, t);
            if(!(t==t0))
            {
                int x0 = wherex(), y0 = wherey();
                gotoxy(46,6);
                cout << score;
                gotoxy(x0,y0);
                Sleep(100);
                addTile();
            }
            drawValues();
        }
        else
            core();

        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                if((t.getTileValue(i,j) != t.getTileValue(i,j+1)) && (t.getTileValue(i,j) != t.getTileValue(i+1,j) )&& ((t.getTileValue(i,j) != 0) && (t.getTileValue(i,j+1) != 0) && (t.getTileValue(i+1,j) != 0)))
                    c++;

        if(c==9) noMoreSteps = true;
        c = 0;
        if(noMoreSteps) cout << "Vesztettel! :(" << endl;


    }

    if(contains(goal))
    {
        cout << "Gratulalok, nyertel! Akarod folytatni? (i/n)";
        int be0 = getch();
        switch(be0)
        {
        case 'i':
            core();
            goal *= 2;
            break;
        }
    }


}

void ControlUnit::merge(int irany, Table& t)
{
    Tile temp; //int temp;
    Tile tileArray[4]; //int v[4];
    int elojel = ((irany == 'w') || (irany == 'a')) ? 1 : -1; //-1 jobbra és fel
    int korr0 = ((irany == 'w') || (irany == 'a')) ? 1 : 2; //2-vel jobbra és fel
    int korr1 = ((irany == 'w') || (irany == 'a')) ? 0 : 3;

    for(int m = 0; m < 4; m++)
    {
        for(int l = 0; l < 4; l++)
        {
            if((irany == 'a') || (irany == 'd'))
            {
                tileArray[l] = t.getTile(m,l);
            }
            else
            {
                tileArray[l] = t.getTile(l,m);
            }
        }

        for(int i = 0; i < 3; i++)
        {
            for (int k = 0; k < 3; k++)
                for (int j = 0; j < 3; j++)
                {
                    if(tileArray[korr1+elojel*j].getValue() == 0)
                    {
                        temp = tileArray[korr1+elojel*j];
                        tileArray[korr1+elojel*j] = tileArray[korr0+elojel*j];
                        tileArray[korr0+elojel*j] = temp;
                    }
                }
            if(tileArray[korr1+elojel*i].getValue() == tileArray[korr0+elojel*i].getValue() && (tileArray[korr1+elojel*i].getValue() != 0 && tileArray[korr0+elojel*i].getValue() != 0))
            {
                tileArray[korr1+elojel*i] += tileArray[korr0+elojel*i];

                score += (log2(tileArray[korr1+elojel*i].getValue())-1)*tileArray[korr1+elojel*i].getValue();

                tileArray[korr0+elojel*i].setAll(0);

            }

        }

        for(int n = 0; n < 4; n++)
        {
            if((irany=='a') || (irany=='d'))
            {
                t.setTileAll(m,n,tileArray[n].getValue());
            }
            else
            {
                t.setTileAll(n,m,tileArray[n].getValue());
            }
        }

    }

}

void ControlUnit::drawTable()
{
    string line = "-------------------------\n";
    string cells = "|     |     |     |     |\n";

    for(int i = 0; i < 4; i++)
    {
        cout << line << cells << cells << cells << cells << cells;
    }

    cout << line;
}

void ControlUnit::drawValues()
{

    int orgPosX = wherex(), orgPosY = wherey();

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            textbackground(t.getTileColor(i,j));

            for(int k = 0; k < 5; k++)
            {
                gotoxy(2+j*6,k+2+i*6);
                cout << "     ";
            }

            switch(t.getTileLength(i,j))
            {
            case 1:
                gotoxy(4+j*6,4+i*6);
                break;
            case 2:
                gotoxy(3+j*6,4+i*6);
                break;
            case 3:
                gotoxy(3+j*6,4+i*6);
                break;
            case 4:
                gotoxy(3+j*6,4+i*6);
                break;
            case 5:
                gotoxy(2+j*6,4+i*6);
                break;
            }

            if(t.getTileLength(i,j) != 0)
            {
                textcolor(WHITE);
                cout << t.getTileValue(i,j);
            }
            else
            {
                gotoxy(2+j*6,4+i*6);
                cout << "     ";
            }

        }
    }

    textbackground(BLACK);
    textcolor(WHITE);
    gotoxy(orgPosX,orgPosY);
}

void ControlUnit::addTile()
{

    double x = (double)rand() / RAND_MAX;
    int posI = rand()%4, posJ = rand()%4, value = (x <= 0.25) ? 4: 2;

    if(t.getTileValue(posI,posJ) == 0)
        t.setTileAll(posI,posJ,value);
    else addTile();
}

bool ControlUnit::contains(int value)
{
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if(t.getTileValue(i,j) == value) return true;
    return false;
}

