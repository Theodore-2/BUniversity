import java.awt.*;
import javax.swing.*;

public class DynamicButtonGenerator {
    public static void main(String[] args) {
        
        JFrame frame = new JFrame("Dynamic Button Generator");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 300);
        frame.setLayout(new BorderLayout());

       
        JPanel inputPanel = new JPanel();
        inputPanel.setLayout(new FlowLayout());

        JLabel label = new JLabel("Enter number of buttons: ");
        JTextField textField = new JTextField(10);
        JButton generateButton = new JButton("Generate Buttons");

        inputPanel.add(label);
        inputPanel.add(textField);
        inputPanel.add(generateButton);

        frame.add(inputPanel, BorderLayout.NORTH);

       
        JPanel buttonPanel = new JPanel();
        buttonPanel.setLayout(new FlowLayout());
        frame.add(buttonPanel, BorderLayout.CENTER);

       
        generateButton.addActionListener(e -> {
            buttonPanel.removeAll();
            try {
                int numberOfButtons = Integer.parseInt(textField.getText());
                if (numberOfButtons <= 0) throw new NumberFormatException();

                for (int i = 1; i <= numberOfButtons; i++) {
                    JButton button = new JButton("Button " + i);
                    button.addActionListener(event -> JOptionPane.showMessageDialog(frame, "You clicked: " + button.getText()));
                    buttonPanel.add(button);
                }

                buttonPanel.revalidate();
                buttonPanel.repaint();

            } catch (NumberFormatException ex) {
                JOptionPane.showMessageDialog(frame, "Please enter a valid positive integer!", "Error", JOptionPane.ERROR_MESSAGE);
            }
        });

        frame.setVisible(true);
    }
}