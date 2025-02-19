import java.util.Arrays;

class Racer {
    private String name;
    private int raceNumber;
    private double time;

    public Racer(String name, int raceNumber, double time) {
        this.name = name;
        this.raceNumber = raceNumber;
        this.time = time;
    }

    public double getTime() {
        return time;
    }

    public String toString() {
        return "Race #" + raceNumber + " - " + name + " - Time: " + time + " sec";
    }
}

class RankingList {
    private Racer[] racers = new Racer[100];
    private int count = 0;

    public void addRacer(Racer racer) {
        if (count < 100) {
            racers[count++] = racer;
            Arrays.sort(racers, 0, count, (a, b) -> Double.compare(a.getTime(), b.getTime()));
        }
    }

    public void displayRanking() {
        System.out.println("🏆 International Ski Federation Ranking List 🏆");
        for (int i = 0; i < count; i++) {
            System.out.println((i + 1) + ". " + racers[i]);
        }
    }
}

public class SkiFederation {
    public static void main(String[] args) {
        RankingList ranking = new RankingList();
        ranking.addRacer(new Racer("John Doe", 101, 98.5));
        ranking.addRacer(new Racer("Alice Smith", 102, 95.3));
        ranking.displayRanking();
    }
}
