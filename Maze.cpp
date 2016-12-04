//
//  Maze.cpp
//  Maze
//
//  Created by Ricardo on 2016/11/15.
//  Copyright © 2016年 Ricardo. All rights reserved.
//

#include "Maze.hpp"
#include <iostream>
using namespace std;
Maze::Maze(){
    _row = 0;
    _column = 0;
    maze = NULL;
}

Maze::Maze(int row,int column){
    _row = row;
    _column = column;
    maze = new int*[row];
    for (int i = 0; i < row; i++) {
        maze[i] = new int[column];
    }
}

void Maze::init(){
    std::cout << "迷宫地图:" << std::endl;
    std::cout << "     ";
    for (int i = 0; i < _column; i++) {
        std::cout << i << "列 ";
    }
    cout << endl;
    for (int i = 0; i < _row; i++) {
        //cout << i << "行";
        for (int j = 0; j < _column; j++) {
            cin >> maze[i][j];
        }
    }
    
}

void Maze::init(int zero){
    for (int i = 0; i < _row; i++) {
        for (int j = 0; j < _column; j++) {
            maze[i][j] = zero;
        }
    }
}

void Maze::print(){
    for (int i = 0; i < _row; i++) {
        for (int j = 0; j < _column; j++) {
            cout << maze[i][j] << "  ";
        }
        cout << endl;
    }

}

int Maze::row() const{
    return this->_row;
}

int Maze::column() const{
    return this->_column;
}

int& Maze::operator()(int row,int column){
    return maze[row][column];
}


ostream& operator<< (ostream& o,Maze& maze){
    maze.print();
    return o;
}
