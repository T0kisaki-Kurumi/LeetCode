package lambda表达式;

import java.util.Arrays;
import java.util.Comparator;

/**
 * @author robbie
 * @date Created in 2024/06/17
 */

@FunctionalInterface  //可以用lambda表达式改写的接口必须是函数式接口，即只有一个抽象方法的接口，可以用@FunctionalInterface注解进行标注
interface MyInterface {
    void method(int a, int b);
}

public class LambdaTest {
    public static void main(String[] args) {
        Integer[] arr = {1, 3, 2, 5, 4};
        Arrays.sort(arr, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o1 - o2;
            }
        });
        System.out.println(Arrays.toString(arr));
        Arrays.sort(arr, (o1, o2) -> o2 - o1);
        System.out.println(Arrays.toString(arr));

        myMethod(new MyInterface() {
            @Override
            public void method(int a, int b) {
                System.out.println(a + " + " + b + " = " + (a + b));
            }
        });

        myMethod((a, b) -> {
            System.out.println(a + " + " + b + " = " + (a + b));
        });
    }

    public static void myMethod(MyInterface myInterface) {
        myInterface.method(2, 3);
    }
}
