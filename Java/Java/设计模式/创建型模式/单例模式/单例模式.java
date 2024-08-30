package 设计模式.创建型模式.单例模式;

/**
 * @author robbie
 * @date Created in 2024/08/13
 */

/**
 * 枚举类
 */
enum Singleton6 {
    INSTANCE;
}

/**
 * 线程不安全的懒汉模式
 */
class Singleton1 {
    private static Singleton1 instance;

    private Singleton1() {
    }

    public static Singleton1 getInstance() {
        if (instance == null) {
            instance = new Singleton1();
        }
        return instance;
    }
}

/**
 * 线程安全的懒汉模式
 */
class Singleton2 {
    private static Singleton2 instance;

    private Singleton2() {
    }

    public static synchronized Singleton2 getInstance() {
        if (instance == null) {
            instance = new Singleton2();
        }
        return instance;
    }
}

/**
 * 饿汉模式
 * 线程安全原理：饿汉模式在类加载时就创建了实例，并将其赋值给静态变量。类加载是线程安全的
 */
class Singleton3 {
    private static Singleton3 instance = new Singleton3();

    private Singleton3() {
    }

    public static Singleton3 getInstance() {
        return instance;
    }
}

/**
 * 双检锁（DCL）
 * 采用双锁机制，安全且在多线程情况下能保持高性能。注意单例前面需要加volatile关键字，禁止重排序优化
 * https://blog.csdn.net/bxg_kyjgs/article/details/128850906
 */
class Singleton4 {
    private static volatile Singleton4 instance;

    private Singleton4() {
    }

    public static Singleton4 getInstance() {
        if (instance == null) {
            synchronized (Singleton4.class) {
                if (instance == null) {
                    instance = new Singleton4();
                }
            }
        }
        return instance;
    }
}

/**
 * 静态内部类
 * 相比于普通的饿汉式，静态内部类在Singleton类被装载时，不会立即静态化，而是在需要实例化时，调用getInstance方法，才会装载SingletonHolder类，实现延迟加载。
 */
class Singleton5 {
    private Singleton5() {
    }

    public static Singleton5 getInstance() {
        return SingletonHolder.INSTANCE;
    }

    private static class SingletonHolder {
        private static final Singleton5 INSTANCE = new Singleton5();
    }
}

public class 单例模式 {
    public static void main(String[] args) {
        Singleton1 s1 = Singleton1.getInstance();
        Singleton1 s2 = Singleton1.getInstance();
        System.out.println(s1 == s2); // true
        Singleton2 s3 = Singleton2.getInstance();
        Singleton2 s4 = Singleton2.getInstance();
        System.out.println(s3 == s4); // true
        Singleton3 s5 = Singleton3.getInstance();
        Singleton3 s6 = Singleton3.getInstance();
        System.out.println(s5 == s6); // true
        Singleton4 s7 = Singleton4.getInstance();
        Singleton4 s8 = Singleton4.getInstance();
        System.out.println(s7 == s8); // true
        Singleton5 s9 = Singleton5.getInstance();
        Singleton5 s10 = Singleton5.getInstance();
        System.out.println(s9 == s10); // true
        Singleton6 s11 = Singleton6.INSTANCE;
        Singleton6 s12 = Singleton6.INSTANCE;
        System.out.println(s11 == s12); // true
    }
}
