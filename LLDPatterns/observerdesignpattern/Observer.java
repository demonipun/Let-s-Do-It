package lldpatterns.observerdesignpattern;

public interface Observer {
    // Push update from Subject to all the Observers
    public void update(float temp, float humidity, float pressure);
}