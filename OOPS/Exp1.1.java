import java.util.Scanner;

public class PalindromeString {
    public static void main(String[] args) {
        String str;
        int flag=0;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a string: ");
        str = sc.next();

        int len = str.length();
        
        for(int i=0; i<len/2; i++) {
            // Compare characters from the start and end of the string moving inward
            if(str.charAt(i) != str.charAt(len-1-i)) {
                flag=1;
                break;
            }
        }

            if(flag==0) {
                System.out.println(str+" is a palindrome");
            }
            else {
                System.out.println(str+" is not a palindrome");
            }
    }
}
