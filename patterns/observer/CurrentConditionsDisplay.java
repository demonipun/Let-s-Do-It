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

    // TYPE-1: Push update by Subject to all the Observers (For the Subject to send notifications)
    public void update(float temperature, float humidity, float pressure) {
        this.temperature = temperature;
        this.humidity = humidity;
        
        display();
    }

    // TYPE-2: Pull update by Observers from the Subject (For an Observer to receive notifications)
    // public void update() {
    //     this.temperature = weatherData.getTemperature();
    //     this.humidity = weatherData.getHumidity();

    //     display();
    // }

    public void display() {
        System.out.println("The current conditions are: " + temperature + "F degrees and " + humidity + "% humidity.");
    }
}