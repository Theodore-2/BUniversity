import java.time.Duration;
import java.time.Instant;

public class TimerExample {
    public static void main(String[] args) {
        Instant start = Instant.now();  // Start the timer

        // Function call or code to measure
        someFunction();

        Instant end = Instant.now();  // End the timer
        Duration duration = Duration.between(start, end);  // Calculate duration

        System.out.println("Execution time: " + duration.toNanos() + " nanoseconds");
        System.out.println("Execution time: " + duration.toMillis() + " milliseconds");
    }

    public static void someFunction() {
        // Simulate some work with a larger loop
        for (int i = 0; i < 100_000_000; i++) {
            Math.sqrt(i);  // Some calculation
        }
    }
}



