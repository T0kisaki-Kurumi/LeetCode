package 设计模式.行为型模式.策略模式;

/**
 * @author robbie
 * @date Created in 2024/08/16
 */

interface Strategy {
    void doOperation(int num1, int num2);
}

class AddStrategy implements Strategy {
    @Override
    public void doOperation(int num1, int num2) {
        System.out.printf("%d + %d = %d\n", num1, num2, num1 + num2);
    }
}

class SubStrategy implements Strategy {
    @Override
    public void doOperation(int num1, int num2) {
        System.out.printf("%d - %d = %d\n", num1, num2, num1 - num2);
    }
}

class MultStrategy implements Strategy {
    @Override
    public void doOperation(int num1, int num2) {
        System.out.printf("%d × %d = %d\n", num1, num2, num1 * num2);
    }
}

class Context {
    private static Strategy strategy;

    public static void setStrategy(Strategy strategy) {
        Context.strategy = strategy;
    }

    public static void executeStrategy(int num1, int num2) {
        strategy.doOperation(num1, num2);
    }
}

public class 策略模式 {
    public static void main(String[] args) {
        Context.setStrategy(new AddStrategy());
        Context.executeStrategy(114, 514);
        Context.setStrategy(new SubStrategy());
        Context.executeStrategy(114, 514);
        Context.setStrategy(new MultStrategy());
        Context.executeStrategy(114, 514);
    }
}
