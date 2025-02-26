package patterns.observer;

public class StatisticsDisplay implements Observer, DisplayElement {
    private float maxTemp = 0.0f;
	private float minTemp = 200;
	private float tempSum= 0.0f;
	private int numReadings;
	private WeatherData weatherData;

	public StatisticsDisplay(WeatherData weatherData) {
		this.weatherData = weatherData;
		weatherData.registerObserver(this);
	}

	// TYPE-1: Push update by Subject to all the Observers (For the Subject to send notifications)
    public void update(float temp, float humidity, float pressure) {
        tempSum += temp;
		numReadings++;

		if (temp > maxTemp) {
			maxTemp = temp;
		}
 
		if (temp < minTemp) {
			minTemp = temp;
		}

		display();
    }

	// TYPE-2: Pull update by Observers from the Subject (For an Observer to receive notifications)
    // public void update() {
    //     tempSum += weatherData.getTemperature();
	// 	numReadings++;

	// 	if (temp > maxTemp) {
	// 		maxTemp = temp;
	// 	}
 
	// 	if (temp < minTemp) {
	// 		minTemp = temp;
	// 	}

	// 	display();
    // }

    public void display() {
		System.out.println("Avg/Max/Min temperature = " + (tempSum / numReadings) + "/" + maxTemp + "/" + minTemp);
	}
}