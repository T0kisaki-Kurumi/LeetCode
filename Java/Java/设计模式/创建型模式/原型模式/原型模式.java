package 设计模式.创建型模式.原型模式;

import java.util.HashMap;
import java.util.logging.Logger;

/**
 * @author robbie
 * @date Created in 2024/08/13
 */

abstract class Shape implements Cloneable {
    abstract void draw();
    private static final Logger logger = Logger.getLogger(Shape.class.getName());

    @Override
    public Object clone(){
        Object obj = null;
        try {
            obj = super.clone();
        } catch (CloneNotSupportedException e) {
//            e.printStackTrace();
            logger.warning(e.getMessage());
        }
        return obj;
    }
}

class Rectangle extends Shape {
    @Override
    public void draw() {
        System.out.println("Rectangle");
    }
}

class Circle extends Shape {
    @Override
    public void draw() {
        System.out.println("Circle");
    }
}

class ShapeCache {
    private HashMap<String, Shape> cache = new HashMap<>();

    public Shape getShape(String shapeType){
        return (Shape) cache.get(shapeType).clone();
    }

    public void loadCache() {
        cache.put("R", new Rectangle());
        cache.put("C", new Circle());
    }
}

public class 原型模式 {
    public static void main(String[] args) {
        ShapeCache shapeCache = new ShapeCache();
        shapeCache.loadCache();

        Shape s1 = shapeCache.getShape("R");
        s1.draw();
        Shape s2 = shapeCache.getShape("C");
        s2.draw();
    }
}
