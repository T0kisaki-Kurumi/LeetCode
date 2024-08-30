package 设计模式.行为型模式.命令模式;

import java.util.ArrayList;
import java.util.List;

interface Order {
    void execute();
}

/**
 * @author robbie
 * @date Created in 2024/08/15
 */

class Stock {
    String name;
    int price;

    public Stock(String name, int price) {
        this.name = name;
        this.price = price;
    }
}

class BuyStock implements Order {
    private Stock stock;

    public BuyStock(Stock stock) {
        this.stock = stock;
    }

    public void execute() {
        System.out.println("Buying stock: " + stock.name + " at price: " + stock.price);
    }
}

class SellStock implements Order {
    private Stock stock;

    public SellStock(Stock stock) {
        this.stock = stock;
    }

    public void execute() {
        System.out.println("Selling stock: " + stock.name + " at price: " + stock.price);
    }
}

class OrderExecutor {
    List<Order> orderList = new ArrayList<Order>();

    public void takeOrder(Order order) {
        orderList.add(order);
    }

    public void executeOrders() {
        for (Order order : orderList) {
            order.execute();
        }
        orderList.clear();
    }
}

public class 命令模式 {
    public static void main(String[] args) {
        Stock stock = new Stock("好看的石头", 114);
        BuyStock buyOrder = new BuyStock(stock);
        SellStock sellOrder = new SellStock(stock);

        OrderExecutor executor = new OrderExecutor();
        executor.takeOrder(buyOrder);
        executor.takeOrder(sellOrder);
        executor.executeOrders();
    }
}
