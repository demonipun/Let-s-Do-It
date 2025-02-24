package lldpatterns.strategydesignpattern.gooddesign;

public class ModelDuck extends Duck {
    public ModelDuck() {
        flyBehavior = new FlyNoWay();
		quackBehavior = new QuackOnly();
    }

    public void display() {
        System.out.println("Hello! I am a Model Duck.");
    }
}
