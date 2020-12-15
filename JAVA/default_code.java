import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner keyboard=new Scanner(System.in);
		String str;
        int num;
		while(keyboard.hasNext()){
		    str=keyboard.next();
            System.out.println(str);
          	num=keyboard.nextInt();
          	System.out.println(num);
        }
	}
}
