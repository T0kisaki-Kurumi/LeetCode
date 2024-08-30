package 反射;

/**
 * @author robbie
 * @date Created in 2024/06/27
 */

public class 反射test {
    public static void main(String[] args) throws Exception {
        Class clazz = Class.forName("反射.testClass");
        System.out.println(clazz.getConstructor(int.class));
        System.out.println(clazz.getConstructor(Integer.class));
    }
}
