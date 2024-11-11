import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

public class TrafficLight_Swing extends JPanel implements ActionListener {
    JFrame frame;
    JRadioButton bRed, bYellow, bGreen;
    ButtonGroup bg;
    Color red, yellow, green;

    TrafficLight_Swing(String caption) {
        red = yellow = green = Color.LIGHT_GRAY;

        frame = new JFrame(caption);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400,400);
        frame.setLayout(new FlowLayout());

        bRed = new JRadioButton("Red");
        bYellow = new JRadioButton("Yellow");
        bGreen = new JRadioButton("Green");

        bg = new ButtonGroup();
        bg.add(bRed);
        bg.add(bYellow);
        bg.add(bGreen);

        bRed.addActionListener(this);
        bYellow.addActionListener(this);
        bGreen.addActionListener(this);

        this.add(bRed);
        this.add(bYellow);
        this.add(bGreen);
        this.setPreferredSize(new Dimension(400,400));

        frame.add(this);
        frame.setVisible(true);
    }

    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.drawOval(50,50,50,50);
        g.setColor(red);
        g.fillOval(50,50,50,50);

        g.drawOval(50,110,50,50);
        g.setColor(yellow);
        g.fillOval(50,110,50,50);

        g.drawOval(50,170,50,50);
        g.setColor(green);
        g.fillOval(50,170,50,50);
    }

    public void actionPerformed(ActionEvent e) {
        JRadioButton b = (JRadioButton) e.getSource();
        red = yellow = green = Color.LIGHT_GRAY;
        
        if(b == bRed) {
            red = Color.RED;
        } else if(b == bYellow) {
            yellow = Color.YELLOW;
        } else if(b == bGreen) {
            green = Color.GREEN;
        }
        repaint();
    }

    public static void main(String[] args) {
        new TrafficLight_Swing("Traffic Light");
    }
}
