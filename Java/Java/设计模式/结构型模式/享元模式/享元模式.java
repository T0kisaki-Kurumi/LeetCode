package 设计模式.结构型模式.享元模式;

import java.util.HashMap;
import java.util.Map;

/**
 * @author robbie
 * @date Created in 2024/08/15
 */

interface Shape {
    void draw();
}

class ShapeImpl implements Shape {
    private String shapeType;

    public ShapeImpl(String shapeType) {
        this.shapeType = shapeType;
    }

    @Override
    public void draw() {
        System.out.println("draw a " + shapeType);
    }
}

class ShapePool {
    private static Map<String, Shape> shapeMap = new HashMap<>();

    public static Shape getShape(String shapeType) {
        if (!shapeMap.containsKey(shapeType)) {
            shapeMap.put(shapeType, new ShapeImpl(shapeType));
            System.out.println("create a new shape: " + shapeType);
        }
        return shapeMap.get(shapeType);
    }
}

public class 享元模式 {
    public static void main(String[] args) {
        String[] shapes = {"rec", "cir", "squ", "tri", "dia"};
        for (int i = 0; i < 20; i++) {
            int index = (int) (Math.random() * shapes.length);
            ShapePool.getShape(shapes[index]).draw();
        }
    }
}
