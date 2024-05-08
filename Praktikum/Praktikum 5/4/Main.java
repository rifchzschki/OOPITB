import java.util.Arrays;
import java.util.List;
import java.util.function.Function;

public class Main {
    public static void main(String[] args) {
        // Buat beberapa data untuk diuji
        List<Integer> numbers = Arrays.asList();

        // Buat instance Streamer
        Streamer<Integer> streamer = new Streamer<Integer>(numbers);

        // Contoh penggunaan metode-metode dalam Streamer

        // collect()
        List<Integer> collectedData = streamer.collect();
        System.out.println("Collected Data: " + collectedData);

        // forEach()
        System.out.print("ForEach: ");
        streamer.forEach(item -> {
            System.out.print(item + " ");
            return null; // Karena metode forEach() memerlukan fungsi yang tidak mengembalikan nilai
        });
        System.out.println();

        // map()
        System.out.println("Mapped Data (multiply by 2):");
        IStreamer<Integer> mappedStream = streamer.map(item -> item * 2);
        mappedStream.forEach(item -> {
            System.out.print(item + " ");
            return null;
        });
        System.out.println();

        // filter()
        System.out.println("Filtered Data (greater than 2):");
        IStreamer<Integer> filteredStream = streamer.filter(item -> item > 2);
        filteredStream.forEach(item -> {
            System.out.print(item + " ");
            return null;
        });
        System.out.println();

        // reduce()
        Integer sum = streamer.reduce(20, acc -> item -> acc + item);
        System.out.println("Sum of all numbers: " + sum);

        // flatMap()
        System.out.println("FlatMapped Data (stream of lists):");
        IStreamer<Integer> flatMappedStream = streamer.flatMap(item -> new Streamer<>(Arrays.asList(item, item + 1, item + 2)));
        flatMappedStream.forEach(item -> {
            System.out.print(item + " ");
            return null;
        });
        System.out.println();

        // findFirst()
        Integer first = streamer.findFirst(item -> item > 2);
        System.out.println("First number greater than 2: " + first);

        // findLast()
        Integer last = streamer.findLast(item -> item > 2);
        System.out.println("Last number greater than 2: " + last);

        // head()
        System.out.println("Head: " + streamer.head());

        // tail()
        System.out.println("Tail: ");
        streamer.tail().forEach(item -> {
            System.out.print(item + " ");
            return null;
        });
        System.out.println();

        // last()
        System.out.println("Last: " + streamer.last());

        // init()
        System.out.println("Init: ");
        streamer.init().forEach(item -> {
            System.out.print(item + " ");
            return null;
        });
        System.out.println();

        // takeFirst()
        System.out.println("TakeFirst 3: ");
        streamer.takeFirst(3).forEach(item -> {
            System.out.print(item + " ");
            return null;
        });
        System.out.println();

        // takeLast()
        System.out.println("TakeLast 3: ");
        streamer.takeLast(3).forEach(item -> {
            System.out.print(item + " ");
            return null;
        });
        System.out.println();

        // isEmpty()
        System.out.println("Is Empty: " + streamer.isEmpty());

        // count()
        System.out.println("Count: " + streamer.count());

        // some()
        System.out.println("Some (is any number greater than 4): " + streamer.some(item -> item > 4));

        // every()
        System.out.println("Every (are all numbers greater than 0): " + streamer.every(item -> item > 0));

        // reverse()
        System.out.println("Reversed Data:");
        streamer.reverse();
        streamer.forEach(item -> {
            System.out.print(item + " ");
            return null;
        });
        System.out.println();
    }
}
