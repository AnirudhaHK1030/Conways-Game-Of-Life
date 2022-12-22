#ifndef _CellularAutomatoh_H_
#define _CellularAutomatoh_H_

#include "GraphicsClient.h"

#include<iomanip>
#include<iostream>
#include<stdio.h>

class CellularAutomaton{

    private:
    int height;
    int width;
    int qState;
    std::string fileName;
    unsigned char **ca_data;
    bool wrap;

    public:
  
    CellularAutomaton(std::string, int);
    CellularAutomaton& operator=(const CellularAutomaton& ca);
    ~CellularAutomaton();
    CellularAutomaton(const CellularAutomaton&);
    void display(GraphicsClient &);
    void step(unsigned char (*rule)(CellularAutomaton *,int,int));
    int getHeight();
    int getWidth();
    unsigned char ** getCA();
    int getValue(int,int);

};

#endif
