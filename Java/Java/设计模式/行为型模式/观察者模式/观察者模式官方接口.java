package 设计模式.行为型模式.观察者模式;

import java.util.Observable;
import java.util.Observer;

/**
 * @author robbie
 * @date Created in 2024/08/16
 */

class Decimal extends Observable {

    private int value;

    public void setValue(int value) {
        this.value = value;
        System.out.println("Decimal value changed to " + value);
        setChanged();
        notifyObservers(value);
    }
}

class Binary implements Observer {
    @Override
    public void update(Observable o, Object arg) {
        if(o instanceof Decimal){
            System.out.println("Binary value : " + Integer.toBinaryString((int)arg));
        }
    }
}

class Octal implements Observer {
    @Override
    public void update(Observable o, Object arg) {
        if(o instanceof Decimal){
            System.out.println("Octal value : " + Integer.toOctalString((int)arg));
        }
    }
}

class Hexadecimal implements Observer {
    @Override
    public void update(Observable o, Object arg) {
        if(o instanceof Decimal){
            System.out.println("Hexadecimal value : " + Integer.toHexString((int)arg));
        }
    }
}

public class 观察者模式官方接口 {
    public static void main(String[] args) {
        Decimal decimal = new Decimal();
        decimal.addObserver(new Binary());
        decimal.addObserver(new Octal());
        decimal.addObserver(new Hexadecimal());

        decimal.setValue(10);
        decimal.setValue(3463637);
    }
}
