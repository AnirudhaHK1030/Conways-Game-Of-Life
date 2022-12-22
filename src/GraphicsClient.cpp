#include<iostream>
#include<iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "GraphicsClient.h"


using namespace std;

GraphicsClient::GraphicsClient(std::string url,int portNum){
    this->url=url;
    this->portNum=portNum;
    this->sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
        fprintf( stderr, "Error creating socket\n");
        exit(-1);
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portNum);

    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
        fprintf(stderr, "Invalid address/ Address not supported \n");
        exit(-1);
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        fprintf(stderr, "Connection Failed \n");
        exit(-1);
    }
}

GraphicsClient::GraphicsClient(const GraphicsClient&obj){
    
    if(this != &obj){
        url=obj.url;
        portNum=obj.portNum;
    }

    this->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        fprintf( stderr, "Error creating socket\n");
        exit(-1);
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portNum);

    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
        fprintf(stderr, "Invalid address/ Address not supported \n");
        exit(-1);
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        fprintf(stderr, "Connection Failed \n");
        exit(-1);
    }
}


GraphicsClient::~GraphicsClient(){
    close(sockfd);
}


GraphicsClient& GraphicsClient::operator=(const GraphicsClient& gc){

    close(sockfd);

    if(this!=&gc){

        this->url=gc.url;
        this->portNum=gc.portNum; 
    }

    this->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        fprintf( stderr, "Error creating socket\n");
        exit(-1);
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portNum);

    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
        fprintf(stderr, "Invalid address/ Address not supported \n");
        exit(-1);
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        fprintf(stderr, "Connection Failed \n");
        exit(-1);
    }

    return *this;
}


void GraphicsClient::setBackgroundColor(int red,int green,int blue){
    
    message[0]=0xFF;
    message[1]=0x00;
    message[2]=0x00;
    message[3]=0x00;
    message[4]=0x07;
    message[5]=0x02;
    message[6]=(red>>4)&0x0F;
    message[7]=(red)&0x0F;
    message[8]=(green>>4)&0x0F;
    message[9]=(green)&0x0F;
    message[10]=(blue>>4)&0x0F;
    message[11]=(blue)&0x0F;

    send(sockfd,message,12,0);

    // message[4] = 0x01;
    // message[5] = 0x01;
    // send(sockfd, message, 6, 0);

    // message[5] = 0x0C;
    // send( sockfd, message, 6, 0);
}


void GraphicsClient::setDrawingColor(int red,int green,int blue){
    message[0]=0xFF;
    message[1]=0x00;
    message[2]=0x00;
    message[3]=0x00;
    message[4]=0x07;
    message[5]=0x06;
    message[6]=(red)&0x0F;
    message[7]=(red>>4)&0x0F;
    message[8]=(green)&0x0F;
    message[9]=(green>>4)&0x0F;
    message[10]=(blue)&0x0F;
    message[11]=(blue>>4)&0x0F;
    send(sockfd,message,12,0);

    // message[4] = 0x01;
    // message[5] = 0x01;
    // send(sockfd, message, 6, 0);

    // message[5] = 0x0C;
    // send( sockfd, message, 6, 0);
}

void GraphicsClient::setPixel(int xCoord, int yCoord, int red, int green, int blue){
    message[0]=0xFF;
    message[1]=0x00;
    message[2]=0x00;
    message[3]=0x00;
    message[4]=0x0F;
    message[5]=0x03; //0x03
    message[6]=(xCoord>>12)&0x0F;
    message[7]=(xCoord>>8)&0x0F;
    message[8]=(xCoord>>4)&0x0F;
    message[9]=(xCoord)&0x0F;
    message[10]=(yCoord>>12)&0x0F;
    message[11]=(yCoord>>8)&0x0F;
    message[12]=(yCoord>>4)&0x0F;
    message[13]=(yCoord)&0x0F;
    message[14]=(red>>4)&0x0F;
    message[15]=(red)&0x0F;
    message[16]=(green>>4)&0x0F;
    message[17]=(green)&0x0F;
    message[18]=(blue>>4)&0x0F;
    message[19]=(blue)&0x0F;

    send(sockfd,message,20,0);

    // message[4] = 0x01;
    // message[5] = 0x01;
    // send(sockfd, message, 6, 0);

    // message[5] = 0x0C;
    // send( sockfd, message, 6, 0);
}

void GraphicsClient::clear(){

    message[0]=0xFF;
    message[1]=0x00;
    message[2]=0x00;
    message[3]=0x00;
    message[4]=0x01;
    message[5]=0x01;

     send(sockfd,message,6,0);

    //  message[4] = 0x01;
    // message[5] = 0x01;
    // send(sockfd, message, 6, 0);

    // message[5] = 0x0C;
    // send( sockfd, message, 6, 0);

}


void GraphicsClient::drawRectangle(int xCoord,int yCoord,int width,int height){
    message[0]=0xFF;
    message[1]=0x00;
    message[2]=0x00;
    message[3]=0x01;
    message[4]=0x01;
    message[5]=0x07;
    message[6]=(xCoord>>12)&0x0F;
    message[7]=(xCoord>>8)&0x0F;
    message[8]=(xCoord>>4)&0x0F;
    message[9]=(xCoord)&0x0F;
    message[10]=(yCoord>>12)&0x0F;
    message[11]=(yCoord>>8)&0x0F;
    message[12]=(yCoord>>4)&0x0F;
    message[13]=(yCoord)&0x0F;
    message[14]=(width>>12)&0x0F;
    message[15]=(width>>8)&0x0F;
    message[16]=(width>>4)&0x0F;
    message[17]=(width)&0x0F;
    message[18]=(height>>12)&0x0F;
    message[19]=(height>>8)&0x0F;
    message[20]=(height>>4)&0x0F;
    message[21]=(height)&0x0F;

     send(sockfd,message,22,0);

    //  message[4] = 0x01;
    // message[5] = 0x01;
    // send(sockfd, message, 6, 0);

    // message[5] = 0x0C;
    // send( sockfd, message, 6, 0);
 

}

void GraphicsClient::fillRectangle(int xCoord,int yCoord,int width,int height){
    message[0]=0xFF;
    message[1]=0x00;
    message[2]=0x00;
    message[3]=0x01;
    message[4]=0x01;
    message[5]=0x08;
    message[6]=(xCoord>>12)&0x0F;
    message[7]=(xCoord>>8)&0x0F;
    message[8]=(xCoord>>4)&0x0F;
    message[9]=(xCoord)&0x0F;
    message[10]=(yCoord>>12)&0x0F;
    message[11]=(yCoord>>8)&0x0F;
    message[12]=(yCoord>>4)&0x0F;
    message[13]=(yCoord)&0x0F;
    message[14]=(width>>12)&0x0F;
    message[15]=(width>>8)&0x0F;
    message[16]=(width>>4)&0x0F;
    message[17]=(width)&0x0F;
    message[18]=(height>>12)&0x0F;
    message[19]=(height>>8)&0x0F;
    message[20]=(height>>4)&0x0F;
    message[21]=(height)&0x0F;

     send(sockfd,message,22,0);

    //  message[4] = 0x01;
    // message[5] = 0x01;
    // send(sockfd, message, 6, 0);

    // message[5] = 0x0C;
    // send( sockfd, message, 6, 0);
 
}

void GraphicsClient::clearRectangle(int xCoord,int yCoord,int width ,int height){
   message[0]=0xFF;
    message[1]=0x00;
    message[2]=0x00;
    message[3]=0x01;
    message[4]=0x01;
    message[5]=0x09;
    message[6]=(xCoord>>12)&0x0F;
    message[7]=(xCoord>>8)&0x0F;
    message[8]=(xCoord>>4)&0x0F;
    message[9]=(xCoord)&0x0F;
    message[10]=(yCoord>>12)&0x0F;
    message[11]=(yCoord>>8)&0x0F;
    message[12]=(yCoord>>4)&0x0F;
    message[13]=(yCoord)&0x0F;
    message[14]=(width>>12)&0x0F;
    message[15]=(width>>8)&0x0F;
    message[16]=(width>>4)&0x0F;
    message[17]=(width)&0x0F;
    message[18]=(height>>12)&0x0F;
    message[19]=(height>>8)&0x0F;
    message[20]=(height>>4)&0x0F;
    message[21]=(height)&0x0F;

     send(sockfd,message,22,0);

    //  message[4] = 0x01;
    // message[5] = 0x01;
    // send(sockfd, message, 6, 0);

    // message[5] = 0x0C;
    // send( sockfd, message, 6, 0);
}


void GraphicsClient::drawOval(int xCoord, int yCoord, int width, int height){
    message[0]=0xFF;
    message[1]=0x00;
    message[2]=0x00;
    message[3]=0x01;
    message[4]=0x01;
    message[5]=0x0A;
    message[6]=(xCoord>>12)&0x0F;
    message[7]=(xCoord>>8)&0x0F;
    message[8]=(xCoord>>4)&0x0F;
    message[9]=(xCoord)&0x0F;
    message[10]=(yCoord>>12)&0x0F;
    message[11]=(yCoord>>8)&0x0F;
    message[12]=(yCoord>>4)&0x0F;
    message[13]=(yCoord)&0x0F;
    message[14]=(width>>12)&0x0F;
    message[15]=(width>>8)&0x0F;
    message[16]=(width>>4)&0x0F;
    message[17]=(width)&0x0F;
    message[18]=(height>>12)&0x0F;
    message[19]=(height>>8)&0x0F;
    message[20]=(height>>4)&0x0F;
    message[21]=(height)&0x0F;

     send(sockfd,message,22,0);

    //  message[4] = 0x01;
    // message[5] = 0x01;
    // send(sockfd, message, 6, 0);

    // message[5] = 0x0C;
    // send( sockfd, message, 6, 0);

}

void GraphicsClient::fillOval(int xCoord,int yCoord,int width,int height){
    message[0]=0xFF;
    message[1]=0x00;
    message[2]=0x00;
    message[3]=0x01;
    message[4]=0x01;
    message[5]=0x0B;
    message[6]=(xCoord>>12)&0x0F;
    message[7]=(xCoord>>8)&0x0F;
    message[8]=(xCoord>>4)&0x0F;
    message[9]=(xCoord)&0x0F;
    message[10]=(yCoord>>12)&0x0F;
    message[11]=(yCoord>>8)&0x0F;
    message[12]=(yCoord>>4)&0x0F;
    message[13]=(yCoord)&0x0F;
    message[14]=(width>>12)&0x0F;
    message[15]=(width>>8)&0x0F;
    message[16]=(width>>4)&0x0F;
    message[17]=(width)&0x0F;
    message[18]=(height>>12)&0x0F;
    message[19]=(height>>8)&0x0F;
    message[20]=(height>>4)&0x0F;
    message[21]=(height)&0x0F;

    send(sockfd,message,22,0);

    // message[4] = 0x01;
    // message[5] = 0x01;
    // send(sockfd, message, 6, 0);

    // message[5] = 0x0C;
    // send( sockfd, message, 6, 0);
 
}

void GraphicsClient::drawLine(int xCoord,int yCoord,int x1Coord,int y1Coord){
    message[0]=0xFF;
    message[1]=0x00;
    message[2]=0x00;
    message[3]=0x01;
    message[4]=0x01;
    message[5]=0xD;
    message[6]=(xCoord>>12)&0x0F;
    message[7]=(xCoord>>8)&0x0F;
    message[8]=(xCoord>>4)&0x0F;
    message[9]=(xCoord)&0x0F;
    message[10]=(yCoord>>12)&0x0F;
    message[11]=(yCoord>>8)&0x0F;
    message[12]=(yCoord>>4)&0x0F;
    message[13]=(yCoord)&0x0F;
    message[14]=(x1Coord>>12)&0x0F;
    message[15]=(x1Coord>>8)&0x0F;
    message[16]=(x1Coord>>4)&0x0F;
    message[17]=(x1Coord)&0x0F;
    message[18]=(y1Coord>>12)&0x0F;
    message[19]=(y1Coord>>8)&0x0F;
    message[20]=(y1Coord>>4)&0x0F;
    message[21]=(y1Coord)&0x0F;
    
    send(sockfd,message,22,0);

    // message[4] = 0x01;
    // message[5] = 0x01;
    // send(sockfd, message, 6, 0);

    // message[5] = 0x0C;
    // send( sockfd, message, 6, 0);
}

// void GraphicsClient::drawString(int xCoord, int yCoord, std::string ){
//     message[0]=0xFF;
//     message[1]=0x00;
//     message[2]=0x00;
//     message[3]=0x01;
//     message[4]=0x01;
//     message[5]=0x05;
//     message[6]=(xCoord>>12)&0x0F;
//     message[7]=(xCoord>>8)&0x0F;
//     message[8]=(xCoord>>4)&0x0F;
//     message[9]=(xCoord)&0x0F;
//     message[10]=(yCoord>>12)&0x0F;
//     message[11]=(yCoord>>8)&0x0F;
//     message[12]=(yCoord>>4)&0x0F;
//     message[13]=(yCoord)&0x0F;
//}

void GraphicsClient::repaint(){
    message[0]=0xFF;
    message[1]=0x00;
    message[2]=0x00;
    message[3]=0x00;
    message[4]=0x01;
    message[5]=0x0C;

    send(sockfd,message,6,0);

}





