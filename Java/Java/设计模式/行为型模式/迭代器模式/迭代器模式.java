package 设计模式.行为型模式.迭代器模式;

/**
 * @author robbie
 * @date Created in 2024/08/16
 */

interface Iterator<T> {
    boolean next();
    T get();
}

interface Container<T> {
    Iterator<T> getIterator();
}

class MyContainer<T> implements Container<T> {
    T[] arr;

    public MyContainer(T[] arr) {
        this.arr = arr;
    }

    @Override
    public Iterator<T> getIterator() {
        return new MyIterator();
    }

    class MyIterator implements Iterator<T> {
        int index = -1;

        @Override
        public boolean next() {
            ++index;
            return index < arr.length;
        }

        @Override
        public T get() {
            return arr[index];
        }
    }
}

public class 迭代器模式 {
    public static void main(String[] args) {
        Container<String> container = new MyContainer<>(new String[]{"a", "b", "c"});
        Iterator<String> iterator = container.getIterator();
        while (iterator.next()) {
            System.out.println(iterator.get());
        }
    }
}
