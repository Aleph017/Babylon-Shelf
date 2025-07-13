import java.util.Random;

public class Shelf{
  private long counter = 0;
  public boolean russian = false;
  private String query = "";
  private String alphabet = "";
    
  public void setRussian(){
    russian = true;
  }

  public void setQuery(String str){
    query = str;
  }

  public long getCounter(){
    return counter;
  }

  public void initiateAlphabet(){
    alphabet = russian ? "йцукенгшщзхъфывапролджэячсмитьбюё" : "qwertyuiopasdfghjklzxcvbnm"; 
  }

  public void findQuery(){
    int query_length = query.length();
    char[] tmp = new char[query_length];
    int alphabet_size = alphabet.length();
    char[] local_alphabet = alphabet.toCharArray();
    Random rng = new Random();
    long timeStart = System.nanoTime();

    while(true){
      for(int i = 0; i < query_length; i++){
        tmp[i] = local_alphabet[rng.nextInt(alphabet_size)];
        counter ++;
      }
      String str_tmp = new String(tmp);

      if(str_tmp.equals(query)){
        long timeEnd = System.nanoTime();
        double duration = (timeEnd - timeStart) / 1_000_000_000.0;
        
        String format = !russian ? "The word \"%s\" was found!\nIt took %,d "+
        "symbols and %,.2f seconds\nAverage combination speed = %,.2f "+
        "symbols per second\n"
        :"Слово \"%s\" было найдено!\nЭто заняло %,d символов и %,.2f секунд "+
        "\nСредняя скорость перебора = %,.2f символов в секунду\n" ;

        System.out.printf(
            format,
            query,
            counter,
            duration,
            counter / duration
        );

        break;
      }
    }
  }
}

