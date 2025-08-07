import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.Color;

public class guh {
    JPanel panel = new JPanel() {
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.setColor(Color.BLACK);
        g.fillRect(50, 50, 100, 100);
    }
};
public static void main(String[] args) {
    JFrame frame = new JFrame();
    frame.add(panel);
    frame.setSize(300, 300);
    frame.setVisible(true);
    } 
}

