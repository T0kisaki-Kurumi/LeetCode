package 设计模式.创建型模式.工厂模式;

/**
 * @author robbie
 * @date Created in 2024/08/13
 */

interface Shape {
    void draw();
}

class Triangle implements Shape {
    public void draw() {
        System.out.println("draw a triangle");
    }
}

class Rectangle implements Shape {
    public void draw() {
        System.out.println("draw a rectangle");
    }
}

class Circle implements Shape {
    public void draw() {
        System.out.println("draw a circle");
    }
}

class ShapeFactory {
    public Shape getShape(String shapeType) {
        if (shapeType == null) {
            return null;
        }
        switch (shapeType) {
            case "Triangle":
                return new Triangle();
            case "Rectangle":
                return new Rectangle();
            case "Circle":
                return new Circle();
            default:
                return null;
        }
    }
}

public class 工厂模式 {
    public static void main(String[] args) {
        ShapeFactory shapeFactory = new ShapeFactory();
        Shape shape = shapeFactory.getShape("Triangle");
        shape.draw();
    }
}
