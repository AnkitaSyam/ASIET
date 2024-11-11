package FISAT_LAB;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;

public class TextFile {
    public static void main(String[] args) {
        try{
            FileReader fr = new FileReader("C:\\Users\\USER\\Java Lab\\TextFileInput.txt");
            BufferedReader br = new BufferedReader(fr);
    
            FileWriter fw = new FileWriter("TextFileOutput.txt");
            BufferedWriter bw = new BufferedWriter(fw);

            String line;
            int charCount = 0;
            int lineCount = 0;
            int wordCount = 0;

            while((line = br.readLine()) != null) {

                System.out.println("Reading line: " + line);
                
                lineCount++;
                charCount = charCount + line.length();
                wordCount = wordCount + line.split("\\s+").length;
            }

            System.out.println("Characters Count: " + charCount);
            System.out.println("Lines Count: " + lineCount);
            System.out.println("Words Count: " + wordCount);

            br.close();
            bw.close();
          
            fr.close();
            fw.close();
        } catch(IOException e) {
            System.out.println(e.getMessage());
        }
    }
}
