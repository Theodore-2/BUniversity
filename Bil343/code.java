import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;

public class code {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Dynamic Button Generator");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 300);
        frame.setLayout(new BorderLayout());

        // Input panel
        JPanel inputPanel = new JPanel();
        inputPanel.setLayout(new FlowLayout());

        JLabel label = new JLabel("Enter number of buttons: ");
        JTextField textField = new JTextField(10);
        JButton generateButton = new JButton("Generate Buttons");

        inputPanel.add(label);
        inputPanel.add(textField);
        inputPanel.add(generateButton);

        frame.add(inputPanel, BorderLayout.NORTH);

        // Button panel
        JPanel buttonPanel = new JPanel();
        buttonPanel.setLayout(new FlowLayout());
        frame.add(buttonPanel, BorderLayout.CENTER);

        // Action for Generate Button
        ActionListener generateAction = e -> {
            buttonPanel.removeAll();
            try {
                String input = textField.getText();
                if (input.contains(".")) {
                    throw new IllegalArgumentException("NO FLOATS");
                }

                int numberOfButtons = Integer.parseInt(input);
                if (numberOfButtons <= 0) {
                    throw new IllegalArgumentException("NEGATIVEEE");
                }

                for (int i = 1; i <= numberOfButtons; i++) {
                    JButton button = new JButton("Button " + i);
                    button.addActionListener(event -> 
                        JOptionPane.showMessageDialog(frame, "You clicked: " + button.getText())
                    );
                    buttonPanel.add(button);
                }

                buttonPanel.revalidate();
                buttonPanel.repaint();

            } catch (NumberFormatException ex) {
                JOptionPane.showMessageDialog(frame, "Please enter a valid positive integer!", "Error", JOptionPane.ERROR_MESSAGE);
            } catch (IllegalArgumentException ex) {
                JOptionPane.showMessageDialog(frame, ex.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
            }
        };

        // Attach ActionListener to both button and text field
        generateButton.addActionListener(generateAction);
        textField.addActionListener(generateAction);

        frame.setVisible(true);
    }
}
