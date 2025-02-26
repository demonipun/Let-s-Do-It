package patterns.observer;

// TYPE-1: Push update by Subject to all the Observers (For the Subject to send notifications)
public interface Observer {
    public void update(float temp, float humidity, float pressure);
}

// TYPE-2: Pull update by Observers from the Subject (For an Observer to receive notifications)
// public interface Observer {
//     public void update();
// }