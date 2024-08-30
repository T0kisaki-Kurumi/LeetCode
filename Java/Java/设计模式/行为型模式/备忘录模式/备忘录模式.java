package 设计模式.行为型模式.备忘录模式;

import java.util.ArrayList;
import java.util.List;

/**
 * @author robbie
 * @date Created in 2024/08/16
 */

class Memento {
    private String state;

    public Memento(String state) {
        this.state = state;
    }

    public String getState() {
        return state;
    }
}

class Originator {
    private String state;

    public Originator(String state) {
        this.state = state;
    }

    public String getState() {
        return state;
    }

    public void setState(String state) {
        this.state = state;
    }

    public void saveState() {
        MementoManager.getInstance().add(new Memento(state));
    }

    public void loadState(int index) {
        state = MementoManager.getInstance().get(index);
    }
}

class MementoManager {
    private static final MementoManager INSTANCE = new MementoManager();

    private List<Memento> mementos = new ArrayList<>();

    private MementoManager() {
    }

    public static MementoManager getInstance() {
        return INSTANCE;
    }

    public void add(Memento memento) {
        mementos.add(memento);
    }

    public void delete(int index) {
        mementos.remove(index);
    }

    public void show() {
        for (Memento memento : mementos) {
            System.out.print(memento.getState() + " ");
        }
        System.out.println();
    }

    public String get(int index) {
        return mementos.get(index).getState();
    }
}

public class 备忘录模式 {
    public static void main(String[] args) {
        Originator originator = new Originator("STATE #1");
        System.out.println(originator.getState());
        originator.saveState();
        originator.setState("STATE #2");
        System.out.println(originator.getState());
        originator.saveState();
        MementoManager.getInstance().show();
        originator.loadState(0);
        System.out.println(originator.getState());
    }
}
