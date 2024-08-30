package 设计模式.结构型模式.桥接模式;

/**
 * @author robbie
 * @date Created in 2024/08/13
 */

interface Color {
    String color();
}

class Blue implements Color {
    @Override
    public String color() {
        return "blue";
    }
}

class Red implements Color {
    @Override
    public String color() {
        return "red";
    }
}

interface Position {
    String position();
}

class Middle implements Position {
    @Override
    public String position() {
        return "x=0, y=0";
    }
}

class Left implements Position {
    @Override
    public String position() {
        return "x=-1, y=0";
    }
}

abstract class Shape {
    Color color;
    Position position;

    public Shape(Color color, Position position) {
        this.color = color;
        this.position = position;
    }

    protected abstract void show();
}

class Circle extends Shape {
    public Circle(Color color, Position position) {
        super(color, position);
    }

    @Override
    public void show() {
        System.out.println("Circle: " + color.color() + ", " + position.position());
    }
}

class Rectangle extends Shape {
    public Rectangle(Color color, Position position) {
        super(color, position);
    }

    @Override
    public void show() {
        System.out.println("Rectangle: " + color.color() + ", " + position.position());
    }
}

public class 桥接模式 {
    public static void main(String[] args) {
        Shape circle = new Circle(new Blue(), new Middle());
        Shape rectangle = new Rectangle(new Red(), new Left());
        circle.show();
        rectangle.show();
    }
}
