package patterns.strategy;

public class QuackFake implements QuackBehavior {
    public void quack() {
        System.out.println("Qwak.");
    }
}
