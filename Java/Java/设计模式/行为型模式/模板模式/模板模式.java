package 设计模式.行为型模式.模板模式;

/**
 * @author robbie
 * @date Created in 2024/08/16
 */

abstract class PlayBall {
    abstract void start();
    abstract void score();
    abstract void stop();

    final void play() {
        start();
        score();
        stop();
    }
}

class PlayFootball extends PlayBall {
    @Override
    void start() {
        System.out.println("开始踢⚽！");
    }

    @Override
    void score() {
        System.out.println("进⚽了！");
    }

    @Override
    void stop() {
        System.out.println("停止踢⚽！");
    }
}

class PlayBasketball extends PlayBall {
    @Override
    void start() {
        System.out.println("开始打🏀！");
    }

    @Override
    void score() {
        System.out.println("🐓进🏀了！");
    }

    @Override
    void stop() {
        System.out.println("停止打🏀！");
    }
}

public class 模板模式 {
    public static void main(String[] args) {
        PlayBall playFootball = new PlayFootball();
        playFootball.play();
        PlayBall playBasketball = new PlayBasketball();
        playBasketball.play();
    }
}
