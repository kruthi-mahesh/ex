/*
Sample input:
10 4 
2 5 3 6
Sample output:
5
*/
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class coinChange {
    public static HashMap<String,Long> map = new HashMap<String,Long>();
    public static int[] coins;
    coinChange(int[] arr){
       coins = arr;
    }

   
             
    public static long makeChange( int money,int index) {
        
        if(money==0)
            return 1;
        if(index >= coins.length)
            return 0;
        
        
        String key = money + " " + index;
        if(map.containsKey(key))
            return map.get(key);
        int amountwithcoin = 0;
        long ways = 0;
        while(amountwithcoin <= money){
            int remaining = money - amountwithcoin;
            ways += makeChange(remaining, index+1);
            amountwithcoin += coins[index];
        }
        map.put(key,ways);
        return ways;
    }
    public static long makeChange(int money){
        return makeChange(money,0);
    }
             
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();//n is money
        int m = in.nextInt();//m is number of different coins
        int coins[] = new int[m];
        for(int coins_i=0; coins_i < m; coins_i++){
            coins[coins_i] = in.nextInt();
        }
        coinChange soln = new coinChange(coins);
        System.out.println(soln.makeChange(n));
    }
}
