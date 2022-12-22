#ifndef _GraphicsClient_H_
#define _GraphicsClient_H_
#include<iostream>
#include<iomanip>
#include <stdio.h>


class GraphicsClient{

private:
char message[100];
std::string url;
int portNum;
int sockfd;

public:

GraphicsClient(std::string,int);
GraphicsClient(const GraphicsClient &);
~GraphicsClient();
GraphicsClient& operator=(const GraphicsClient& gc);
//An equals operator
void setBackgroundColor(int , int , int );
void setDrawingColor(int , int , int );
void clear();
void setPixel(int, int, int, int, int);
void drawRectangle(int , int , int , int);
void fillRectangle(int , int , int , int );
void clearRectangle(int , int , int , int );
void drawOval(int , int , int , int );
void fillOval(int , int , int , int );
void drawLine(int , int , int , int );
void drawString(int , int , std::string );
void repaint();

};

#endif