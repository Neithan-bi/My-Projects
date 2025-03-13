
public class CricketPlayer {
    private String name;
    private int age;
    private int totalRuns;
    private int totalBoundaries;
    private String teamName;

    public CricketPlayer(String name, int age, int totalRuns, int totalBoundaries, String teamName) {
        this.name = name;
        this.age = age;
        this.totalRuns = totalRuns;
        this.totalBoundaries = totalBoundaries;
        this.teamName = teamName;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public int getTotalRuns() {
        return totalRuns;
    }

    public void setTotalRuns(int totalRuns) {
        this.totalRuns = totalRuns;
    }

    public int getTotalBoundaries() {
        return totalBoundaries;
    }

    public void setTotalBoundaries(int totalBoundaries) {
        this.totalBoundaries = totalBoundaries;
    }

    public String getTeamName() {
        return teamName;
    }

    public void setTeamName(String teamName) {
        this.teamName = teamName;
    }

    @Override
    public String toString() {
        return "CricketPlayer{ " + "Name= '" + name + '\'' + ", age= " + age + ", totalRuns= " + totalRuns + ", totalBoundaries= " + totalBoundaries + ", teamName= '" + teamName + '\'' + '}';
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null || getClass() != obj.getClass()) {
            return false;
        }
        CricketPlayer that = (CricketPlayer) obj;
        return age == that.age &&
               totalRuns == that.totalRuns &&
               totalBoundaries == that.totalBoundaries &&
               name.equals(that.name) &&
               teamName.equals(that.teamName);
    }

    public static void main(String[] args) {
        CricketPlayer player = new CricketPlayer("Jadejah", 30, 1000, 150, "India");
        System.out.println(player);
    }
}
