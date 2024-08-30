package 迭代器;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;
import java.util.ListIterator;

/**
 * @author robbie
 * @date Created in 2024/08/28
 */

public class test {
    // 在迭代器中，如果在遍历过程中对集合进行了修改（增加或删除元素），会导致ConcurrentModificationException
    static void test1() {
        List<Integer> list = new ArrayList<>();
        list.add(1);
        list.add(2);
        list.add(3);
        for (Integer i : list) {
            if (i == 2) {
//                list.add(4);
//                list.remove(3);
            }
        }
    }

    // 使用迭代器对象iterator()方法获取迭代器，在迭代过程中可以删除元素（但仍然不能添加，因为没这个方法）
    public static void test2() {
        List<Integer> list = new ArrayList<>();
        list.add(1);
        list.add(2);
        list.add(3);
        Iterator<Integer> iterator = list.iterator();
        while (iterator.hasNext()) {
            int i = iterator.next();
            if (i == 2) {
//                list.remove(3);
                iterator.remove();
            }
        }
    }

    // 使用ListIterator接口可以实现对集合的双向遍历
    // 初始时，ListIterator指向第一个元素的前一个位置，调用next()方法后指向最后一次迭代的元素后面的位置，调用previous()方法后指向最后一次迭代的元素前面的位置
    public static void test3() {
        List<Integer> list = new ArrayList<>();
        list.add(1);
        list.add(2);
        list.add(3);
        ListIterator<Integer> iterator = list.listIterator();
        while (iterator.hasNext()) {
            System.out.print(iterator.next() + " ");
        }
        while (iterator.hasPrevious()) {
            System.out.print(iterator.previous() + " ");
        }
        while (iterator.hasNext()) {
            System.out.print(iterator.next() + " ");
        }
        while (iterator.hasPrevious()) {
            System.out.print(iterator.previous() + " ");
        }
        System.out.println();
    }

    // ListIterator接口提供了对集合的双向遍历，并可以修改/删除/添加元素，注意修改/删除/添加的位置是相对于上一次迭代完的元素的位置
    // 尤其是add方法，用完next()方法和previous()方法之后add的位置是不一样的。因此使用一个未知的ListIterator对象时，直接使用add的结果是不确定的。
    // 特别注意，用完ListIterator的add方法之后迭代器会指向添加的元素的后面，而不是原来的位置！
    public static void test4() {
        List<Integer> list = new ArrayList<>();
        list.add(1);
        list.add(2);
        list.add(3);
        ListIterator<Integer> iterator = list.listIterator();
        while (iterator.hasNext()) {
            int i = iterator.next();
        }
        iterator.set(114);
        while (iterator.hasPrevious()) {
            int i = iterator.previous();
        }
        iterator.set(514);
        for (Integer i : list) {
            System.out.print(i + " ");
        }
        System.out.println();
        List<Integer> list2 = new ArrayList<>();
        list2.add(1);
        ListIterator<Integer> iterator2 = list2.listIterator();
        iterator2.next();
        iterator2.add(2);
        iterator2.previous();
        iterator2.previous();
        iterator2.add(3);
        for (Integer i : list2) {
            System.out.print(i + " ");
        }
    }

    public static void main(String[] args) {
        test1();
        test2();
        test3();
        test4();
    }
}
