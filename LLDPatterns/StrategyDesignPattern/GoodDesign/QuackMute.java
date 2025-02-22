package LLDPatterns.StrategyDesignPattern.GoodDesign;

public class QuackMute implements QuackBehavior{
    public void quack() {
        System.out.println("<< Silence >>");
    }
}
