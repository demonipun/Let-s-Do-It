package lldpatterns.strategydesignpattern.gooddesign;

public class QuackOnly implements QuackBehavior {
    public void quack() {
        System.out.println("Quack.");
    }
}
