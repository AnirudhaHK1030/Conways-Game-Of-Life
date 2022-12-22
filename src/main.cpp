#include <iostream>
#include <iomanip>
#include <stdio.h>

#include "GraphicsClient.h"
#include "CellularAutomaton.h"

unsigned char ruleOfLife(CellularAutomaton *ca, int x, int y)
{

    char setValue;
    int count = 0;

    //count the number of alive neighbors

    int x1 = x - 1;
    int x2 = x + 1;
    int y1 = y - 1;
    int y2 = y + 1;

    //Wrapping stuff around in order to get the correct values at each cell.

    if (x1 == -1)
    {
        x1 = ca->getHeight() - 1;
    }

    if (x2 == ca->getHeight())
    {
        x2 = 0;
    }

    if (y1 == -1)
    {
        y1 = ca->getWidth() - 1;
    }

    if (y2 == ca->getWidth())
    {
        y2 = 0;
    }

    if (ca->getValue(x1, y) == 1)
    { //done
        count += 1;
    }

    if (ca->getValue(x, y1) == 1)
    { //done
        count += 1;
    }

    if (ca->getValue(x1, y1) == 1)
    { //done
        count += 1;
    }

    if (ca->getValue(x2, y2) == 1)
    { //done
        count += 1;
    }

    if (ca->getValue(x2, y1) == 1)
    { //done
        count += 1;
    }

    if (ca->getValue(x2, y) == 1)
    { //done
        count += 1;
    }

    if (ca->getValue(x, y2) == 1)
    { //done
        count += 1;
    }

    if (ca->getValue(x1, y2) == 1)
    { //done
        count += 1;
    }

    //  printf("%d",count);

    //Implements the rules based on the Wiki page.

    if (ca->getValue(x, y) == 1 && (count == 0 || count == 1))
    {
        setValue = 0;
    }
    else if (ca->getValue(x, y) == 1 && (count == 2 || count == 3))
    {
        setValue = 1;
    }
    else if (ca->getValue(x, y) == 1 && (count > 3))
    {
        setValue = 0;
    }
    else if (ca->getValue(x, y) == 0 && count == 3)
    {
        setValue = 1;
    }
    else
    {
        setValue = 0;
    }
    return setValue;
}

int main(int argc, char *argv[])
{

    if (argc == 2)
    {

        //  printf("begin");
        CellularAutomaton *ca;
        // printf("start");
        ca = new CellularAutomaton(argv[1], 0);
        //printf("Created new Ca");
        GraphicsClient *gc = new GraphicsClient("127.0.0.1", 7777);
        //printf("Created new GC");
        ca->display(*gc);

        // printf("Displayed new Gc");

        // for(int i=0;i<ca->getHeight();i++){
        //     for(int j=0;j<ca->getWidth();j++){
        //         printf("%u ", ca->getValue(i,j));
        //     }

        //     printf("\n");
        //   }
       
        //  ca->step(ruleOfLife);      //call the rule on the CA

        //   for(int i=0;i<ca->getHeight();i++){
        //         for(int j=0;j<ca->getWidth();j++){
        //             printf("%u ", ca->getValue(i,j));
        //         }

        //         printf("\n");
        //   }
        // printf("Called rule");
        // ca->display(*gc);

        // printf("Called display after rule");

        //     for (int i = 0; i < ca->getHeight(); i++)
        //         {
        //             for (int j = 0; j < ca->getWidth(); j++)
        //             {
        //                 printf("%u ", ca->getValue(i, j));
        //             }

        //             printf("\n");
        //         }

        // ca->step(ruleOfLife);


        //      for (int i = 0; i < ca->getHeight(); i++)
        //         {
        //             for (int j = 0; j < ca->getWidth(); j++)
        //             {
        //                 printf("%u ", ca->getValue(i, j));
        //             }

        //             printf("\n");
        //         }

        //          ca->step(ruleOfLife);


        //      for (int i = 0; i < ca->getHeight(); i++)
        //         {
        //             for (int j = 0; j < ca->getWidth(); j++)
        //             {
        //                 printf("%u ", ca->getValue(i, j));
        //             }

        //             printf("\n");
        //         }

        //          ca->step(ruleOfLife);


        //      for (int i = 0; i < ca->getHeight(); i++)
        //         {
        //             for (int j = 0; j < ca->getWidth(); j++)
        //             {
        //                 printf("%u ", ca->getValue(i, j));
        //             }

        //             printf("\n");
        //         }




        while (1)
        {
            char ch;
            ch = fgetc(stdin);

            if (ch == '\n')
            {
                for (int i = 0; i < ca->getHeight(); i++)
                {
                    for (int j = 0; j < ca->getWidth(); j++)
                    {
                        printf("%u ", ca->getValue(i, j));
                    }

                    printf("\n");
                }

                ca->step(ruleOfLife); //call the rule on the CA
                gc->clear();
                 gc->repaint();
                ca->display(*gc);     //display again

            }
            else
            {
                exit(0);
            }
        }
    }
    else if (argc > 2)
    {
        printf("Too many arguments");
    }
    else
    {
        printf("Too few arguments");
    }
}

// #include <iostream>
// #include <stdio.h>
// #include <stdlib.h>
// #include <sys/socket.h>
// #include <arpa/inet.h>
// #include <unistd.h>
// #include <string.h>
// #include "GraphicsClient.h"

// using namespace std;

// int main(void) {
//     GraphicsClient* x = new GraphicsClient("127.0.0.1", 7777);

//   //  x -> drawString(120, 120, "DEFAULT");
//     x -> repaint();

//     cin.get();
//     x -> clear();
//     x -> repaint();

//     x -> setBackgroundColor(255, 165, 0);
//     x -> clear();
//   //  x -> drawString(120, 120, "SETTING BACKGROUND COLOR");
//     x -> repaint();

//   cin.get();

//     x -> setBackgroundColor(150,150 , 150 );
//     x -> clear();
//   //  x -> drawString(120, 120, "SETTING BACKGROUND COLOR");
//     x -> repaint();

//     cin.get();
//     x -> clear();
//     x -> repaint();

//     x -> setDrawingColor(0, 0, 0);
//     x -> clear();
//     x -> repaint();
//   //  x -> drawString(120, 120, "SETTING DRAWING COLOR (set to black)");
//     x -> repaint();

//     cin.get();
//     x -> clear();
//     x -> repaint();

//    // x -> drawString(120, 120, "DRAWING LINE");

//     x -> drawLine(120, 122, 210, 122);
//    printf("draw a line");
//    //x ->clear();
//    printf("Clear done");
//    cin.get();
//    x -> repaint();
//    printf("Clear done222");

//     cin.get();
//    x -> clear();

//    x -> repaint();
//   printf("Clear doneeeeeee");
//   cin.get();

//   x-> repaint();

//  x -> clear();
//   x -> setBackgroundColor(215,100,140);
//   x -> clear();
//   printf("Set bg");

//     x-> repaint();

//   printf("Repainted");
//   cin.get();

//   printf("called pixel");
//     x -> setPixel(140, 140, 0, 0, 0);
//     x -> setPixel(141, 141, 0, 0, 0);
//     x -> setPixel(142, 142, 0, 0, 0);
//     x -> setPixel(143, 143, 0, 0, 0);
//     x -> setPixel(144, 144, 0, 0, 0);
//   // x -> drawString(120, 120, "SETTING PIXELS");
//     x -> repaint();

//     cin.get();
//     x -> clear();
//     x -> repaint();

//     x -> drawRectangle(225, 225, 100, 100);
//     x -> fillRectangle(500, 225, 100, 100);
//   //  x -> drawString(120, 120, "DRAWING & FILLING RECTANGLES");
//     x -> repaint();

//     cin.get();

//     x -> clearRectangle(525, 250, 50, 50);
//     x -> clearRectangle(100, 100, 400, 40);
//     x -> clearRectangle(225, 225, 100, 100);
//    // x -> drawString(120, 120, "CLEARING RECTANGLES");
//     x -> repaint();

//     cin.get();
//     x -> clear();
//     x -> repaint();

//     x -> drawOval(225, 225, 100, 100);
//     x -> fillOval(350, 225, 100, 100);
//     x -> repaint();
//   //  x -> drawString(120, 120, "DRAWING & FILLING OVALS");
//     x -> repaint();

//     cin.get();
//     x -> clear();
// }