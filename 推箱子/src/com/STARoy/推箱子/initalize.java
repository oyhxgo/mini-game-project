package com.STARoy.推箱子;

import java.util.Random;

public class initalize {

    //1.0的初始化函数
    public static String[][] initalize1() {
        String wall[][] = new String[15][15];
        for (int i = 0; i < wall.length; i++) {
            for (int j = 0; j < wall.length; j++) {
                if (i == 0)
                    wall[i][j] = "H";//第一排都是H
                else if (i == wall.length - 1)//最后一排都是H
                    wall[i][j] = "H";
                else if (j == 0)//不是第一排，则第一个为H
                    wall[i][j] = "H";
                else if (j == wall[i].length - 1)//不是第一排，则最后一个为H
                    wall[i][j] = "H";
                else//其他都为空
                    wall[i][j] = " ";
            }
        }

        wall[14][7] = "&";
        //初始位置随机化
        Random temp= new Random(System.currentTimeMillis());
        //空出一围，防止出现无解的情况（1.0没有拉的功能）
        int start= temp.nextInt(2,12);
        int end= temp.nextInt(2,12);
        int start2=temp.nextInt(1,13),end2=temp.nextInt(1,13);
        //考虑重合
        while(start==start2){
            start2= temp.nextInt(1,13);
            end2= temp.nextInt(1,13);
        }
        wall[start][end] = "O";
        wall[start2][end2] = "@";
        return wall;
    }
}
