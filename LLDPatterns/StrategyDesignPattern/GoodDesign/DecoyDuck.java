package LLDPatterns.StrategyDesignPattern.GoodDesign;

public class DecoyDuck extends Duck {
    public DecoyDuck() {
        setFlyBehavior(new FlyNoWay());
        setQuackBehavior(new QuackMute());
    }
    
    public void display() {
        System.out.println("Hello! I am a Decoy Duck.");
    }
}
