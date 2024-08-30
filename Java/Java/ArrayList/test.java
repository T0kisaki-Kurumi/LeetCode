package ArrayList;

import java.util.ArrayList;
import java.util.List;

/**
 * @author robbie
 * @date Created in 2024/08/13
 */

public class test {
    private static <T> void show(List<T> list){
        for(T t:list){
            System.out.println(t);
        }
    }

    public static void main(String[] args) {
        List<String> list = new ArrayList<>();
        list.add("1");
        list.add("2");
        list.add("3");
        list.add("1");
        // 只会删掉第一个"1"，remove会根据内容而非引用来删除元素，因此如果是自定义类型的话，需要重写equals方法
        list.remove("1");
        show(list);
    }
}
