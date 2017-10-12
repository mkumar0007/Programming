import java.io.*;
import java.util.*;


public class TestClass {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter wr = new PrintWriter(System.out);
        int T = Integer.parseInt(br.readLine().trim());
        for(int t_i=0; t_i<T; t_i++)
        {
            String P = br.readLine();
            String Q = br.readLine();
            int cost_size = Integer.parseInt(br.readLine().trim());
            String[] arr_cost = br.readLine().split(" ");
            int[] cost = new int[cost_size];
            for(int i_cost=0; i_cost<arr_cost.length; i_cost++)
            {
            	cost[i_cost] = Integer.parseInt(arr_cost[i_cost]);
            }

            int out_ = amount_to_pay(Q, P, cost);
            System.out.println(out_);
         }

         wr.close();
         br.close();
    }
    static int amount_to_pay(String Q, String P, int[] cost){
        int arrlen=cost.length;
        int c=0;
        int num[]=new int[arrlen];
        int qlen=Q.length()-1;
        int len=P.length();
        int index=P.indexOf(Q);
        if(index>=0)
        {
            num[c]=cost[index];
            c++;
            for(int k=index+1;k<len;k+=index+qlen)
            {
                index=P.indexOf(Q,k);
                num[c]=cost[index];
                c++;
            }
        }
        Arrays.sort(num);
        return num[arrlen-1]+num[arrlen-2];
    }
}
