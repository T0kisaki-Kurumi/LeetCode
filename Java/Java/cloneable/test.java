package cloneable;

/**
 * @author robbie
 * @date Created in 2024/08/13
 */

class A {
    @Override
    public Object clone() throws CloneNotSupportedException {
        return super.clone();
    }
}

class B implements Cloneable {
    @Override
    public Object clone() throws CloneNotSupportedException {
        return super.clone();
    }
}

public class test {
    public static void main(String[] args) throws CloneNotSupportedException {
//        A a1 = new A();
//        A a2 = (A) a1.clone();
        B b1 = new B();
        B b2 = (B) b1.clone();
    }

}
