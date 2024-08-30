package 设计模式.行为型模式.解释器模式;

/**
 * @author robbie
 * @date Created in 2024/08/15
 */

interface Expression {
    String interpret(String context);
}

// 终结符表达式
// 方向
class DirectionExpression implements Expression {
    @Override
    public String interpret(String context) {
        switch (context) {
            case "N":
            case "north":
                return "北";
            case "S":
            case "south":
                return "南";
            case "E":
            case "east":
                return "东";
            case "W":
            case "west":
                return "西";
            default:
                throw new UnsupportedOperationException("无效方向");
        }
    }
}

class MoveExpression implements Expression {
    @Override
    public String interpret(String context) {
        switch (context) {
            case "walk":
                return "走";
            case "run":
                return "跑";
            case "fly":
                return "飞";
            default:
                throw new UnsupportedOperationException("无效移动类型");
        }
    }
}

class DistanceExpression implements Expression {
    @Override
    public String interpret(String context) {
        if (Integer.parseInt(context) >= 0) {
            return context;
        } else {
            throw new UnsupportedOperationException("无效距离");
        }
    }
}

// 非终结符表达式
class SentenceExpression implements Expression {
    private Expression directionExpression;
    private Expression moveExpression;
    private Expression distanceExpression;

    public SentenceExpression(Expression directionExpression, Expression moveExpression, Expression distanceExpression) {
        this.directionExpression = directionExpression;
        this.moveExpression = moveExpression;
        this.distanceExpression = distanceExpression;
    }

    @Override
    public String interpret(String sentence) {
        String[] tokens = sentence.split(" ");
        return String.format("向%s%s%s米", directionExpression.interpret(tokens[0]), moveExpression.interpret(tokens[1]), distanceExpression.interpret(tokens[2]));
    }
}

public class 解释器模式 {
    public static void main(String[] args) {
        String sentence1 = "north walk 100";
        String sentence2 = "E fly 514";
        String sentence3 = "N run -1";
        Expression sentenctExpression = new SentenceExpression(new DirectionExpression(), new MoveExpression(), new DistanceExpression());
        System.out.println(sentenctExpression.interpret(sentence1));
        System.out.println(sentenctExpression.interpret(sentence2));
        System.out.println(sentenctExpression.interpret(sentence3));
    }
}
