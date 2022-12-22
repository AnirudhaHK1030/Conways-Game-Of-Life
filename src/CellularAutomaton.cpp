#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<fstream>

#include "CellularAutomaton.h"

CellularAutomaton::CellularAutomaton(std::string fileName, int qState){
   //printf("begin");
   
    int cellValue;
    this->fileName=fileName;
    this->qState=qState; 
  

    // int x=500;
    // this->ca_data=new unsigned char*[x];
    std::ifstream myFile;
    myFile.open(fileName);
    myFile>>this->height;
  //  printf("%d ", this->height);
    myFile>>this->width;
   // printf("%d ", this->width);
    wrap=true;

      this->ca_data=(unsigned char **)calloc(this->height,sizeof(char *));
      this->ca_data[0]=(unsigned char *)calloc(this->width,sizeof(char));
      for(int i=1;i<this->height;i++){
        //  this->ca_data[i]=this->ca_data[0]+(this->width*i);
        this->ca_data[i]=(unsigned char *)calloc(this->width,sizeof(char));
      }

    //     int x=500;
    //   this->ca_data=new unsigned char*[x];

      for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            this->ca_data[i][j]=qState;
          //  printf("%u ",(unsigned int)this->ca_data[i][j]);
        }
    }

  //  printf("Assign values");
   // printf("\n");    
        for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            myFile>>cellValue;
          //  printf("%c ",cellValue);
            this->ca_data[i][j]=cellValue;
             // printf("%u ",(unsigned int)this->ca_data[i][j]);
        }
        //printf("\n");
    }

}


 CellularAutomaton::CellularAutomaton(const CellularAutomaton &obj){

      int cellValue;
      fileName=obj.fileName;
      qState=obj.qState;
      std::ifstream myFile;
      myFile.open(fileName);
      myFile>>this->height;
      myFile>>this->width;
    //   for(int i=0;i<height;i++){
    //     for(int j=0;j<width;j++){
    //         this->ca_data[i][j]=qState;
    //     }
    // }

    this->ca_data=(unsigned char **)calloc(this->height,sizeof(char *));
    this->ca_data[0]=(unsigned char *)calloc(this->width,sizeof(char));
    for(int i=1;i<this->height;i++){
     //   this->ca_data[i]=this->ca_data[0]+(this->width*i);
    this->ca_data[i]=(unsigned char *)calloc(this->width,sizeof(char));

  


    }
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            myFile>>cellValue;
            this->ca_data[i][j]=cellValue;
        }
    }
 }


 CellularAutomaton::~CellularAutomaton(){
        for(int i=0;i<width;i++){
              free(ca_data[i]);
        }         
         free(ca_data);
 }


CellularAutomaton& CellularAutomaton::operator=(const CellularAutomaton& ca){
    int cellValue;
    this->fileName=ca.fileName;
    this->qState=ca.qState;
    std::ifstream myFile;
    myFile.open(fileName);
    myFile>>this->height;
    myFile>>this->width;
    // for(int i=0;i<height;i++){
    //     for(int j=0;j<width;j++){
    //         this->ca_data[i][j]=qState;
    //     }
    // }

      this->ca_data=(unsigned char **)calloc(this->height,sizeof(char *));
      this->ca_data[0]=(unsigned char *)calloc(this->width,sizeof(char));//sizeof(char));
      for(int i=1;i<this->height;i++){
        //  this->ca_data[i]=this->ca_data[0]+(this->width*i);
       this->ca_data[i]=(unsigned char *)calloc(this->width,sizeof(char));
      }

    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            myFile>>cellValue;
            this->ca_data[i][j]=cellValue;
        }
    } 

    return *this;
}


void CellularAutomaton::step(unsigned char(*rule)(CellularAutomaton *c, int x, int y)){
    
    CellularAutomaton ca=*this;
    int i,j;
    for(i = 0 ; i < ca.height;i++){
        for(j = 0;j< ca.width;j++){
           //printf("%u ",ca.ca_data[i][j]);
           ca.ca_data[i][j] =this->ca_data[i][j]; 
          // printf("%u %u | ",ca.ca_data[i][j],this->ca_data[i][j]);
        }
       // printf("\n");
    }

    
    for(i = 0 ; i < ca.height;i++){
        for(j = 0;j< ca.width;j++){
           //printf("%u ",ca.ca_data[i][j]);
           this->ca_data[i][j] = rule(&ca,i,j);
          // printf("%u %u | ",ca.ca_data[i][j],this->ca_data[i][j]);
        }
       // printf("\n");
    }

    //free(&ca);
    //ca.~CellularAutomaton();

}

void CellularAutomaton::display(GraphicsClient &gc){
    int m;
    int cellSize;
    int cellGap;
    int xInd=0;
    int yInd=0;
    m=std::max(height,width);

    if(m>200 && m<=600){
        cellSize=1;
        cellGap=0;
    }
    else if(m>100 && m<=200){
        cellSize=2;
        cellGap=1;
    }
    else if(m>50 && m<=100){
        cellSize=4;
        cellGap=1;
    }
    else{
        cellSize=10;
        cellGap=2;
    }

  //  printf("%d %d ", height, width);
    gc.setBackgroundColor(0,0,0);
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
             xInd=i*(cellSize+cellGap);
             yInd=j*(cellSize+cellGap);
           
            if(ca_data[i][j]==0){
              //  gc.drawRectangle(xInd,yInd,cellSize+cellGap,cellSize+cellGap);
              //gc.clear();
                
            }
            else{    
               //  gc.drawRectangle(yInd,xInd,cellSize+cellGap,cellSize+cellGap);
                 gc.fillRectangle(yInd,xInd,cellSize,cellSize);
                //gc.drawLine(xInd,yInd,cellSize+cellGap,cellSize+cellGap);
                
                
            }  
        }
        gc.repaint();
       
       
    }

}

int CellularAutomaton::getHeight(){
    return this->height;
}

int CellularAutomaton::getWidth(){
    return this->width;
}

unsigned char ** CellularAutomaton::getCA(){
    return this->ca_data;
}

int CellularAutomaton::getValue(int i,int j){
    return this->ca_data[i][j];
}

