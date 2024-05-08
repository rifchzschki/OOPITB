import java.util.ArrayList;
import java.util.List;
import java.util.function.Function;

public class Streamer<T> implements IStreamer<T> {

    private List<T> data;

    public Streamer(List<T> data) {
        this.data = data;
    }

    @Override
    public List<T> collect() {
        return new ArrayList<>(data);
    }

    @Override
    public void forEach(Function<T, Void> consumer) {
        for (T t : data) {
            consumer.apply(t);
        }
    }

    @Override
    public <R> IStreamer<R> map(Function<T, R> mapper) {
        List<R> mappedData = new ArrayList<>();
        for (T t : data) {
            mappedData.add(mapper.apply(t));
        }
        return new Streamer<>(mappedData);
    }

    @Override
    public IStreamer<T> filter(Function<T, Boolean> predicate) {
        List<T> filteredData = new ArrayList<>();
        for (T t : data) {
            if (predicate.apply(t)) {
                filteredData.add(t);
            }
        }
        return new Streamer<>(filteredData);
    }

    @Override
    public <R> R reduce(R initialValue, Function<R, Function<T, R>> reducer) {
        R result = initialValue;
        for (T t : data) {
            result = reducer.apply(result).apply(t);
        }
        return result;
    }

    @Override
    public <R> IStreamer<R> flatMap(Function<T, IStreamer<R>> mapper) {
        List<R> flatMappedData = new ArrayList<>();
        for (T t : data) {
            IStreamer<R> mappedStream = mapper.apply(t);
            List<R> Data = mappedStream.collect();
            for (R d : Data) {
                flatMappedData.add(d);
            }
        }
        return new Streamer<>(flatMappedData);
    }

    @Override
    public T findFirst(Function<T, Boolean> predicate) {
        for (T t : data) {
            if (predicate.apply(t)) {
                return t;
            }
        }
        return null;
    }

    @Override
    public T findLast(Function<T, Boolean> predicate) {
        T lastMatch = null;
        for (T t : data) {
            if (predicate.apply(t)) {
                lastMatch = t;
            }
        }
        return lastMatch;
    }

    @Override
    public T head() {
        return data.isEmpty() ? null : data.get(0);
    }

    @Override
    public IStreamer<T> tail() {
        return data.isEmpty() ? new Streamer<>(new ArrayList<>()) : new Streamer<>(data.subList(1, data.size()));
    }

    @Override
    public T last() {
        return data.isEmpty() ? null : data.get(data.size() - 1);
    }

    @Override
    public IStreamer<T> init() {
        return data.isEmpty() ? new Streamer<>(new ArrayList<>()) : new Streamer<>(data.subList(0, data.size() - 1));
    }

    @Override
    public IStreamer<T> takeFirst(int n) {
        return new Streamer<>(data.subList(0, Math.min(n, data.size())));
    }

    @Override
    public IStreamer<T> takeLast(int n) {
        return new Streamer<>(data.subList(Math.max(0, data.size() - n), data.size()));
    }

    @Override
    public Boolean isEmpty() {
        return data.isEmpty();
    }

    @Override
    public Integer count() {
        return data.size();
    }

    @Override
    public Boolean some(Function<T, Boolean> predicate) {
        for (T t : data) {
            if (predicate.apply(t)) {
                return true;
            }
        }
        return false;
    }

    @Override
    public Boolean every(Function<T, Boolean> predicate) {
        if(isEmpty()){
            return false;
        }else{
            for (T t : data) {
                if (!predicate.apply(t)) {
                    return false;
                }
            }
            return true;
        }
    }

    @Override
    public void reverse() {
        List<T> reversedData = new ArrayList<>();
        for (int i = data.size() - 1; i >= 0; i--) {
            reversedData.add(data.get(i));
        }
        data = reversedData;
    }
}
