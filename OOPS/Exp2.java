import java.util.Scanner;

class Frequency {
    public static void main(String[] argv) {
       int i,l=0,count=0;
       String str,ch;
       Scanner sc=new Scanner(System.in);
       
       System.out.print("Enter the string: ");
       str=sc.next();
       
       System.out.print("Enter the string for checking frequency: ");
       ch=sc.next();
       
       l=str.length();
       
       for(i=0;i<l;i++) {
       if(str.charAt(i)==ch.charAt(0)) {
       count++;
       }
     }
    System.out.print("Frequency of the given character: "+count);
   }
}  

    
