package patterns.observer;

public class ForecastDisplay implements Observer, DisplayElement {
    private float currentPressure = 29.92f;  
	private float lastPressure;
	private WeatherData weatherData;

    public ForecastDisplay(WeatherData weatherData) {
        this.weatherData = weatherData;
		weatherData.registerObserver(this);
    }

	// TYPE-1: Push update by Subject to all the Observers (For the Subject to send notifications)
    public void update(float temp, float humidity, float pressure) {
        lastPressure = currentPressure;
		currentPressure = pressure;

		display();
    }

	// TYPE-2: Pull update by Observers from the Subject (For an Observer to receive notifications)
    // public void update() {
    //     lastPressure = currentPressure;
	// 	currentPressure = weatherData.getPressure();

    //     display();
    // }

    public void display() {
		System.out.print("Forecast: ");
		if (currentPressure > lastPressure) {
			System.out.println("Improving weather on the way!");
		} else if (currentPressure == lastPressure) {
			System.out.println("More of the same");
		} else if (currentPressure < lastPressure) {
			System.out.println("Watch out for cooler, rainy weather");
		}
	}
}