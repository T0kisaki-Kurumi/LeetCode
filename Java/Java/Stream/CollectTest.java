package Stream;

import java.util.ArrayList;
import java.util.Collections;
import java.util.stream.Collectors;

/**
 * @author robbie
 * @date Created in 2024/06/17
 */

public class CollectTest {
    public static void main(String[] args) {
        ArrayList<String> list = new ArrayList<>();
        Collections.addAll(list, "apple-1", "banana-2", "orange-3", "pear-4");
        System.out.println(list);
        String[] arr = list.stream().map(s -> s.split("-")[1]).toArray(value -> new String[value]);
        for(String s : arr){
            System.out.println(s);
        }
        list.stream().map(s -> s.split("-")[0]).collect(Collectors.toList());
    }
}
