package 设计模式.创建型模式.抽象工厂模式;

import javafx.scene.control.ColorPicker;

/**
 * @author robbie
 * @date Created in 2024/08/13
 */

interface Shape{
    void draw();
}

class Triangle implements Shape{
    public void draw(){
        System.out.println("draw a triangle");
    }
}

class Circle implements Shape{
    public void draw(){
        System.out.println("draw a circle");
    }
}

interface Color{
    void fill();
}

class Red implements Color{
    public void fill(){
        System.out.println("fill red");
    }
}

class Blue implements Color{
    public void fill(){
        System.out.println("fill blue");
    }
}

abstract class AbstractFactory{
    abstract Shape getShape(String shapeType);
    abstract Color getColor(String colorType);
}

class ShapeFactory extends AbstractFactory{
    @Override
    Shape getShape(String shapeType) {
        if(shapeType == null) return null;
        switch (shapeType){
            case "Triangle":
                return new Triangle();
            case "Circle":
                return new Circle();
            default:
                return null;
        }
    }

    @Override
    Color getColor(String colorType) {
        return null;
    }
}

class ColorFactory extends AbstractFactory{

    @Override
    Shape getShape(String shapeType) {
        return null;
    }

    @Override
    Color getColor(String colorType) {
        if(colorType == null) return null;
        switch (colorType){
            case "Red":
                return new Red();
            case "Blue":
                return new Blue();
            default:
                return null;
        }
    }
}

public class 抽象工厂模式 {
    public static void main(String[] args) {
        AbstractFactory shapeFactory = new ShapeFactory();
        shapeFactory.getShape("Triangle").draw();
        shapeFactory.getShape("Circle").draw();

        AbstractFactory colorFactory = new ColorFactory();
        colorFactory.getColor("Red").fill();
        colorFactory.getColor("Blue").fill();
    }
}
