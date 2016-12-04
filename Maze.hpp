//
//  Maze.hpp
//  Maze
//
//  Created by Ricardo on 2016/11/15.
//  Copyright © 2016年 Ricardo. All rights reserved.
//

#ifndef Maze_hpp
#define Maze_hpp

#include <stdio.h>
#include <iostream>
using namespace std;
class Maze{
private:
    friend ostream& operator<<(ostream& ,Maze& );
    int _row;
    int _column;
    int** maze;
public:
    Maze();
    Maze(int row,int column);
    int row() const;
    int column() const;
    void init();
    void init(int zero);
    void print();
    int& operator()(int row,int column);
};

#endif /* Maze_hpp */
