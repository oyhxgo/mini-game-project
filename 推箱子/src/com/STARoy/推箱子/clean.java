package com.STARoy.推箱子;

import java.io.IOException;

public class clean {
        public static void clearScreen() {
            try {
                String os = System.getProperty("os.name");
                if (os.contains("Windows")) {
                    new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
                } else {
                    Runtime.getRuntime().exec("clear");
                }
            } catch (IOException | InterruptedException e) {
                e.printStackTrace();
                System.out.println(123);
            }
        }
}
