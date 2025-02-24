package patterns.strategy;

public class QuackSqueak implements QuackBehavior {
    public void quack() {
        System.out.println("Squeak.");
    }
}
