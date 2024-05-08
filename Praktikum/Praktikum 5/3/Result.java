public class Result<T, E extends Exception> implements IResult<T, E> {
    private T data;
    private E error;

    // constructor
    public Result(T data, E err){
      this.data = data;
      this.error = err;
    }
  
    // return new Result object with data based on input
    public static <T, E extends Exception> Result<T, E> ok(T data) {
      return new Result<T,E>(data, null);
    }
  
    // return new Result object with error based on input
    public static <T, E extends Exception> Result<T, E> err(E error) {
      return new Result<T,E>(null, error);
    }
  
    // implement all other functions in the interface
    @Override
    public boolean isOk(){
      return data!=null;
    }

    @Override
    public boolean isErr(){
      return error != null;
    }

    @Override
    public T unwrap() throws Exception{
      if(!isOk()){
        throw error;
      }else{
        return data;
      }
    }

    @Override
    public T unwrapOrElse(T defaultValue) {
      if(!isOk()){
        return defaultValue;
      }else{
        return data;
      }
    }

    @Override
    public T unwrapOrThrow(Exception defaultException) throws Exception{
      if(!isOk()){
        throw defaultException;
      }else{
        return data;
      }
    }
  }