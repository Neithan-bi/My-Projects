import java.awt.*;
import java.awt.event.*;

public class StudentForm implements ActionListener {
    Frame f;
    TextField nameField, emailField;
    Checkbox cbJava, cbPython, cbC;
    CheckboxGroup genderGroup;
    Checkbox male, female;
    Choice courseChoice;
    TextArea addressArea;
    Label resultLabel;
    Button submitBtn, clearBtn;

    public StudentForm() {
        f = new Frame("AWT Student Registration Form");
        f.setSize(500, 600);
        f.setLayout(new GridLayout(15, 2, 10, 10));

        // Name
        f.add(new Label("Name:"));
        nameField = new TextField();
        f.add(nameField);

        // Email
        f.add(new Label("Email:"));
        emailField = new TextField();
        f.add(emailField);

        // Gender Label
        f.add(new Label("Gender:"));
        f.add(new Label("Select one"));

        // Gender Options
        genderGroup = new CheckboxGroup();
        male = new Checkbox("Male", genderGroup, true);   // default selected
        female = new Checkbox("Female", genderGroup, false);
        f.add(male);
        f.add(female);

        // Skills Label
        f.add(new Label("Skills:"));
        f.add(new Label("Select all that apply"));

        // Skill Checkboxes
        cbJava = new Checkbox("Java");
        cbPython = new Checkbox("Python");
        cbC = new Checkbox("C");
        f.add(cbJava);
        f.add(cbPython);
        f.add(cbC);
        f.add(new Label("")); // for layout balance

        // Course
        f.add(new Label("Course:"));
        courseChoice = new Choice();
        courseChoice.add("BSc CS");
        courseChoice.add("BCA");
        courseChoice.add("MSc CS");
        courseChoice.add("MCA");
        f.add(courseChoice);

        // Address
        f.add(new Label("Address:"));
        addressArea = new TextArea(3, 20);
        f.add(addressArea);

        // Buttons
        submitBtn = new Button("Submit");
        clearBtn = new Button("Clear");
        submitBtn.addActionListener(this);
        clearBtn.addActionListener(this);
        f.add(submitBtn);
        f.add(clearBtn);

        // Result
        f.add(new Label("Result:"));
        resultLabel = new Label("");
        f.add(resultLabel);

        // Window Closing
        f.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent we) {
                f.dispose();
            }
        });

        f.setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == submitBtn) {
            String name = nameField.getText();
            String email = emailField.getText();
            String gender = genderGroup.getSelectedCheckbox().getLabel();

            String skills = "";
            if (cbJava.getState()) skills += "Java ";
            if (cbPython.getState()) skills += "Python ";
            if (cbC.getState()) skills += "C ";

            String course = courseChoice.getSelectedItem();
            String address = addressArea.getText();

            resultLabel.setText("Registered: " + name + ", " + gender + ", " + course + ", " + skills);
        }

        if (e.getSource() == clearBtn) {
            nameField.setText("");
            emailField.setText("");
            genderGroup.setSelectedCheckbox(male); // reset to default
            cbJava.setState(false);
            cbPython.setState(false);
            cbC.setState(false);
            courseChoice.select(0);
            addressArea.setText("");
            resultLabel.setText("");
        }
    }

    public static void main(String[] args) {
        new StudentForm();
    }
}