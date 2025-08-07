import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Project extends JFrame implements ActionListener {
    private JButton[][] buttons = new JButton[3][3];
    private char currentPlayer = 'X'; 

    public Project() {                              
        setTitle("Tic Tac Toe");                    
        setSize(400, 400);                          
        setDefaultCloseOperation(EXIT_ON_CLOSE);    
        setLayout(new GridLayout(3, 3));           
        initializeBoard();                          
        setVisible(true); } 

    private void initializeBoard() {
        Font font = new Font("Arial", Font.BOLD, 60);   
        for (int i = 0; i < 3; i++) {                   
            for (int j = 0; j < 3; j++) {
                buttons[i][j] = new JButton("");       
                buttons[i][j].setFont(font);           
                buttons[i][j].setFocusPainted(false);   
                buttons[i][j].addActionListener(this);   
                add(buttons[i][j]);}}}

    private boolean checkWin() {
        String p = String.valueOf(currentPlayer);

        for (int i = 0; i < 3; i++) {
            if (p.equals(buttons[i][0].getText()) &&
                p.equals(buttons[i][1].getText()) &&
                p.equals(buttons[i][2].getText())) return true;

            if (p.equals(buttons[0][i].getText()) &&
                p.equals(buttons[1][i].getText()) &&
                p.equals(buttons[2][i].getText())) return true;
        }
        return (p.equals(buttons[0][0].getText()) &&
                p.equals(buttons[1][1].getText()) &&
                p.equals(buttons[2][2].getText())) ||

               (p.equals(buttons[0][2].getText()) &&
                p.equals(buttons[1][1].getText()) &&
                p.equals(buttons[2][0].getText()));
    }

    private boolean isBoardFull() {
        for (JButton[] row : buttons) {
            for (JButton btn : row) {
                if (btn.getText().equals("")) return false; }}
        return true; }

    private void showResult(String message) {
        int option = JOptionPane.showOptionDialog(this,
                message + "\nDo you want to play again?",
                "Game Over",
                JOptionPane.YES_NO_OPTION, 
                JOptionPane.INFORMATION_MESSAGE, 
                null,
                new String[]{"Play Again", "Exit"},
                "Play Again");

        if (option == JOptionPane.YES_OPTION) {
            resetBoard();
        } else {
            System.exit(0);} }

    private void resetBoard() {
        currentPlayer = 'X';
        for (JButton[] row : buttons) {
            for (JButton btn : row) {
                btn.setText("");}} }

    public void actionPerformed(ActionEvent e) {
        JButton clicked = (JButton) e.getSource(); 
        if (!clicked.getText().equals("")) {
            JOptionPane.showMessageDialog(this, "Cell already taken! Choose another."); 
            return; }
        clicked.setText(String.valueOf(currentPlayer)); 
        clicked.setForeground(currentPlayer == 'X' ? Color.PINK : Color.BLACK);
        if (checkWin()) {
            showResult("Player " + currentPlayer + " wins!");
        } else if (isBoardFull()) {
            showResult("It's a draw!");
        } else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';} }
            
    public static void main(String[] args) { new Project(); }}