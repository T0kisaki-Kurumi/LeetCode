package 设计模式.行为型模式.空对象模式;

import java.util.ArrayList;
import java.util.List;

/**
 * @author robbie
 * @date Created in 2024/08/16
 */

abstract class AbstractConsumer{
    protected String name;
    public abstract void showName();
    public abstract void buy();
}

class RealConsumer extends AbstractConsumer{
    public RealConsumer(String name){
        this.name = name;
    }

    @Override
    public void showName() {
        System.out.println(this.name);
    }

    @Override
    public void buy() {
        System.out.println(this.name + "买东西");
    }
}

class NullConsumer extends AbstractConsumer{

    @Override
    public void showName() {
        System.out.println("空");
    }

    @Override
    public void buy() {
        System.out.println("空");
    }
}

class ConsumerFactory{
    private static final List<String> consumerList = new ArrayList<>();
    static {
        consumerList.add("Robot");
        consumerList.add("Jack");
        consumerList.add("Tom");
    }

    public static AbstractConsumer getConsumer(String name){
        if(consumerList.contains(name)){
            return new RealConsumer(name);
        } else {
            return new NullConsumer();
        }
    }
}

public class 空对象模式 {
    public static void main(String[] args) {
        AbstractConsumer consumer1 = ConsumerFactory.getConsumer("Jack");
        consumer1.showName();
        consumer1.buy();

        AbstractConsumer consumer2 = ConsumerFactory.getConsumer("Tom");
        consumer2.showName();
        consumer2.buy();

        AbstractConsumer consumer3 = ConsumerFactory.getConsumer("Robot");
        consumer3.showName();
        consumer3.buy();

        AbstractConsumer consumer4 = ConsumerFactory.getConsumer("Alice");
        consumer4.showName();
        consumer4.buy();
    }
}
