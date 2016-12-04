//
//  main.cpp
//  Maze
//
//  Created by Ricardo on 2016/11/15.
//  Copyright © 2016年 Ricardo. All rights reserved.
//

#include <iostream>
#include "Maze.hpp"
using namespace std;

int SeekPath(int x,int y,Maze& maze,Maze& mark){
    int g,h;
    int move[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    if(((y == maze.column()-1)&&(maze(x,y) == 0)&&(mark(x,y) == 1))
       ||((x == maze.row()-1)&&(maze(x,y) == 0)&&(mark(x,y) == 1))){
        return 1;
    }
    for (int i = 0; i < 4; i++) {
        g = x + move[i][0];
        h = y + move[i][1];
        if (g < maze.row() && h < maze.column() && maze(g,h) == 0 && mark(g,h) == 0) {
            mark(g,h) = 1;
            if (SeekPath(g, h, maze, mark)) {
                maze(g,h) = -1;
                return 1;
            }
        }
    }
    if (x == 1 && y == 1) {
        cout << "no path in Maze" << endl;
    }
    return 0;
}

void showPath(Maze& maze,int x,int y){
    cout << "迷宫路径" << endl;
     cout << "(" << x << "," << y << ")";
    for(int i = 0;i < maze.row();i++){
        for (int j = 0 ; j < maze.column(); j++) {
            if(maze(i,j) == -1) {
                cout << "--->";
                cout << "(" << i << "," << j << ")";
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    int row,column;
    cout << "请输入迷宫的行数：";
    cin >> row;
    cout << "请输入迷宫的列数：";
    cin >> column;
    Maze maze(row,column);
    maze.init();                      //初始化迷宫
    Maze mark(row,column);
    mark.init(0);                     //初始化标记迷宫
    int originX, originY;             //起点由用户设置
    cout << "请输入起点X坐标： ";
    cin >> originX;
    cout << "请输入起点Y坐标： ";
    cin >> originY;
    mark(originX,originY) = 1;
    SeekPath(originX, originY, maze, mark);
    showPath(maze,originX,originY);
    return 0;
}
 
