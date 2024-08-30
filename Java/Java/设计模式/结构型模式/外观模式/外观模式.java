package 设计模式.结构型模式.外观模式;

/**
 * @author robbie
 * @date Created in 2024/08/28
 */

interface Shape{
    void draw();
}

class Rectangle implements Shape{
    @Override
    public void draw() {
        System.out.println("Rectangle::draw()");
    }
}

class Circle implements Shape{
    @Override
    public void draw() {
        System.out.println("Circle::draw()");
    }
}

class ShapeFacade{
    private Rectangle rectangle;
    private Circle circle;

    public ShapeFacade(){
        rectangle = new Rectangle();
        circle = new Circle();
    }

    public void drawRectangle(){
        rectangle.draw();
    }

    public void drawCircle(){
        circle.draw();
    }
}

public class 外观模式 {
    public static void main(String[] args) {
        ShapeFacade shapeFacade = new ShapeFacade();
        shapeFacade.drawRectangle();
        shapeFacade.drawCircle();
    }
}
