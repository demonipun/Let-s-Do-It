package lldpatterns.strategydesignpattern.gooddesign;

public class RedHeadDuck extends Duck {
 
	public RedHeadDuck() {
		flyBehavior = new FlyWithWings();
		quackBehavior = new QuackOnly();
	}
 
	public void display() {
		System.out.println("Hello! I am a real Red Headed duck.");
	}
}
