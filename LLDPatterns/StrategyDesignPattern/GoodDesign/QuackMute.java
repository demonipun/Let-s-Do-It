package lldpatterns.strategydesignpattern.gooddesign;

public class QuackMute implements QuackBehavior{
    public void quack() {
        System.out.println("<< Silence >>");
    }
}
