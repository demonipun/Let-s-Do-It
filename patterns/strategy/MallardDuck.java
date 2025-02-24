package patterns.strategy;

public class MallardDuck extends Duck {
    public MallardDuck() {
        quackBehavior = new QuackOnly();
		flyBehavior = new FlyWithWings();
    }
    
    public void display() {
        System.out.println("Hello! I am a Mallard Duck.");
    }
}
