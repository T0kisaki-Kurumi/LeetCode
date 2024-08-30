package 设计模式.行为型模式.观察者模式;

import java.util.ArrayList;
import java.util.List;

/**
 * @author robbie
 * @date Created in 2024/08/16
 * @description 观察者模式，java中有现成的Observable和Observer接口可以用
 */

class Subject {
    private List<MyObserver> observers = new ArrayList<>();

    private int state;

    public int getState() {
        return state;
    }

    public void setState(int state) {
        this.state = state;
        System.out.println("Subject state changed to " + state);
        notifyAllObservers();
    }

    protected void notifyAllObservers() {
        for (MyObserver observer : observers) {
            observer.update(this);
        }
    }

    public void registerObserver(MyObserver observer) {
        observers.add(observer);
    }

    public void deregisterObserver(MyObserver observer) {
        observers.remove(observer);
    }
}

interface MyObserver {
    void update(Subject s);
}

class BinObserver implements MyObserver {
    @Override
    public void update(Subject s) {
        System.out.println("BinObserver : " + Integer.toBinaryString(s.getState()));
    }
}

class OctObserver implements MyObserver {
    @Override
    public void update(Subject s) {
        System.out.println("OctObserver : " + Integer.toOctalString(s.getState()));
    }
}

class HexObserver implements MyObserver {
    @Override
    public void update(Subject s) {
        System.out.println("HexObserver : " + Integer.toHexString(s.getState()));
    }
}

public class 观察者模式 {
    public static void main(String[] args) {
        Subject subject = new Subject();
        subject.registerObserver(new BinObserver());
        subject.registerObserver(new OctObserver());
        subject.registerObserver(new HexObserver());

        subject.setState(10);
        subject.setState(3463637);
    }
}
