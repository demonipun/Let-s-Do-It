package patterns.observer;

// Concrete Subject Class
public class WeatherData implements Subject {
    private float temperature;
    private float humidity;
    private float pressure;
    private List<Observer> observers;

    // initializes empty list of observers
    public WeatherData() {
        observers = new ArrayList<Observer>();
    }

    public void registerObserver(Observer ob) {
        observers.add(ob);
    }

    public void removeObserver(Observer ob) {
        observers.remove(ob);
    }

    public void notifyObservers() {
        for(Observer observer: observers) {
            observer.update(temperature, humidity, pressure);
        }
    }

    public void measurementsChanged() {
        notifyObservers();
    }

    public void setMeasurements(float temperature, float humidity, float pressure) {
        this.temperature = temperature;
        this.humidity = humidity;
        this.pressure = pressure;

        measurementsChanged();
    }

    // getter methods
    public float getTemperature() {
		return temperature;
	}
	
	public float getHumidity() {
		return humidity;
	}
	
	public float getPressure() {
		return pressure;
	}
}