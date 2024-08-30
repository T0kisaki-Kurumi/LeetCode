package 封装类;

/**
 * @author robbie
 * @date Created in 2024/06/27
 */

public class test {
    public static void main(String[] args) {
        Integer a = new Integer(1);
        Integer b = new Integer(1);
        Integer c = new Integer(1111111111);
        Integer d = new Integer(1111111111);
        Integer e = 1;
        Integer f = 1;
        Integer g = 1111111111;
        Integer h = 1111111111;
        System.out.println(a == b);
        System.out.println(c == d);
        System.out.println(e == f);
        System.out.println(g == h);
        System.out.println(a.equals(b));
        System.out.println(c.equals(d));
        System.out.println(e.equals(f));
        System.out.println(g.equals(h));
    }
}
