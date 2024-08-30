package 设计模式.创建型模式.建造者模式;

import java.util.ArrayList;
import java.util.List;

/**
 * @author robbie
 * @date Created in 2024/08/13
 */

interface Packing {
    public String packing();
}

class Wrapper implements Packing {
    @Override
    public String packing() {
        return "Wrapper";
    }
}

class Bottle implements Packing {
    @Override
    public String packing() {
        return "Bottle";
    }
}

interface Item {
    public String name();
    public Packing packing();
    public float price();
}

abstract class Food implements Item {
    @Override
    public Packing packing(){
        return new Wrapper();
    }
}

class Rice extends Food {

    @Override
    public String name() {
        return "rice";
    }

    @Override
    public float price() {
        return 11.4f;
    }
}

class Noodle extends Food {

    @Override
    public String name() {
        return "noodle";
    }

    @Override
    public float price() {
        return 51.4f;
    }
}

abstract class Drink implements Item {
    @Override
    public Packing packing(){
        return new Bottle();
    }
}

class Cola extends Drink {

    @Override
    public String name() {
        return "cola";
    }

    @Override
    public float price() {
        return 19.1f;
    }
}

class Juice extends Drink {

    @Override
    public String name() {
        return "juice";
    }

    @Override
    public float price() {
        return 98.10f;
    }
}

class Meal {
    private List<Item> items = new ArrayList<>();

    public void addItem(Item item) {
        items.add(item);
    }

    public void show(){
        for (Item item : items) {
            System.out.println(item.name() + " " + item.packing().packing() + " " + item.price());
        }
    }

    public float getTotalPrice(){
        float total = 0;
        for (Item item : items) {
            total += item.price();
        }
        return total;
    }
}

class MealBuilder {
    public Meal Taocan1(){
        Meal meal = new Meal();
        meal.addItem(new Rice());
        meal.addItem(new Cola());
        return meal;
    }

    public Meal Taocan2(){
        Meal meal = new Meal();
        meal.addItem(new Noodle());
        meal.addItem(new Juice());
        return meal;
    }
}

public class 建造者模式 {
    public static void main(String[] args) {
        Meal meal1 = new MealBuilder().Taocan1();
        Meal meal2 = new MealBuilder().Taocan2();
        meal1.show();
        System.out.println(meal1.getTotalPrice());
        meal2.show();
        System.out.println(meal2.getTotalPrice());
    }
}
