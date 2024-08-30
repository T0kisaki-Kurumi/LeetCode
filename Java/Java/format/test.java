package format;

/**
 * @author robbie
 * @date Created in 2024/07/31
 */

public class test {
    public static void main(String[] args) {
        String str = "CREATE PROCEDURE %s\\.%s\\(%s\\).*?END\n" +
                "';";
        String.format(str, 1,2,3);
    }
}
