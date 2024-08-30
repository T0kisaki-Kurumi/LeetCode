package 设计模式.行为型模式.访问者模式;

/**
 * @author robbie
 * @date Created in 2024/08/19
 */

interface Part{
    void accept(ComputerPartVisitor visitor);
}

class Monitor implements Part{
    @Override
    public void accept(ComputerPartVisitor visitor) {
        visitor.visit(this);
    }
}

class Keyboard implements Part{
    @Override
    public void accept(ComputerPartVisitor visitor) {
        visitor.visit(this);
    }
}

class Mouse implements Part{
    @Override
    public void accept(ComputerPartVisitor visitor) {
        visitor.visit(this);
    }
}

interface ComputerPartVisitor{
    void visit(Monitor monitor);
    void visit(Keyboard keyboard);
    void visit(Mouse mouse);
}

class ComputerPartVisitorImpl implements ComputerPartVisitor{
    @Override
    public void visit(Monitor monitor) {
        System.out.println("visit monitor");
    }

    @Override
    public void visit(Keyboard keyboard) {
        System.out.println("visit keyboard");
    }

    @Override
    public void visit(Mouse mouse) {
        System.out.println("visit mouse");
    }
}

public class 访问者模式 {
    public static void main(String[] args) {
        Part[] computer = {new Keyboard(), new Mouse(), new Monitor()};
        ComputerPartVisitorImpl visitor = new ComputerPartVisitorImpl();
        for (Part part : computer) {
            part.accept(visitor);
        }
    }
}
