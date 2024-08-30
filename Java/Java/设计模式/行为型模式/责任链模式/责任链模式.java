package 设计模式.行为型模式.责任链模式;

/**
 * @author robbie
 * @date Created in 2024/08/15
 */

enum LogLevel {
    INFO(1),
    DEBUG(2),
    ERROR(3);

    private final int level;

    LogLevel(int level) {
        this.level = level;
    }

    public int compare(LogLevel logLevel) {
        return this.level - logLevel.level;
    }
}

abstract class AbstractLogger {
    protected LogLevel level;

    protected AbstractLogger nextLogger;

    public void setNextLogger(AbstractLogger nextLogger) {
        this.nextLogger = nextLogger;
    }

    abstract void log(LogLevel level, String msg);
}

class InfoLogger extends AbstractLogger {
    public InfoLogger(LogLevel level) {
        this.level = level;
    }

    public void log(LogLevel level, String msg) {
        if (this.level.compare(level) <= 0) {
            System.out.println("[INFO] " + msg);
        }
        if (this.nextLogger != null) {
            this.nextLogger.log(level, msg);
        }
    }
}

class DebugLogger extends AbstractLogger {
    public DebugLogger(LogLevel level) {
        this.level = level;
    }

    public void log(LogLevel level, String msg) {
        if (this.level.compare(level) <= 0) {
            System.out.println("[DEBUG] " + msg);
        }
        if (this.nextLogger != null) {
            this.nextLogger.log(level, msg);
        }
    }
}

class ErrorLogger extends AbstractLogger {
    public ErrorLogger(LogLevel level) {
        this.level = level;
    }

    public void log(LogLevel level, String msg) {
        if (this.level.compare(level) <= 0) {
            System.out.println("[ERROR] " + msg);
        }
        if (this.nextLogger != null) {
            this.nextLogger.log(level, msg);
        } else {
            System.out.println("=======================================");
        }
    }
}

public class 责任链模式 {
    private static AbstractLogger initLoggerChain() {
        AbstractLogger infoLogger = new InfoLogger(LogLevel.INFO);
        AbstractLogger debugLogger = new DebugLogger(LogLevel.DEBUG);
        AbstractLogger errorLogger = new ErrorLogger(LogLevel.ERROR);
        infoLogger.setNextLogger(debugLogger);
        debugLogger.setNextLogger(errorLogger);
        return infoLogger;
    }

    public static void main(String[] args) {
        AbstractLogger logger = initLoggerChain();
        logger.log(LogLevel.INFO, "This is an info message");
        logger.log(LogLevel.DEBUG, "This is a debug message");
        logger.log(LogLevel.ERROR, "This is an error message");
    }
}
