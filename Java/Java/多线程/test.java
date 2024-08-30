package 多线程;

import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.FutureTask;

/**
 * @author robbie
 * @date Created in 2024/08/27
 */

class MyRunnable implements Runnable {
    @Override
    public void run() {
        System.out.println(Thread.currentThread().getName());
    }
}

class MyCallable implements Callable<String> {
    @Override
    public String call() throws Exception {
        return Thread.currentThread().getName();
    }
}

public class test {
    public static void main(String[] args) throws Exception {
        System.out.println("可用的处理器数量：" + Runtime.getRuntime().availableProcessors());

        MyRunnable myRunnable = new MyRunnable();
        new Thread(myRunnable).run();
        new Thread(myRunnable).start();

        MyCallable myCallable = new MyCallable();
        FutureTask<String> futureTask = new FutureTask<>(myCallable);
        new Thread(futureTask).start();
        System.out.println(futureTask.get());
    }
}
