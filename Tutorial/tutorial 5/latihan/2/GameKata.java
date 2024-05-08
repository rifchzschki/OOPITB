import java.util.HashMap;
import java.util.Map;

public class GameKata {
    public static void run(String[] tito, String[] wiwid) {
         Map<String, Integer> titoWords = new HashMap<>();
         Map<String, Integer> wiwidWords = new HashMap<>();

         for (String string : tito) {
            titoWords.put(string, titoWords.getOrDefault(titoWords, 0)+1);
         }
         for (String string : wiwid) {
            wiwidWords.put(string, wiwidWords.getOrDefault(wiwidWords, 0)+1);
         }
         for (String key : titoWords.keySet()) {
            if(wiwidWords.containsKey(key)){
                System.out.println(key);
            }
         }
    
    }
}
