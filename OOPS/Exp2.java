import java.util.Scanner;

public class Frequency {
    public static void main(String[] args) {
        String str, ch;
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a string: ");
        str = sc.next();
        
        System.out.print("Enter the character to check frequency: ");
        ch = sc.next();

        int len, count = 0;

        len = str.length();

        for(int i=0; i<len; i++) {
            if(str.charAt(i) == ch.charAt(0)) {
                count++;
            }
        }

        System.out.print("Frequency = "+count);
    }
}
