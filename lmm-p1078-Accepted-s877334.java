
import java.util.*;
public class Another_candies {
    public static void main(String[] args) {
        Scanner in =new Scanner(System.in);
        long t = in.nextLong();
        
        for(int i = 0; i < t; i++)
        {
            long cont = 0;
            long N = in.nextLong();
            for(int j = 0; j < N; j++)
            {
                long x = in.nextLong();
                cont += x;
            }
            if(cont % N==0)
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }
}
        