package patterns.strategy;

public class QuackOnly implements QuackBehavior {
    public void quack() {
        System.out.println("Quack.");
    }
}
