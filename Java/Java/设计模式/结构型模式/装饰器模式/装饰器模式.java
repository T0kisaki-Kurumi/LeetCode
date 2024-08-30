package 设计模式.结构型模式.装饰器模式;

/**
 * @author robbie
 * @date Created in 2024/08/15
 */

interface Shape{
    void draw();
}

class Rectangle implements Shape{
    public void draw(){
        System.out.println("draw a rectangle");
    }
}

class Circle implements Shape{
    public void draw(){
        System.out.println("draw a circle");
    }
}

abstract class ShapeDecorator implements Shape{
    protected Shape decoratedShape;

    public ShapeDecorator(Shape decoratedShape){
        this.decoratedShape = decoratedShape;
    }

    @Override
    public void draw() {
        this.decoratedShape.draw();
    }
}

class RedShapeDecorator extends ShapeDecorator{
    public RedShapeDecorator(Shape decoratedShape) {
        super(decoratedShape);
    }

    private void fill(){
        System.out.println("filled with red");
    }

    @Override
    public void draw() {
        super.draw();
        this.fill();
    }
}

public class 装饰器模式 {
    public static void main(String[] args) {
        Shape shape = new Rectangle();
        ShapeDecorator redShapeDecorator = new RedShapeDecorator(shape);
        redShapeDecorator.draw();
    }
}
