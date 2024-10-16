package com.STARoy.推箱子;

public class Display {
    public static void display(String[][] wall) {
        for (int i = 0; i < wall.length; i++) {
            for (int j = 0; j < wall.length; j++)
                System.out.print(wall[i][j]);
            System.out.println();
        }
    }
}
