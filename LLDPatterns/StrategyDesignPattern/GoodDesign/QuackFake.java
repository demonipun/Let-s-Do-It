package LLDPatterns.StrategyDesignPattern.GoodDesign;

public class QuackFake implements QuackBehavior {
    public void quack() {
        System.out.println("Qwak.");
    }
}
