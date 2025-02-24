package patterns.observer;

public class CurrentConditionsDisplay implements Observer, DisplayElement {
    private float temperature;
    private float humidity;
    private WeatherData weatherData;

    // passing the subject with the observer concrete class
    public CurrentConditionsDisplay (WeatherData weatherData) {
        this.weatherData = weatherData;
        weatherData.registerObserver(this);
    }

    public void update(float temperature, float humidity, float pressure) {
        this.temperature = temperature;
        this.humidity = humidity;
        
        display();
    }

    public void display() {
        System.out.println("The current conditions are: " + temperature + "F degrees and " + humidity + "% humidity.");
    }
}