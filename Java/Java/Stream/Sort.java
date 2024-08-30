package Stream;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

/**
 * @author robbie
 * @date Created in 2024/07/26
 */
class Param{
    public Param(int x, String name){
        this.x = x;
        this.name = name;
    }

    public int x;
    public String name;
}

public class Sort {
    public static void main(String[] args) {
        List<Param> params = new ArrayList<Param>();
        params.add(new Param(3, "apple"));
        params.add(new Param(1, "orange"));
        params.add(new Param(7, "pear"));
        params.add(new Param(4, "pineapple"));
        params.forEach(param -> System.out.println(param.x));
        params = params.stream().sorted((p1, p2) -> p1.x - p2.x).collect(Collectors.toList());
        params.forEach(param -> System.out.println(param.x));
    }
}
