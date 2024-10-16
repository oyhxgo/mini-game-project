package com.STARoy.推箱子;

import java.sql.SQLOutput;
import java.util.Random;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        String again="y";
        while (again.equals("y")||again.equals("r")) {
            String wall[][] = initalize.initalize1();//initalize初始化墙壁
            Display.display(wall);
            // 初始位置wall[14][7] = "&";
            int i = 14, j = 7, flag = 1;
            boolean bool = true;
            while (bool) {
                System.out.println("使用w（向上)，s(向下),a(向左)，d(向右)，请键入操作:");
                Scanner scanner = new Scanner(System.in);
                String input = scanner.nextLine();
                if (input.equals("s") && i == 14 && j == 7) {
                    System.out.println("臣早已无路可退，身不由己啊~~~");
                    continue;
                }
                if ((!input.equals("s")) && (!input.equals("a")) && (!input.equals("d")) && (!input.equals("w"))) {
                    System.out.println("你这是要我往哪呀~~~");
                    continue;
                }
                switch (input) {
                    case "w": {
                        if (wall[i - 1][j] == " ") {
                            System.out.println("您向上狗了一步....");
                            wall[i][j] = " ";
                            wall[--i][j] = "&";
                        }
                        //成功了
                        else if (wall[i - 1][j] == "O") {
                            if (wall[i - 2][j] == "@") {
                                bool = false;
                                wall[i][j] = " ";
                                wall[--i][j] = "&";
                                wall[i - 1][j] = "囍";
                                System.out.println("前程似锦，恭喜闯关成功");
                                break;
                            }
                            //普通情况
                            else if (wall[i - 2][j] == " ") {
                                wall[i][j] = " ";
                                wall[--i][j] = "&";
                                wall[i - 1][j] = "O";
                            }
                            //失败了
                            //情况较为复杂，还待思考
                            else if (wall[i - 2][j] == "H") {
                                flag = 0;
                                bool = false;
                                wall[i][j] = " ";
                                wall[--i][j] = "&";
                                wall[i - 1][j] = "败";
                                System.out.println("可惜不是你，陪我到最后~~");
                                break;
                            }
                        }
                        //否则输出
                        else {
                            System.out.println("走不了了，孩子！！！");
                        }
                        break;
                    }
                    case "s": {
                        if (wall[i + 1][j] == " ") {
                            System.out.println("您向下跳了一步....");
                            wall[i][j] = " ";
                            wall[++i][j] = "&";
                        } else if (wall[i + 1][j] == "O") {
                            if (wall[i + 2][j] == "@") {
                                bool = false;
                                wall[i][j] = " ";
                                wall[++i][j] = "&";
                                wall[i + 1][j] = "囍";
                                System.out.println("功成名就，闯关成功，期待您再创辉煌！！！");
                                break;
                            } else if (wall[i + 2][j] == " ") {
                                wall[i][j] = " ";
                                wall[++i][j] = "&";
                                wall[i + 1][j] = "O";
                            } else if (wall[i + 2][j] == "H") {
                                flag = 0;
                                bool = false;
                                wall[i][j] = " ";
                                wall[++i][j] = "&";
                                wall[i + 1][j] = "败";
                                System.out.println("失败是竞争中不可避免的一部分。");
                                break;
                            }
                        }
                        //否则输出
                        else {
                            System.out.println("啊啊，痛死我啦~");
                        }
                        break;
                    }
                    case "a": {
                        if (wall[i][j - 1] == " ") {
                            System.out.println("您向左ji了一步....");
                            wall[i][j] = " ";
                            wall[i][--j] = "&";
                        } else if (wall[i][j - 1] == "O") {
                            if (wall[i][j - 2] == "@") {
                                bool = false;
                                wall[i][j] = " ";
                                wall[i][--j] = "&";
                                wall[i][j - 1] = "囍";
                                System.out.println("恭喜你，闯关成功！你的勇气和智慧令人敬佩。");
                                break;
                            } else if (wall[i][j - 2] == " ") {
                                wall[i][j] = " ";
                                wall[i][--j] = "&";
                                wall[i][j - 1] = "O";
                            } else if (wall[i][j - 2] == "H") {
                                flag = 0;
                                bool = false;
                                wall[i][j] = " ";
                                wall[i][--j] = "&";
                                wall[i][j - 1] = "败";
                                System.out.println("人生最大的悲哀或许就是如此凄凉，让我还没有开始就被判出局。");
                                break;
                            }
                        }
                        //否则输出
                        else {
                            System.out.println("人生总是会碰壁的，重要的是跌倒之后再次站起来");
                        }
                        break;
                    }
                    case "d": {
                        if (wall[i][j + 1] == " ") {
                            System.out.println("您向右嘻嘻了一步....");
                            wall[i][j] = " ";
                            wall[i][++j] = "&";
                        } else if (wall[i][j + 1] == "O") {
                            if (wall[i][j + 2] == "@") {
                                bool = false;
                                wall[i][j] = " ";
                                wall[i][++j] = "&";
                                wall[i][j + 1] = "囍";
                                System.out.println("闯关成功，这是你努力和智慧的结晶，恭喜你取得了这一阶段性的胜利！");
                                break;
                            } else if (wall[i][j + 2] == " ") {
                                wall[i][j] = " ";
                                wall[i][++j] = "&";
                                wall[i][j + 1] = "O";
                            } else if (wall[i][j + 2] == "H") {
                                flag = 0;
                                bool = false;
                                wall[i][j] = " ";
                                wall[i][++j] = "&";
                                wall[i][j + 1] = "败";
                                System.out.println("减挫了自己的智商，嘻嘻嘻，看来无法发挥全部实力啦");
                                break;
                            }
                        }
                        //否则输出
                        else {
                            System.out.println("别撞啦，迟早被你害死！！！！");
                        }
                        break;
                    }
                }
                //屏幕要清除
                //画面重新打印
                Display.display(wall);
            }
            if (flag == 1) {
                System.out.println("今宵有酒今宵醉，恭喜你闯关成功！！！");
                System.out.println("这次是本主宰的失误，再给本主宰一次机会吧！");
                System.out.println("输入y继续前进！！！");
            }
            else {
                System.out.println("孩子，还得多练！！！");
                System.out.println("小老弟，要继续挑战本主宰吗？");
                System.out.println("输入r重新再来！！！");
            }

            Scanner scanner = new Scanner(System.in);
            again=scanner.nextLine();
        }
    }
}
