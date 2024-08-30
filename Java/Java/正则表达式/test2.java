package 正则表达式;

/**
 * @author robbie
 * @date Created in 2024/07/31
 */

public class test2 {
    public static void main(String[] args) {
        String str = "hello (world)";
        System.out.println(str);
        str = str.replaceAll("\\(", "\\\\(");
        System.out.println(str);
    }
}
