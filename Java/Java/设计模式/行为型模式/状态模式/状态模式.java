package 设计模式.行为型模式.状态模式;

/**
 * @author robbie
 * @date Created in 2024/08/16
 */

interface State {
    void doAction();
}

class StartState implements State {
    @Override
    public void doAction() {
        System.out.println("切换到开始状态");
    }
}

class StopState implements State {
    @Override
    public void doAction() {
        System.out.println("切换到停止状态");
    }
}

class Context{
    private State state;

    private final static Context INSTANCE = new Context();

    public void setState(State state) {
        state.doAction();
        this.state = state;
    }

    public static Context getInstance() {
        return INSTANCE;
    }

    public void showState(){
        System.out.println("当前状态：" + state.getClass().getSimpleName());
    }
}

public class 状态模式 {
    public static void main(String[] args) {
        Context context = new Context();
        State startState = new StartState();
        State stopState = new StopState();
        context.setState(startState);
        context.showState();
        context.setState(stopState);
        context.showState();
    }
}
