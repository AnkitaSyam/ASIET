package FISAT_LAB;

import java.io.FileReader;
import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.BufferedWriter;
import java.io.IOException;

class LowerCase extends Thread {
    String inputFile;
    String outputFile;

    LowerCase(String inputFile, String outputFile) {
        this.inputFile = inputFile;
        this.outputFile = outputFile;
    }

    public void run() {
        try {
            FileReader fr = new FileReader(inputFile);
            BufferedReader br = new BufferedReader(fr);

            FileWriter fw = new FileWriter(outputFile);
            BufferedWriter bw = new BufferedWriter(fw);

            int ch;
            while ((ch = br.read()) != -1) {
                if (Character.isLowerCase(ch)) {
                    bw.write(ch);
                }
            }

            br.close();
            bw.close();
            fr.close();
            fw.close();
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }
}

class UpperCase extends Thread {
    String inputFile;
    String outputFile;

    UpperCase(String inputFile, String outputFile) {
        this.inputFile = inputFile;
        this.outputFile = outputFile;
    }

    public void run() {
        try {
            FileReader fr = new FileReader(inputFile);
            BufferedReader br = new BufferedReader(fr);

            FileWriter fw = new FileWriter(outputFile);
            BufferedWriter bw = new BufferedWriter(fw);

            int ch;
            while ((ch = br.read()) != -1) {
                if (Character.isUpperCase(ch)) {
                    bw.write(ch);
                }
            }

            br.close();
            bw.close();
            fr.close();
            fw.close();
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }
}

public class FileProcessing {
    public static void main(String[] args) {
        String inputFile = "f1.txt";
        String lowerOutputFile = "f2.txt";
        String upperOutputFile = "f3.txt";

        LowerCase lc = new LowerCase(inputFile, lowerOutputFile);
        UpperCase uc = new UpperCase(inputFile, upperOutputFile);

        lc.start();
        uc.start();

        try {
            lc.join();
            uc.join();
        } catch (InterruptedException e) {
            System.out.println(e.getMessage());
        }

        System.out.println("File processing completed.");
    }
}
