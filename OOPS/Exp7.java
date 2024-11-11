import java.io.FileReader;
import java.io.FileWriter;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;

public class FileRW {
    public static void main(String[] args) {
        
        try {
            FileReader fr = new FileReader("FileRWInput.txt");
            BufferedReader br = new BufferedReader(fr);

            FileWriter fw = new FileWriter("FileRWOutput.txt");
            BufferedWriter bw = new BufferedWriter(fw);

            String line;

            while((line = br.readLine()) != null) {
                System.out.println(line);
                bw.write(line);
            }

            br.close();
            bw.close();

            fr.close();
            fw.close();
            
        } catch(IOException e) {
            System.out.println(e.getMessage());
        }
        
    }
}
