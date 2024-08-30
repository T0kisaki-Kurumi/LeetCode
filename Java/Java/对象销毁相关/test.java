package 对象销毁相关;

/**
 * @author robbie
 * @date Created in 2024/08/15
 */

class A {}

class B{
    private A a;
    public B(A a){}
}

class Test1{
    // 非静态方法不返回
    public void f1(){
        A a = new A();
        B b = new B(a);
    }

    // 非静态方法返回
    public B f2(){
        A a = new A();
        B b = new B(a);
        return b;
    }

    // 静态方法不返回
    public static void f3(){
        A a = new A();
        B b = new B(a);
    }

    // 静态方法返回
    public static B f4(){
        A a = new A();
        B b = new B(a);
        return b;
    }
}

public class test {
    public static void main(String[] args) {
        Test1 t = new Test1();
        t.f1();
        t.f2();
        Test1.f3();
        Test1.f4();
    }
}
